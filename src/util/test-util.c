#include "util.h"
#include <memoire.h>
#include <chaine.h>
#include <stdlib.h> 
#include <stdio.h>

int main(int argc , char **argv){
  if(argc !=2 ){
    fprintf(stderr,"Usage:<%s> \"phrase a fragmenter en mot\"(entre quote!!)\n",argv[0]);
    exit(EXIT_FAILURE);
  }
  char phrase[] = "une phrase a fragmenter en sept mots";
  char **tab = memoire_allouer(7*sizeof(char *));
  fragmenter_chaine(phrase,tab, 7);
  for (int i = 0 ; i < 7; i++){
    printf("%s\t",tab[i]);
    memoire_liberer(tab[i]);
  }
  memoire_liberer(tab);
  printf("\nmemoire balance : %d\n",memoire_balance());

  printf("test passe avec succes\n");
  return EXIT_SUCCESS;
}

