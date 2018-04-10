// Este programa lee los datos contenidos en un archivo, guardandolos
// temporalmente en una lista porque no se sabe la cantidad de datos
// a leer.  Luego, crea un vector con la memoria necesaria y
// transfiere los datos.
#include <iostream>
#include <fstream>

using namespace std;

// Estructura de datos para guardar lo leido
struct Dato {
  float num;
  Dato *next;
};


// Prototipos de funcion para manipular la lista de datos
Dato* AgregarDato  (Dato *l, Dato *n);
Dato* CrearDato    (float num);
void  MostrarDatos (Dato *d);
void  BorrarDatos  (Dato *d);

// Prototipo de funcion para pasar de lista a vector
float* ListaAVector (Dato *l, int cant);


int main (void) {
  char nombre[30];
  int error=0, cantidad=0, i=0;
  float num=0.0, *numeros=NULL;
  Dato *lista=NULL, *aux=NULL;
  fstream entrada;

  cout << "Ingrese el nombre del archivo: ";
  cin >> nombre;

  entrada.open(nombre);
  if (entrada.fail()) { // Verificar apertura del archivo
    cerr << "No se pudo abrir el archivo" << endl;
    error=1;
  }

  if (!error) { // Si no hay error intento leer el primer dato
    entrada >> num;
    while (!entrada.eof()) { // Repite hasta el final del archivo
      cantidad++;
      aux=CrearDato(num); // Asigna memoria para un FLOAT
      if (aux==NULL) {    // Verifica si se pudo asignar
	cerr << "Memoria insuficiente" << endl;
	error=1;
      }
      else {  // Si no hay error, agrega el dato en la lista y
	      // continua leyendo el archivo de entrada
	lista=AgregarDato(lista,aux);
	entrada >> num;	
      }
    }

    // Opcional para verificar lo leido
    //    MostrarDatos(lista);

    // Luego de leer los datos, paso la informacion a un vector
    numeros=ListaAVector(lista,cantidad);
    if (numeros==NULL) { // Verifica si pudo asignar memoria
      error=1;
    }

    for (i=cantidad-1;i>=0;i--) { // Muestra los numeros en orden
      cout << numeros[i] << endl; // inverso al leido
    }

    delete [] numeros;  // Libera la memoria del vector de datos
    BorrarDatos(lista); // Libera la memoria de la lista
    entrada.close();    // Cierra el archivo de entrada
  }

  return error;
}


Dato* AgregarDato  (Dato *l, Dato *n) {
  Dato *aux=NULL;
  if (l==NULL) { // Esta verificacion indica si es el primer dato
    l=n;         // de la lista
  }
  else {  // Si no es el primer dato, lo agrega al final
    aux=l;
    while(aux->next!=NULL) { // Esto nos lleva al final de la lista
      aux=aux->next;
    }
    aux->next=n;
  }
  return l;
}


Dato* CrearDato    (float num) {
  Dato *aux=NULL;
  cout << "creando dato" << endl;
  aux = new Dato;  // Pide memoria para guardar el dato
  if (aux==NULL) { // Verifica si fue posible la asignacion
    cerr << "Memoria insuficiente" << endl;
  }
  else { // Inicializa los campos de la estructura
    aux->num=num;
    aux->next=NULL;
  }
  return aux;
}


void  MostrarDatos (Dato *d) {
  while (d!=NULL) { // Muestra por pantalla el contenido de la lista
    cout << d->num << endl;
    d=d->next;
  }
}


void  BorrarDatos  (Dato *d) {
  Dato *aux=NULL;
  while (d!=NULL) { // Libera la memoria asignada a cada estructura
    aux=d;
    d=d->next;    // NOTA: siempre debe mantenerse el puntero al siguiente
    delete aux;   // elemento de la lista porque sino no se puede terminar
  }               // la tarea porque se pierde la referencia
}


float* ListaAVector (Dato *l, int cant) {
  int i=0;
  float *v=NULL;

  v = new float[cant];  // Pide memoria para los datos
  if (v==NULL) {  // Verifica la asignacion de la memoria
    cerr << "Memoria insuficiente" << endl;
  }
  else {
    for (i=0;i<cant;i++) { // Copia de la lista al vector
      v[i]=l->num;
      l=l->next;
    }
  }
  return v;
}


