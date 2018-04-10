#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[]) {
  const int elems = 1000;
  int error = 0, repeat = 200000000;
  int idx = 0, loop = 0;
  double sourceArray[elems], maximum = 0.0, max1 = 0.0, max2 = 0.0;

  if (argc == 2)
    repeat = atoi(argv[1]);

  srand(time(NULL));

  for (idx = 0; idx < elems; idx++)
    sourceArray[idx] = RAND_MAX / 2.0 / rand();

  for (loop = 0; loop < repeat; loop++) {
    max1 = sourceArray[0];
    max2 = sourceArray[1];
    for (idx = 2; idx < elems; idx += 2) {
      if (sourceArray[idx] > max1)
        max1 = sourceArray[idx];
      if (sourceArray[idx + 1] > max2)
        max2 = sourceArray[idx + 1];
    }
    if (max1 > max2)
      maximum = max1;
    else
      maximum = max2;
  }


/*   for (idx = 0; idx < 10; idx++) */
/*     printf("%f\n", sourceArray[idx]); */

  return error;
}
