#include <math.h>
#include "disterre.h"

const double RAYON_TERRESTRE=6371.0;

static double 
deg2rad(double degree)
{
  const double PI = 3.1415926535897932384626433832795028841971693993751058209;
  return  (degree * PI)/180;
}

/*
static double 
deg2rad(coordonnee c)
{
  const double un_degre = atan(1.0) / 45.0; 

  return c.cardinalite * 
    (c.degre + c.minute / 60.0 + c.seconde / 3600.0) * un_degre;
}
*/

double disterre_distance(position_terrestre x, position_terrestre y)
{

  double latx = deg2rad(x.latitude);
  double lonx = deg2rad(x.longitude);
  double laty = deg2rad(y.latitude);
  double lony = deg2rad(y.longitude);

    
  return  RAYON_TERRESTRE * 
   acos((cos(latx)*cos(laty)*cos(lony - lonx))+sin(latx)*sin(laty));
}
