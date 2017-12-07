/*
  LETRA MÁS USADA 
Ejercicio 4.49 Del libro INTRODUCCIÓN A LA PROGRAMACIÓN de Antonio Garrido
  Blanca Cana 
  5 / 12 / 2017
  Se desea realizar un programa para calcular la frecuencia de las letras en un
documento. Para ello, se analizarán las apariciones de cada una de las letras de la parte básica de la tabla ASCII (los
caracteres del cero al 127).
Escriba un programa que lea los caracteres de un texto hasta encontrar el carácter ’#’. Para cada uno de los caracteres
leídos, calculará la frecuencia de aparición. Como resultado, escribirá en la salida estándar cada uno de los pares
carácter/frecuencia de mayor a menor frecuencia. Sólo se imprimirán los caracteres que hayan aparecido, al menos, una
vez.

Ejemplo de código:
blanca@debian:~/campo_batalla$ ./a.out 
hola, mi numero favorito es e EEEEEE LO PETA. #         
Caracter: , Frecuencia: 1
Caracter: . Frecuencia: 1
Caracter: A Frecuencia: 1
Caracter: E Frecuencia: 7
Caracter: L Frecuencia: 1
Caracter: O Frecuencia: 1
Caracter: P Frecuencia: 1
Caracter: T Frecuencia: 1
Caracter: a Frecuencia: 2
Caracter: e Frecuencia: 3
Caracter: f Frecuencia: 1
Caracter: h Frecuencia: 1
Caracter: i Frecuencia: 2
Caracter: l Frecuencia: 1
Caracter: m Frecuencia: 2
Caracter: n Frecuencia: 1
Caracter: o Frecuencia: 4
Caracter: r Frecuencia: 2
Caracter: s Frecuencia: 1
Caracter: t Frecuencia: 1
Caracter: u Frecuencia: 1
Caracter: v Frecuencia: 1

 */

#include <iostream>
#include <vector>
using namespace std;

/**
   @brief: Vector con frecuencia que se repite caracter ascc introducido por cin hasta que se encuentra un # cuyo valro es el 35 en ASCII
   @return: vector de tamaño 127 que contiene la las veces que se ha repetido ese caracter ascci
 */
vector<int> vector_frecuencia()
{
  vector<int> ascii(127 , 0 );
  char  caracter;
  
  cin >> caracter;
  int num = caracter;

  while ( num != 35 )
    {
      ascii[ num ] += 1;
      cin >> caracter;
      num = caracter;
    }
  
  return ascii;
}

/**
   @brief: imprime vector entendiendo el índice como un caracter ascci y su valos la frecuencia con que aparece
   @param vector: vecctor de enteros (para que tenga sentido)
 */
void imprime( vector<int> vector)
{
  for( int i = 0 ; i < vector.size() ; i++ )
    {
      int valor = vector[i];
      if(valor)
	{
	  char caracter = i;
	  cout << "Caracter: " << caracter << " Frecuencia: " << valor << endl;
	}
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ main ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main()
{
  imprime(vector_frecuencia());
  return 0;
}
  
