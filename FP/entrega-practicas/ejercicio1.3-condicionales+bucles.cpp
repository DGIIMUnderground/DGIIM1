/*
Autor: José Luis Ruiz Benito. 1º DGIIM.
Fecha: 27/10/2017

Descripción:
	Entrada:
		Círculo de confusión: c
		Longitud focal: f
		Distancia de enfoque: d
		Número f: N

	Salida:
		Hiperfocal: H
		Distancia mínima de la zona enfocada: dmin
		Distancia máxima de la zona enfocada: dmax
		Profundidad de campo: p

Versión: 2: Utilizo bucles do-while para comprobar los datos de entrada y solicitarlos de nuevo en caso de error.

*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	cout << "NOTA: Los parámetros deben introducirse en milímetros\n" << endl;
	
	double c, f, d, N; //parámetros de entrada
	bool rc, rf, rd, rN; //rango de los parámetros.

	do{
		cout << "Introduzca el círculo de confusión (0.001 a 1): ";
		cin >> c;
		
		//Comprobación y notificación de error:
		rc = (c>=0.001 && c<=1);
		if(!rc)
			cout << "Círculo de confusión erróneo." << endl;
	}while(!rc);
		
	do{
		cout << "Introduzca la longitud focal (5 a 2000) y la distancia de enfoque (>= 1): ";
		cin >> f >> d;

		//En caso de que la distancia de enfoque sea menor que la longitud focal intarcambio sus valores:
	
		if(d<f){
			double tempf; //variable temporal en la que almacenar el valor de f.
			tempf=f;
			f=d;
			d=tempf;

			cout << "Intercambiadas distancia de enfoque y longitud focal." << endl;
		}

		//Comprobación y notificación de errores:
		rf = (f>=5 && f<=2000);
		if(!rf)
			cout << "Longitud focal errónea." << endl;
		
		rd = (d>=1);
		if(!rd)
			cout << "Distancia de enfoque errónea." << endl;
		
	}while(!rf || !rd);
		
	do{
		cout << "Introduzca el número f (0.5 a 64): ";
		cin >> N;
		
		//Comprobación y notificación de error:
		rN = (N>=0.5 && N<=64);		
		if(!rN)
			cout << "Número f erróneo." << endl;
	}while(!rN);
	

	double H, dmin, dmax, p; //parámetros de salida

	//CÁLCULO de los parámetros de salida:
	
	H = (f*f)/(N*c)+f;
	dmin = (d*(H-f))/(H+d-2*f);
	dmax = (d*(H-f))/(H-d);
	p = dmax-dmin;

	//SALIDA DEL PROGRAMA:

	cout << "\nResultados: " << endl;

	if(H>=0)
		cout << "Hiperfocal: " << H << endl;
	if(dmin>=0)
		cout << "Distancia mínima de la zona enfocada: " << dmin << endl;
	if(dmax>=0){
		cout << "Distancia máxima de la zona enfocada: " << dmax << endl;
	}
	else{
		cout << "Distancia máxima de la zona enfocada: infinito" << endl;
	}
	if(p>=0){
		cout << "Profundidad de campo: " << p << endl;
	}
	else{
		cout << "Profundidad de campo: infinito " << endl;
	}
	cout << "\n";
}
