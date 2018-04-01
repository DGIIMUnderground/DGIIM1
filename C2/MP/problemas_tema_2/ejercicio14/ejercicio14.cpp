#include <iostream>
#include <fstream> // ifstream
using namespace std;



void inicializar (char* & arraychar, int nCaracteres){
  nCaracteres = 0;
  arraychar = new char[nCaracteres];
}

void liberar(char* & arraychar, int nCaracteres){
  delete [] arraychar;
  arraychar = 0;
  nCaracteres = 0;
}

void mostrar (ostream& flujo ,char* const & arraychar,int nCaracteres ){
  for (size_t i = 0; i < nCaracteres; i++) {
    flujo << arraychar[i];
  }
}

void redimensionar (char* &arraychar, int & nCaracteres, int incremento){
  if (nCaracteres + incremento > 0){
    char* arrayCharResize = new char [nCaracteres + incremento] ;
    for (size_t i = 0; ( i < nCaracteres ) && (i < nCaracteres + incremento); i++) {
      arrayCharResize[i] = arraychar[i];
    }
    delete [] arraychar;
    arraychar = arrayCharResize;
    nCaracteres += incremento;
  }
}

void aniadir (char* &arraychar, int & nCaracteres, char caracter){
  redimensionar(arraychar, nCaracteres, 1 );
  arraychar[nCaracteres - 1] = caracter;
}

void leer(istream& flujo, char* &array, int& nchar){
  char caracter;

  while(flujo.get(caracter)){
    aniadir(array, nchar, caracter);
  }
}


int main(int argc, char* argv[])
{
  char* arraychar;
  int nCaracteres;

  inicializar(arraychar, nCaracteres);

  if (argc==1)
    leer(cin, arraychar, nCaracteres);
  else {
    ifstream flujo(argv[1]);
    if (!flujo) {
      cerr << "Error: Fichero " << argv[1] << " no válido." << endl;
      return 1;
    }
  leer(flujo, arraychar, nCaracteres);
  }

  mostrar(cout, arraychar, nCaracteres);
  liberar(arraychar, nCaracteres); // Libera la memoria dinámica reservada
}
