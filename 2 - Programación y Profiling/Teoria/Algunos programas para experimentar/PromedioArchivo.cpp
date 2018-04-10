#include <iostream>
#include <fstream>

using namespace std;

int PromedioArchivo (int &promedio, int &total);

int main (void) {
  int error = 0, promedio = 0, total = 0;

  error = PromedioArchivo(promedio, total);
  if (!error)
    cout << "El promedio de los numeros del archivo es "
	 << promedio << " de " << total << " numeros" << endl;

  return error;
}

int PromedioArchivo (int &promedio, int &total) {
  int error = 0, aux = 0;
  string nombre;
  ifstream entrada;

  cout << "Ingrese el nombre del archivo: ";
  cin  >> nombre;

  entrada.open(nombre.c_str());
  if (entrada.fail()) {
    cerr << "No se pudo abrir el archivo" << endl;
    error = 1;
  }
  else {
    entrada >> aux;
    while (!entrada.eof()) {
      promedio += aux;
      total++;
      entrada >> aux;
    }
    promedio /= total;
    entrada.close();
  }

  return error;
}

