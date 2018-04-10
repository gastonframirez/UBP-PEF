#include <iostream>

using namespace std;

int main (void) {
    int num=3, comp=2, noPrimo=0, cant=0, nros=1;
    
    cout << "Ingrese cantidad de numeros primos: ";
    cin >> cant;

    if (cant>0) {
        cout << "2 es primo" << endl;
    }
    
    while (nros < cant) {
        comp=2;
        noPrimo=0;
        while ((noPrimo==0) && (comp<num)) {
            if (num%comp==0) {
                noPrimo=1;
            }
            else {
                comp++;
            }
        }
        if (!noPrimo) {
            cout << num << " es primo" << endl;
            nros++;
        }
        num++;
    }
    
    
    return 0;
}
