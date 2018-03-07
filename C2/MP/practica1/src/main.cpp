/**
 * @file central.cpp
 * @author MP - DGIM - Grupo A, Ana Martínez Sabiote
**/


#include <iostream>
#include "intervalo.h"
using namespace std;

int main()
{
	int nintervalos;
	Intervalo vacio;
	Intervalo punto(1,1);
	Intervalo interv[10];

	// Lectura de datos 
	cout << endl<< "Cuantos intervalos se van a introducir? (max 10):";
	do{
		cin >> nintervalos;
	} while (nintervalos >10);

	cout << endl << "Introduce [ o ( cotaInferior, cotaSuperior ) o ]";
	for(int i=0; i < nintervalos; i++)
		leer(interv[i]);

	// Comprobaciones
	cout << endl << "Comprobando intervalo vacio"<< endl;
	escribir(vacio);
	if (vacio.esVacio())
		cout << " Es vacío " << endl;
	else
		cout << " No es vacío " << endl;
	escribir(punto);
	if (punto.esVacio())
		cout << " Es vacío " << endl;
	else
		cout << " No es vacío " << endl;

	// Dado un conjunto de valores −1, −0.001, 0, 5.7, 9.6, 10
	double v[]= {-1, -0.001, 0, 5.7, 9.6, 10};
	int numvalores = 6;
	cout << endl;
	for(int i=0; i < nintervalos; i++){
		escribir(interv[i]);
		cout << endl << "Valores dentro del intervalo:";
		for (int j= 0; j < numvalores; j++){
			if (interv[i].estaDentro(v[j]))
				cout << v[j] <<" ";
		}
		cout << endl << "Valores fuera del intervalo:";
		for (int j= 0; j < numvalores; j++){
			if (!interv[i].estaDentro(v[j]))
				cout << v[j] <<" ";
		}
		cout << endl;
	}
	return 0; 
}
