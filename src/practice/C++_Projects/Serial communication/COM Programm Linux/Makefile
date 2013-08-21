CC=gcc
CFLAGS=-pg -Wall
#CFLAGS=-g
LIB=-lm
INC=
INSTALL=/usr/bin/install -c
DEPEND=/usr/X11R6/bin/makedepend
TARGET=rs232
S_LINK=sjinn

prefix=/usr/local
exec_prefix=${prefix}
bindir=${exec_prefix}/bin
mandir=${prefix}/man/man1

rs232: rs232opts.o rs232main.o rs232ctl.o 
	$(CC) -o $(TARGET) rs232opts.o rs232main.o rs232ctl.o  $(CFLAGS) $(INC) $(LIB)

rs232opts.o: rs232opts.c rs232.h
	$(CC) -c rs232opts.c  $(CFLAGS) $(INC)

rs232main.o: rs232main.c rs232.h  
	$(CC) -c rs232main.c  $(CFLAGS) $(INC)

rs232ctl.o: rs232ctl.c rs232.h
	$(CC) -c rs232ctl.c  $(CFLAGS) $(INC)

install:
	$(INSTALL) $(TARGET) ${bindir}
	rm -f ${bindir}/$(S_LINK)
	ln -s ${bindir}/$(TARGET) ${bindir}/$(S_LINK)
	$(INSTALL) $(TARGET).1.gz ${mandir}/$(TARGET).1.gz
	rm -f ${mandir}/$(S_LINK).1.gz
	ln -s ${mandir}/$(TARGET).1.gz ${mandir}/$(S_LINK).1.gz

uninstall:
	rm -f ${bindir}/$(S_LINK)
	rm -f ${bindir}/$(TARGET)
	rm -f ${mandir}/$(S_LINK).1.gz
	rm -f ${mandir}/$(TARGET).1.gz

clean:
	rm -f $(TARGET) *.o 
# DO NOT DELETE
