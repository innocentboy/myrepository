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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <math.h>
#include <string.h>
#include <sys/termios.h>
#include <sys/ioctl.h>
#include "rs232.h"

#define TOGGLE(flag) flag=flag?OFF:ON

static int setBaudRate  (struct termios *rs232_attr, int baudrate);
static int setDataBits  (struct termios *rs232_attr, int databits);
static int setParity    (struct termios *rs232_attr, char parity);
static int setStopBits  (struct termios *rs232_attr, int stopbits);
static int setFlowCtl   (struct termios *rs232_attr, int xonxoff, int rtscts);
static void modemLine   (int *mdlns, int enabled, int mask);
static int  hex2dec     (char const *s);
static void dispMdlns   (char const *s, int status, int mdln);

static struct termios rs232_attr;

/*****************************************************************************
 * OPEN SERIAL DEVICE
 ****************************************************************************/
extern tRS232
rs232_open (char const *device, int dbug)
{
   tRS232 rs232;

   rs232 = open ("/dev/ttyS0", O_RDWR | O_NOCTTY);
    
   if (dbug) printf ("%s ", device);
   rs232 = open (device, O_RDWR | O_NOCTTY);
   if (rs232 == -1) {
      fprintf (stderr, "error opening %s\n", device); 
      Abort (rs232);
   }

   return rs232;
}

/*****************************************************************************
 * INITIALIZE SERIAL DEVICE (SET COMMUNICATION PARAMETERS)
 ****************************************************************************/
extern int
rs232_init (tRS232 rs232, tCommParms *commParm, int dbug)
{
   if (dbug)
     printf ("%d %d%c%d ", commParm->baudrate,
	     commParm->databits, commParm->parity, commParm->stopbits);
   
   rs232_attr.c_oflag = 0;
   rs232_attr.c_lflag = 0;
   rs232_attr.c_iflag = ICRNL | IGNPAR;
   rs232_attr.c_cflag = CREAD | CLOCAL;	
   
   if (setBaudRate (&rs232_attr, commParm->baudrate) == ERROR) Abort (rs232);
   if (setDataBits (&rs232_attr, commParm->databits) == ERROR) Abort (rs232);
   if (setParity   (&rs232_attr, commParm->parity  ) == ERROR) Abort (rs232);
   if (setStopBits (&rs232_attr, commParm->stopbits) == ERROR) Abort (rs232);
   if (setFlowCtl  (&rs232_attr, commParm->xonxoff, commParm->rtscts) == ERROR)
     Abort (rs232);

   if ( tcsetattr (rs232, TCSANOW, &rs232_attr) == -1) { 
      fprintf (stderr, "error setting tcsetattr on %s\n", commParm->device);  
      Abort (rs232);
   }

   return OK;
}

/*****************************************************************************
 * CONTROL MODEM LINES
 ****************************************************************************/
extern int
rs232_mdlns (tRS232 rs232, tMdLines *mdLine, int dbug)
{
   int mdlns;

   if ( ioctl (rs232,TIOCMGET,&mdlns) == -1) {
      fprintf (stderr,"error ioctl TIOCMGET\n"); 
      Abort (rs232);
   }
   modemLine (&mdlns, mdLine->dtr, (int)TIOCM_DTR);
   modemLine (&mdlns, mdLine->rts, (int)TIOCM_RTS);
   
   if ( ioctl (rs232,TIOCMSET,&mdlns) == -1) {
      fprintf(stderr,"error ioctl(TIOCMSET)\n"); 
      Abort (rs232);
   }
   
   if (dbug) {
      if ( ioctl (rs232,TIOCMGET,&mdlns) == -1) {
	 fprintf (stderr,"error ioctl TIOCMGET\n"); 
	 Abort (rs232);
      }
      dispMdlns ("dtr", mdlns, TIOCM_DTR);
      dispMdlns ("rts", mdlns, TIOCM_RTS);
      dispMdlns ("cts", mdlns, TIOCM_CTS);
      dispMdlns ("dsr", mdlns, TIOCM_DSR);
      printf ("\n");
   }
   return OK;
}

/*****************************************************************************
 * SEND STRING TO SERIAL DEVICE
 ****************************************************************************/
extern int
rs232_send (tRS232 rs232, char *sendstring, float pause, int msec, int dbug)
{
   int hexMode = OFF;     /* send hex values instead of ASCII chars */
   int writeMode = ON;    /* \p and \h should not be sendt to device */
   int charcnt;
   
   char *cp = sendstring; /* character pointer */
   char *startptr;
   char h[3];             /* hex code buffer */
   char c;                /* character to be written to device */
   char s[MAXSENDCHARS];
   
   h[2]='\0';             /* terminate hex code buffer */   
  
   if (dbug) printf ("send ");
   
   do {
      writeMode = ON;
      if (*cp == '\\') {
	 switch ( *(cp + 1) ) {
	    /* BACK-SLASH */
	  case '\\':
	    if (dbug) printf ("\\");
	    c = '\\';
	    cp++;
	    break;
	    /* MINUS-SIGN (DASH) */
	  case '-':
	    if (dbug) printf ("-");
	    c = '-';
	    cp++;
	    break;
	    /* NL */
	  case 'n':
	    if (dbug) printf ("<lf>");
	    c = '\n';
	    cp++;
	    break;
	    /* LF */ 	    
	  case 'r':	    
	    if (dbug) printf ("<cr>");
	    c = '\r';
	    cp++;
	    break;
	    /* NULL */	   
	  case '0':
	    if (dbug) printf ("<null>");
	    c = '\0';
	    cp++;
	    break;
	    /* PAUSE */
	  case 'p': 
	    if (dbug) printf ("<pause>\n");
	     rs232_wait (pause, msec, dbug);
	     cp++;
	     writeMode = OFF;
	     break;
	    /* WAIT */
	  case 'w': 
	     if (dbug) printf ("<wait>\n");
	     charcnt = 0;
	     startptr = cp + 2;
	     while (*(cp+charcnt) != '\0' && *(cp+charcnt) != ' ') {
		++charcnt;
	     }
	     strncpy (s, startptr, charcnt-2);    
	     rs232_wait (ck_atof (s), msec, dbug);
	     cp += charcnt;
	     break;
	     /* HEX */
	   case 'h':
	     TOGGLE(hexMode);
	     if (dbug) {
	       if (hexMode == ON)
		 printf("<hex>");
	       else
		 printf("<ascii>");
	    }
	    cp++;
	    writeMode = OFF;
	    break;
	  default:
	    if (dbug) printf("%c", *cp);
	    c = *cp;
	 }
      } else {
	 if (hexMode) {
	    /* HEX CODE */
	    if (*cp == ' ')
	      ++cp;
	    h[0]=*(cp++);
	    h[1]=*(cp);
	    c = (char)hex2dec (h);
	    if (dbug) { 
	       if (c < 0)
		 printf ("(%x)", (int)c + 0x100);
	       else
		 printf ("(%x)", (int)c);
	    }
	 } else {
	    if (dbug) printf("%c", *cp);
	    c = *cp;
	 }
      }
      
      if (writeMode == ON)
	if (write (rs232, &c, 1) != 1) {
	   fprintf (stderr, "error: write\n");
	   Abort (rs232);
	}
      
   } while (*(++cp) != '\0');
   
   if (dbug) printf("\n");	

   return OK;
};

/*****************************************************************************
 * WAIT FOR # of SECONDS
 ****************************************************************************/
extern void
rs232_wait (float waittime, int mSec, int dbug)
{
   if (mSec == TRUE) {
      usleep (waittime * 1E3);
      if (dbug)
	printf ("wait %f mSec\n", waittime);
   } else {
      usleep (waittime * 1E6);
      if (dbug)
	printf ("wait %f seconds\n", waittime);
   }
}

/*****************************************************************************
 * READ # of BYTES FROM SERIAL DEVICE OR UNTIL STOP CHARACTER IS FOUND
 ****************************************************************************/
extern char *
rs232_read (tRS232 rs232, char *readbuf, int readlength, int dbug)
{
   if (dbug) printf("read %d characters", readlength);

   if (read (rs232, readbuf, readlength) == -1) Abort (rs232);
   readbuf[readlength]='\0';
   
   if (dbug) printf("\n");
   return readbuf; 
 }

/*****************************************************************************
 * CLOSE SERIAL DEVICE
 ****************************************************************************/
extern int
rs232_close (tRS232 rs232)
{
  if (close (rs232) == -1) {
      fprintf (stderr, "error closing serial I/O device\n");
      Abort (-1);
  }
  return OK;
}

/*****************************************************************************
 * SET BAUD RATE
 ****************************************************************************/
static int
setBaudRate (struct termios *rs232_attr, int baudrate)
{
   switch (baudrate) { 
    case 50:
      rs232_attr->c_cflag |= B50;
      break;
    case 75:
      rs232_attr->c_cflag |= B75;
      break;
    case 110:
      rs232_attr->c_cflag |= B110;
      break;
    case 134:
      rs232_attr->c_cflag |= B134;
      break;
    case 150:
      rs232_attr->c_cflag |= B150;
      break;
    case 200:
      rs232_attr->c_cflag |= B200;
      break;
    case 300:
      rs232_attr->c_cflag |= B300;
      break;
    case 600:
      rs232_attr->c_cflag |= B600;
      break;
    case 1200:
      rs232_attr->c_cflag |= B1200;
      break;
    case 2400:
      rs232_attr->c_cflag |= B2400;
      break;
    case 4800:
      rs232_attr->c_cflag |= B4800;
      break;
    case 9600:
      rs232_attr->c_cflag |= B9600;
      break;
    case 19200:
      rs232_attr->c_cflag |= B19200;
      break;
    case 38400:
      rs232_attr->c_cflag |= B38400;
      break;
    case 57600:
      rs232_attr->c_cflag |= B57600;
      break;
    case 115200:
      rs232_attr->c_cflag |= B115200;
      break;
    case 230400:
      rs232_attr->c_cflag |= B230400;
      break;
    default:
      fprintf (stderr, "error: unsupported baud rate\n");
      return ERROR;
   }

   return OK;
}

/*****************************************************************************
 * SET CHARACTER SIZE
 ****************************************************************************/
static int
setDataBits (struct termios *rs232_attr, int databits)
{
   switch (databits) {   
    case 5:
      rs232_attr->c_cflag |= CS5;
      break;
    case 6:  
      rs232_attr->c_cflag |= CS6;
      break;
    case 7:
      rs232_attr->c_cflag |= CS7;
      break;
    case 8:
      rs232_attr->c_cflag |= CS8;
      break;
    default:
      fprintf (stderr, "error: unsupported character size\n");
      return ERROR;
   }
   return OK;
}

/*****************************************************************************
 * SET PARITY
 ****************************************************************************/
static int
setParity (struct termios *rs232_attr, char parity)
{
   switch (toupper(parity)) {   
     case 'N':
       break;
     case 'E':  
       rs232_attr->c_cflag |= PARENB;
       break;
     case 'O': 
       rs232_attr->c_cflag |= PARODD;
       break;
     default:
       fprintf (stderr, "error: unsupported parity mode\n");
       return ERROR;
   }
   return OK;
}

/*****************************************************************************
 * SET STOP BITS
 ****************************************************************************/
static int
setStopBits (struct termios *rs232_attr, int stopbits)
{
   switch (stopbits) {   
    case 1:
      break;
    case 2:  
      rs232_attr->c_cflag |= CSTOPB;
      break;
    default:
      fprintf (stderr, "error: unsupported number of stop bits\n");
      return ERROR;
   }
   return OK;
}

/*****************************************************************************
 * SET HARDWARE and SOFTWARE FLOW CONTROL
 ****************************************************************************/
static int
setFlowCtl (struct termios *rs232_attr, int xonxoff, int rtscts)
{
   if (xonxoff) {
      rs232_attr->c_iflag |= IXON;
      rs232_attr->c_iflag |= IXOFF;
   }
   
   if (rtscts)
     rs232_attr->c_cflag |= CRTSCTS;
   
   return OK;
}
   
/*****************************************************************************
 * SET AN INDIVIDUAL MODEM LINE
 ****************************************************************************/
static void
modemLine (int *mdlns, int enabled, int mask)
{
   if (enabled)
     *mdlns |= mask;
   else
     *mdlns &= ~mask;
}

/*****************************************************************************
 * CONVERT HEX STRING (w/o 0x, i.e. "0D") to DECIMAL
 *   Inputs:  hex string without 0x preceding the number
 *            (i.e. "OD" will work, "0xOD" will not work)
 *   Outputs: the decimal value after conversion or
 *            or the ERROR constant if the string was not valid
 ****************************************************************************/
static int
hex2dec (char const *s)
{
   int n, i;
   int dec = 0;
    i = strlen (s) - 1;
   while (i >= 0) {
      if (isdigit (*s))
	n = *s - 48;
      else 
	 n = toupper (*s) - 55;
      if ((n < 0) || (n > 15))
	return ERROR;
      dec += (int)pow (16, i--) * n;
      s++;
   }
   return dec;
}

static void   
dispMdlns (char const *s, int status, int mdln)
{   
   if ((status & mdln) == mdln)
     printf ("+");
   else
     printf ("-");
   printf ("%s ", s);
}
   
/*****************************************************************************
* DEBUG CODE
*****************************************************************************/
/*
 char buffer[64];
 int rs232, mdlns;
 struct termios rs232_attr;

 rs232 = open ("/dev/ttyS0", O_RDWR | O_NOCTTY);
 rs232_attr.c_oflag = 0;
 rs232_attr.c_lflag = 0;
 rs232_attr.c_iflag = IGNBRK | IGNPAR;
 rs232_attr.c_cflag = B600 | CS7 | CREAD | CSTOPB| CLOCAL;
 tcsetattr (rs232, TCSANOW, &rs232_attr);
 ioctl (rs232, TIOCMGET, &mdlns);
 mdlns &= ~TIOCM_RTS;
 ioctl (rs232, TIOCMSET, &mdlns);
 write(rs232, "d\n", 2);
 usleep(3000000);
 read (rs232, buffer,64);
 buffer[64] = '\0';
 close (rs232);
 printf ("reading: %s\n", buffer);
*/
