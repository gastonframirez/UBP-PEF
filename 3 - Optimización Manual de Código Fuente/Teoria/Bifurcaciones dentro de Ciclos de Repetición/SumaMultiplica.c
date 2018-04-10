#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define elems 1000


int main (int argc, char *argv[]) {
/*   static int elems = 1000; */
  int loop = 0, repeat = 200000000;
  int idx = 0, error = 0;
  double sourceArray[elems], destArray[elems], value = 0.0;

  if (argc == 2)
    repeat = atoi(argv[1]);

  srand(time(NULL));

  value = RAND_MAX / 4.0 / rand();
  for (idx = 0; idx < elems; idx++) {
    sourceArray[idx] = (RAND_MAX / 2.0 / rand()) - (RAND_MAX / 4.0);
    destArray[idx]   = (RAND_MAX / 2.0 / rand()) - (RAND_MAX / 4.0);
  }

  printf("Ejecutando %d veces\n", repeat);
  for (loop = 0; loop < repeat; loop++) {
    for (idx = 0; idx < elems; idx++)
      destArray[idx] = destArray[idx] + sourceArray[idx] * value;
  }


/*   for (idx = 0; idx < 10; idx++) */
/*     printf("%f\n", sourceArray[idx]); */

  return error;
}
