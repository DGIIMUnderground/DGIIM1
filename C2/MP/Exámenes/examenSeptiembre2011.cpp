#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <string>

using namespace std;



/**

1.Considere que tenemos almacenada una secuencia ordenada de números enteros en una lista de celdas enlazadas
definidas con la siguiente estructura:
struct Celda {
int dato;
// Dato en la celda actual
Celda *sig; // Puntero al siguiente elemento de la lista
};
a) (0.75 puntos) Defina una función que recibe un entero y una lista y modifica dicha lista ordenada insertando
el entero en la posición correspondiente.
b) (0.75 puntos) Defina una función que recibe un entero y una lista y modifica dicha lista eliminando la
primera aparición de ese entero en la lista.
Nota: Tenga en cuenta que en ambas funciones se puede dar el caso de que la lista que se pasa esté vacía
*/
struct Celda{
  int dato;
  Celda* sig;
};
void insercion_ordenada(Celda* lista, int num){
  if (lista == 0){
    cerr << "Error lista vacía" << endl;
  }
  else{
    bool encontrado = false;
    Celda* aux = lista;
    while(aux != 0 && ! encontrado){
      if ( aux->dato >= num ){
        Celda* nueva = new Celda;
        nueva->sig = aux->sig;
        aux->sig = nueva;
        nueva->dato = num;
        encontrado = true;
      }
      aux = aux->sig;
    }
  }
}

void eliminar_entero(Celda* lista, int n){
  if (lista == 0){
    cerr << "Error lista vacía" << endl;
  }
  else{
    bool encontrado = false;
    Celda* aux = lista;

    while(aux != 0 && !encontrado){
      if ( aux->sig != 0 && n == aux->sig->dato){
        encontrado = true;
        Celda* brrar = aux->sig;
        aux->sig = aux->sig->sig;
        delete brrar;
        brrar = 0;
      }
      aux = aux->sig;
    }

  }
}
/**2. Se define una matriz bilineal simétrica como una matriz de n × n enteros en la que todos los elementos
significativos (distintos de un valor por defecto) están situados en las 2 diagonales principales y tal que al
recorrer ambas diagonales en orden creciente de filas, presentan los mismos elementos. Un ejemplo de este tipo
de matrices es la matriz del ejemplo. Es una matriz 6 × 6 de valores enteros y con el 0 como valor por defecto.

Se quiere construir la clase MatrizBS. Resuelva los siguientes problemas:
a) (0.75 puntos) Definir la parte privada de la clase. Debe minimizarse el uso de memoria, guardando lo
estrictamente necesario, para lo que será necesario usar memoria dinámica. Nótese que no se deben guardar
los n × n valores de la matriz, ya que serı́an valores redundantes.
b) (0.75 puntos) Implementar el constructor por defecto y el destructor. El constructor por defecto creará una
matriz de tamaño 4 × 4, en la que los elementos de las dos diagonales principales serán todos 1 y el valor
por defecto será 0.
c) (0.75 puntos) Implementar un constructor que reciba tres valores: n (el número de filas y columnas),un
vector de enteros que contiene n elementos correspondientes a los valores en las diagonales y, finalmente,
el valor que corresponde a las posiciones fuera de las diagonales. Este último será un parámetro opcional
cuyo valor por defecto será cero.
d ) (0.75 puntos) Implemente la sobrecarga del operador de asignación de la clase MatrizBS.
*/

class MatrizBS{
private:
  int* m;
  int nfc;
  int _default;

public:
  MatrizBS(){
    nfc = 4;
    m = new int[nfc];
    for(unsigned i = 0; i < nfc; ++i){
      m[i] = 1;
    }
    _default = 0;
  }

  MatrizBS(int nf, int nc, vector<int> diagonal, int por_defecto = 0){
    assert(diagonal.size() == nf && nf == nc);
    this->nfc = nf;
    m = new int [this->nfc];
    for (unsigned i = 0; i <this->nfc;++i){
      m[i] = diagonal[i];
    }
    _default = por_defecto;
  }

  MatrizBS& operator=(const MatrizBS & ma){
    if (this != &ma){
      this->nfc = ma.nfc;
      if(this->m != 0){
        delete [] this->m;
      }
      this->m = new int [this->nfc];
      for (unsigned i = 0; i <this->nfc;++i){
        this->m[i] = ma.m[i];
      }
      this->_default = ma._default;
    }
    return *this;
  }

  friend ostream& operator<<(ostream & flujo, const MatrizBS & matriz){
    for (unsigned i = 0; i < matriz.nfc; ++i){
      for (unsigned j = 0; j < matriz.nfc; ++j){
        if ( i == j){
          flujo << matriz.m[i] << " ";
        }
        else{
          flujo << matriz._default << " ";
        }
      }
      flujo << endl;
    }
    return flujo;
  }

};




/**
3. (1.5 puntos) Escribir un programa que reciba como parámetros -en la lı́nea de órdenes- tres nombres de ficheros de
texto. Los dos primeros ficheros contienen números reales ordenados en orden creciente y separados por espacios
en blanco. El programa tomará los datos de esos ficheros y los irá copiando ordenadamente (de forma creciente)
en el tercer fichero, de forma que al finalizar también esté ordenado.
*/

int main(int argc, char const *argv[]) {

  cout << "TEST DEL PRIMER EJERCICIO DEL EXAMEN" << endl;
  Celda* lista;
  int dato;
  lista = 0;
  cin >> dato;

  while ( dato != -1 ){
    Celda* aux = new Celda;
    aux->dato = dato;
    aux->sig = lista;
    lista = aux;
    cin >> dato;
  }

  insercion_ordenada(lista,4);
  Celda* aux = lista;
  while(aux != 0){
    cout << aux->dato << " ";
    aux = aux->sig;
  }
  eliminar_entero(lista,4);
  cout << endl;
  aux = lista;
  while(aux != 0){
    cout << aux->dato << " ";
    aux = aux->sig;
  }

//--------------------------------------------------------------



  cout << "TEST DEL SEGUNDO EJERCICIO DEL EXAMEN" << endl;
  MatrizBS m1;
  cout << m1 << endl;
  vector <int> prob={2,4,7,1,9,6};
  MatrizBS m2(6,6,prob,2);
  cout << m2 << endl;
  m1 = m2;
  cout << m1 << endl;
//-------------------------------------------------------

/**3. (1.5 puntos) Escribir un programa que reciba como parámetros -en la lı́nea de órdenes- tres nombres de ficheros de
texto. Los dos primeros ficheros contienen números reales ordenados en orden creciente y separados por espacios
en blanco. El programa tomará los datos de esos ficheros y los irá copiando ordenadamente (de forma creciente)
en el tercer fichero, de forma que al finalizar también esté ordenado.
*/



  cout << "TEST TERCER EJERCICIO"
  if (argc != 4){
    cerr << "Error en el numero de argumentos" << endl;
    return 1;
  }

  ifstream entrada1(argv[1]);
  ifstream entrada2(argv[2]);
  ofstream salida(argv[3]);

  float n1;
  float n2;

  if (entrada1 && entrada2){
    entrada1 >> n1;
    entrada2 >> n2;
  }

  while(entrada1 && entrada2){
    if (n1 <= n2){
      salida << n1 << " ";
      entrada1 >> n1;
    }
    else{
      salida << n2 << " ";
      entrada2 >> n2;
    }
  }
  while(entrada1){
    salida << n1 << " ";
    entrada1 >> n1;
  }
  while(entrada2){
    salida << n2 << " ";
    entrada2 >> n2;
  }
}
//-------------------------------------------------------------------
