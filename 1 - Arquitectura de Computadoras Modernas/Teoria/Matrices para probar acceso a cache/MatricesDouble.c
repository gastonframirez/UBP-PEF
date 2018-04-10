#include <stdio.h>
#include <stdlib.h>

double**  CrearMatriz   (int rows, int cols);
void     BorrarMatriz  (double **m, int rows);
void     CargarMatriz  (double **m, int rows, int cols);
void     MostrarMatriz (double **m, int rows, int cols, FILE *out);

void     SumarElementos (double **m, double **n, int rows, int cols);

int main (int argc, char *argv[]) {
  int error=0, matrixRows=0, matrixCols=0, maxIters=0;
  double **matrizOriginal=NULL, **matrizAuxiliar=NULL, maxDiferencia=0.0;

  /* Verificacion de la cantidad de argumentos */
  if (argc<3) {
    fprintf(stderr,"Utilizar:\n\t%s iters rows [cols]\n",argv[0]);
    error=1;
  }
  else {
    /* Se toma la cantidad de elementos de la matriz (cuadrada) */
    maxIters=atoi(argv[1]);
    matrixRows=atoi(argv[2]);
    matrixCols= argc==4 ? atoi(argv[3]) : matrixRows;
    /* Se reserva la memoria para la matriz principal */
    matrizOriginal=CrearMatriz(matrixRows,matrixCols);
    if (matrizOriginal==NULL) {
      error=1;
    }
  }
  if (!error) {
    /* Se reserva la memoria para la matriz auxiliar */
    matrizAuxiliar=CrearMatriz(matrixRows,matrixCols);
    if (matrizAuxiliar==NULL) {
      error=1;
    }
  }

  if (!error) {
    /* Se inicializan ambas matrices con los mismos valores */
    CargarMatriz(matrizOriginal,matrixRows,matrixCols);
    CargarMatriz(matrizAuxiliar,matrixRows,matrixCols);

    SumarElementos(matrizOriginal,matrizAuxiliar,matrixRows,matrixCols);
    SumarElementos(matrizOriginal,matrizAuxiliar,matrixRows,matrixCols);
    SumarElementos(matrizOriginal,matrizAuxiliar,matrixRows,matrixCols);
    SumarElementos(matrizOriginal,matrizAuxiliar,matrixRows,matrixCols);
/*     MostrarMatriz(matrizOriginal,matrixRows,matrixCols,stdout); */
  }

  /* Se libera la memoria reservada para ambas matrices */
  BorrarMatriz(matrizOriginal,matrixRows);
  BorrarMatriz(matrizAuxiliar,matrixRows);

  return error;
}


/* Esta funcion reserva en memoria espacio para una matriz */
double**  CrearMatriz (int rows, int cols) {
  int i=0;
  double **m=NULL;

  m=(double**)(calloc(rows,sizeof(double*)));
/* printf("Allocate: %p |",m); */
  if (*m!=NULL) {
    perror("Chan!");
  }
  while (i<rows) {
    m[i]=(double*)(calloc(cols,sizeof(double)));
/* printf("  %p",m[i]); */
    if (m[i]==NULL) {
      perror("Chan!");
    }
    i++;
  }
/* printf("\n"); */

  return m;
}


/* Esta funcion libera la memoria utilizada para una matriz */
void BorrarMatriz (double **m, int rows) {
  int i=0;
/* printf("Freeing: "); */
  while (i<rows) {
/* printf("%p  ",m[i]); */
    free(m[i]);
    i++;
  }
/* printf("| %p\n",m); */
  free(m);
}


/* Esta funcion carga los valores iniciales en una matriz */
void CargarMatriz (double **m, int rows, int cols) {
  int i=0, j=0;
  for (i=0; i<rows; i++) {
    for (j=0; j<cols; j++) {
      m[i][j]=1.0;
    }
  }
}


/* Esta funcion muestra en pantalla el contenido de una matriz */
/* No conviene utilizarla con matrices grandes por la cantidad */
/* de informacion que genera */
void MostrarMatriz (double **m, int rows, int cols, FILE *out) {
  int i=0, j=0;
  for (i=0; i<rows; i++) {
    for (j=0; j<cols; j++) {
      fprintf(out,"%6.2f  ",m[i][j]);
    }
    fprintf(out,"\n");
  }
}


void SumarElementos (double **m, double **n, int rows, int cols) {
  int i=0, j=0;
  for (i=0; i<rows; i++) {
    for (j=0; j<cols; j++) {
/*       m[i][j]= m[i][j] + n[i][j]; */
      m[i][j]= m[i][j] * n[i][j];
    }
  }
}


