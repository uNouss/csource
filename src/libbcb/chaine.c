#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "chaine.h"
#include "memoire.h"

#define TAILLE_BLOC 8


int
chaine_compter_occurrences (const char s[], char c)
{
  int nb = 0;
  for (char *p = strchr (s, c); p != NULL; p = strchr (p + 1, c))
    nb++;
  return nb;
}


void
chaine_remplacer_occurrences (char s[], char c1, char c2)
{
  for (char *p = strchr (s, c1); p != NULL; p = strchr (p + 1, c1))
    *p = c2;
}

char *
chaine_dupliquer (const char s[])
{
  int taille = strlen (s) + 1;
  char *res = memoire_allouer ((taille) * sizeof (char));
  memcpy (res, s, taille);
  return res;
}

char *
chaine_concatener (const char s1[], const char s2[])
{
  int len1 = strlen (s1);
  int len2 = strlen (s2);
  char *res = memoire_allouer ((len1 + len2 + 1) * sizeof (char));
  memcpy (res, s1, len1);
  memcpy (res + len1, s2, len2 + 1);
  return res;
}

char *
chaine_filtrer (const char s[], int (*f) (int))
{
  char *res = memoire_allouer ((strlen (s) + 1) * sizeof (char));
  int i;
  for (i = 0; s[i] != '\0'; i++)
    res[i] = f (s[i]);
  res[i] = '\0';
  return res;
}

char *
chaine_vers_majuscules (const char s[])
{
  return chaine_filtrer (s, toupper);
}

char *
chaine_vers_minuscules (const char s[])
{
  return chaine_filtrer (s, tolower);
}

char *
chaine_suffixe (const char s[], char c)
{
  char *p = strrchr (s, c);
  if (p == NULL)
    return chaine_dupliquer (s);
  return chaine_dupliquer (p + 1);
}

char *
chaine_prefixe (const char s[], char c)
{
  char *p = strrchr (s, c);
  if (p == NULL)
    return chaine_dupliquer ("");
  char *res = memcpy (memoire_allouer ((p - s + 1) * sizeof (char)), s, p - s);
  res[p - s] = '\0';
  return res;
}

char *
chaine_lire ()
{
  return chaine_lire_ligne_de_fichier(stdin);
}

char *
chaine_lire_ligne_de_fichier (FILE *f)
{
  int c = getc (f);
  if (c == EOF)
    return NULL;

  int taille = TAILLE_BLOC;
  char *tampon = memoire_allouer (taille);
  int i;

  for (i = 0; c != EOF; c = getc (f))
  {
    if (c == '\n')
    {
      if (i > 0 && tampon[i - 1] == '\\')
      {
        i--;			/* annulation du \n (precedé de \) */
        continue;
      }
      break;
    }

    tampon[i++] = c;

    if (i == taille)
    {
      /* Agrandissement du tampon de lecture */
#ifdef TRACE
      printf ("chaine_lire: %d -> %d\n", taille, 2 * taille);
#endif /* TRACE */
      tampon = memoire_reallouer (tampon, 2 * taille);
      taille *= 2;
    }
  }
  tampon[i] = '\0';
  return memoire_reallouer (tampon, i + 1);
}

void fragmenter_chaine(char *s,char *tab[],int taille) 
{ 
  assert(taille > 0);
  int j; 
  int i; 
  int k; 
  char p[256]; 
  char *q; 
  int h = 0; 
  strcpy (p, s); 
  k = strlen (p); 
  j = 0; 
  for (i = 0; i <= k; i++) { 
    if (p[i] == ' ' || p[i]== '\t'|| i == k) { 
      q = memoire_allouer(j + 1); 
      strncpy (q, p + i - j, j); 
      q[j] = 0; 
      tab[h] = memoire_allouer((strlen(q)+1));
      strcpy(tab[h],q);
      memoire_liberer(q); 
      j = 0; 
      h++;
    } else { 
      j = j + 1; 
    } 
  } 
}