/*
 * Ejercicio 5.11 — Mayúsculas. Haga un programa que lea una frase cualquiera y que la transforme de la siguiente forma:
todas las letras deberán transformarse en minúsculas salvo aquellas que sean el comienzo de una palabra, que deberán
transformarse en mayúsculas. Se considera que la separación entre palabras es cualquier carácter que no sea una letra
(espacio, dígitos, signos de puntuación, etc). Veamos un ejemplo de ejecución:

	Escriba una frase: HOLa, ¿fUnCIOnará ESTO?
	La frase se quedaría así: Hola, ¿Funcionará Esto?

José L. Ruiz

*/

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Pone la primera letra de cada palabra en mayúscula y el resto en minúsculas. No altera el resto de carcteres.
 * @param f: frase sobre la que actúa
 */
void Procesar ( string & f )
{
	f.at(0) = toupper(f.at(0) ); //pongo la primera letra en mayúscula; si f.at(0) es un signo de puntuación, no hace nada
	
	for (int i=1; i<f.size(); i++)
	{
		if ( isalpha( f.at(i) ) )
		{
			if ( ! isalpha( f.at(i-1) ) )
			{
				f.at(i) = toupper( f.at(i) );
			}
			else
			{
				f.at(i) = tolower( f.at(i) );
			}
		}
	}
}

int main()
{
	string frase;
	
	cout << "Escriba una frase: ";
	getline(cin, frase);
	
	Procesar(frase);
	
	cout << "La frase quedaría así: " << frase << endl;
}
