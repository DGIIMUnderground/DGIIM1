/*

Enunciado: Realizar un programa que lea un matriz de enteros y muestre ordenados de forma creciente los elementos de
la fila que contiene el mayor elemento de la matriz.

*/

#include <iostream>
#include <vector>

using namespace std;

void Leer_matriz( vector<vector<int> > & m)
{
	for (int i=0; i<m.size(); i++)
	{
		for (int j=0; j<m[i].size(); j++)
		{
			cout << "m[" << i << "][" << j << "]: ";
			cin >> m[i][j];
		}
	}
}

int Fila_mayor_elemento( const vector<vector<int> > & m)
{
	int maximo=0;
	int fila_maximo;
	
	for (int i=0; i<m.size(); i++)
	{
		for (int j=0; j<m[i].size(); j++)
		{
			if (m[i][j] > maximo)
			{
				maximo = m[i][j];
				fila_maximo = i;
			}
		}
	}
	
	return fila_maximo;
}

vector<int> Extraer_fila( const vector<vector<int> > & m, const int & num_fila)
{
	vector<int> fila = m[num_fila];
	
	return fila;
}

void Ordenar_burbuja( vector<int> & v)
{
	for (int i=v.size()-1; i>0; i--)
	{
		for (int j=0; j<i; j++)
		{
			if ( v.at(j) > v.at(j+1) )
			{
				int aux = v.at(j);
				v.at(j) = v.at(j+1);
				v.at(j+1) = aux;
			}
		}
	}
}

void Mostrar_vector( const vector<int> & v)
{
	for (int i=0; i<v.size(); i++)
	{
		cout << v.at(i) << " ";
	}
	cout << endl;
}

int main()
{
	int nfilas, ncolumnas;
	
	cout << "Número de filas de la matriz: ";
	cin >> nfilas;
	
	cout << "Número de columnas de la matriz: ";
	cin >> ncolumnas;
	
	vector<vector<int> > matriz(nfilas, vector<int> (ncolumnas) );
	
	cout << "Introduzca los téminos de la matriz" << endl;
	Leer_matriz(matriz);
	
	int num_fila = Fila_mayor_elemento(matriz); //el número de fila en el que se encuentra el mayor elemento de la metriz
	
	vector<int> fila = Extraer_fila(matriz, num_fila); //la fila
	
	Ordenar_burbuja(fila);
	
	cout << "Fila que contiene el mayor elemento ordenado: ";
	Mostrar_vector(fila);
}
