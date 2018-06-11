#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <string>

using namespace std;



class Matriz{
private:
  int nfilas;
  int *ncolumnas;
  double **datos;
public:
  Matriz(){
    nfilas = 3;

    ncolumnas = new int [nfilas];
    for(unsigned i = 1; i < nfilas + 1;++i){
      ncolumnas[i -1] = i;
    }
    this->datos = new double* [nfilas];
    for(unsigned i = 0; i < nfilas; ++i){
      this->datos[i] = new double[ this->ncolumnas[i] ];

      for (unsigned j = 0; j < this->ncolumnas[i]; ++j){
        this->datos[i][j] = 0;
      }

    }
  }
  ~Matriz(){
    for(unsigned i = 0; i < nfilas;++i){
      if (datos[i] != 0){
        delete [] datos[i];
      }
    }
    if (ncolumnas != 0){
      delete [] ncolumnas;
    }
    if (datos != 0)
      delete [] datos;
  }

  Matriz (const Matriz & copia){

    this->nfilas = copia.nfilas;
    this->ncolumnas = new int [nfilas];
    this->datos = new double* [nfilas];

    for(unsigned i = 0; i < nfilas; ++i){
      this->ncolumnas[i] = copia.ncolumnas[i];
      datos[i] = new double[ this->ncolumnas[i] ];

      for (unsigned j = 0; j < this->ncolumnas[i]; ++j){
        this->datos[i][j] = copia.datos[i][j];
      }
    }
  }

  Matriz& operator=(const Matriz & copia){
    if( this != &copia){
      if ( datos != 0 ){
        for(unsigned i = 0; i < nfilas;++i){
          if (datos[i] != 0){
            delete [] datos[i];
          }
        }
        if (ncolumnas != 0){
          delete [] ncolumnas;
        }
        delete [] datos;
      }
      this->nfilas = copia.nfilas;
      this->ncolumnas = new int [nfilas];
      this->datos = new double* [nfilas];

      for(unsigned i = 0; i < nfilas; ++i){
        this->ncolumnas[i] = copia.ncolumnas[i];
        datos[i] = new double[ this->ncolumnas[i] ];

        for (unsigned j = 0; j < this->ncolumnas[i]; ++j){
          this->datos[i][j] = copia.datos[i][j];
        }
      }
    }
    return *this;
  }

  double Get(int i, int j) const{
    if ( i < nfilas && j < ncolumnas[i]){
      return datos[i][j];
    }
  }
  void Set(int i, int j,double valor) const{
    if ( i < nfilas && j < ncolumnas[i]){
      datos[i][j] = valor;
    }
  }

  Matriz Vflip()const{
    Matriz flip(*this);
    for (unsigned i = 0; i < this->nfilas/2; ++i ){
      int aux1 = flip.ncolumnas[i];
      flip.ncolumnas[i] = flip.ncolumnas[flip.nfilas - i - 1];
      flip.ncolumnas[flip.nfilas - i - 1] = aux1;

      double* aux = flip.datos[i];
      flip.datos[i] = flip.datos[this->nfilas - i - 1];
      flip.datos[this->nfilas - i - 1] = aux;
    }

    return flip;
  }

  void Max(int & fila, int & columna) const{
    fila = columna = 0;
    int maximo = this->Get(fila,columna);

    for(unsigned i = 0; i < this->nfilas; ++i){
      for (unsigned j = 0; j < this->ncolumnas[i]; ++j){
        if (datos[i][j] > maximo){
          maximo = datos[i][j];
          fila = i;
          columna = j;
        }
      }
    }
  }

  void Escribir(const char* fichero, string comentario = ""){
    ofstream salida (fichero,ios::binary);
    char* cabecera = "MP\n";
    if(salida){
      salida.write(cabecera,sizeof(char)*3);
    }
    if (comentario != ""){
      comentario = '#' + comentario;
      cout << comentario;
      salida.write(comentario.c_str(),sizeof(char)*comentario.length());
    }
      salida.write(reinterpret_cast<char*>(&nfilas),sizeof(int));
      salida.put('\n');

    for (unsigned i = 0; i < this->nfilas && salida; ++i){
      salida.write(reinterpret_cast<char*>(&(this->ncolumnas[i])),sizeof(int));
      salida.write(reinterpret_cast<char*>(&(this->datos[i])),sizeof(double)*this->ncolumnas[i]);
      }
    salida.close();
  }

  void Leer (const char* fichero){
    ifstream entrada(fichero);

    for(unsigned i = 0; i < nfilas;++i){
      if (datos[i] != 0){
        delete [] datos[i];
      }
    }
    if (ncolumnas != 0){
      delete [] ncolumnas;
    }
    if (datos != 0){
      delete [] datos;
    }

    char aux[3];
    entrada.read(aux,sizeof(char)*3);
    int aux1 = entrada.get();
    if(aux1 == '#'){
      entrada.ignore(5000, '\n');
    }
    else{
      entrada.unget();
    }
    entrada.read(reinterpret_cast<char*>(&(this->nfilas)),sizeof(int));
    entrada.get();

    ncolumnas = new int [nfilas];
    datos = new double*[nfilas];
    for (unsigned i = 0; i < this->nfilas && entrada; ++i){
      entrada.read(reinterpret_cast<char*>(&(this->ncolumnas[i])),sizeof(int));
      datos[i] = new double[this->ncolumnas[i]];
      entrada.read(reinterpret_cast<char*>(&(this->datos[i])),sizeof(double)*ncolumnas[i]);
      }

    entrada.close();
  }

  friend ostream& operator<<(ostream & flujo, const Matriz & matriz){
    for(unsigned i = 0; i < matriz.nfilas; ++i){
      for(unsigned j = 0; j < matriz.ncolumnas[i];++j){
        flujo << matriz.datos[i][j] << " ";
      }
      flujo << endl;
    }
    return flujo;
  }
/**@warnin Suponiendo que la matriz está ya construida en memoria dinámica
De tener este examen le preguntaría que coño hay que hacer*/

  friend istream& operator>>(istream & flujo,Matriz & matriz){
    for(unsigned i = 0; i < matriz.nfilas; ++i){
      for(unsigned j = 0; j < matriz.ncolumnas[i];++j){
        flujo >> matriz.datos[i][j];
      }
    }
    return flujo;
  }
};

int main(int argc, char const *argv[]) {
  const char* entrada = argv[1];

  Matriz matriz;
  cout << "Introduce valores para la matriz" << endl;
  cin >> matriz;
  cout << matriz << endl;
  cout << endl;
  Matriz matriz2(matriz);
  cout << matriz2 << endl;
  matriz2 = matriz.Vflip();
  cout << matriz2;
  int fila;
  int columna;
  matriz.Max(fila,columna);
  cout << "Maximo en la posicion "<< fila << " " << columna << endl;

  matriz2.Escribir(entrada);
  Matriz matrizleida;
  matrizleida.Leer(entrada);
  cout << matrizleida << endl;




  return 0;
}
