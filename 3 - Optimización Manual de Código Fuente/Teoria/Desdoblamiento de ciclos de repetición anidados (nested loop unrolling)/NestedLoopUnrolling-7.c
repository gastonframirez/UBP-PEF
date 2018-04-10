#include <stdio.h>
#include <stdlib.h>

double** CrearMatriz  (int fil, int col);
double** BorrarMatriz (double** matriz, int fil);

int main (int argc, char *argv[]) {
  int repetir = 1, loop = 0, offset = 0;
  int error = 0, f = 0, c = 0;
  int filas = 1920, columnas = 1200;
  double **pantalla = NULL, **imagen = NULL;

  if (argc > 1)
    repetir = atoi(argv[1]);
  if (argc > 2) {
    filas = atoi(argv[2]);
    if (argc == 4)
      columnas = atoi(argv[3]);
    else
      columnas = filas;
  }

  pantalla = CrearMatriz(filas, columnas);

  if (pantalla == NULL) {
    perror("CrearMatriz()");
    error = -1;
  }
  else {
    imagen = CrearMatriz(filas, columnas);
    if (pantalla == NULL) {
      perror("CrearMatriz()");
      error = -1;
    }
  }

  if (!error) {
    printf("Ok!\nRepitiendo loops %d veces para matriz %dx%d\n",
	   repetir, filas, columnas);

    for (f = 0; f < filas; f++)
      for (c = 0; c < columnas; c++)
	imagen[f][c] = 20.0 + f * c;

    for (loop = 0; loop < repetir; loop++) {
      offset = filas % 7;
      for (f = 0; f < offset; f++)
	for (c = 0; c < columnas; c++)
	  pantalla[f][c]     = imagen[f][c]     + 120.0;

      for (f = offset; f < filas; f += 7)
	for (c = 0; c < columnas; c++) {
	  pantalla[f][c]     = imagen[f][c]     + 120.0;
	  pantalla[f + 1][c] = imagen[f + 1][c] + 120.0;
	  pantalla[f + 2][c] = imagen[f + 2][c] + 120.0;
	  pantalla[f + 3][c] = imagen[f + 3][c] + 120.0;
	  pantalla[f + 4][c] = imagen[f + 4][c] + 120.0;
	  pantalla[f + 5][c] = imagen[f + 5][c] + 120.0;
	  pantalla[f + 6][c] = imagen[f + 6][c] + 120.0;
	}
    }
  }
  pantalla = BorrarMatriz(pantalla, filas);
  imagen   = BorrarMatriz(imagen  , filas);

  return error;
}

double** CrearMatriz  (int fil, int col) {
  int idx = 0;
  double **m = NULL;

  m = calloc(fil, sizeof(double*));
  if (m != NULL) {
    m[idx] = calloc(col, sizeof(double));
    while ((m[idx] != NULL) && (++idx < fil))
      m[idx] = calloc(col, sizeof(double));
    if (m[idx - 1] == NULL)
      m = BorrarMatriz(m, idx - 1);
  }
  return m;
}

double** BorrarMatriz (double** matriz, int fil) {
  int idx = 0;

  if (matriz != NULL) {
    for (idx = 0; idx < fil; idx++)
      free(matriz[idx]);
    free(matriz);
    matriz = NULL;
  }
  return matriz;
}

