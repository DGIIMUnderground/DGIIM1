#include <iostream>

using namespace std;

#define SIZE 10

void ordenacionPorBurbuja( int* num, int** p, int len ) {
  for ( int i = 0; i < len; i++ ) {
    p[i] = num + i;
  }
  for ( int i = 1; i < len; i++ )
    for ( int j = 0; j < len - 1; j++ ) {
      if ( **(p+j) > **(p+j+1) ) {
        int* aux = *(p + j);
        p[j] = *(p+j+1);
        p[j+1] = aux;
      }
    }
}

int main() {
  int arr[SIZE] = {1,6,2,0,9,10,13,4,4,8};
  int *ord[SIZE];
  ordenacionPorBurbuja( arr, ord, SIZE );
  for ( int i = 0; i < 10; i++ )
    cout << arr[i] << " ";
  cout << endl;
  for ( int i = 0; i < 10; i++ )
    cout << *(ord[i]) << " ";
  cout << endl;
}
