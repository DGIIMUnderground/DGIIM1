#include <iostream>
#include <vector>
#include <string>
using namespace std;

class VectorEnteros{
public:
  VectorEnteros (){
    vector <int> defecto (1,0);
    lista = defecto;
  }

  VectorEnteros (const vector <int> & vector_copia){
    lista = vector_copia;
  }

  vector <int> get_vector () const{
    return lista;
  }
  /**@brief Suma dos vectores de IGUAL tamaño.
     @param vector_sumar: Segundo vector a sumar
     @return: EL resultado de la suma entre el vector objeto y el pasado.
    **/
  vector <int> operator+(const VectorEnteros & vector_sumar) const {
    vector <int> vector_final;

    for (int i = 0; i < lista.size() ; ++i){
      vector_final.push_back( lista[i] + vector_sumar.get_vector()[i]);
    }
    return vector_final;
  }
  /**@brief Calcula el numero de secuencias ascendientes de un vector.
     @return: EL numero de secuencias ascendientes
  */
  int secuencias_ascendentes(){
    int n_sec = 0;

    for (unsigned i = 0; i < lista.size(); ++i){
      int j = 1;
      bool ascendente = false;
      while ( i+j < lista.size() && lista[i + j] >= lista[i]){
        j ++;
        ascendente = true;
      }
      cout << j << endl;

      if (ascendente){
        n_sec ++;
        i = j;
      }
    }
    return n_sec;
  }

private:
  vector <int> lista;
};

int main(){
  vector <int> buenas;
  int n;
  cin >> n;
  while (n >= 0){
    buenas.push_back(n);
    cin >> n;
  }
  VectorEnteros lista1(buenas);
  VectorEnteros lista2(buenas);
  buenas = lista1 + lista2;

  for (int i = 0; i < buenas.size(); ++i){
    cout << buenas[i] << " ";
  }
  cout << lista1.secuencias_ascendentes();









}
