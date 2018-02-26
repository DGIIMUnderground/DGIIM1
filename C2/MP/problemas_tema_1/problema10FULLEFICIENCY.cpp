#include <iostream>
#include "funciones.cpp"
using namespace std;

/**@brief Lee un texto caracter a caracter. Hasta que se introduce #
   @param vc: Array donde se guarda el texto;
          size: Tamano maximo del array.

   @return vc_util: Dimension util del array;
*/

int leerTexto(char vc[] ,const int & size){
  char caracter;
  int vc_util = 1;

  cin >> caracter;
  for (size_t i = 0; i < size && caracter != '#';  i++) { //REVISAR
    vc[i] = caracter;
    cin >> caracter;
    vc_util ++;
  }
  return vc_util;
}
/**@brief Cuenta las letras de un vector c
   @param vc: Array donde se guarda el texto.
          vcutil: Dimension util del array de texto.
          v: Array donde se guardan las frecuencias de cada letra.
          vutil: Dimension util del array de frecuencias
*/
void contar_letras ( char vc[] , int vcutil , int v[] , int vutil){

  for (size_t i = 0; i < vcutil; ++i) {
    for (size_t j = 0; j < vutil; ++j) { //DIM vutil == 26
      char aux = 97 + j;
      if ( vc[i] == aux ){
        v[j] ++;
      }
    }
  }

}

int main(){

  const int size = 100;

  char array [size];
  int array2[size] = {0};
  int leidos = 26;


  int vcutil = leerTexto (array, size);
  //imprimirArray (array,vcutil);

  contar_letras (array,vcutil,array2,leidos);

  imprimirArray (array2,leidos);
}
