/*
 * Ejercicio 6.1.
 * Desarrollar un programa que calcule el máximo y el mínimo de un conjunto de números reales (se leerá previamente un entero que indique el número de datos).
 * Como restricción, no se podrá declarar ningún objeto que no sea puntero.

jruib
 */

#include <iostream>

using namespace std;

void LecturaArrayInt( int * p, int n){
	for ( int i=0; i<n; i++)
		cin  >> p[i];
}

int * MaxArrayInt( int * p, int n){
	int * pmax = p;
	for ( int i=1; i<n; i++)
		if ( p[i] > *pmax )
			pmax = p + i;
	return pmax;
}

int * MinArrayInt( int * p, int n){
	int * pmin = p;
	for ( int i=1; i<n; i++)
		if ( p[i] < *pmin )
			pmin = p + i;
	return pmin;
}

int main(){
	int *pdatos, ndatos;
	cout << "Número de datos que se introducirán: ";
	cin >> ndatos;
	pdatos = new int[ndatos];
	cout << "Introduzca datos: ";
	LecturaArrayInt(pdatos, ndatos);
	
	cout << "El máximo es: " << *MaxArrayInt(pdatos, ndatos) << endl << "El mínimo es: " << *MinArrayInt(pdatos, ndatos) << endl;
	
	delete [] pdatos;
}
