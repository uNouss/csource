#include "disterre.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>

int main(void){
  position_terrestre pt1  = {43.30000, 5.400000};
  position_terrestre pt2  = {48.86667, 2.333333};
  double paris_marseille = disterre_distance(pt1, pt2);
  printf("La distance entre Paris et Marseille est %f\n", paris_marseille);
  assert((int)disterre_distance(pt1, pt2) == 662);
  printf("test passé avec success\n");
  return 0;
}
