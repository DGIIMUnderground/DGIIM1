#include <iostream>
using namespace std;


/**@brief Eleva al cuadrado el dato apuntado por el puntero
   @param Puntero del dato que se quiere elevar al cuadrado.
*/
void elevarAlCuadrado (int* & ptrq ){
  *ptrq = *ptrq * *ptrq;
  ptrq = 0;
}

int main(){
  int a=6;
  int *q;
  q = &a;
  elevarAlCuadrado (q);
  cout << a << q;


}
