#include <iostream>
#include <iomanip>

using namespace std;

//
// Autor: Maximiliano A. Eschoyez
// Programacion Eficiente - UBP 2007
//
// Mon Aug  6 23:58:43 ART 2007
//

int main (void) {
  float  x=0.1, y=1.0, resultadoF=0.0;
  double xx=0.1, yy=1.0, resultadoD=0.0;
  int i=0;

  for (i=0; i<11; i++) {
    x  *= 0.1;
    xx *= 0.1;
    y  *= 10.0;
    yy *= 10.0;
    resultadoF = x + y;
    resultadoD = xx + yy;

    cout << "Utilizando FLOAT:  ";
    cout << setiosflags(ios::fixed)<<setprecision(12)<<setw(16) << x  << " + ";
    cout << setiosflags(ios::fixed)<<setprecision(12)<<setw(25) << y  << " = ";
    cout << setiosflags(ios::fixed)<<setprecision(12)<<setw(25) << resultadoF << endl;
    cout << "Utilizando DOUBLE: ";
    cout << setiosflags(ios::fixed)<<setprecision(12)<<setw(16) << xx << " + ";
    cout << setiosflags(ios::fixed)<<setprecision(12)<<setw(25) << yy << " = ";
    cout << setiosflags(ios::fixed)<<setprecision(12)<<setw(25) << resultadoD << endl << endl;
  }

  return 0;
}
