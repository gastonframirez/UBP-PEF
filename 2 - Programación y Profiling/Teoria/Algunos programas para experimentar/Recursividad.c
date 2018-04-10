#include <stdio.h>

void c (int n);
void a (int n);

int main (void) {
  int i = 0, n = 10;

  for (i = 0; i < 1000; i++) {
    c(n);
    a(n);
  }

  return 0;
}

void c (int n) {
  if (n > 0) {
    a(n - 1);
    c(n - 1);
  }
}

void a (int n) {
  c(n);
}
