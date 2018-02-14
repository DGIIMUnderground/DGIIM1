/*
  TRIÁNGULO RARO (tartaglia mola más)
Blanca Cana
Realizar un programa que lea desde el teclado un numero entero n mayor que cero y muestre las n
primeras filas del siguiente triangulo:
             1
            232
           34543
          4567654
         567898765
        67890109876
       7890123210987
      890123454321098
     90123456765432109
    0123456789876543210
   123456789010987654321
  23456789012321098765432
 3456789012345432109876543


.....................
  Granada 7/11/17
 
 */

#include<iostream>

using namespace std;

int main()
{
  int filas;
  cout << "Introduzca el número de filas para el triángulo: ";
  cin >> filas;

  string izquierda,derecha,espacio;
  char ch;
  espacio = string ( 10 , 'a');
  cout << espacio;
  
  espacio = string ( filas , ' '); //fución para repetir un carácter :D
  
  for ( int i = 1 ; i <= filas ; i++)
    {
      derecha = "";
      izquierda = "";
      
      for( int j = i ; j < i + i - 1  ; j++ )
	{
	  ch = static_cast<char>( j % 10 + 48); //entro a ascci (su número módulo 10 )
	  izquierda += ch;
	  derecha = ch + derecha;  
	}
      ch = static_cast<char>(( i+i-1 )%10 + 48 );
      cout << endl << espacio << izquierda << ch << derecha ;

      espacio = string(filas-i , ' ');

           
    }

  cout << endl;
 
  

  
  return 0;
}
