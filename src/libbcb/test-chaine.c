#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <strings.h>

#include "chaine.h"

#define CARACTERE_A_REMPLACER 'i'
#define CARACTERE_DE_REMPLACEMENT 'o'
#define CARACTERE_LIMITE 'i'

#define CHAINE_DE_TEST "Kilimandjaro"

int
main(void) {
  char chaine[] = CHAINE_DE_TEST;
  char chaine_limite[2] ={CARACTERE_LIMITE,'\0'};

  int nb1 = chaine_compter_occurrences(chaine, CARACTERE_A_REMPLACER);
  int nb2 = chaine_compter_occurrences(chaine, CARACTERE_DE_REMPLACEMENT);
    
  printf("chaine initiale : \"%s\"\n", chaine);
  printf("occurrences de %c : %d\n", CARACTERE_A_REMPLACER, nb1);
  printf("occurrences de %c : %d\n", CARACTERE_DE_REMPLACEMENT, nb2);

  char *dup_chaine = chaine_dupliquer(chaine);
  assert(strcmp(dup_chaine, chaine) == 0);

  chaine_remplacer_occurrences(dup_chaine, CARACTERE_A_REMPLACER,
			       CARACTERE_DE_REMPLACEMENT);
  printf("chaine apr�s remplacement de %c par %c :\n \"%s\"\n",
	 CARACTERE_A_REMPLACER, CARACTERE_DE_REMPLACEMENT, dup_chaine);


  if (chaine_compter_occurrences(dup_chaine, CARACTERE_A_REMPLACER) != 0) {
    fprintf(stderr, "certains caract�res n'ont pas �t� remplac�s\n");
    return EXIT_FAILURE;
  }

  if (nb1 + nb2 !=
      chaine_compter_occurrences(dup_chaine, CARACTERE_DE_REMPLACEMENT)) {
    fprintf(stderr, "Le test de coh�rence a �chou�\n");
    return EXIT_FAILURE;
  }


  printf("chaine initiale : \"%s\"\n", chaine);
  printf("chaine correspondante en majuscule : \"%s\", \
en minuscule : \"%s\"\n", 
	 chaine_vers_majuscules(chaine), chaine_vers_minuscules(chaine));

  assert(strcasecmp(chaine_vers_majuscules(chaine),
		    chaine_vers_minuscules(chaine)) == 0 &&
	 strcmp(chaine_vers_majuscules(chaine),
		chaine_vers_minuscules(chaine)) != 0);

  printf("chaine initiale : \"%s\"\n", chaine);
  printf("Avec caractere limite %c, chaine prefixe : \"%s\", \
 chaine suffixe : \"%s\"\n", 
	 CARACTERE_LIMITE, chaine_prefixe(chaine, CARACTERE_LIMITE), 
	 chaine_suffixe(chaine, CARACTERE_LIMITE));

  if (chaine_compter_occurrences(chaine, CARACTERE_LIMITE) != 0)
    assert(strcmp(chaine_concatener(chaine_concatener(chaine_prefixe(chaine,
								     CARACTERE_LIMITE), 
						      chaine_limite),
				    chaine_suffixe(chaine, CARACTERE_LIMITE)), 
		  chaine) == 0);
  else
    assert(strcmp(chaine_concatener(chaine_prefixe(chaine, CARACTERE_LIMITE),
				    chaine_suffixe(chaine, CARACTERE_LIMITE)),
		  chaine) == 0);

  char filename[] = "test-chaine.c";
  FILE *f = fopen(filename, "r");
  //check((f == NULL ? -1:0), "Cannot open file \"%s\"", filename);
  char *buf;
  while((buf = chaine_lire_ligne_de_fichier(f)) != NULL){
    printf("%s\n", buf);
  }

  printf("Test passé avec succes\n");
  return EXIT_SUCCESS;
}
