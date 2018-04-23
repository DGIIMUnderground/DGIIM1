/* 12. Haz un programa que contenga una función que compruebe si una cadena (estilo C) es
o no un palı́ndromo, es decir, que se lee igual de izquierda a derecha que de derecha a
izquierda sin tener en cuenta los espacios. Por ejemplo, anilina serı́a un palı́ndromo. La
función para ver si la cadena es un palı́ndromo, se ayudará de otra función auxiliar que,
dada una cadena, obtiene otra donde se han eliminado los espacios en blanco.

José L. Ruiz
*/

#include <iostream>

using namespace std;

void Lectura( char p[], int & util_p){
	util_p = 0;
	cin >> p[util_p];
	while( p[util_p] != '.' ){
		util_p++;
		cin >> p[util_p];
	}
}

bool EsPalindromo( const char p[], const int & util_p){
	char sin_espacios[util_p];
	int util_sin_espacios = 0;
	for (int i=0; i<util_p; i++){
		if( p[i] != ' ' ){
			sin_espacios[util_sin_espacios] = p[i];
			util_sin_espacios++;
		}
	}
	bool palindromo = true;
	for(int i=0; i<util_sin_espacios/2 && palindromo; i++)
		if( sin_espacios[i] != sin_espacios[util_sin_espacios-1-i] )
			palindromo = false;
	
	return palindromo;
}

int main(){
	const int TAMANO = 100;
	char palabra[TAMANO];
	int util_palabra;
	
	cout << "Introduzca un palabra (termine con '.'): ";
	Lectura(palabra, util_palabra);
	
	if( EsPalindromo(palabra, util_palabra) )
		cout << "Es un palíndromo" << endl;
	else
		cout << "NO es un palíndromo" << endl;
}
