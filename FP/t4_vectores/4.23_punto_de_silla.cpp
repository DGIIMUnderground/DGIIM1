/*

	José L. Ruiz
	 
	 Ejercio 4.23 del tema de vectores del cuaderno de ejercicios del libro de Antonio Garrido.
	 Punto de silla: Implemente un programa que lea los datos de una matriz de tamño arbitrario.
	 El programa nos dirá si existe o no algún elemento que sea  a la vez máximo de su fila y mínimo de su columna.

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


void Mostrar_matriz( const vector<vector<double> > & m)
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

struct Posicion{ //tipo de dato para representar las coordenadas de una posición de la matriz
	int i;
	int j;
};

void Mostrar_posicion( const Posicion & x)
{
	cout << "m[" << x.i << "][" << x.j << "]";
}

void Mostrar_vector_posiciones(const vector<Posicion> & v)
{
	for (int i=0; i<v.size(); i++)
	{
		Mostrar_posicion( v.at(i) );
		cout << " ";
	}	
}

/**
	@brief Calcula las posiciones de los elementos que son a la vez máximo de su fila y mínimo de su columna.
	@param m: Una matriz rectangualar de números reales
	@return Devuelve un vector con las posiciones de los elementos que cumpler ser a la vez máximo de su fila y mínimo de su columna
 
*/
vector<Posicion> Elemento_especial(const vector<vector<double> > & m)
{
	vector<Posicion> especiales;
	
	for (int i=0; i<m.size(); i++) //recorrer filas i
	{
		Posicion maximo_fila;
		maximo_fila.i = i;
		maximo_fila.j = 0;
		
		for (int j=0; j<m[i].size(); j++) //recorrer elementos j de la fila
		{
			if( m[i][j] > m[maximo_fila.i][maximo_fila.j] ) //si encuentro un elemento mayor actualizo la posición del mayor de la fila
			{
				maximo_fila.j = j;
			}
		}
			
		Posicion minimo_columna;
		//supongo que el mayor de la fila es también el mínimo de la columna:
		minimo_columna.i = maximo_fila.i; 
		minimo_columna.j = maximo_fila.j;
		
		for (int k=0; k<m.size(); k++) //miro si el máximo de la fila es también el mínimo de su columna. Voy variando la fila k para encontrar otro menor.
		{
			if (m[k][maximo_fila.j] < m[minimo_columna.i][minimo_columna.j] ) //si encuentro otro menor en la columna, actualizo la posición del menor de la columna
			{
				minimo_columna.i = k;
			}
		}
			
		if ( maximo_fila.i == minimo_columna.i && maximo_fila.j == minimo_columna.j ) //si las posiciones del máximo de la fila y mínimo de la columna coinciden...
		{
				especiales.push_back(maximo_fila);
		}
	}
	
	return especiales;
}

int main()
{
	int nfilas, ncolumnas;
	
	cout << "\nNúmero de filas de la matriz: ";
	cin >> nfilas;
	
	cout << "Número de columnas de la matriz: ";
	cin >> ncolumnas;
	
	vector<vector<double> > matriz(nfilas, vector<double> (ncolumnas) );
	
	cout << "\nIntroduzca los términos de la matriz:" << endl;
	Leer_matriz(matriz);
	
	cout << "\nLa matriz leída es: " << endl;
	Mostrar_matriz(matriz);
	
	vector<Posicion> especiales = Elemento_especial(matriz);
	
	cout << "\nLos elementos que son a la vez máximo de su fila y mínimo de su columna son:" << endl;
	Mostrar_vector_posiciones(especiales);
	
}
