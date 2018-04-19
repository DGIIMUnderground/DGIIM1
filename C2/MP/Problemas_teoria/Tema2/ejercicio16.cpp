#include <iostream>
#include <fstream> // ifstream
using namespace std;

struct ListaCadenas{
  char** cadenas;
  int ncads;
};

void crear(ListaCadenas& listaCadenas) {
  listaCadenas.ncads = 0;
  listaCadenas.cadenas = new char*;
}

void imprimir(ostream& flujo, const ListaCadenas& listaCadenas) {
  for ( int i = 0; i < listaCadenas.ncads; i++ )
    cout << listaCadenas.cadenas[i] << endl;
}

void redimensionar(ListaCadenas& listaCadenas, int newSize) {
    char** cadenas_new = new char*[newSize];
    for (int i = 0; i < listaCadenas.ncads; i++)
      cadenas_new[i] = listaCadenas.cadenas[i];
    listaCadenas.ncads = newSize;
}

// ¡¡HE TENIDO QUE HACER ESTO!!
void copiarCharP( char* &modif, const char* copia ) {
  int cont = 0;
  while (copia[cont] != '\0')
    modif[cont] = copia[cont];
  modif[cont] = '\0';
}

void aniadir(ListaCadenas& listaCadenas, const char* cadena ) {
  redimensionar(listaCadenas, listaCadenas.ncads+1);
  copiarCharP(listaCadenas.cadenas[listaCadenas.ncads-1], cadena);
}

void leer(iostream& flujo, ListaCadenas& listaCadenas) {
  const int NCARACTERES=1000;
  char linea[NCARACTERES];
  while(flujo.getline(linea, NCARACTERES)) {
    aniadir(listaCadenas, linea);
  }
}

void liberar(ListaCadenas& listaCadenas) {
  cout << "liberarrr";
}

bool esMenor ( char* cadena1, char* cadena2 ) {
  bool resultado = false;
  bool stop = false;
  for ( int i = 0; !stop; i++ ) {
    if ( cadena1[i] == '\0' || cadena2[i] == '\0' )
      stop = true;
    else {
      if ( cadena1[i] < cadena2[i] ) {
        stop = true;
        resultado = true;
      } else if ( cadena1[i] > cadena2[i] ) {
        stop = true;
        resultado = false;
      }
    }
  }
  return resultado;
}

void ordenar(ListaCadenas& listaCadenas) {
  for ( int i = 0; i < listaCadenas.ncads - 1; i++ ) {
    int posmin = i;
    for ( int j = i+1; j < listaCadenas.ncads; j++ ) {
      if ( esMenor(listaCadenas.cadenas[j], listaCadenas.cadenas[i]) ) {
        posmin = j;
      }
    }
    char* aux = listaCadenas.cadenas[i];
    listaCadenas.cadenas[i] = listaCadenas.cadenas[posmin];
    listaCadenas.cadenas[posmin] = aux;
  }
}

int main(int argc, char* argv[]) {
  ListaCadenas lista;
  crear(lista);
  if (argc==1)
    leer(cin, lista);
  else {
    ifstream f(argv[1]);
    if (!f) {
      cerr << "Error: mostrarFichero " << argv[1] << " no válido." << endl;
      return 1;
    }
    leer(f, lista);
  }
  cout << "Original:" << endl;
  imprimir(cout, lista);
  ordenar(lista);
  cout << "Resultado:" << endl;
  imprimir(cout, lista);
  liberar(lista);
}
