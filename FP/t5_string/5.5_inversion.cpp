/*

	José L. Ruiz.
	
	Ejercicio 5.5. String:
	Lee una cadena de caracteres, la invierte y la muestra.

*/

#include <iostream>
#include <string>

using namespace std;

void Invertir( string & s)
{
	for (int i=0; i<s.size()/2; i++) //voy intercambiando el primero con el último y así sucesivamente
	{
		char aux;
		aux = s.at(i);
		s.at(i) = s.at( s.size()-1-i);
		s.at( s.size()-1-i) = aux;
	}
}

int main()
{
	string frase;
	
	cout << "Escriba una frase: ";
	getline(cin, frase);
	
	Invertir(frase);
	
	cout << "Frase invertida: " << frase;
}
