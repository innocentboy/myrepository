/*
* sjinn - command-line RS-232 control and serial communications
* Copyright (C) 2001  Aspen Research Corporation
* 
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
* 
* Brian Peterson <bpeterso@aspenresearch.com>
* Aspen Research Corporation, 1700 Buerkle Road, White Bear Lake, MN 55110
*/

#define PACKAGE "sjinn"
#define VERSION "1.0"

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "rs232.h"

#define strMove(d,s) memmove(d,s,strlen(s)+1)

static void  print_version (void);
static void  print_help    (void);
static char  *strDelChar   (char *s, char const *delchar);
static void  setstr        (char *s, char *opt, int length);
static int   ck_range      (char const *s, int min, int max);

/*****************************************************************************
 * DISPLAY VERSION INFO
 * **************************************************************************/
static void
print_version (void)
{
   printf ("%s version %s\n", PACKAGE, VERSION );
   printf ("Software provided courtesy of Aspen Research Corporation\n");
   printf ("This is free software with ABSOLUTELY NO WARRANTY\n");
}

/*****************************************************************************
 * DISPLAY HELP INFO
 * **************************************************************************/
static void
print_help (void)
{
   printf ("\n");
   printf ("Usage:   %s option [options] ...\n", PACKAGE);
   printf ("\n");
   printf ("-d, --file  serial I/O device                      [default /dev/ttyS0]\n");
   printf ("-b, --baud  set baudrate                           [default 9600]\n");
   printf ("-p, --comm  set (databits)(parity)(stopbits)       [default 8n1]\n");
   printf ("\n");
   printf ("--xonxoff   XON/XOFF (software flow control)       [default off]\n");
   printf ("--rtscts    RTS/CTS  (hardware flow control)       [default off]\n");
   printf ("--dtr       disable DTR                            [default enabled]\n");
   printf ("--rts       enable  RTS                            [default disabled]\n");
   printf ("\n");
   printf ("-s, --send  STRING  write string to device\n");
   printf ("-r, --read  INT     read n characters from device\n");
   printf ("-w, --wait  FLOAT   seconds between send and read  [default 0.5]\n");
   printf ("--pause     FLOAT   wait time for pause-character  [default = wait]\n");
   printf ("-m, --msec  specify pause and \\w times in mSec     [default = seconds]\n");
   printf ("\n");
   printf ("-n, --nolf  do not output the trailing new line\n");
   printf ("--trim      INT truncate lines to n chars\n");
   printf ("--wrap      INT wrap lines to n characters\n");
   printf ("--hex       display read buffer in hex             [default = ASCII_ONLY]\n");
   printf ("--hex+      display read buffer in hex + ASCII     [default = ASCII_ONLY]\n");
   printf ("--verbose   verbose\n");
   printf ("\n");
   printf ("-h  --help     display this help and exit\n");
   printf ("-V, --version  output version and exit\n");
}

/*****************************************************************************
 * MAIN
 * **************************************************************************/
extern int
main (int argc, char **argv)
{
   char devicename[MAXFILECHARS];
   char sendstring[MAXSENDCHARS];
   
   tCommParms commParm;  /* serial I/O parameters */
   tCmdParms  cmdParm;   /* serial I/O command parameters */
   tOutParms  outParm;   /* read buffer display parameters */
   tMdLines   mdLine;    /* RS-232 modem control lines */
   tProgParms progParm;  /* program parameters */
   
   int c;	         /* option character */
   int pauseArg = FALSE; /* flag to check if pause option was used */ 
   
   /* SET OPTION DEFAULTS */
   
   strcpy (devicename, "/dev/ttyS0");
   strcpy (sendstring, "");
  
   progParm.debug = OFF;
   progParm.rndm  = OFF;
   
   commParm.device   = devicename;
   commParm.baudrate = 9600;
   commParm.databits = 8;
   commParm.parity   = 'n';
   commParm.stopbits = 1;
   commParm.xonxoff  = OFF;
   commParm.rtscts   = OFF;

   cmdParm.write      = OFF;
   cmdParm.sendstring = sendstring;
   cmdParm.wait       = 0.5;
   cmdParm.read       = OFF;
   cmdParm.readlength = 255;
   cmdParm.pause      = cmdParm.wait;
   cmdParm.msec       = FALSE;
   
   outParm.wrap       = OFF;
   outParm.wraplen    = 80;
   outParm.trim       = OFF;
   outParm.trimlen    = 80;
   outParm.lf         = ON;

   outParm.hex        = ASCII_ONLY;
   
   mdLine.dtr = ON;
   mdLine.rts = OFF;
   
   /* GET OPTIONS */
   
   while (1)
     {
	int option_index = 0;
	static struct option long_options[] = {
	     { "file",	   required_argument, NULL, 'd' },
	     { "baud",	   required_argument, NULL, 'b' },
	     { "comm",	   required_argument, NULL, 'p' },
	     { "xonxoff",  no_argument,       NULL, 129 },
	     { "rtscts",   no_argument,       NULL, 130 },
	     { "dtr",	   no_argument,       NULL, 131  },
	     { "rts",	   no_argument,       NULL, 132  },
	     { "send",	   required_argument, NULL, 's' },
	     { "wait",	   required_argument, NULL, 'w' },
	     { "read",	   required_argument, NULL, 'r' },
	     { "pause",    required_argument, NULL, 133 },
             { "msec",     no_argument,       NULL, 'm' },   
	     { "hex",      no_argument,       NULL, 134 },
	     { "hex+",     no_argument,       NULL, 135 },
	     { "wrap",     required_argument, NULL, 136 },
	     { "trim",     required_argument, NULL, 137 },
	     { "nolf",     no_argument,       NULL, 'n' },
	     { "verbose",  no_argument,       NULL, 139 },
	     { "help",	   no_argument,       NULL, 'h' },
	     { "version",  no_argument,       NULL, 'V' },
	     { "rand",	   no_argument,       NULL, 255 },
	     { NULL,	   no_argument,       NULL,  0  }
	};

	c = getopt_long (argc, argv, "hVd:b:p:mns:r::w:",
			 long_options, &option_index);
	
	if (c == -1)
	  break;
	
	switch (c) {

	   /* device */
	 case 'd':	
	   setstr (commParm.device, optarg, MAXFILECHARS);
	   break;
	   /* baud */
	 case 'b':
	   commParm.baudrate = ck_range (optarg, 50, 230400);
	   break;
	   /* comm. parameters */	   
	 case 'p':
	   strDelChar (optarg, ","); /* remove commas separating settings */
	   strDelChar (optarg, " "); /* remove spaces between parameters */
	   commParm.databits = (int)optarg[0] - 48;
	   commParm.parity   = toupper (optarg[1]);
	   commParm.stopbits = (int)optarg[2] - 48;
           break;

	   /* XON/XOFF */  
	 case 129:
	   commParm.xonxoff=ON;
	   /* RTS/CTS */  
	 case 130:
	   commParm.rtscts = ON;
  	   /* DTR low */
	 case 131:
	   mdLine.dtr = OFF;
	   break;
	   /* RTS low */
	 case 132:
	   mdLine.rts = ON;
	   break;

	   /* send */   
	 case 's':
	   setstr (cmdParm.sendstring, optarg, MAXSENDCHARS);
  	   cmdParm.write=ON;
	   break;
	   /* wait time */ 
	 case 'w':
	   cmdParm.wait = ck_atof (optarg);
	   if (pauseArg == FALSE)
	     cmdParm.pause = cmdParm.wait;
	   break;
	   /* read */  
	 case 'r':
	   cmdParm.readlength = ck_range (optarg, 1, MAXREADCHARS);
	   cmdParm.read = ON;
	   break;
	   /* pause time */
	 case 133:
	   cmdParm.pause = ck_atof (optarg);
	   pauseArg = TRUE;
           break;
	   /* milliseconds */
	 case 'm':
	   cmdParm.msec = TRUE;
           break;
	   	   
	   /* hex */
	 case 134:
	   outParm.hex = HEX_ONLY;
	   break;
	   /* hex + ascii */
	 case 135:
	   outParm.hex = BOTH;
	   break;
	   /* line wrap */
	 case 136:
	   outParm.wrap = ON;
	   if (optarg != NULL)
	     outParm.wraplen = ck_range (optarg, 16, 80);  
	   break;
	   /* truncate (trim) line */
	 case 137:
	   outParm.trim = ON;
	   outParm.trimlen = ck_range (optarg, 16, 80);
	   break;  
	   /* hex + ascii */
	 case 'n':
	   outParm.lf = OFF;
	   break;
	   /* verbose */
	 case 139:	
	   progParm.debug = ON;
	   break;

	   /* help */  
	 case 'h':
	   print_help ();
	   exit (EXIT_OK);
	   /* version */
	 case 'V':	
	   print_version ();
	   exit (EXIT_OK);
	   
	   /* hidden option for developers - generates random read buffer */
	 case 255:
	   progParm.rndm = ON;
	   break;
	   
	   /* invalid option (getopt_long displayed error) */
	 case '?': 
	   exit (EXIT_ERROR);
	}
     }

   if (argc <= 1) { 
      printf("%s: Nothing to do.\n", PACKAGE);
      printf("%s: Try 'sjinn --help' for more information.\n", PACKAGE);
      return ERROR;
   }
   
   rs232_main (&commParm, &cmdParm, &mdLine, &progParm, &outParm);
   return OK;
}


/*****************************************************************************
 * DELETE ALL INSTANCES of a CHARACTER from STRING
 * inputs:
 *   *str  = address of string
 *   *char = address of character to delete
 * outputs:
 *   address of string
 ****************************************************************************/
static char *
strDelChar (char *str, char const *c)
{
   char *s;
   
   if (!str || !*str) 
     return NULL;
   
   if (c)
     for (s=str; *s; ++s)
       if (strchr (c, *s) ) {
	strMove (s, s+1);
	--s;
     }
   
   return str;
}

/*****************************************************************************
 * CHECK RANGE
 * inputs:
 *   num = number to be checked
 *   min = mininum value
 *   max = maximum value
 * outputs:
 *   if out of range -> prints error messages and exits with error
 ****************************************************************************/
static int
ck_range (char const *str, int min, int max)
{
   int i;
   
   i = (int)ck_atof (str);  
   if (i < min  || i > max) {
      fprintf (stderr, "%s: %d out of range\n", PACKAGE, i);
      exit (EXIT_ERROR);
   }
   
   return i;
}

/*****************************************************************************
 * CONVERT STRING to FLOAT 
 * inputs:
 *   *str = address of string to be converted to a float
 * outputs:
 *   if valid number -> return float
 *   if invalid num  -> print error message and exit with error
 ****************************************************************************/
extern float
ck_atof (char const *str)
{
  char const *cp;
   
  for (cp = str; *cp; cp++)
    if (!isdigit (*cp) && *cp != '.' ) {
       fprintf (stderr, "%s: %s should be a number\n", PACKAGE, str);
      exit (EXIT_ERROR);
    }

  return atof (str);
}


/*****************************************************************************
 * SET (COPY) STRING
 * inputs:
 *   *str = address of string to store results
 *   *opt = address of option string to be copied
 * outputs:
 *   valid number = set string str to string opt 
 *   invalid      = print error message, exits program with ERROR
 ****************************************************************************/
static void
setstr (char *str, char *opt, int length)
{
   char *cp;
   if (strlen (opt) > length) {
      fprintf (stderr, "%s: %s argument too long\n", PACKAGE, opt);
      exit (EXIT_ERROR);
   }
   for (cp=opt; (*cp != '\0'); cp++) {
      if (*cp == '-') {
	 if (cp == opt || (*(cp-1) != '\\')) {
	    fprintf (stderr, "%s: to send NULL use -s\"\\0\" not -s\"\" or -s\n", PACKAGE);
            fprintf (stderr, "%s: to include '-' character in send string use '\\-'\n", PACKAGE);
            exit (EXIT_ERROR);
         }
      }
   }
   strcpy (str, opt);
}
