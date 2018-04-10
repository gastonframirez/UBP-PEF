#include <iostream>
#include <iomanip>

using namespace std;

//
// Autor: Maximiliano A. Eschoyez
// Programacion Eficiente - UBP 2007
//
// Wed Aug  8 00:51:51 ART 2007
//

int main (void) {
  const int cant=12;
  int i=0;
  float resultado=0.0;
  float numeros[cant] =
    {3e7, 1.2e6, 3.4e5, 5.8e4, 9.1e3, 32, 0.062, 7.2e-3, 2e-4, 3.6e-5, 2.5e-6, 3e-8};
  double resultadoD=0.0;
  double numerosD[cant] =
    {3e7, 1.2e6, 3.4e5, 5.8e4, 9.1e3, 32, 0.062, 7.2e-3, 2e-4, 3.6e-5, 2.5e-6, 3e-8};

  cout << "Probando FLOAT:" << endl;
  for (i=0; i<cant; i++) {
    resultado+=numeros[i];
    cout << "La suma de mayor a menor es ";
    cout << setiosflags(ios::fixed)<<setprecision(12)<<setw(21) << resultado;
    cout << endl;
  }
  cout << endl;

  resultado=0.0;
  for (i=cant-1; i>=0; i--) {
    resultado+=numeros[i];
    cout << "La suma de menor a mayor es ";
    cout << setiosflags(ios::fixed)<<setprecision(12)<<setw(21) << resultado;
    cout << endl;
  }
  cout << endl;

  cout << "Probando Double:" << endl;
  for (i=0; i<cant; i++) {
    resultadoD+=numerosD[i];
    cout << "La suma de mayor a menor es ";
    cout << setiosflags(ios::fixed)<<setprecision(12)<<setw(21) << resultadoD;
    cout << endl;
  }
  cout << endl;

  resultadoD=0.0;
  for (i=cant-1; i>=0; i--) {
    resultadoD+=numerosD[i];
    cout << "La suma de menor a mayor es ";
    cout << setiosflags(ios::fixed)<<setprecision(12)<<setw(21) << resultadoD;
    cout << endl;
  }

  cout <<endl<< "El resultado correcto deberia ser 31607132.06943853" <<endl;

  return 0;
}

