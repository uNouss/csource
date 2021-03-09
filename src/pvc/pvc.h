/*
** voyageurCommerce.h
** 
** Made by (Sow Younoussa)
** Login   <unouss@ik.me>
** 
** Started on  Tue Mar 25 13:48:11 2018 Sow Younoussa
** Last update Wed Apr  9 12:02:26 2018 Sow Younoussa
*/

#ifndef   	VOYAGEURCOMMERCE_H_
# define   	VOYAGEURCOMMERCE_H_
#include <vext.h>
#include <disterre.h>

typedef struct ville *ville;

extern ville creer_ville(char *,position_terrestre );
extern void afficher_ville(ville);
extern double distance_itineraire(vext );
extern void permutation(vext itineraire, vext tourne_optimal);
extern void lire_villes(const char *filename, vext villes);

#endif 	    /* !VOYAGEURCOMMERCE_H_ */
