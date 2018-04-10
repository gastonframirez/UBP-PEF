#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main () {
    int error = 0, i = 0;
    string nombre;
    ofstream aleatorio;

    srand(time(NULL));

    cout << "Ingrese el nombre del archivo: ";
    cin >> nombre;

    aleatorio.open(nombre.c_str());
    if (aleatorio.fail()) {
        cerr << "No se pudo abrir el archivo" << endl;
        error = 1;
    }
    else {
         for (i = 0; i < 100; i++) {
             aleatorio << rand() % 101 << endl;
         }
         aleatorio.close();
    }

    return error;
}
