CC= gcc

PREFIX=../..

INCDIR = $(PREFIX)/include
LIBDIR = $(PREFIX)/lib
BINDIR = $(PREFIX)/bin

CFLAGS= -g -Wall -std=c99 
CPPFLAGS= -I$(INCDIR) 
LDFLAGS= -L$(LIBDIR) 

LDLIBS= -lbcb

LIBFILENAME=libvext.a
INSTHEADERS=vext.h 


OUTFILE= test-vext


OBJS   = vext.o test-vext.o

$(OUTFILE) : $(OBJS)


vext.o: vext.c vext.h 

test-vext.o: test-vext.c vext.h 

install:  $(OUTFILE)
	./$(OUTFILE)
	test -d $(INCDIR) || mkdir $(INCDIR)
	test -d $(LIBDIR) || mkdir $(LIBDIR)
	cp $(INSTHEADERS) $(INCDIR)
	ar -rs  $(LIBDIR)/$(LIBFILENAME)  vext.o

clean :
	rm -f  $(OUTFILE) $(OBJS)

mrproper: clean
	rm -f   $(LIBDIR)/$(LIBFILENAME)  $(INCDIR)/$(INSTHEADERS)
