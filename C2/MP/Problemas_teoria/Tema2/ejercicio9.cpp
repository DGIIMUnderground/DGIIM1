#include <iostream>

using namespace std;

#define SIZE 10

int ordenCreciente( int l, int r ) {
  return l-r;
}
int ordenDecreciente( int l, int r ) {
  return r-l;
}

void ordenacionPorBurbuja( int* num, int** p, int len, int (*ordenacion)( int, int ) ) {
  for ( int i = 0; i < len; i++ ) {
    p[i] = num + i;
  }
  for ( int i = 1; i < len; i++ )
    for ( int j = 0; j < len - 1; j++ ) {
      if ( ordenacion(**(p+j), **(p+j+1)) > 0 ) {
        int* aux = *(p+j);
        p[j] = *(p+j+1);
        p[j+1] = aux;
      }
    }

}

int main() {
  int arr[SIZE] = {1,6,2,0,9,10,13,4,4,8};
  int *ord[SIZE];
  char ordenar;
  cout << "¿Cómo desea ordenar los números? C=creciente, D=decreciente : ";
  cin >> ordenar;
  if ( ordenar == 'C' )
    ordenacionPorBurbuja( arr, ord, SIZE, ordenCreciente );
  else if ( ordenar == 'D' )
    ordenacionPorBurbuja( arr, ord, SIZE, ordenDecreciente );
  for ( int i = 0; i < 10; i++ )
    cout << arr[i] << " ";
  cout << endl;
  for ( int i = 0; i < 10; i++ )
    cout << *(ord[i]) << " ";
  cout << endl;
}
