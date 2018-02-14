/*
 1. (2.5 puntos) Deseamos implementar un módulo que, dada una secuencia de dı́gitos de longitud arbitraria, calcule
un dı́gito de control. Este dı́gito se utiliza para la detección de errores en la transmisión de dicha secuencia. En
concreto, debes realizar un módulo que reciba una secuencia de caracteres (cada uno de ellos será un dı́gito del
’0’ al ’9’) y que devuelva un carácter con el dı́gito de control (también del ’0’ al ’9’). El algoritmo utilizado
será el siguiente: sumar los dı́gitos de las posiciones impares (SI), sumar los dı́gitos de las posiciones pares (SP)
y calcular S = SP + 3 * SI. El dı́gito de control será la diferencia entre la decena inmediatamente superior a S
y S. Si esa diferencia es diez entonces el dı́gito de control será cero. Por ejemplo:
Secuencia de dı́gitos 1738603229867591209: (SI=1+3+6+3+2+8+7+9+2+9=50,
SP=7+8+0+2+9+6+5+1+0=38, S=38+3*50=188). DC=190-188=2
Secuencia de dı́gitos 19473819: (SI=1+4+3+1=9, SP=9+7+8+9=33, S=33+3*9=60). DC=70-60=10 ⇒
DC=0
* 
* José L. Ruiz
 */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/**
 * @brief Valida una secuencia, devuelve otra que contenga sólo dígitos del 0 al 9
 */
string Valida( const string & sec)
{
	string sec_valida;
	
	for (int i = 0; i<sec.size(); i++)
	{
		char c = sec[i]; //me da palo escribir sec[i] tol rato
		
		if ( c=='0' || c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c=='8' || c=='9' )
		{
			sec_valida += c; //añado a sec_valida
		}
	}
	
	return sec_valida;	
}

/**
 * @brief Calcula el dígito de control de un vector de char
 */
char DigitoControl( const string & v)
{
	char digito_control;
	
	int SI=0; //suma de los dígitos de las posiciones impares
	int SP=0; //suma de los dígitos de las posiciones pares
	
	for(int i=0; i<v.size(); i++)
	{
		int sumando = v[i]-'0'; // el resto el código ascii del '0' para que de el valor del dígito como int
		
		if( (i+1)%2 == 0) // si la posición es par
		{
			SP = SP + sumando;
		}
		else //si la posición es impar
		{
			SI = SI + sumando;
		}
	}
	
	int S = SP + 3*SI;
	
	digito_control = (10 - (S%10) ) + '0'; //le sumo el código ascii del '0' para tenerlo como carácter
	
	return digito_control;
}

int main()
{
	string secuencia;
	
	cout << "Introduzca secuencia (de dígitos): ";
	getline(cin, secuencia);
	
	string secuencia_valida = Valida(secuencia);
	
	cout << "El dígito de control es: " << DigitoControl(secuencia_valida) << endl;
}

//¡¡¡funciona!!! ;)
