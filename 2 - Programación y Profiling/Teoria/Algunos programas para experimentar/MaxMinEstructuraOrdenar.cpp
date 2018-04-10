#include <iostream>

using namespace std;

struct Vector {
  int longitud;
  int numeros[10];
  int minimo, maximo;
};

void CargarNumeros (Vector *nro);
void MaxMin        (Vector *nro);
void MayorAMenor   (Vector *nro);
void MostrarVector (Vector *nro);

int main (void) {
  Vector numeros;
  numeros.longitud=10;

  CargarNumeros(&numeros);
  MaxMin(&numeros);

  cout << "El valor maximo es " << numeros.maximo
       << " y el minimo es " << numeros.minimo << endl;

  MayorAMenor(&numeros);
  MostrarVector(&numeros);

  return 0;
}


void CargarNumeros (Vector *nro) {
  int idx=0;
  cout << "Ingrese " << nro->longitud << "numeros" << endl;
  while (idx < nro->longitud) {
    cin >> nro->numeros[idx];
    idx++;
  }
}


void MaxMin (Vector *nro) {
  int i=0;
  nro->minimo=nro->numeros[0];
  nro->maximo=nro->numeros[0];

  for (i=1; i<nro->longitud; i++) {
    if (nro->minimo > nro->numeros[i]) {
      nro->minimo = nro->numeros[i];
    }
    if (nro->maximo < nro->numeros[i]) {
      nro->maximo = nro->numeros[i];
    }
  }
}


void MayorAMenor   (Vector *nro) {
  int cambio=1, idx=0, aux=0;
  while (cambio) {
    cambio=0;
    MostrarVector(nro);
    for (idx=1; idx < nro->longitud; idx++) {
      if (nro->numeros[idx-1]<nro->numeros[idx]) {
	aux = nro->numeros[idx-1];
	nro->numeros[idx-1] = nro->numeros[idx];
	nro->numeros[idx] = aux;
	cambio=1;
      }
    }
  }
}


void MostrarVector (Vector *nro) {
  int idx=0;
  for (idx=0; idx < nro->longitud; idx++) {
    cout << nro->numeros[idx] << "\t";
  }
  cout << endl;
}
