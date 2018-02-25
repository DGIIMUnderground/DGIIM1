/* 6. Se pide construir una función que tenga como entrada un array de caracteres (tipo char),
y suprima todas las secuencias de espacios en blanco de longitud mayor de uno. Por
ejemplo, si el array original es (’ ’,’a’,’h’,’ ’,’ ’,’ ’,’c’), el array resultante debe ser (’
’,’a’,’h’,’ ’,’c’). Las modificaciones se harán sobre el mismo array de entrada y no se
podrán usar arrays auxiliares. La implementación debe ser lo más eficiente posible.

José L. Ruiz
*/

#include <iostream>

using namespace std;

const int TAMANO = 100;

void Lectura( char p[], int & util_p){
	util_p = 0;
	cin >> noskipws >> p[util_p]; //noskipws PERMITE NO SALTAR EL CARÁCTER ' ' (espacio) Y METERLO EN EL ARRAY
	while( p[util_p] != '#' && util_p<= TAMANO ){
		util_p++;
		cin >> p[util_p];
	}
}

void Mostrar( const char cad[], const int & util_cad){
	for (int i=0; i<util_cad; i++)
		cout << cad[i];
}

/**
 * @brief Elimina la posicion posicion_borrar del array
 */
void EliminaPosicion( const int & posicion_borrar, char cad[], int & util_cad){
	util_cad--;
	for(int i=posicion_borrar; i<util_cad; i++)
		cad[i] = cad[i+1];
}

/**
 * @brief Elimina espacios consecutivos de un array de char, quedando como máximo 1 espacio.
 */
void EliminarEspacios(char cad[], int & util_cad){
	for(int i=1; i<util_cad; )
		if( isspace(cad[i-1]) && isspace(cad[i]) )
			EliminaPosicion(i, cad, util_cad);
		else
			i++;
}

int main(){
	char cadena[TAMANO];
	int util_cadena;
	cout << "Introduzca una cadena de caracteres (termine con '#'): ";
	Lectura(cadena, util_cadena);
	
	EliminarEspacios(cadena, util_cadena);
	
	cout << "Cadena resultante: " << endl;
	Mostrar(cadena, util_cadena);
	cout << endl;
}
