/*

	José L. Ruiz
	* 
	*Ejercicio 7.4. Tema "Funciones con cadenas y vectores"
	* Programa al que se introduce un polinomio y ofrece las opciones de evaluar el polinomio en un punto, derivarlo, calcular máximo en un intervalo y calcular raíz en un intervalo.

*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//Lee los coeficientes de un polinomio
void Leer_polinomio(vector<double> & p)
{
	int grado;
	cout << "Grado del polinomio: ";
	cin >> grado;
	
	double coeficiente;
	
	cout << "Introducir coefiecientes: ";
	for (int i=grado; i>=0; i--) //ejemplifica como deben ser introducidos los coeficientes
	{
		cout << "x^" << i << " ";
	}
	cout << endl;
	
	for (int i=0; i<=grado; i++)
	{
		cin >> coeficiente;
		p.push_back(coeficiente);
	}
}

//Escribe un polinomio:
void Escribir_polinomio(const vector<double> & p)
{
	for (int i=0; i<p.size(); i++)
	{
		cout << " + " << p.at(i) << "x^" << p.size()-1-i;
	}
	cout << endl;
}

//Devuelve el valor del polinomio en un punto
double Evaluar_polinomio( const vector<double> & p, const double punto)
{
	double valor=0;
	
	for(int i=0; i<p.size(); i++)
	{
		valor = valor + p.at(i)*pow(punto, p.size()-1-i);
	}
	
	return valor;
	
}

//se ejecuta al seleccionar la opción 1. escribe en la salida estándar y se sirve de Evaluar_polinomio para hacer los cálculos
void Opcion_Evaluar_polinomio( const vector<double> & p)
{	
	double punto;
	cout << "Punto en el que se evaluará el polinomio: ";
	cin >> punto;
	
	double valor = Evaluar_polinomio(p, punto);
	
	cout << "Valor del polinomio en el punto: " << valor << endl;	
}

//Escribe la derivada del polinomio
void Opcion_Derivada( const vector<double> & p)
{
	vector<double> derivado;
	
	double termino;
	
	for (int i=0; i<p.size()-1; i++) //llega hasta size()-1 porque el termino independiente desaparece.
	{
		termino = p.at(i) * (p.size()-1-i); //multiplico el coeficiente por el exponente.
		derivado.push_back(termino);
	}
	
	cout << "La derivada del polinomio es: ";
	Escribir_polinomio(derivado);
}

//Escribe el máximo que alcanza un polinomio en un intervalos
void Opcion_Maximo( const vector<double> & p)
{
	double izq, der;
	cout << "Introducir los extremos del intervalo (extremo_izquiero extremo_derecho): ";
	cin >> izq >> der;
	
	int cant;
	cout << "Número de puntos a muestrear en ese intervalo: ";
	cin >> cant;
	
	double punto, valor;
	double valor_max=0;
	double punto_max;
	
	for(int i=0; i<=cant; i++)
	{
		punto = izq + i*(der/cant);
		valor = Evaluar_polinomio(p, punto);
		
		if (valor > valor_max)
		{
			valor_max = valor;
			punto_max = punto;
		}
	}
	
	cout << "El máximo del polinomio en el intervalo [" << izq << "," << der << "] es " << valor_max << " y lo alcanza en el punto " << punto_max << "." << endl;
}

//Escribe la raíz de un polinomio en un intervalo usando el algoritmo de bisección
void Opcion_Raiz(const vector<double> p)
{
	double izq, der;
	
	cout << "Intervalo en el que se buscará la raíz (extremo_izquiero extremo_derecho): ";
	cin >> izq >> der;
	while( Evaluar_polinomio(p, izq)*Evaluar_polinomio(p, der) > 0)
	{
		cout << "No se conoce si el polinomio tiene raíz en el intervalo. Introduzca un intervalo en el que cambie de signo: ";
		cin >> izq >> der;
	}
	
	double error;
	cout << "Error máximo en el cálculo de la raíz: ";
	cin >> error;
	
	while ( error > abs( Evaluar_polinomio(p, izq) - Evaluar_polinomio(p, der) ) )
	{
		if ( Evaluar_polinomio(p, izq)*Evaluar_polinomio( p, (izq+der)/2 ) < 0)
		{
			der = (izq+der)/2;
		}
		else
		{
			izq = (izq+der)/2;
		}
	}
	
	double raiz = (izq+der)/2;
	
	cout << "Raiz del polinomio: " << raiz << endl;
	
}

int main()
{
	cout << "BIENVENIDO A UN PROGRAMA QUE NO SIRVE PARA NADA" << endl << endl;
	
	vector<double> polinomio;
	
	Leer_polinomio(polinomio);
	
	cout << "Polinomio leído: ";
	Escribir_polinomio(polinomio);
	
	int opcion;
	
	do{
		cout << "\nMenú: \n\t0. Salir \n\t1. Evaluar en un punto  \n\t2. Derivar polinomio \n\t3. Calcular máximo en un intervalo"
			"\n\t4. Calcular raíz en un intervalo conocido \nElija una opción: ";
		cin >> opcion;
		
		switch(opcion)
		{
			case 0:
				cout << "Saliendo..." << endl;
				break;
			
			case 1:
				Opcion_Evaluar_polinomio(polinomio);
				break;
				
			case 2:
				Opcion_Derivada(polinomio);
				break;
				
			case 3:
				Opcion_Maximo(polinomio);
				break;
				
			case 4:
				Opcion_Raiz(polinomio);
				break;
				
			default:
				cout << "Opción no válida" << endl;
				break;
		}
				
	}while(opcion!=0);
}
