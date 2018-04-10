#include <stdio.h>

void Sumar (float decimal, float esperado);

int main () {
  float decimal = 0.1;
  printf("Probando sumar %f 10 veces\n", decimal);
  Sumar(decimal, 1.0);

  decimal = 0.11;
  printf("Probando sumar %f 10 veces\n", decimal);
  Sumar(decimal, 1.1);

  decimal = 0.2;
  printf("Probando sumar %f 10 veces\n", decimal);
  Sumar(decimal, 2.0);

  decimal = 0.25;
  printf("Probando sumar %f 10 veces\n", decimal);
  Sumar(decimal, 2.5);

  return 0;
}

void Sumar (float decimal, float esperado) {
  int i = 0;
  float resultado = 0.0;

  for (i = 0; i < 10; i++)
    resultado += decimal;

  if (resultado == esperado)
    printf("%.9f decimal se puede representar correctamente\n", decimal);
  else
    printf("%.9f decimal no se puede representar correctamente\n", decimal);
}
