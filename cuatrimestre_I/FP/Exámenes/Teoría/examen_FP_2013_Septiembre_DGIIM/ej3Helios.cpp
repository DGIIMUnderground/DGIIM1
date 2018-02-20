#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Frase {
private:
  vector <char> frase;


public:

  /**@brief Localiza la k-ésima palabra de la frase.
     @param k: Numero de palabra que se pretende localizar
     @return: Posición de la k-esima palabra;
  **/
  int buscar_palabra(int k) const{
    int posicion;
    vector <int> lista_posiciones;
    bool palabra = false;
    int longitud_palabra = 0;

    for (int i = 0 ; i < frase.size() ; ++i){
      if ( isalpha(frase[i]) ){
        palabra = true;
        longitud_palabra ++;
        }
      else if(palabra || i == frase.size() - 1 ) {
        palabra = false;
        lista_posiciones.push_back( i - longitud_palabra );
        longitud_palabra = 0;
      }
    }
    return lista_posiciones[k - 1];
  }

};
int main(){
  cout << "jaja si soy yo el chocu" << endl;
}
