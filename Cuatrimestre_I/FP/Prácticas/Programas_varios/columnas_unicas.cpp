/*
  COLUMNAS ÚNICAS 
  Blanca Cana
  7 / 12 / 17
Ejercicio 4.21 — Columnas únicas. Escriba un programa que lea una matriz bidimensional desde la entrada estándar y
que indique cuántas de sus columnas son únicas. Una columna se considera única si no se repite, es decir, si no hay otra
igual a ella.

A mejorar:
Que cuando sepa que varias columans son iguales las tome como si fuera solo una y así se ahorra casos a comparar

Ejemplo de ejecución: 

Veamos cuántas columnas únicas tiene su matriz 
Introduzca número de filas: -69
ERROR, el tamaño debe ser mayor de cero, venga pruebe de nuevo: 2
Introduzca número columnas: 5
Introduzca 5 elementos en la fila 1: 1 1 2 6 4  
Introduzca 5 elementos en la fila 2: 2 2 8 9 8
La matriz introducida es: 
1 1 2 6 4 
2 2 8 9 8 
Por si no fuera lo suficientemente obvio, su matriz posee 4 columnas únicas :) 
 

 */

#include <iostream>
#include <vector>

using namespace std;

/**
   @brief: imprime en pantalla una matriz
   @param matriz: matriz bidimensional de tipo float,no puede ser vacía
 */
void imprime_matriz( const vector< vector<float> >& matriz )
{
  int filas = matriz.size();
  int columnas = matriz[0].size();

  for( int i = 0; i < filas ; i++ )
    {
      for( int j = 0; j < columnas ; j++ )
	cout << matriz[i][j] << " ";
      cout << endl;
    }
}


/**
   @brief: introduzca número de filas y de columnas de nuesta matriz, y despúes los elemento fila pro fila
   @return: matriz 
 */
vector<vector<float> > lee_matriz()
{
  // Introducción del tamaño del vector
  
  int fila , columna; //núemro de filas que tendrá nuesta matriz

  cout << "Veamos cuántas columnas únicas tiene su matriz \n"
       << "Introduzca número de filas: ";
  cin >> fila;

  while( fila <1 )
    {
      cout << "ERROR, el tamaño debe ser mayor de cero, venga pruebe de nuevo: ";
      cin >> fila;
    }

  
  cout << "Introduzca número columnas: ";
  cin >> columna;

  while( columna <1 )
    {
      cout << "ERROR, el tamaño debe ser mayor de cero, venga pruebe de nuevo: ";
      cin >> columna;
    }

  //creación e introducción de datos de la matriz

  vector< vector<float> > matriz( fila , vector<float>(columna));
  float num;
  
  for ( int i = 0 ; i < fila ; i++ )
    {
      cout << "Introduzca " << columna << " elementos en la fila " << i+1 << ": ";
      for( int j = 0 ; j < columna ; j++ )
	{
	  cin >> num;
	  matriz[i][j] = num;
	}
    }
  return matriz;
}

/**
   @brief: Indica cuantas columnas son únicas, el algoritmo utilizado para compararlas todas sin repetir se demmuestra por inducción sobre el númmero de biyecciones por columnas, se deja a demostrar como ejercicio :)
   @param: matriz bidimensional de tipo float, NO DEBE ESTAR VACÍA
   @return: número de columnas diferentes
 */
int columnas_independientes( const vector< vector<float> >& matriz)
{
  int filas = matriz.size();
  int columnas = matriz[0].size();

  int num = 1; //Comienza en uno porque la primera es única, ya que no hay otra con la que compararla
  bool igualdad = true;
  int fila = 0;
  
  for ( int i = 0 ; i < columnas; i++)
    {
      igualdad = true;
      for ( int j = 0 ; j < i ; j++) 
	{
	  fila = 0;
	  
	  while( igualdad && fila < filas )
	      ( matriz[fila][i] != matriz[fila][j])? igualdad = false : fila++ ;
	  
	}
      
      if(!igualdad)
	num++;
    }
  
  return num;
}




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ main ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main()
{
  vector<vector<float> >matriz (lee_matriz());
  cout << "La matriz introducida es: " << endl;
  imprime_matriz( matriz );

  cout << "Por si no fuera lo suficientemente obvio, su matriz posee "
       << columnas_independientes( matriz )
       << " columnas únicas :) "
       << endl;
  return 0;
}
