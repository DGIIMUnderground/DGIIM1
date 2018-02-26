/*

	José L. Ruiz Benito
	
	Ejercicio 5.6. String
	Lee los nombres de dos personas y los ordena alfabéticamente
	
	Utilizo vector de string porque sí.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//En este caso no es necesario usar un algoritmo de ordenación de vectores porque solo hay dos elementos, pero muestro como se haría en caso de que hubiese más elementos.

void Burbuja(vector<string> & vs)
{
	for (int i=vs.size()-1; i>0; i--)
	{
		for (int j=0; j<i; j++)
		{
			if (vs.at(j) > vs.at(j+1) )
			{
				string aux;
				aux = vs.at(j);
				vs.at(j) = vs.at(j+1);
				vs.at(j+1) = aux;
			}
		}
	}
}

void Mostrar_vector(vector<string> vs)
{
	for (int i=0; i<vs.size(); i++)
	{
		cout << vs.at(i) << endl;
	}
}

int main()
{
	vector<string> nombres(2);
	
	cout << "Nombre de la primera persona: ";
	getline(cin, nombres.at(0));
	
	cout << "Nombre de la segunda persona: ";
	getline(cin, nombres.at(1));
	
	Burbuja(nombres);
	
	Mostrar_vector(nombres);
}
