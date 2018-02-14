/*

José L. Ruiz

Ejercicio 4.22: traspuesta de una matriz

*/

#include <iostream>
#include <vector>

using namespace std;

void Lectura_matriz(vector<vector<double> > & matriz)
{
	for(int i=0; i<matriz.size(); i++)
	{
		for (int j=0; j<matriz[i].size(); j++)
		{
			cout << i << "," << j << ": ";
			cin >> matriz[i][j];
		}
	}
}

void Mostrar_matriz(vector<vector<double> > & matriz)
{
	for(int i=0; i<matriz.size(); i++)
	{
		for (int j=0; j<matriz[i].size(); j++)
		{
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
}

vector<vector<double> > Traspuesta(const vector<vector<double> > & matriz)
{
	vector<vector<double> > traspuesta(matriz[0].size(), vector<double>(matriz.size()) );
	
	for (int i=0; i<matriz.size(); i++)
	{
		for (int j=0; j<matriz[i].size(); j++)
		{
			traspuesta[j][i] = matriz[i][j];
		}
	}
	
	return traspuesta;
}

int main()
{
	int nfilas, ncolumnas;
	
	cout << "Introduzca número de filas y columnas de la matriz: ";
	cin >> nfilas >> ncolumnas;
	
	vector<vector<double> > matriz( nfilas, vector<double>(ncolumnas) );
	
	Lectura_matriz(matriz);
	
	cout << "Matriz leída: " << endl;
	Mostrar_matriz(matriz);
	
	vector<vector<double> > traspuesta = Traspuesta(matriz);
	
	cout << "\nMatriz traspuesta: " << endl;
	Mostrar_matriz(traspuesta);
}
