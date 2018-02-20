#include <iostream>
#include <string>


using namespace std;

char minuscula ( char caracter ) {
	if ( caracter >= 65 && caracter <= 90 ) {
		caracter += 32;
	}
	return caracter;
}


string usuario_sugerido(string nombre_apellidos, const int & N) {
	nombre_apellidos += " ";
	string sugerencia = "";
	string sug_parcial = "";
	int contador = 0;
	for ( int i = 0; i < nombre_apellidos.size(); i++ ) {
		if ( nombre_apellidos[i] == ' ' ) {
			contador = 0;
			sugerencia += sug_parcial;
			sug_parcial = "";
		} else {
			if ( contador < N ) {
				sug_parcial += minuscula(nombre_apellidos[i]);
				contador++;
			}
		}
	}
	return sugerencia;
}

int main() {
	string nombre = "Ma Gomez Sanchez";
	cout << usuario_sugerido(nombre, 3);
}
