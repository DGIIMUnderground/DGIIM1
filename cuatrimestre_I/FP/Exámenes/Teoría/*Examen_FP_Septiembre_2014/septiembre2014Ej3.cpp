#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**@brief Dado un intervalo y un numero calcula la cantidad  de numeros que hay en dicho intervalo
   @param m: Primer valor del intervalo
          n: Segundo valor del intervalo
          k: Numero a saber cuantas veces está;
   @return: Nº de veces que está k en el intervalo
**/

int n_intervalo (const int & m , const int & n , const int & k  ){
  int n_final = 0;
  for (int i = m; i <= n; ++i ){
    int aux = i;
    //cout << aux << " " << k << " " << aux - k << " " << n_final;
    while ( ( (aux - k) % 10 ) == 0 &&  (aux - k) >= 0){
      n_final ++;
      aux = aux /10;
      cout << i << " ";
    }
  }
  return n_final;

}
int main(){

  cout << n_intervalo(1,1000,9);
}
