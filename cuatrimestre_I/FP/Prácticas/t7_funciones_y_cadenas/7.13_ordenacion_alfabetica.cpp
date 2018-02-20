/*
	José L. Ruiz
	
	Ejercicio 7.13: Ordenación alfabética de nombres de personas, por nombre y por apellido.

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Persona //me invento este tipo de dato para no tener que crear un vector para nombres y otro para apellidos.
{
	string n; //nombre de la persona
	string a; //apellidos de la persona
};

void Mostrar_nombre( const Persona & p)
{
	cout << p.n << " " << p.a;
}

void Mostrar_vector_nombres(const vector<Persona> & g)
{
	for (int i=0; i<g.size(); i++)
	{
		Mostrar_nombre( g.at(i) );
		cout << endl;
	}
}

void Ordenar_nombre(vector<Persona> & g)
{
	for (int i=g.size()-1; i>0; i--)
	{
		for (int j=0; j<i; j++)
		{
			if ( g[j].n > g[j+1].n ) //si el nombre de j es "mayor" que el nombre de j+1
			{
				Persona aux;
				aux = g[j];
				g[j] = g[j+1];
				g[j+1] = aux;
			}
		}
	}
}

void Ordenar_apellidos(vector<Persona> & g)
{
	for (int i=g.size()-1; i>0; i--)
	{
		for (int j=0; j<i; j++)
		{
			if ( g[j].a > g[j+1].a ) //si el nombre de j es "mayor" que el nombre de j+1
			{
				Persona aux;
				aux = g[j];
				g[j] = g[j+1];
				g[j+1] = aux;
			}
		}
	}
}

int main()
{
	cout << "ORDENACIÓN ALFABÉTICA" << endl << endl;
	
	vector<Persona> gente;
	
	int contador=0; //identifica el número de persona
	
	Persona individuo;
	
	while (individuo.n != "#" )
	{
		cout << "Persona " << contador << ", nombre: ";
		getline(cin, individuo.n);
		
		if(individuo.n != "#" )
		{
			cout << "Persona " << contador << ", apellidos: ";
			getline(cin, individuo.a);
			
			gente.push_back(individuo);
			
			contador++;
		}
	}
	
	cout << "\nNombres leídos:" << endl;
	Mostrar_vector_nombres(gente);
	
	//Ordeno por nombres y muestro:
	Ordenar_nombre(gente) ;
	
	cout << "\nLa ordenación por nombre es:" << endl;
	Mostrar_vector_nombres(gente);
	
	//Ordeno por apellido y muestro:
	Ordenar_apellidos(gente);
	
	cout << "\nLa ordenación por apellidos es:" << endl;
	Mostrar_vector_nombres(gente);
}
