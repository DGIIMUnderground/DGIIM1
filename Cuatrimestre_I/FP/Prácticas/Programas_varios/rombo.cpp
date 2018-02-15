/* 
   Ejercicio 3.27 — Mostrar figuras. Escriba un programa que lea un número entero N desde la entrada estándar y que a
continuación dibuje con asteriscos –en la salida estándar– las siguientes figuras:
1. Triángulo de lado N
2. Cuadrado hueco de lado N
3. Rombo de altura N y de ancho N/2. En este caso N debe ser un número impar. (En el ejemplo dibuja uno de N*N, yo sigo el del el ejemplo)
A continuación vemos una muestra de estas figuras para N=7:

   Blanca Cano Camarero
   Grnanada 7 / 11 / 17
 */

#include<iostream>
using namespace std;

//Funciones que utilizo
int triangulo(int lado); // dibuja triángulo
int cuadrado(int lado); // dibuja cuadtado hueco
int rombo(int rombo);   // creo que ya empiezas a intuir que significan por el nombre: D
  
int main()
{
  int longitud;
  int lado;

  cout << "Introduzca la longitud de los polígonos: ";
  cin >> lado;
  
  triangulo(lado);
  cuadrado(lado);
  rombo(lado);
  
  
  return 0 ;
}

/**
@brief: Dibuja un triángulo rectángulo de cateto de lados *
@param lado: longitud, número de asteriscos
 */
int triangulo( int lado)
{
  cout << "Triángulo de lado " << lado << endl;
  for (int i = 0 ; i < lado ; i++)
    {
      cout << string( i , '*') << endl;
	
    }
  return 0 ;
}

/**
@brief: dibuja un cuadrado hueco de lado n con asteríscos
@param lado: núemro de astericos en cada lado
 */

int cuadrado(int lado)
{
  cout << "Cuadrado de lado " << lado << endl;
  cout << string( lado , '*' ) << endl;
  for( int i = 0 ; i < lado - 2 ; i++)
    {
      cout << "*" << string ( lado-2 , ' ' ) << "*" << endl ;
    }
    cout << string( lado , '*' ) << endl;
  return 0 ;
}

int rombo (int lado)
{
  if( ! lado % 2 )
    cout << "Imposible dibujar un rombo con longitud par" << endl;
  else
    {
      cout << "Rombo de lado " << lado << endl;
      int cnt = 1;
      for ( int i = 0 ; i < (lado-1) / 2; i++)
	{
	  cout << string ( (lado-1)/2-i , ' ' ) << string (cnt , '*') << endl;
	  cnt += 2;
	}
      cout << string( cnt , '*') << endl;
      cnt -=2;

      for (int i = (lado-1) / 2 ; i > 0 ; i -- )
	{
	  cout << string ( (lado-1)/2-i+1 , ' ' ) << string (cnt , '*') << endl;
	  cnt -= 2;

	}
    }
  return 0 ; 
}
