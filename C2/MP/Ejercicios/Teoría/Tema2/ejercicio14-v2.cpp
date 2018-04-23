// CORREGIDO EN CLASE

#include <iostream>
#include <fstream> // ifstream
using namespace std;

struct VectorChar {
  char *array;
  int util;
  int capacidad;
}

void inicializar ( VectorChar & v ) {
  v.array = new char[10];
  v.util = 0;
  v.capacidad = 10;
}

void liberar ( char* &array, int & util ) {
  delete[] v.array; // si no pasásemos array por referencia, array seguiría apuntando a _ (ídem util), pero sí liberaría memoria
  v.array = 0;
  v.util = 0;
  v.capacidad = 0;
}

void mostrar ( ostream &flujo, const VectorChar & v ) {
  for ( int i = 0; i < v.util; i++ )
    flujo << v.array[i];
  flujo << endl;
}

// redimensionar en transparencia

void aniadir ( VectorChar & v, char caracter ) {
  if ( v.util == v.capacidad )
    redimensionar( v, v.capacidad );
  v.array[util] = caracter;
  v.util++;
}

void leer(istream& flujo, VectorChar & v){
  char caracter;
  while(flujo.get(caracter))
    aniadir(v, caracter);
}

int main(int argc, char∗ argv[]) {
  // nuestro array dinámico está hecho de:
  VectorChar vchar;
  inicializar(vchar);
  if (argc==1)
    leer(cin, vchar);
  else {
    ifstream flujo(argv[1]); // crea un flujo asociado a un fichero
      // argv[1] es el primer argumento del main
    if (!flujo) {
      cerr << "Error: Fichero " << argv[1] << " no válido." << endl;
      return 1;
    }
    leer(flujo, vchar);
  }
  mostrar(cout, vchar);
  liberar(vchar); // Libera la memoria din´ amica reservada
}
