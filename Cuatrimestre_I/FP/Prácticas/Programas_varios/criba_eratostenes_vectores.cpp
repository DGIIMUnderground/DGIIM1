/*
 * Criba de eratośtenes mejorada: utilizo vectores.
 * 
 * Explicación del algoritmo:
 * Creamos un vector para almacenar los números primos que encontremos. Al comienzo sólo tiene el 2, el primer primo conocido.
 * Para encontrar más primos, pasamos al número natural siguiente. Si no es divisible entre los elementos del vector (números primos) menores
 * que su raíz cuadrada, lo añadimos al vector de números primos y lo mostramos.
 * 
 *José L. Ruiz
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int max;

	cout << "Calcular números primos hasta el: ";
	cin >> max;
	

	vector<int> primos; //para almacenar números primos
	primos.push_back(2); //partimos de que el 2 es el primer primo;
	
	cout << 2 << "\t"; //muestro el primer número primo
	
	bool primo; //condición  que determinará si un número es primo.
	
	for (int i=3; i<= max; i++)
	{
		primo = true; //suponemos que el número es primo y si encontramos algún divisor hacemos primo = false;
		
		//Veamos si es divisible entre los primos que ya conocemos:
		
		for (int j=0; primos[j]<=sqrt(i) && j<primos.size() ; j++) //pruebo a dividir el número entre los elementos del vector "primos" menores que su raíz cuadrada.
		{
			if ( i % primos[j] == 0)
			{
				primo = false;
				break; //ya sabemos que no es primo, no iteramos más.
			}
		}
		
		if (primo) //si no se ha encontrado ningún divisor
		{
			primos.push_back(i); //añado el número al vector de primos
			cout << i << "\t"; //muestro el número
		}
	}
	
	cout << endl << "Se han encontrado " << primos.size() << " números primos menores que " << max << endl;
}
