/*
Se está diseñando un sistema web que recolecta datos personales de un usuario y, en un momento
dado, debe sugerirle un nombre de usuario (login). Dicho login estará basado en el nombre y los apellidos, en
concreto estará formado por los N primeros caracteres de cada nombre y apellido (en minúsculas, unidos y sin
espacios en blanco). Por ejemplo, si el nombre es "Antonio Francisco Molina Ortega" y N=2, el nombre de
usuario sugerido será "anfrmoor".
Debe tener en cuenta que el número de palabras que forman el nombre y los apellidos puede ser cualquiera.
Además, si N es mayor que alguna de las palabras que aparecen en el nombre, se incluirá la palabra completa. Por
ejemplo, si el nombre es "Ana CAMPOS de
la Blanca" y N=4, entonces la sugerencia será "anacampdelablan"
(observe que se pueden utilizar varios espacios en blanco para separar palabras).
Implemente un módulo que reciba una cadena de caracteres formada por nombre y apellidos (separados por uno
o más espacios en blanco) y un valor entero N y que devuelva otra cadena con la sugerencia de login.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Lee un nombre completo desde la entrada estándar
*/
string Lectura()
{
	string nombre;
	
	cout << "Introducir nombre y apellidos: ";
	getline(cin, nombre);
	
	return nombre;
}

/**
 * @brief Devuelve un nombre de usuario para un nombre completo
 * @param nombre: nombre completo de la persona
 * @param n: número de letras que se selccionarán de cada palabra apra construir el login
 * @return nombre de usuario (login)
*/
string Propuesta_login( string nombre, const int & n )
{
	string propuesta;
	string palabra; //cada palabra que se va detectando del nombre completo
	
	nombre += ' '; //añado un espacio al final del nombre para que detecte el fin de la última palabra
	
	for (int i=0; i<nombre.size(); i++)
	{
		if (nombre[i] != ' ' )
		{
			if (nombre[i] >= 'A' && nombre[i] <= 'Z' ) //si la letra es mayúscula la paso a minúscula sumándole 32 a su código ASCII
			{
				char aux = nombre[i] + 32;
				palabra += aux;
			}
			else
			{
				palabra += nombre[i];
			}
		}
		else
		{
			if (palabra.size()<=n) //si la palabra es menor que el número de letras que se cogen
			{
				propuesta += palabra;
			}
			else
			{
				for (int j=0; j<n; j++)
				{
					propuesta += palabra[j];
				}
			}
			palabra = ""; //vacío la palabra
		}
	}
	
	return propuesta;
}

int main()
{
	string nombre_real = Lectura();

	int n;
	cout << "Se seleccionarán las primeras N letras de cada palabra. Introducir N: ";
	cin >> n;

	string login = Propuesta_login(nombre_real, n);
	cout << "Se le propone el siguiente nombre de usuario: " << login << endl;
}
