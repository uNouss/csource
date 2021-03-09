#ifndef   	VOYAGEURCOMMERCE_H_
#define   	VOYAGEURCOMMERCE_H_
#include <vext.h>
#include <disterre.h>

typedef struct ville *ville;

extern ville creer_ville(char *,position_terrestre );
extern void afficher_ville(ville);
extern double distance_itineraire(vext );
extern unsigned int permutation(vext itineraire, vext tourne_optimal);
extern void lire_villes(const char *filename, vext villes);

#endif 	    /* !VOYAGEURCOMMERCE_H_ */
