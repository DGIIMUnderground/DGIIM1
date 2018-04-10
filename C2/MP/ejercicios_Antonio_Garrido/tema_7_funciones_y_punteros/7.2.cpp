/*
 * Ejercicio 7.2.
 * Implemento una función PrimerEspacio de tipo char, que reciba como entrada una cadena de carcteres y devuelva como resultado un puntero al primer espacio de la cadena, o al final de la cadena en caso de que no haya espacios.
 * 
 * jruib
 */

#include <iostream>

const int MAX = 100; //tamaño máximo de la cadena

using namespace std;

const char * PrimerEspacio( const char * cad){
	int i;
	for ( i=0; i < MAX && cad[i] != '\0' && cad[i] != ' '; i++);
	const char * p = cad + i;
	return p;
}

int main(){
	const char *cadena = "Hola caracola";
	cout << "El primer espacio se encuentra en la posición: " << "X" << *PrimerEspacio(cadena) << "X" << endl;
}
