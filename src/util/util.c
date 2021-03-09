#include "util.h"
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 
#include <assert.h>
#include <memoire.h>
#include <stdbool.h>


int *creer_entier(int a){
  int *t = malloc(sizeof(int));
  assert(t != NULL);
  *t= a;
  return t;
}


float *creer_float(float a){
  float *t = malloc(sizeof(float));
  assert(t != NULL);
  *t= a;
  return t;
}


double *creer_double(double a){
  double *t = malloc(sizeof(double));
  assert(t != NULL);
  *t= a;
  return t;
}



char *creer_car(char a){
  char *t = malloc(sizeof(char));
  assert(t != NULL);
  *t= a;
  return t;
}


int lire_entier(void)
{
   int x;
   
   while (true)
   {
      if (scanf("%d", &x) == 1)
	 return x;
      scanf ("%*[^\n]");
   }
} /* lire_entier */

double lire_flottant(void)
{
   double x;
   
   while (true)
   {
      if (scanf("%lg", &x) == 1)
	 return x;
      scanf ("%*[^\n]");
   }
}

char lire_caractere(void)
{
   char x;
   
   while (true)
   {
      if (scanf ("%c", &x)==1)
	 return x;
      scanf ("%*[^\n]");
   }   
} /* lire_caractere */