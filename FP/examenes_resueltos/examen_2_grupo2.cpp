#include <iostream>
#include <vector>

using namespace std;

void Leer_vector(vector<int> & v)
{
	int elemento;
	cin >> elemento;
	
	while(elemento >= 0 )
	{
		v.push_back(elemento);
		cin >> elemento;
	}
}

void Ordenar_burbuja(vector<int> & v)
{
	for (int i=v.size()-1; i>0; i--)
	{
		for (int j=0; j<i; j++)
		{
			if( v.at(j) > v.at(j+1) )
			{
				int aux = v.at(j);
				v.at(j) = v.at(j+1);
				v.at(j+1) = aux;
			}
		}
	}
}

int Mediana(const vector<int> & v)
{
	int posicion = (v.size()-1)/2;
	
	return v.at(posicion);
}

int main()
{
	vector<int> datos;
	
	cout << "Introducir datos: ";
	Leer_vector(datos);
	
	Ordenar_burbuja(datos);
	
	int mediana = Mediana(datos);
	
	cout << "La mediana es: " << mediana << endl;
}
