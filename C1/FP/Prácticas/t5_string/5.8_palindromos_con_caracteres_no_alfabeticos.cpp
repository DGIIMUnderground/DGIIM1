/*
 * Comprobar si una frase es palíndromo. Primero se eliminarán signos de puntuación y espacios en blanco.
 * No usaremos letras con tilde
 * 
 * José L. Ruiz
 */
 
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Asigna el valor a una cadena de caracteres mediante la entrada estándar
 * @param f: cadena de carcateres qu ese leerá
 */
void Lectura( string & f)
{
	cout << "Introducir frase (¡No usar tildes!): ";
	getline(cin, f);
}

/**
 * @brief Elimina caracteres no alfabéticos de una cadena de caracteres
 * @param f: cadena de carcteres
 */
void Preparacion( string & f)
{
	for (int i=0; i<f.size(); i++)
	{
		if ( f.at(i) < 'a' || f.at(i) > 'z' ) //si no es una minúscula
		{
			if ( f.at(i) >= 'A' && f.at(i) <= 'Z') //si es una mayúscula
			{
				f.at(i) = f.at(i) + 32; //las mayúsculas las paso a minusculas
			}
			else //si no es minúscula y si no es mayúscula
			{
				f.erase( i, 1);
				i--; //reduzco una unidad i para que al aumentar al final del for no se salte la comprobación de un carácter
			}
		}
	}
}

bool Es_palindromo(const string & cadena)
{
	bool palindromo=true;
	
	for (int i=0; i<cadena.size()/2; i++)
	{
		if( cadena.at(i) != cadena.at( cadena.size()-1-i ) )
		{
			palindromo = false;
			break;
		}
	}
	
	return palindromo;
}

int main()
{
	string frase;
	Lectura(frase);

	Preparacion(frase); //para eliminar espacios en blanco y signos de puntuacion;
			cout << "Frase preparada: " << frase << endl;
	

	if ( Es_palindromo(frase) )
	{
		cout << "La frase introducida es un palíndromo" << endl;
	}
	else
	{
		cout << "La frase introducida NO es un palíndromo" << endl;
	}
}
