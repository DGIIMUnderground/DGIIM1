/*
. (2.5 puntos) Se desea implementar una clase para representar un número complejo. Un complejo se define como
un par ordenado de números reales (a, b), donde a representa la parte real y b la parte imaginaria.
a)
b)
c)
d )
Defina los atributos de la clase y el constructor o constructores que estime oportunos.
Implemente un método para la suma de dos complejos definida como (a, b) + (c, d) = (a + c, b + d)
Implemente un método para el producto de dos complejos definido como (a, b) · (c, d) = (ac − bd, ad + bc)
Implemente un método para determinar si dos complejos son iguales: (a, b) = (c, d) si y solo si a = c y
b = d.
e) Implemente un método que
p determine la distancia euclı́dea entre dos números complejos (a, b) y (c, d). La
distancia se define como (c − a) 2 + (d − b) 2 .
f ) Implemente un módulo para que dado un vector de complejos y un número complejo, devuelva la posición
en el vector del complejo más cercano.
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Complejo
{
	private:
		double real;
		double imaginaria;
		
	public:
	
		/**
		 * @brief Constructor por defecto
		 */
		Complejo()
		{
			real = 0;
			imaginaria = 0;
		}
		
		/**
		 * @brief Constructor con dos parámetros
		 */
		Complejo( double parte_real, double parte_imaginaria)
		{
			real = parte_real;
			imaginaria = parte_imaginaria;
		}
		
		Complejo operator+( const Complejo & otro_complejo) const
		{
			Complejo suma(real + otro_complejo.real, imaginaria + otro_complejo.imaginaria);
			return suma;
		}
		
		Complejo operator*( const Complejo & otro_complejo) const
		{
			Complejo producto( real*otro_complejo.real - imaginaria*otro_complejo.imaginaria, real*otro_complejo.imaginaria + real+otro_complejo.real );
			return producto;
		}
		
		bool operator==(const Complejo & otro_complejo) const
		{
			return real==otro_complejo.real && imaginaria==otro_complejo.imaginaria;
		}
		
		double Distancia(const Complejo & otro_complejo) const
		{
			return sqrt( (otro_complejo.real-real)*(otro_complejo.real-real) + (otro_complejo.imaginaria-imaginaria)*(otro_complejo.imaginaria-imaginaria) );
		}
};


/**
 * @brief Dado un vector de complejos y un número complejo, devuelve la posición en el vector del complejo más cercano.
*/
int PosicionComplejoMasCercano ( const vector<Complejo> & v, Complejo num )
{
	int posicion = 0;
	int distancia_minima = v[0].Distancia(num); //comienzo suponiendo que el más cercano será el primero
	
	for (int i=0; i<v.size(); i++)
	{
		if( v[i].Distancia(num) < distancia_minima)
		{
			posicion = i;
			distancia_minima = v[i].Distancia(num);
		}
	}
	
	return posicion;
}


int main()
{
	cout << "BIENVENIDO A LA CALSE COMPLEJO" << endl;
	
	Complejo a;
	Complejo b(1,2);
	
	if (a==b)
	{
		cout << "Son iguales" << endl;
	}
	else
	{
		cout << "No son iguales" << endl;
	}
	
	a = a+b;
	
	if (a==b)
	{
		cout << "Son iguales" << endl;
	}
	else
	{
		cout << "No son iguales" << endl;
	}
	
	b = a*a;
	
	cout << "La distancia de A a B es: " << a.Distancia(b) << endl;
	
	
	vector<Complejo> lista(3);
	Complejo c(4,5), d(5,6);
	lista[2] = c;
	
	cout << "El complejo más cercano a d en la lista ocupa la posicion: " << PosicionComplejoMasCercano(lista, d) << endl;
}
