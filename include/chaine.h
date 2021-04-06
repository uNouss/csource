#ifndef CHAINE_H
#define CHAINE_H

#include <stdio.h>

extern int chaine_compter_occurrences(const char [], char);
extern void chaine_remplacer_occurrences(char [], char, char);

extern char *chaine_dupliquer(const char []);
extern char *chaine_concatener(const char [], const char []);

extern char *chaine_filtrer(const char [], int (*)(int));

extern char *chaine_vers_majuscules(const char []);
extern char *chaine_vers_minuscules(const char []);

extern char *chaine_suffixe(const char [], char);
extern char *chaine_prefixe(const char [], char);

extern char *chaine_lire();
extern char *chaine_lire_ligne_de_fichier (FILE *f);

extern void fragmenter_chaine(char *s,char *tab[],int taille);

#endif /* CHAINE_H */
