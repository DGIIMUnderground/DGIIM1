#include <iostream>
using namespace std;

int main(){
  const int size = 10;
  int v[size] = {-10,4,6,34,4,2,6,8,2};
  int* p = &(v[0]) ;

  int cotaInf = *p;
  int cotaSup = *p;

  int* pMax = &cotaInf;
  int* pMin = &cotaSup;

  while ( p - &(v[0]) < size ){
    if ( *p > *pMax){
      pMax = p;
    }
    else if ( *p < *pMin){
      pMin = p;
    }
    p++;
  }
  cout << "Max: " << *pMax;
  cout << "Min: " << *pMin;
}
