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
* Written By: Brian Peterson <bpeterso@aspenresearch.com>
* Aspen Research Corporation, 1700 Buerkle Road, White Bear Lake, MN 55110
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include "rs232.h"

#define ASCII_WRAP_LEN 78
#define HEX_WRAP_LEN   26

static void sighandler (int whatever);
static void displayReading (char *readbuf, int readlength,
			    tOutParms const *outParm);
static char *randomRead (char *readbuf, int readlength);

tRS232 fd;

/*****************************************************************************
 * MAIN LOOP
 * ---------------------------------------------------------------------------
 *   inputs:
 *     commParm serial I/O settings
 *     cmdParm  serial I/O command settings
 *     mdln     RS-232 modem control line settings
 *     dbug     display verbose messages ?
 ***************************************************************************/
void
rs232_main (tCommParms *commParm, tCmdParms *cmdParm, tMdLines *mdln,
	    tProgParms *progParm, tOutParms *outParm) {

   char *readptr;
   char readbuf[MAXREADCHARS];

   readptr = readbuf;
    
   signal (SIGINT,  sighandler); 
   signal (SIGTERM, sighandler); 
   
   fd = rs232_open (commParm->device, progParm->debug);
   rs232_init  (fd, commParm, progParm->debug);
   rs232_mdlns (fd, mdln, progParm->debug);
   
   if (cmdParm->write) {
      rs232_send  (fd, cmdParm->sendstring, cmdParm->pause, cmdParm->msec, progParm->debug);
      rs232_wait  (cmdParm->wait, FALSE, progParm->debug);
   }

   if (cmdParm->read) { 
      if (progParm->rndm == OFF)
	readptr = rs232_read (fd, readbuf, cmdParm->readlength, progParm->debug);
      else 
	readptr = randomRead (readbuf, cmdParm->readlength);
      displayReading (readptr, cmdParm->readlength, outParm);
   }
   
   rs232_close(fd);
}

/*****************************************************************************
 * SIGNAL HANDLER - CLEANUP 
 ****************************************************************************/
static void
sighandler (int whatever ) {
   rs232_close(fd);
   exit(EXIT_INTRPT);
}
   
void 
Abort (tRS232 rs232) {
   if (rs232 != -1)
     rs232_close(fd);
   exit(EXIT_ERROR);
}
     

/*****************************************************************************
 * DISPLAY READ BUFFER
 * ---------------------------------------------------------------------------
 *   inputs:
 *     readptr pointer to read buffer
 * **************************************************************************/
static void 
displayReading (char *readbuf, int readlength,
		tOutParms const *outParm)
{
   int charcntr=0;            /* character counter */
   int colcntr=0;             /* column counter    */
   char *startptr = readbuf;  /* start of line     */
   char *stopptr;             /* end of line       */
   char *readptr  = readbuf;  /* current character */
      
   switch (outParm->hex) {
      
    case ASCII_ONLY:

       for (charcntr=0; charcntr < readlength; charcntr++) {
	 if ( (outParm->trim == OFF) || (colcntr+1 < outParm->trimlen) ) {
	    if (*readptr > 0x1f && *readptr < 0x7f)
	      printf ("%c", *(readptr));
	    else if (*(readptr) != 0xa) 
	      printf(".");
	 }
	 if (*readptr == 0xa) {
	    printf("\n");
	    colcntr=-1;
	 }
	 ++readptr;
	 ++colcntr;
	 if ((outParm->wrap == ON) && (outParm->trim ==OFF) &&
	     (colcntr+1 >= outParm->wraplen)) {
	    printf ("\n");
	    colcntr = 0;
	 }
      }
      if (outParm->lf == ON)
	printf ("\n");
      break;
      
    case HEX_ONLY:
	 
      for (charcntr=0; charcntr < readlength; charcntr++) {
	 if ( (outParm->trim == OFF) || (colcntr+3 < outParm->trimlen) ) {
	    if (*readptr >= 0)
	      printf ("%2x ", *(readptr));
	    else
	      printf ("%2x ", *(readptr) + 0x100);
	 }
	 ++readptr;
	 colcntr += 3;
	 if ((outParm->wrap == ON) && (outParm->trim == OFF) &&
	     (colcntr+3 >= outParm->wraplen)) {
	    printf ("\n");
	    colcntr = 0;
	 }
      }
      if (outParm->lf == ON)
	printf ("\n");
      break;
      
    case BOTH:
 
      while (charcntr < readlength) {
	 colcntr = 0;
         startptr=readptr;
	 while ( ((outParm->wrap == OFF) || (colcntr+3 < outParm->wraplen)) &&
	      (charcntr < readlength) && (*readptr != 0xa) ) {
	    if ( ((outParm->trim == OFF) || (colcntr+3 < outParm->trimlen)) ) {
	       if (*readptr > 0x1f && *readptr < 0x7f)
		 printf (" %c ", *(readptr));
	       else
		 printf(" . ");
	    }
	    ++charcntr;   
	    ++readptr;
	    colcntr += 3;
	 }
	 if (*readptr == 0xa)
	   printf ("CR");
	 printf ("\n");
	 colcntr = 0;
	 stopptr = readptr+1;	 
	 readptr = startptr;
	 while ( ((outParm->wrap == OFF) || (colcntr+3 < outParm->wraplen)) &&
		(readptr < stopptr) && (*readptr != 0xa) ) {
	    if ( ((outParm->trim == OFF) || (colcntr+3 < outParm->trimlen)) ) {
	       if (*readptr >= 0)
		 printf ("%2x ", *(readptr));
	       else
		 printf ("%2x ", *(readptr) + 0x100);
	    }
	    ++readptr;
	    colcntr += 3;
	 }
	 if (*readptr == 0xa) {
	   printf (" a ");
	   ++readptr;
	 }
	 printf("\n");
      }
   }
}

static char *
randomRead (char *readbuf, int readlength)
{
   int i;
   int r;
   srand(readlength);
   for(i=0; i < readlength; i++) {
      r = (int) (255.0*rand()/(RAND_MAX+1.0));
//      printf("%3d %2x\n",r,r);
      *(readbuf + i) = r;
   }
   strcpy (readbuf, "testing\n");
   *(readbuf + 9) = 144;
   *(readbuf + 10) = 160;
   *(readbuf + 100) = 10;
   return readbuf;
}

