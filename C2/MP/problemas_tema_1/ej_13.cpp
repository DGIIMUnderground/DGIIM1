/* 13. Haz un programa que contenga una función que reciba como entrada dos cadenas de
caracteres estilo C (cad y subcad) y que compruebe si la segunda (subcad) está presente
o no dentro de la primera (cad). Si la subcadena es encontrada, devolverá la posición
donde se encuentra y, en caso contrario, devolverá -1.

José L. Ruiz
*/

#include <iostream>

using namespace std;

const int TAMANO = 100;

void Lectura( char p[], int & util_p){
	util_p = 0;
	cin >> p[util_p];
	while( p[util_p] != '#' && util_p<= TAMANO ){
		util_p++;
		cin >> p[util_p];
	}
}

int Localiza(const char subcadena[], const int & util_subcadena, const char cadena[], const int & util_cadena){
	int posicion = -1;
	for (int i=0; i<util_cadena && util_cadena-i>=util_subcadena && posicion == -1; i++){
		bool existe = true;
		for( int j=0; j<util_subcadena && existe; j++)
			if( subcadena[j] != cadena[i+j] )
				existe = false;
		if (existe)
			posicion = i;
	}
	return posicion;
}

int main(){

	char cadena[TAMANO], subcadena[TAMANO];
	int util_cadena, util_subcadena;
	
	cout << "Introduzca una cadena de caracteres (termine con '#'): ";
	Lectura(cadena, util_cadena);
	
	cout << "Introduzca la subcadena que desea buscar (termine con '#'): ";
	Lectura(subcadena, util_subcadena);

	int posicion = Localiza(subcadena, util_subcadena, cadena, util_cadena);
	
	if (posicion != -1)
		cout << "La subcadena se encuentra en la cadena en la posición " << posicion << "." << endl;
	else
		cout << "La subcadena no se encuentra en la cadena." << endl;
}
