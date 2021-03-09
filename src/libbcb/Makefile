CC= gcc

PREFIX=../..

INCDIR = $(PREFIX)/include
LIBDIR = $(PREFIX)/lib
BINDIR = $(PREFIX)/bin

CFLAGS= -g -Wall -std=c99
CPPFLAGS=
LDLIBS=

LIBFILENAME=libbcb.a
INSTHEADERS=chaine.h memoire.h

OUTFILE=test-chaine
OBJS   = test-chaine.o chaine.o memoire.o


$(OUTFILE) : $(OBJS)

test-chaine.o: test-chaine.c chaine.h

chaine.o: chaine.c chaine.h

memoire.o: memoire.c memoire.h


install:  $(OUTFILE)
	./$(OUTFILE)
	test -d $(INCDIR) || mkdir $(INCDIR)
	test -d $(LIBDIR) || mkdir $(LIBDIR)
	cp $(INSTHEADERS) $(INCDIR)
	ar -rs  $(LIBDIR)/$(LIBFILENAME)  chaine.o memoire.o

clean :
	rm -f  $(OUTFILE) $(OBJS)

mrproper: clean
	rm -f   $(LIBDIR)/$(LIBFILENAME)
	cd $(INCDIR) ; rm -f $(INSTHEADERS)
