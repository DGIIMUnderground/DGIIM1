/*
José L. Ruiz

Ejercicio 4.13 - Frecuencia de datos.
	Escriba un programa para obtener la frecuencia de los datos de entrada. El programa recibe un entero que indica el número de datos, seguido de los datos. La salida será el conjunto de datos introducidos junto a su frecuencia.


*/

#include <iostream>
#include <vector>

using namespace std;

void Lectura_vector(vector<double> & v)
{
	for (int i=0; i<v.size(); i++)
	{
		cin >> v.at(i);
	}
}

void Mostrar_vector(const vector<double> & v) //ayuda a depurar el programa.
{
	for (int i=0; i<v.size(); i++)
	{
		cout << v.at(i) << " ";
	}
	cout << endl;
}

void Ordena_burbuja(vector<double> & v)
{
	for (int i=0; i<v.size(); i++)
	{
		for (int j=i+1; j<v.size(); j++)
		{
			if ( v.at(i) > v.at(j) )
			{
				double temp = v.at(i);
				v.at(i) = v.at(j);
				v.at(j) = temp;
			}
		}
	}
}

/**
	@brief Dado un vector ordenado devuelve otro con los mismos elementos pero sin repetir ninguno
	@param v: vector del que se extraerá el vector sin elementos repetidos
	@return vector con los mismos elementos sin repetir ninguno
	@pre El vector debe estar ordenado
*/
vector<double> Sin_repetir(const vector<double> & v)
{
	vector<double> sin_repetir;
	
	double elemento = v.at(0);
	sin_repetir.push_back(elemento); //es claro que el primer elemento no está repetido.
	
	for (int i=1; i<v.size(); i++)
	{
		if(v.at(i) != elemento)
		{
			elemento = v.at(i);
			sin_repetir.push_back(elemento);
		}
	}
	
	return sin_repetir;
}

void Frecuencia(const vector<double> & v)
{
	vector<double> sin_repetir = Sin_repetir(v);
	
	for (int i=0; i<sin_repetir.size(); i++)
	{
		int frecuencia_i=0;
		
		for(int j=0; j<v.size(); j++)
		{
			if ( v.at(j) == sin_repetir.at(i) )
			{
				frecuencia_i++;
			}
		}
		cout << "Elemeto " << sin_repetir.at(i) << ": " << frecuencia_i << " veces" << endl;
	}
}

int main()
{
	int ndatos;
	cout << "¿Cuántos datos hay?  ";
	cin >> ndatos;

	vector<double> datos(ndatos);
	cout << "Introduzca datos: ";
	Lectura_vector(datos);
			//cout << "Vector leído: "; Mostrar_vector(datos);
	
	Ordena_burbuja(datos);
			//cout << "Vector ordenado: "; Mostrar_vector(datos);
			
	cout << endl << "Resultado: " << endl;
	Frecuencia(datos);
}
