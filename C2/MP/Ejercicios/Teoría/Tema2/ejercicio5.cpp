#include <iostream>
using namespace std;

int main(){
  const int size = 1000;
  int v[size];
  int* p = &(v[0]);
  int* f = &(v[999]) + 1;

  while ( p < f){
    if (*p < 0){
      *p *= (-1);
    }
    cout << *p << " ";
    p ++;
  }
}
