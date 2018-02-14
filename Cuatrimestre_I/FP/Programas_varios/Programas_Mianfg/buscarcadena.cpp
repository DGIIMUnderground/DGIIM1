#include <iostream>
#include <string>
using namespace std;

int buscar_cadena ( const string & cadena, const string & buscar ) {
	int contador = 0;
	int loc = -1;
	int loc_posible = 0;
	bool seguir_buscando = true;
	for ( int i = 0; i < cadena.size() && seguir_buscando; i++ ) {
		if ( cadena[i] == buscar[contador] ) {
			contador++;
		} else {
			contador = 0;
			loc_posible = i+1;
		}
		if ( contador == buscar.size() ) {
			seguir_buscando = false;
			loc = loc_posible;
		}
	}
	return loc;
}

int main() {
	string cadena = "Cadenades";
	cout << buscar_cadena(cadena, "s");
}
