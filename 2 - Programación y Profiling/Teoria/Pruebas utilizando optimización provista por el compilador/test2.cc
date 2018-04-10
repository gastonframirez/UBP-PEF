// 
// File:   test1.cc
// Author: meschoyez
//
// Created on August 6, 2007, 10:23 PM
//

#include <iostream>

using namespace std;

//
// 
//
int main() {
  float  x=0.0, y=0.0, z=0.0;
  double X=0.0, Y=0.0, Z=0.0;
  int i=0;

  cout << "Utilizando datos tipo FLOAT" << endl;
  for (x=1.0; x<1000.0; x=x+1.0) {
    y = 1.0 / x;
    z = y * x;
    if ( z != 1.0 ) {
      i++;
    }
  }
  cout << "Se acertaron " << i << " operaciones" << endl;
  
  i=0;
  cout << endl << "Utilizando datos tipo DOUBLE" << endl;
  for (X=1.0; X<1000.0; X=X+1.0) {
    Y = 1.0 / X;
    Z = Y * X;
    if ( Z != 1.0 ) {
      i++;
    }
  }
  cout << "Se acertaron " << i << " operaciones" << endl;
  
  return 0;
}

