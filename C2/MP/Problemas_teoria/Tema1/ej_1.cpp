/*
Haz un programa que lea de la entrada estándar el número de elementos que tendrá un array de enteros, y dos enteros para el rango (mínimo, máximo) de posibles valores que
tomarán los elementos del array. El programa rellenará el array con números aleatorios enteros en el rango proporcionado, y posteriormente lo mostrará en la salida estándar.
Autor: Manuel Gachs Ballegeer
*/

#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

/**
	@brief: Rellena un array con valores pseudoaleatorios.
	@param a_enteros: Array a rellenar. ES MODIFICADO
	@param n_elementos: Nº de elementos a rellenar.
	@param min: Mínimo de los posibles valores del array.
	@param max: Máximo de los posibles valores del array.
*/
void generarArray(int a_enteros[], int n_elementos, int max, int min);

/**
	@brief: Muestra en la salida estándar los componentes de un array y su numero de elementos.
	@param a_enteros: Array a mostrar.
	@param n_elementos: Nº de elementos del array.
*/
void imprimirArray(const int a_enteros[], int n_elementos);

void generarArray(int a_enteros[], int n_elementos, int max, int min) {
	
	srand((int) time(0));
	
	for (int i=0; i<n_elementos-1;i++) {
		
		int aux = rand() % max + min;
		a_enteros[i] = aux;
	}
}

void imprimirArray(const int a_enteros[], int n_elementos) {
	
	cout << "\nNumero de elementos: " << n_elementos << endl;
	
	for (int i=0; i<n_elementos-1; i++)
		cout << a_enteros[i] << " ";
}

int main(int argc, char* argv[]) {
	
	int min, max, n_elementos;
	
	cout << "Introduce el numero de elementos: ";
	cin >> n_elementos;
	
	static_cast<const int> (n_elementos);
	int a_enteros[n_elementos];
	
	do{
		
		cout << "Introduce el minimo y el maximo de posibles valores: ";
		cin >> min >> max;
	}while(max<min);
	
	generarArray(a_enteros,n_elementos,max,min);
	imprimirArray(a_enteros,n_elementos);
	
}
