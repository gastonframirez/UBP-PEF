#include <stdio.h>

int main () {
  float dato1 = 2.5e-6, dato2 = 1e6, tmp, r;
  int i;

  printf("Valores iniciales: %g y %g\n", dato1, dato2);

  tmp = dato1;
  for (i = 0; i < 1000; i++)
    tmp += dato1 * i;

  r = tmp + dato2;
  printf("Primero sumo los menores y luego le sumo el mayor\n");
  printf("tmp = %f - total = %f\n", tmp, r);

  /******************************/
  tmp = dato2 + dato1;
  for (i = 0; i < 1000; i++)
    tmp += dato1 * i;

  r = tmp;
  printf("Ahora invierto el orden de las sumas\n");
  printf("tmp = %f - total = %f\n", tmp, r);

  return 0;
}
