
PREFIX=../..

INCDIR = $(PREFIX)/include
LIBDIR = $(PREFIX)/lib
BINDIR = $(PREFIX)/bin
#le compilateur
CC= gcc

#les flags de compilation
CFLAGS= -g -Wall -pedantic-errors -Werror -std=c99

# les flags du preprocesseur
CPPFLAGS= 

#les flags de l'editeur de lien 
LDFLAGS= -lm

#les librairies utilisees
LDLIBS= -lm

#la librairie a construire
LIBFILENAME= libdisterre.a

#les fichiers d'entete a construire
INSTHEADERS= disterre.h

#Le nom du fichier executable
OUTFILE= test-disterre

# les fichiers objets
OBJS= disterre.o test-disterre.o

#la creation du fichier executable
all:  $(OUTFILE)

# les dependances

$(OUTFILE) : $(OBJS)

# regle implicite utilisee par make pour l'edition de liens 

#	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS)  -o $@

# regle implicite utilisee par make pour la compilation

#	$(CC)   $(CPPFLAGS) $(CFLAGS) -c  -o $@ $<

# la creation et l'installation des bibliotheques


install:  $(OUTFILE)
	./$(OUTFILE)
	test -d $(INCDIR) || mkdir $(INCDIR)
	test -d $(LIBDIR) || mkdir $(LIBDIR)
	cp $(INSTHEADERS) $(INCDIR)
	ar -rs  $(LIBDIR)/$(LIBFILENAME) disterre.o 

# le nettoyage 
clean :
	rm -f  $(OUTFILE) $(OBJS)

mrproper: clean
	rm -f   $(LIBDIR)/$(LIBFILENAME) 
	cd $(INCDIR); rm  $(INSTHEADERS)
