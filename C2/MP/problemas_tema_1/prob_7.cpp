/* 7. Construir una función que dada una cadena de caracteres que contiene un número entero,
devuelva su correspondiente valor numérico. Razonar sobre qué hacer si la cadena no
contiene un número entero.

José L. Ruiz
*/

#include <iostream>

using namespace std;

const int TAMANO = 350;

void Lectura( char p[], int & util_p){
	util_p = 0;
	cin >> noskipws >> p[util_p]; //noskipws PERMITE NO SALTAR EL CARÁCTER ' ' (espacio) Y METERLO EN EL ARRAY
	while( p[util_p] != '#' && util_p<= TAMANO ){
		util_p++;
		cin >> p[util_p];
	}
}

/**
 * @brief Determina si existe una cifra en una cadena de caracteres (array de caracteres)
 * @param num: cifra eventualmente existente en la cadena. Si se encuentra una cifra, se alomacenará en esta variable
 * @param cad: cadena de caracteres en la que se buscará el número
 * @param util_cad: longitud operativa de la cadena de caracteres
 * @return true si se encuentra una cifra, false si no
 */
bool ExisteNumero( int & num, const char cad[], const int & util_cad){
	bool existe = false;
	for( int i=0; i<util_cad && !existe; i++)
		if( cad[i] >= '0' && cad[i] <= '9' ){
			existe = true;
			num = cad[i] - '0';
		}
	return existe;
}

int main(){
	char cadena[TAMANO];
	int util_cadena;
	cout << "Introduzca una cadena de caracteres (termine con '#'): ";
	Lectura(cadena, util_cadena);
	
	int numero;
	bool tiene_numero = ExisteNumero(numero, cadena, util_cadena);

	if( tiene_numero )
		cout << "El número es: " << numero << endl;
	else
		cout << "NO hay ningún número." << endl;
}
