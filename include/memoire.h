#ifndef MEMOIRE_H
#define MEMOIRE_H

#include <stddef.h>
#include <stdbool.h>

extern void *memoire_allouer(size_t size);
extern void *memoire_reallouer(void *p, size_t size);
extern void memoire_liberer(void *p);
extern void memoire_trace(bool actif);
extern int memoire_balance();

#endif  /* MEMOIRE */
