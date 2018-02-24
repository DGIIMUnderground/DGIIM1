/* 14. Construir una función que inserte una cadena de caracteres dentro de otra cadena
en una determinada posición.

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

void Inserta(const char subcadena[], const int & util_subcadena, char cadena[], int & util_cadena, const int & posicion_insertar){
	util_cadena += util_subcadena;
	for(int i=util_cadena; i>=util_cadena-util_subcadena; i--)
		cadena[i] = cadena[i-util_subcadena];
	for (int i=0; i<util_subcadena; i++)
		cadena[i+posicion_insertar] = subcadena[i];
}

void Mostrar( const char cad[], const int & util_cad){
	for (int i=0; i<util_cad; i++)
		cout << cad[i];
}

int main(){
	char cadena[TAMANO], subcadena[TAMANO];
	int util_cadena, util_subcadena;
	
	cout << "Introduzca una cadena de caracteres (termine con '#'): ";
	Lectura(cadena, util_cadena);
	
	cout << "Introduzca la subcadena que desea insertar (termine con '#'): ";
	Lectura(subcadena, util_subcadena);
	while( util_cadena+util_subcadena > TAMANO){
		cerr << "Error. Cadena demasiado extensa" << endl;
		cout << "Introduzca la subcadena que desea insertar (termine con '#'): ";
		Lectura(subcadena, util_subcadena);
	}
	
	int posicion_insertar;
	cout << "Introduzca la posición en la que desea insertar la subcadena: ";
	cin >> posicion_insertar;
	while( posicion_insertar > util_cadena){
		cerr << "Error. Inserte una posición válida." << endl;
		cout << "Introduzca la posición en la que desea insertar la subcadena: ";
		cin >> posicion_insertar;
	}
	
	Inserta(subcadena, util_subcadena, cadena, util_cadena, posicion_insertar);
	
	cout << "Cadena resultante: " << endl;
	Mostrar(cadena, util_cadena);
	cout << endl;
}
