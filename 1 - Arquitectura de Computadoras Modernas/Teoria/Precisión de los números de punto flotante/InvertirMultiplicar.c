#include <stdio.h>

int main () {
  const int total = 1000;
  int i, cantidad = 0;
  float x = 1.0, y, z;

  for (i = 0; i < total; i++) {
    y = 1.0 / x;
    z = x * y;
    if (z == 1.0)
      cantidad++;
    x += 1.0;
  }

  printf("Resultaron iguales %d intentos sobre %d\n", cantidad, total);

  return 0;
}
