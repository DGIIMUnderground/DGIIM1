/*

José L. Ruiz Benito

Producto matricial.

*/

#include <iostream>
#include <vector>

using namespace std;

void Leer_matriz(vector<vector<double> > & m)
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

 
/**
	@brief Multiplica dos matrices
	@param m1: primer multiplicando
	@param m2: segundo multiplicando
	@return producto m1xm2
	@pre las matrices deben ser multiplicables
*/
vector<vector<double> > Producto ( const vector<vector<double> > & m1, const vector<vector<double> > & m2)
{
	vector<vector<double> > producto ( m1.size(), vector<double> ( m2[0].size() ) ); //el producto tiene las filas de m1 y las columnas de m2.
	
	for (int i=0; i<producto.size(); i++)
	{
		for (int j=0; j<producto[0].size(); j++)
		{
			//Calculemos el término producto[i][j]:
			double term = 0;
			
			for (int k=0; k<m1[0].size(); k++)
			{
				term = term + m1[i][k]*m2[k][j];	
			}
			producto[i][j] = term;
		}
	}
	
	return producto;
}

void Mostrar_matriz(const vector<vector<double> > & m )
{
	for (int i=0; i<m.size(); i++)
	{
		for (int j=0; j<m[i].size(); j++)
		{
			cout << m[i][j] << " ";
		}
		
		cout << endl;
	}
}

int main()
{
	cout << "Producto de dos matrices" << endl;
	
	int f1, c1, f2, c2;
	
	cout << "Filas y columnas de la Matriz 1: ";
	cin >> f1 >> c1;
	
	cout << "Filas y columnas de la Matriz 2: ";
	cin >> f2 >> c2;
	
	if (c1 == f2)
	{
		vector<vector<double> > m1(f1, vector<double> (c1)), m2(f2, vector<double> (c2));
		
		cout << "Introducir Matriz 1: ";
		Leer_matriz(m1);
		
		cout << "Introducir Matriz 2: ";
		Leer_matriz(m2);
		
		vector<vector<double> > producto = Producto(m1, m2);
		
		cout << endl << "M1 x M2 = " << endl;
		Mostrar_matriz(producto);
		
	}
	else
	{
		cout << "Las matrices no se pueden multiplicar." << endl;
	}
}
