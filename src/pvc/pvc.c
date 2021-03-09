#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <memoire.h>
#include <vext.h>
#include <disterre.h>
#include "pvc.h"

#define LINE_BUFFER_SIZE 1024
#define STRING_BUFFER_SIZE 256

struct ville{
  char *nom;
  position_terrestre position;
};


void afficher_ville(ville self){
  printf("%s ",self->nom);
}


ville creer_ville(char *nom,position_terrestre pt){
  ville v = memoire_allouer(sizeof(struct ville));
  v->nom = nom;
  v->position = pt;
  return v;
}


double distance_itineraire(vext self){
  int nb_v = vext_nombre_d_elements(self);
  ville v_depart = vext_lire(self,0);
  ville v_precedent = v_depart,v_courant;
  double d = 0.0;
  for(int i = 1 ; i < nb_v;i++)
  {
    v_courant = vext_lire(self,i);
    d += disterre_distance(v_precedent->position, v_courant->position);
    v_precedent = v_courant;
  }
  return d + disterre_distance(v_courant->position, v_depart->position);
}

void permutation(vext itineraire, vext tourne_optimal){
	int nb_element = vext_nombre_d_elements(itineraire);
	register unsigned int i;
	unsigned int indexes[nb_element];
  register double dist_itineraire, dist_min;
  for(i = 0; i < nb_element; i++) indexes[i] = 0;
  dist_min = DBL_MAX;
  //vext_afficher(itineraire);
	i = 0;
	while(i < nb_element){
		if(indexes[i] < i){
			vext_echanger_elements( i % 2 == 0 ? 0: indexes[i], i, itineraire);
      //vext_afficher(itineraire);
      dist_itineraire = distance_itineraire(itineraire);
      if(dist_itineraire < dist_min){
        dist_min = dist_itineraire;
        vext_copier(itineraire, tourne_optimal);
      }
			indexes[i]++;
			i = 0;
		} else {
			indexes[i] = 0;
			i++;
		}
	}
}

void
lire_villes(const char *filename, vext villes)
{
  FILE *file;
  if((file = fopen(filename, "r")) == NULL){
    perror("fopen");
    exit(EXIT_FAILURE);
  }
  double longitude, latitude;
  char buffer[LINE_BUFFER_SIZE];
  // memset(buffer, 0, LINE_BUFFER_SIZE);

  // lire l'entête
  fgets(buffer, LINE_BUFFER_SIZE, file);
  while (!feof(file)) 
  {
    // lire la line courante et la parser
    fgets(buffer, LINE_BUFFER_SIZE, file);
    char nom_ville[STRING_BUFFER_SIZE];
    sscanf(buffer, "%s%lf%lf", nom_ville, &latitude, &longitude);
    position_terrestre pt = {latitude, longitude};
    //printf("\n%s : lat = %lf, lon = %lf\n", nom_ville, pt.latitude, pt.longitude);
    vext_ajouter(villes, creer_ville(nom_ville, pt));
  }

  fclose(file);
}

/*
void
lire_villes(const char *filename, vext villes)
{
  FILE *file;
  if((file = fopen(filename, "r")) == NULL){
    perror("fopen");
    exit(EXIT_FAILURE);
  }
  double longitude, latitude;
  char nom_ville[STRING_BUFFER_SIZE] = {0};
  char *buffer;
  // lire l'entête
  chaine_lire_ligne_de_fichier(file);
  while((buffer = chaine_lire_ligne_de_fichier(file)) != NULL)
  {
    // lire la line courante et la parser
    sscanf(buffer, "%s%lf%lf", nom_ville, &latitude, &longitude);
    position_terrestre pt = {latitude, longitude};
    printf("%20s : lat = %2lf, lon = %2lf\n", nom_ville, pt.latitude, pt.longitude);
    vext_ajouter(villes, creer_ville(nom_ville, pt));
  }

  fclose(file);
}
*/