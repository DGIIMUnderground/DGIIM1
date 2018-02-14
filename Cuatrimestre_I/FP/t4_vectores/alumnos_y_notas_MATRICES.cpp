/*

Autor: José Luis Ruiz Benito.

	Ejercicio propuesto en el libro Fundamentos de Programación con la STL, de Antonio Garrido.
	UTILIZA MATRICES.
	Enunciado: Escriba un programa para leer una serie de m de notas para cada uno de los n alumnos a procesar. Para ello, almacene todas las notas en una matiz para finalmente escribir un informe con todas ellas y mostrar las medias de cada alumno y la media global.

*/

#include <iostream>
#include <vector>

using namespace std;

/**
	@brief Lee los componentes de una matriz
	@param m: matriz, definida en main
	@param filas: número de filas de la matriz
	@param columnas: número de columnas de la matriz
*/
void Lectura_matriz(vector<vector<double> > & m)
{
	for (int i=0; i<m.size(); i++)
	{
		cout << "ALUMNO: " << i << endl;
		for (int j=0; j<m[i].size(); j++)
		{
			cout << "\tNota " <<  j << ": ";
			cin >> m[i][j];
		}
	}
}

/**
	@brief Imprime una matriz en la salida estándar
	@param m: matriz que se imprimirá
*/
void Mostrar_matriz(const vector<vector<double> > & m)
{
	for (int i=0; i<m.size(); i++)
	{
		for (int j=0; j<m[i].size(); j++)
		{
			cout << m[i][j] << "  ";
		}
		
		cout << endl;
		
	}
}

/**
	@brief Calcula la media de cada alumno
	@param m: matriz con las notas
	@return medias: un vector con la media de cada alumno.
*/
vector<double> Medias_alumnos(const vector<vector<double> > & m)
{
	vector<double> medias;
	
	for (int i=0; i<m.size(); i++)
	{
		double suma=0.0;
		
		for(int j=0; j<m[i].size(); j++)
		{
			suma=suma+m[i][j];
		}
		
		double media = suma / m[i].size();
		
		medias.push_back(media);	
	}
	
	return medias;
}

/**
	@brief Muestra la nota media de cada alumno
	@param v: vector con las notas medias de todos los alumnos
*/
void Mostrar_medias_alumnos(const vector<double> & v)
{
	cout << "MEDIA DE CADA ALUMNO:" << endl;
	
	for ( int i=0; i< v.size(); i++)
	{
		cout << "\tAlumno " << i << ": " << v.at(i) << endl;
	}
	
	cout << endl;
}

/**
	@brief Calcula la media global, esto es, la media de las medias de los alumnos
	@param v: vector con las notas medias de todos los alumnos
	@returm media_global: la media global
*/
double Media_global(const vector<double> & v)
{
	double suma=0.0;
	
	for (int i=0; i<v.size(); i++)
	{
		suma=suma+v.at(i);
	}
	double media_global = suma / v.size();
	
	return media_global;
}

int main()
{
	int alumnos, ndatos; //número de alumnos y  número de datos por alumno.
	
	cout << "Introducir número de alumnos: ";
	cin >> alumnos;
	
	cout << "Introducir número de notas para cada alumno: ";
	cin >> ndatos;
	
	vector<vector<double> > tabla( alumnos, vector<double>(ndatos) ); //defino una matriz con "alumnos" filas y "ndatos" columnas
	
	Lectura_matriz(tabla); //lectura de la matriz tabla
	
	cout << endl << "Matriz creada: " << endl;
	Mostrar_matriz(tabla);
	cout << endl;
	
	vector<double> medias = Medias_alumnos(tabla);
	
	Mostrar_medias_alumnos(medias);
	
	double media_global = Media_global(medias);
	
	cout << "Media Global: " << media_global << endl;
}
