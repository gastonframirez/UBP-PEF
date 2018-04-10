#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[]) {
  const int elems = 1000;
  int error = 0, repeat = 200000000, doIt = 1;
  int idx = 0, loop = 0;
  double sourceArray[elems], destArray[elems];

  if (argc == 2)
    repeat = atoi(argv[1]);

  srand(time(NULL));

  for (idx = 0; idx < elems; idx++)
    sourceArray[idx] = RAND_MAX / 2.0 / rand();

  if (doIt)
    for (loop = 0; loop < repeat; loop++)
      for (idx = 0; idx < elems; idx++)
        destArray[idx] = sourceArray[idx] * 1000.0;
  else
    for (loop = 0; loop < repeat; loop++)
      for (idx = 0; idx < elems; idx++)
        destArray[idx] = 0;

/*   for (idx = 0; idx < 10; idx++) */
/*     printf("%f\n", sourceArray[idx]); */

  return error;
}
