#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main () {
  int error = 0, i = 0, tmp = 0;
  float dato = 0.0;
  string nombre;
  ofstream binario;

  cout << "Ingrese el nombre del archivo: ";
  cin >> nombre;

  binario.open(nombre.c_str());
//   binario.open(nombre.c_str(), ios::binary);
  if (binario.fail()) {
    cerr << "No se pudo abrir el archivo " << nombre << endl;
    error = 1;
  }
  else {
    for (i = 0; i < 100; i++) {
      tmp = rand() % 2000 - 1000;
      dato = 1.0 / tmp;
      binario << dato << endl;
//       binario.write(reinterpret_cast< const char * >(&dato),
//                       sizeof(float));
    }
    binario.close();
  }

  return error;
}
