#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <memoire.h>
#include <vext.h>
#include <disterre.h>
#include "pvc.h"


static unsigned int factorielle(int n){
  return n <= 0 ? 1: n * factorielle(n-1);
}

int main(void){
  // memoire_trace(true);
  vext itineraire = vext_creer();
  vext_definir_liberation(itineraire , memoire_liberer);
  vext_definir_affichage(itineraire , afficher_ville);
  

  position_terrestre pt1  = {43.30000, 5.400000};
  position_terrestre pt2  = {48.86667, 2.333333};
  position_terrestre pt3  = {50.63333, 3.066667};
  position_terrestre pt4  = {47.25000, 6.033333};
  position_terrestre pt5  = {48.40000, -4.483333};
  position_terrestre pt6  = {47.21667, -1.550000};
  position_terrestre pt7  = {44.83333, -0.566667};
  position_terrestre pt8  = {43.30000, -0.366667};
  position_terrestre pt9  = {43.60000, 3.883333};
  position_terrestre pt10 = {43.60000, 1.433333};
  // position_terrestre pt11 = {49.43333, 1.083333};
  // position_terrestre pt12 = {47.08333, 2.400000};
  // position_terrestre pt13 = {48.68333, 6.200000};
  // position_terrestre pt14 = {49.13333, 6.166667};
  // position_terrestre pt15 = {48.58333, 7.750000};
  // position_terrestre pt16 = {45.16667, 5.716667};
  // position_terrestre pt17 = {45.56667, 5.933333};
  // position_terrestre pt18 = {45.75000, 4.850000};
  // position_terrestre pt19 = {47.91667, 1.900000};
  // position_terrestre pt20 = {43.70000, 7.250000};
  // position_terrestre pt21 = {44.56667, 6.083333};
  // position_terrestre pt22 = {44.933333, 4.9};
  
  ville v1 = creer_ville("MARSEILLE",pt1);
  ville v2 = creer_ville("PARIS",pt2);
  ville v3 = creer_ville("LILLE",pt3);
  ville v4 = creer_ville("BESANCON",pt4);
  ville v5 = creer_ville("BREST",pt5);
  ville v6 = creer_ville("NANTES",pt6);
  ville v7 = creer_ville("BORDEAUX",pt7);
  ville v8 = creer_ville("PAU",pt8);
  ville v9 = creer_ville("MONTPELLIER",pt9);
  ville v10 = creer_ville("TOULOUSE",pt10);
  // ville v11 = creer_ville("ROUEN",pt11);
  // ville v12 = creer_ville("BOURGES",pt12);
  // ville v13 = creer_ville("NANCY",pt13);
  // ville v14 = creer_ville("METZ",pt14);
  // ville v15 = creer_ville("STRASBOURG",pt15);
  // ville v16 = creer_ville("GRENOBLE",pt16);
  // ville v17 = creer_ville("CHAMBERY",pt17);
  // ville v18 = creer_ville("LYON",pt18);
  // ville v19 = creer_ville("ORLEANS",pt19);
  // ville v20 = creer_ville("NICE",pt20);
  // ville v21 = creer_ville("GAP",pt21);
  // ville v22 = creer_ville("VALENCE",pt22);

  vext_ajouter(itineraire,v1);
  vext_ajouter(itineraire,v2);
  vext_ajouter(itineraire,v3);
  vext_ajouter(itineraire,v4);
  vext_ajouter(itineraire,v5);
  vext_ajouter(itineraire,v6);
  vext_ajouter(itineraire,v7);
  vext_ajouter(itineraire,v8);
  vext_ajouter(itineraire,v9);
  vext_ajouter(itineraire,v10);
  // vext_ajouter(itineraire,v11);
  // vext_ajouter(itineraire,v12);  
  // vext_ajouter(itineraire,v13);  
  // vext_ajouter(itineraire,v14);  
  // vext_ajouter(itineraire,v15);  
  // vext_ajouter(itineraire,v16);  
  // vext_ajouter(itineraire,v17);  
  // vext_ajouter(itineraire,v18);  
  // vext_ajouter(itineraire,v19);  
  // vext_ajouter(itineraire,v20);  
  // vext_ajouter(itineraire,v21);  
  // vext_ajouter(itineraire,v22);  
  
  vext tourne_otpimal, s_itineraire;
  
  //vext_copier(itineraire, tourne_otpimal);
  unsigned int nb_ville = vext_nombre_d_elements(itineraire);


  double mesure_temps[nb_ville-3];
  unsigned int mesure_memoire[nb_ville-3];
  clock_t start, end;
  printf("nb_ville,temps,memoire,factorielle\n");
  for(unsigned int i = 3; i <= nb_ville; i++){
    tourne_otpimal = vext_creer();
    s_itineraire = vext_creer();
    for(int j = 0; j < i; j++){
      vext_ajouter(s_itineraire, vext_lire(itineraire, j));
    }

    vext_copier(s_itineraire, tourne_otpimal);
    vext_definir_affichage(tourne_otpimal, afficher_ville);
    start = clock(); 
    mesure_memoire[i-3] = permutation(s_itineraire, tourne_otpimal);
    end = clock();
    mesure_temps[i-3] = ((double)(end - start));
    printf("%d,%f,%d,%d\n", i, mesure_temps[i-3], mesure_memoire[i-3], factorielle(i));
    // double d_min = distance_itineraire(tourne_otpimal);
    // printf("Voici un parcours minimal de longueur %g : \n",d_min);
    // vext_afficher(tourne_otpimal);
    vext_liberer(s_itineraire);
    vext_liberer(tourne_otpimal);
  }
  
  // double d_min = distance_itineraire(tourne_otpimal);
  // printf("Voici un parcours minimal de longueur %g : \n",d_min);
  // vext_afficher(tourne_otpimal);

  // vext villes = vext_creer();
  // vext_definir_affichage(villes, afficher_ville);
  // vext_definir_liberation(villes, memoire_liberer);
  // lire_villes("20villes.txt", villes);
  // vext_afficher(villes);
  // vext_liberer(villes);

  vext_liberer(itineraire);
  printf("memoire balance = %d \n", memoire_balance());
  return EXIT_SUCCESS;
}
