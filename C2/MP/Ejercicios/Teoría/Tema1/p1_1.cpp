/*
  Haz un progr,a que lea de la entrada un número de elemento sque tendrá un array de enteros y dos enteros de rango mínimo y máximo de los posibles valores que tomará el array. El programa lo rellenará con númeoros aleatorios y luego lo mostrará en la salida estándar.

Blanca Cano
20 / II / 18
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void imprimir_array( int v[] , int tam);
void generar_array( int tam , int min , int max , int v []); 

int main()
{
  const int tam_max = 100;
  int array [ tam_max ];

  int tam_array;
  int min , max;

  cout << "Introduzca el tamaño del array, el rango de valores enteros que tomará,  mínimo y máximo \n";

  cin >> tam_array >> min >> max ;

  //control de error de tamaño de array
  while( tam_array > tam_max)
    {
      cout << "El tamaño del array sobrepasa el tamaño máximo que es " << tam_max << "\n Introduzca nuevo dato: ";
      cin >> tam_array;
    }

  //control de error en el rango
  while ( max < min )
    {
      cout << "El intervo introducido no es el válido, pruebe de nuevo por favor; y recuerde, primero el mínimo y luego el máximo: \n";
      cin >> min >> max;
    }
  
  srand( (int) time(0));
  
  generar_array( tam_array , min ,  max , array);
}
//----------------------------------------------------------------------------------------------------
void generar_array( int tam , int min , int max , int v [])
{
  int rango = max - min + 1; //rango de valores que tomará el vector
  
  for( int i = 0 ; i < tam ; i++)
    v[i] = rand() % rango + min;

}

void imprimir_array( int v[] , int tam)
{
  for ( int i = 0 ; i < tam ; i++)
    cout << v[i] << " ";
  cout << endl;
}


