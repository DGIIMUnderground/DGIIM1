/*

EXAMEN FP GRUPO 1. NOVIEMBRE DE 2017

Calcula número racional aproximado a pi

by José L. Ruiz

*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	const double PI=3.14159265358979323846;
	
	int cifras;
	
	double numerador_d, denominador_d; //numerador y denominador como reales.
	int numerador, denominador; // numerador y denominador como enteros.
	
	double error=PI, error_temp;
	
	do{
	
		cout << "Introducir número de cifras del numerador: ";
		cin >> cifras;
	
		if(cifras<1 || cifras>5){
			cout << "Error. El número de crifras debe encontrarse entre 1 y 5" << endl;
		}
		
	}while(cifras<1 || cifras>5);
	
	numerador=pow(10, cifras-1);
	denominador=1;
	
	for(int i=numerador; i<=pow(10, cifras)-1; i++)
	{
		for(int j=denominador; j<i; j++)
		{
			numerador_d=i;
			denominador_d=j;
			
			if(PI-numerador_d/denominador_d>0)
			{
				error_temp=PI-numerador_d/denominador_d;
			}
			else
			{
				error_temp=numerador_d/denominador_d-PI;
			}
			
			if(error_temp<error){
				error=error_temp;
				numerador=i;
				denominador=j;
			}
			
		}
	}
	
	cout << numerador << "/" << denominador << "\nEl error cometido es: " << error << endl;
}
