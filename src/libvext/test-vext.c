#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <memoire.h>

#include "vext.h"

static void
afficher_element(void *element)
{
  printf("%s ", (char *) element);
}

static vext
faire_v1(void)
{
  vext v1 = vext_creer();
 
  vext_ajouter(v1, "10");
  vext_ajouter(v1, "20");
  vext_ajouter(v1, "30");
  vext_ecrire(v1, 1, "40");
  
  return v1;
}

static vext
faire_v2(void)
{
  vext v2 = vext_creer();
 
  // vext_definir_liberation(v2, memoire_liberer);
  vext_ajouter(v2, "50");
  vext_ajouter(v2, "60");
  vext_ajouter(v2, "70");
  vext_ecrire(v2, 1, "80");
  
  return v2;
}

int
main(int argc, char *argv[])
{
  memoire_trace(false);
  vext v1 = faire_v1();
  
  printf("v1 : ");
  vext_iterer(v1, afficher_element);
  printf("\n");
  
  vext_liberer(v1);
  printf("memoire balance= %d\n", memoire_balance());
  
  vext v2= faire_v2();
  printf("v2 : ");
  vext_iterer(v2, afficher_element);

  printf("\n");

  vext_liberer(v2);
  printf("memoire balance= %d\n", memoire_balance());

  return EXIT_SUCCESS;
}