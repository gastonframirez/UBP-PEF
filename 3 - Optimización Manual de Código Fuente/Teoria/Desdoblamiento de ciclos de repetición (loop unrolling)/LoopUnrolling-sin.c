#include <stdio.h>
#include <stdlib.h>

double* CrearVector  (int elems);
double* BorrarVector (double * vector);

int main (int argc, char *argv[]) {
  int repetir = 1, loop = 0;
  int error = 0, f = 0;
  int elementos = 5000;
  double *pantalla = NULL, *imagen = NULL;

  if (argc > 1)
    repetir = atoi(argv[1]);
  if (argc == 3)
    elementos = atoi(argv[2]);

  pantalla = CrearVector(elementos);

  if (pantalla == NULL) {
    perror("CrearVector()");
    error = -1;
  }
  else {
    imagen = CrearVector(elementos);
    if (pantalla == NULL) {
      perror("CrearVector()");
      error = -1;
    }
  }

  if (!error) {
    printf("Ok!\nRepitiendo loops %d veces para vector %d\n",
	   repetir, elementos);

    for (f = 0; f < elementos; f++)
      imagen[f] = 100.0 + f;

    for (loop = 0; loop < repetir; loop++)
      for (f = 0; f < elementos; f++)
	pantalla[f] = imagen[f] + 120.0;

  }
  pantalla = BorrarVector(pantalla);
  imagen   = BorrarVector(imagen);

  return error;
}

double* CrearVector  (int elems) {
  double *m = NULL;

  m = calloc(elems, sizeof(double));

  return m;
}

double* BorrarVector (double* vector) {
  if (vector != NULL) {
    free(vector);
    vector = NULL;
  }
  return vector;
}

