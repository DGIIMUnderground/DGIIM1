/* 8. Construir una función que dada una cadena de caracteres cad y dos valores enteros pos
y tam modifique cad eliminando los tam caracteres empezando en la posición pos.
Razonar sobre todos los casos posibles que pueden suceder.

José L. Ruiz
*/

#include <iostream>

using namespace std;

const int TAMANO = 350;

void Lectura( char p[], int & util_p){
	util_p = 0;
	cin >> p[util_p];
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
 * @brief Elimina, si es posible, tam caracteres de cad a partir de la posición pos
 * @param pos: posición a partir de la cual se elimina
 * @param tam: número de caracteres eliminados
 * @param cad: cadena de caracteres
 * @param util_cad: longitud operativa de la cadena de caracteres
 * @return true si ha sido posible llevar a cabo la operación, false en otro caso
 */
bool Elimina( const int & pos, const int & tam, char cad[], int & util_cad){
	bool satisfactorio = pos+tam < util_cad;
	if (satisfactorio){
		util_cad -= tam;
		for( int i=pos; i<pos+tam; i++)
			cad[i] = cad[i+tam];
	}
	return satisfactorio;
}

int main(){
	char cadena[TAMANO];
	int util_cadena;
	cout << "Introduzca una cadena de caracteres (termine con '#'): ";
	Lectura(cadena, util_cadena);
	
	cout << "Se ha leído la cadena: ";
	Mostrar(cadena, util_cadena);
	cout << endl;
	
	int posicion_eliminar, tamano_eliminar;
	cout << "Introduzca posición 'p' a partir de la cual desea eliminar 'n' caracteres" << endl;
	cout << "p: ";
	cin >> posicion_eliminar;
	cout << "n: ";
	cin >> tamano_eliminar;
	
	bool posible_eliminar = Elimina(posicion_eliminar, tamano_eliminar, cadena, util_cadena);
	
	if(posible_eliminar){
		cout << "Cadena de caracteres resultante: " << endl;
		Mostrar(cadena, util_cadena);
	}
	else
		cerr << "NO es posible realizar la operación" << endl;
}
