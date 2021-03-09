#include <stdio.h>
#include <stdlib.h>
#include "memoire.h"

static int niveau = 0;
static bool trace = false;

static void
erreur_memoire(char *s)
{
    fprintf(stderr, "Erreur %s mémoire\n", s);
    exit(EXIT_FAILURE);
}

void
memoire_trace(bool mode)
{
    trace = mode;
}

static void
tracer(void *p)
{
  if (trace)
    printf("[memoire : %d (%p)]\n", niveau, p);
}

void *
memoire_allouer(size_t size)
{
    void *p = malloc(size);
    
    if (p == NULL && size != 0)
	    erreur_memoire("allocation");

    niveau++;
    tracer(p);

    return p; 
}

void *
memoire_reallouer(void *p, size_t size)
{
  void *q = realloc(p, size);
  
  if (size != 0 && q == NULL)
    erreur_memoire("reallocation");
  
  if (p == NULL && q != NULL)      
    niveau++;
  else if (p != NULL && size == 0)      
    niveau--;
  
  tracer(q);
  
  return q;
}

void 
memoire_liberer(void *p)
{
  free(p);
  if (p != NULL)
    niveau--;    
  
  tracer(p);
}

int 
memoire_balance()
{
  return niveau;
}
