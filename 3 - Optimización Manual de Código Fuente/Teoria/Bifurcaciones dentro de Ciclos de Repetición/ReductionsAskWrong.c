#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[]) {
  const int elems = 1000;
  int error = 0, repeat = 200000000;
  int idx = 0, loop = 0;
  double sourceArray[elems], maximum = 0.0;

  if (argc == 2)
    repeat = atoi(argv[1]);

  srand(time(NULL));

  for (idx = 0; idx < elems; idx++)
    sourceArray[idx] = RAND_MAX / 2.0 / rand();

  for (loop = 0; loop < repeat; loop++) {
    maximum = sourceArray[0];
    for (idx = 1; idx < elems; idx++)
      maximum = sourceArray[idx] > maximum ? sourceArray[idx] : maximum;
  }


/*   for (idx = 0; idx < 10; idx++) */
/*     printf("%f\n", sourceArray[idx]); */

  return error;
}
