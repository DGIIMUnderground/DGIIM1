/*
 * 1. (3 puntos) Una matriz rectangular contiene valores enteros que representan medidas tomadas sobre una deter-
minada región. Se supone que todos los valores deben ser positivos aunque por problemas de captación y registro
algunos de ellos son negativos.
Es preciso corregir estos valores erróneos y se propone sustituirlos por el valor promedio de sus ocho vecinos más
cercanos espacialmente. Debe considerar que entre estos vecinos pudieran haber valores negativos, y en este caso
no intervendrán en el cálculo del valor promedio:
Si hubiera un sólo valor negativo en la vecindad, se sumarán los valores de los 7 vecinos válidos y la suma
se dividirá entre 7. Si hubiera dos valores negativos en la vecindad, se sumarán los valores de los 6 vecinos
vĺidos y la suma se dividirá entre 6. . . . Si no hubiera ningún valor válido, se sustituirá por un cero.
Implemente un módulo para que dada una matriz rectangular como las descritas, devuelva otra matriz rectangular
corregida. La matriz original no se modifica.
Para la implementación debe considerar:
a) El algoritmo debe ser simple y claro.
b) Para simplificar, las casillas de los bordes no se modifican, aunque sı́ se usan para efectuar las correcciones
oportunas. En definitiva, la primera y la última fila ası́ como la primera y la última columna son iguales entre
la matriz original y la corregida.
*/

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Lee una matriz de enteros
 */
void Lectura( vector<vector<int> > & m)
{
	for (int i=0; i<m.size(); i++)
	{
		for (int j=0; j<m[i].size(); j++)
		{
			cout << "[" << i << "," << j << "]: ";
			cin >> m[i][j];
		}
	}
}


vector<vector<int> > Corregir( const vector<vector<int> > & m)
{
	vector<vector<int> > corregida = m;
	
	//Comencemos con la corección
	
	for (int i=1; i<m.size()-1; i++)
	{
		for (int j=1; j<m[i].size()-1; j++)
		{
			if( m[i][j] < 0 ) //Si encuentro un elemento negativo, lo corrijo
			{
				//Calculo la media de los de alrededor que no sean negativos:
				int suma = 0; //luego dividiré por el número de datos para sacar la media
				int ndatos=0;
				
				for (int k=i-1; k<=i+1; k++)
				{
					for (int l=j-1; l<=j+1; l++)
					{
						if( !(k==i && l==j) ) //si no es el elemento central
						{
							if( m[k][j] >= 0 )
							{
								suma = suma + m[k][j];
								ndatos++;
							}
						}
					}
				}
				
				if(ndatos>0)
				{
					corregida[i][j] = suma / ndatos;
				}
				else
				{
					corregida[i][j] = 0;
				}
			}
		}
	}
	
	
	return corregida;
}

void Mostrar( const vector<vector<int> > & m)
{
	for (int i=0; i<m.size(); i++)
	{
		for (int j=0; j<m[i].size(); j++)
		{
			cout << m[i][j] << "\t";
		}
		cout << endl;
	}
}

int main()
{
	int nfilas, ncolumnas;
	
	cout << "Introducir nfilas y ncolumnas de la matriz: ";
	cin >> nfilas >> ncolumnas;
	
	vector<vector<int> > matriz(nfilas, vector<int> (ncolumnas));
	
	Lectura(matriz);
	
	vector<vector<int> > matriz_corregida = Corregir(matriz);
	
	cout << "La matriz leída es: " << endl;
	Mostrar(matriz);
	cout << endl;
	
	cout << "La matriz corregida es: " << endl;
	Mostrar(matriz_corregida);
	cout << endl;
	
}
