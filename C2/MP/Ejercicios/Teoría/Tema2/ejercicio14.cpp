// CORREGIDO EN CLASE

#include <iostream>
#include <fstream> // ifstream
using namespace std;

void inicializar ( char* &array, int & util ) {
  array = 0; // NULL ó nullptr
  util = 0;
}

void liberar ( char* &array, int & util ) {
  delete[] array; // si no pasásemos array por referencia, array seguiría apuntando a _ (ídem util), pero sí liberaría memoria
  array = 0;
  util = 0;
}

void mostrar ( ostream &flujo, const char [array], int util ) {
                                // const char *array  - no por referencia constante, sólo merece la pena cuando son grandes
                                //    tb podríamos hacer el puntero constante
  for ( int i = 0; i < util; i++ )
    flujo << array[i];
  flujo << endl;
}

// redimensionar en transparencia

void aniadir ( char * &array, int & util, char caracter ) {
  redimensionar( array, util, 1 );
  array[util-1] = caracter;
          // ya lo hemos redimensionado
}

void leer(istream& flujo, char* &array, int& nchar){
  char caracter;
  while(flujo.get(caracter))
    aniadir(array, nchar, caracter);
}

int main(int argc, char∗ argv[]) {
  // nuestro array dinámico está hecho de:
  char* arraychar;
  int nCaracteres;
  inicializar(arraychar, nCaracteres);
  if (argc==1)
    leer(cin, arraychar, nCaracteres);
  else {
    ifstream flujo(argv[1]); // crea un flujo asociado a un fichero
      // argv[1] es el primer argumento del main
    if (!flujo) {
      cerr << "Error: Fichero " << argv[1] << " no v´ alido." << endl;
      return 1;
    }
    leer(flujo, arraychar, nCaracteres);
  }
  mostrar(cout, arraychar, nCaracteres);
  liberar(arraychar, nCaracteres); // Libera la memoria din´ amica reservada
}
