#ifndef DISTERRE_H
#define DISTERRE_H

/*
typedef enum {Nord=1, Sud=-1, Est=1, Ouest=-1} point_cardinal;

typedef struct 
{
  int degre;
  int minute;
  int seconde;
  point_cardinal cardinalite;
} coordonnee;

typedef struct 
{
  coordonnee latitude;
  coordonnee longitude;
} position_terrestre;
*/

typedef struct 
{
  double latitude;
  double longitude;
} position_terrestre;

extern double disterre_distance(position_terrestre x, position_terrestre y);


#endif
