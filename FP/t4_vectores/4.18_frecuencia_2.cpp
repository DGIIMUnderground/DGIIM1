/*

	José L. Ruiz Benito
	
	Tema Vectores y Matrices:
	4.18 hecho de forma extraña: leer enteros y calcular la frecuencia de cada uno.

*/

#include <iostream>
#include <vector>

using namespace std;

struct Par{
	int numero;
	int frecuencia;
};

void Mostrar_par(Par x)
{
	cout << x.numero << ": " << x.frecuencia << " veces" << endl;
}

void Mostrar_vector(vector<Par> v)
{
	for (int i=0; i<v.size(); i++)
	{
		Mostrar_par(v[i]);
	}
}

/**
 * @brief Determina si existe el par número-frecuencia para un número dado
 * @param v: Vector con los pares número-frecuencia en el que buscamos el número dado
 * @param num: Número del que se busca si tiene un par asociado
 * @param pos_par: posición del vector en la que se encuentra el par asociado al número; se modifica si existe dicho par.
 * @return true si existe el par asociado a un número, false si no
*/
bool Existe_el_par(const vector<Par> & v, const int & num, int & pos_par)
{
	bool existe=false;
	
	for( int i=0; i<v.size(); i++)
	{
		if (num == v[i].numero )
		{
			existe=true;
			pos_par = i;
			break;
		}
	}
	
	return existe;
}

int main()
{
	int ndatos;
	cout << "Número de datos que se introducirán: ";
	cin >> ndatos;
	
	vector<int> datos; //números enteros que se introducirán
	vector<Par> pares; //parejas de datos junto a su frecuencia
	
	for( int i=0; i<ndatos; i++)
	{
		//Leo elementos del vector:
		int elemento;
		cout << "v[" << i << "]: ";
		cin >> elemento;
		
		//Si el elemento tiene un par elemento-frecuencia asociado en el vector, sumo 1 a la frecuencia:
		int posicion_par;
		if ( Existe_el_par(pares, elemento, posicion_par) ) //paso posicion_par a la función para que lo modifique en caso de existir el par y así saber en qué posición se encuentra
		{
			pares[posicion_par].frecuencia++;
		}
		
		//Si no existe el par, creo uno nuevo. En la primera posición pongo el elemenento y la segunda (frecuencia) la inicializado a 1.
		else
		{
			Par nuevo;
			nuevo.numero = elemento;
			nuevo.frecuencia = 1;
			pares.push_back(nuevo);
		}
	}
	
	//Muestro cada elemento junto a su frecuencia.
	Mostrar_vector(pares);
}
