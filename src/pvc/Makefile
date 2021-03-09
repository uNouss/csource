
PREFIX=../..

INCDIR = $(PREFIX)/include
LIBDIR = $(PREFIX)/lib
BINDIR = $(PREFIX)/bin
#le compilateur
CC= gcc

#les flags de compilation
CFLAGS= -g -Wall -pedantic-errors -Werror -std=c99

# les flags du preprocesseur
CPPFLAGS= -I$(INCDIR)

#les flags de l'editeur de lien 
LDFLAGS= -L$(LIBDIR)

#les librairies utilisees
LDLIBS= -lvext -lbcb -ldisterre -lm -lutil -litoa

#la librairie a construire
LIBFILENAME= 

#les fichiers d'entete a construire
INSTHEADERS= 

SRC=$(wildcard *.c)

#Le nom du fichier executable
OUTFILE= voyageur

# les fichiers objets
OBJS= $(SRC:.c=.o)

#la creation du fichier executable
all:  $(OUTFILE)
	./$(OUTFILE)

# les dependances

$(OUTFILE) : $(OBJS)

# regle implicite utilisee par make pour l'edition de liens 

#	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS)  -o $@

# regle implicite utilisee par make pour la compilation

#	$(CC)   $(CPPFLAGS) $(CFLAGS) -c  -o $@ $<

# le nettoyage 
clean :
	rm -f  $(OUTFILE) $(OBJS)