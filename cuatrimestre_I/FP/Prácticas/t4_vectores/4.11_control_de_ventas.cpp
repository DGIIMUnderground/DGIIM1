/*
 
	José L. Ruiz Benito
	
	Tema 4: Vectores y matrices
	Ejercicio 4.11: Control de ventas.

*/

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Suma los términos de un vector de reales
 * @param v: vector
 * @return suma de los términos
*/
double Suma( const vector<double> & v)
{
	double suma=0;
	
	for (int i=0; i<v.size(); i++)
	{
		suma = suma + v.at(i);
	}
	
	return suma;
}

void Mostrar_vector( const vector<double> & v)
{
	for (int i=0; i<v.size(); i++)
	{
		cout << v.at(i) << " ";
	}
}

int main()
{
	vector<double> datos;
	double termino;
	
	cout << "Introducir datos. Separar vendedores con -1 y finalizar con -2: " << endl;
	cin >> termino;
	while (termino != -2)
	{
		datos.push_back(termino);
		cin >> termino;
	}
	
	double suma; //para acumular las ventas de cada vendedor
	double maximo=0; //máxima de las sumas
	int vendedor=0; //número de vendedor del que se están haciendo los cálculos.
	int vendedor_maximo=1; //inicializo suponiendo que el que más ha vendido ha sido el vendedor
	vector<double> secuencia_vendedor; //secuencia del vendedor
	vector<double> secuencia_vendedor_maximo; //secuencia del vendedor que más ha vendido
	
	for (int i=0; i<datos.size(); i++)
	{
		if (datos.at(i) != -1 && datos.at(i) != -2)
		{
			secuencia_vendedor.push_back( datos.at(i) );
		}
		else
		{
			suma = Suma(secuencia_vendedor);
			
			if ( suma > maximo)
			{
				maximo=suma;
				vendedor_maximo=vendedor;
				secuencia_vendedor_maximo = secuencia_vendedor;
			}
			
			cout << "Vendedor " << vendedor << ": " << suma << " ventas" << endl;
			
			secuencia_vendedor.resize(0);
			vendedor++;
		}
		
	}
	
	cout << "El vendedor que más ha vendido ha sido el número " << vendedor_maximo << endl;
	cout << "Su secuencia de ventas es: ";
	Mostrar_vector(secuencia_vendedor_maximo);
	cout << endl;
}
