#include <iostream>
using namespace std;

int main(){
  const int size = 1000;
  int v[size];
  int* p = &(v[0]);

  while ( p - &(v[0]) < size){
    if (*p < 0){
      *p *= (-1);
    }
    cout << *p << " ";
    p ++;
  }
}
