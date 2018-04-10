#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[]) {
  const int elems = 100;
  int error = 0, repeat = 200000000;
  int f = 0, c = 0, loop = 0;
  double sourceArray[elems][elems], destArray[elems][elems];

  if (argc == 2)
    repeat = atoi(argv[1]);

  srand(time(NULL));

  for (f = 0; f < elems; f++)
    for (c = 0; c < elems; c++)
      sourceArray[f][c] = RAND_MAX / 2.0 / rand();

  for (loop = 0; loop < repeat; loop++) {
    for (f = 0; f < elems; f++)
      for (c = 0; c < elems; c++) {
        if (f < c)
          destArray[f][c] = sourceArray[f][c] * 1000.0;
        else
          destArray[f][c] = 0;
      }
  }

  return error;
}
