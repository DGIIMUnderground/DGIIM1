/*

Autor: José Luis Ruiz Benito
Bibliografía:
	- Fundamentos de Programación con la STL, Antonio Garrido Carrillo.
	- Apuntes de Juan Carlos Cubero.

Descripción del programa:  
	Ordena vectores con los algoritmos de Burbuja, Selección e Inserción
	Incluye ademaś funciones de Lectura de un vector, Mostrar los elementos de un vector e Intercambio de dos valores.
	Leído el vector, el programa permite elegir el algoritmo que utilizará para ordenar sus elementos de MENOR A MAYOR.

*/

#include <iostream>
#include <vector>

using namespace std;

void Lectura(vector<int> & v)
{
	int componente;
	
	cin >> componente;
	
	while (componente >= 0)
	{
		v.push_back(componente);
		cin >> componente;
	}
}

void Intercambiar(int & a, int & b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}

void Mostrar(const vector<int> &v)
{
	for (int i=0; i<v.size(); i++)
	{
		cout << v.at(i) << " ";
	}
	cout << endl;
}

void Burbuja(vector<int> & v)
{
	for (int i=v.size()-1; i>0; i--)
	{
		for (int j=0; j<i; j++)
		{
			if ( v.at(j) > v.at(j+1) )
			{
				Intercambiar( v.at(j), v.at(j+1) );
			}
		}
	}
}

void Seleccion(vector<int> & v)
{
	for (int i=0; i<v.size(); i++)
	{
		int minimo = v.at(i);
		int pos_minimo = i;
		
		for (int j=i+1; j<v.size(); j++)
		{
			if( v.at(j) < minimo )
			{
				minimo = v.at(j);
				pos_minimo = j;
			}
		}
		
		Intercambiar( v.at(i), v.at(pos_minimo) );
	}
}

void Insercion(vector<int> & v) //No funciona
{
	for (int i=1; i<v.size(); i++)
	{
		int aux = v.at(i); //obtenemos el elemento de la posición i.
		
		int j;
		for (j=i; j>0 && aux < v.at(j-1); j--)
		{
			v.at(j) = v.at(j-1); //echamos los elementos una posición hacia atrás
		}
		
		v.at(j) = aux;
	}
}


int main()
{
	vector<int> datos;
	
	cout << "Introduzca datos positivos (termine con un valor negativo): ";
	Lectura(datos);
	
	int respuesta=0;
	
	cout << "Algoritmos: \n1. Burbuja \n2. Selección \n3. Inserción \n¿Qué algoritmo desea utilizar?: ";
	cin >> respuesta;
	
	
	switch(respuesta)
	{
		case 1:
			cout << "Burbuja" << endl;
			Burbuja(datos);
			break;
		
		case 2:
			cout << "Selección" << endl;
			Seleccion(datos);
			break;
		
		case 3:
			cout << "Inserción" << endl;
			Insercion(datos);
			break;
			
		default:
			cout << "No se ordenará" << endl;
	}
	
	cout << "Vector ordenado: ";
	Mostrar(datos);
}
