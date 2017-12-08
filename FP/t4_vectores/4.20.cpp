/*

Ejercicio 4.20: Escriba un programa que lea un número positivo y escriba su descomposición en números primos. El progama almacenará la descomosición en un vector.	

*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> Descomponer(int n)
{
	vector<int> descomposicion(0);
	
	for (int divisor=2; divisor<=n; )
	{
		if(n%divisor==0)
		{
			descomposicion.push_back(divisor);
			
			n=n/divisor;
		}
		else
		{
			divisor++;
		}
	}
	
	return descomposicion;
}

void Mostrar_vector(const vector<int> & v)
{
	for (int i=0; i<v.size(); i++)
	{
		cout << v.at(i) << "  ";
	}
	
	cout << endl;
}

int main()
{
	int n;
	
	cout << "Introducir número: ";
	cin >> n;
	
	vector<int> descomposicion = Descomponer(n);
	
	cout << "Descomposición: ";
	Mostrar_vector(descomposicion);
}
