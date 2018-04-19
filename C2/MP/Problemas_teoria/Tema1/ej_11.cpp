#include <iostream>
using namespace std;

#define DIM 100

void copiarArray ( const char original[], char copiar[] ) {
  int pos = 0;
  for ( int i = 0; original[i] != '\0'; i++ ) {
    copiar[i] = original[i];
    pos++;
  }
  copiar[pos] = '\0';
}

void mostrarArray ( const char cadena[] ) {
  for ( int i = 0; cadena[i] != '\0'; i++ )
    cout << cadena[i];
}

int main() {
  char cadena1[DIM], cadena2[DIM];
  cout << "Inserte la cadena1: ";
  cin.getline(cadena1, DIM);
  cout << "Cadena leída (cadena1): ";
  mostrarArray(cadena1);
  cout << endl;
  copiarArray(cadena1, cadena2);
  cout << "Cadena copiada (cadena2): ";
  mostrarArray(cadena2);
  cout << endl;
}
