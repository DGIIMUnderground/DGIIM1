/* 5. Haz un programa que lea el número de elementos (como máximo 100) para un array
(vector-c) y un conjunto de números enteros y los guarde en un array. Luego debe
ordenar el array con el algoritmo de ordenación por selección y mostrará el array
ya ordenado en la salida estándar. Este algoritmo consiste en recorrer el array a partir
de la posición 0, repitiendo sucesivamente los siguientes pasos:
4(a) Buscar el elemento más pequeño del array (desde posición actual hasta el final).
(b) Intercambiar el elemento más pequeño con el elemento de la posición actual.
Fı́jate, que puedes usar el método buscarMinimoArray implementado en un ejercicio
anterior para hacer el paso a).
El programa contendrá las siguientes funciones:
• La función main.
• La función imprimirArray para mostrar en la salida estándar el número de elementos
(y un salto de lı́nea a continuación) y los elementos de un array de enteros (separados
por espacios en blanco).
• La función leerArray para leer de la entrada estándar los elementos de un array.
Para ello recibe como parámetro un array de enteros, su dimensión y el número de
elementos finalmente leı́dos (este último parámetro se pasa por referencia).
• La función buscarMinimoArray que reciba un array de enteros, y dos enteros (ı́ndices
inicial y final del array donde buscar el mı́nimo) y devuelva la posición donde se
encuentra el mı́nimo elemento del subarray que comienza en la posición inicial y
acaba en la posición final (ambas inclusive).
• La función ordenarporSeleccion que reciba un array de enteros y lo ordene de
menor a mayor con el método de selección.

José L. Ruiz
*/

#include <iostream>

using namespace std;

void leerArray( int v[], const int & dimension, const int & utiles){
	for (int i=0; i<utiles; i++){
		cout << "Elemento " << i << " : ";
		cin >> v[i];
	}
}

void imprimirArray(const int v[], const int & utiles){
	cout << "Número de elementos del vector: " << utiles << endl;
	cout << "Elementos: ";
	for (int i=0; i<utiles; i++)
		cout << v[i] << "  ";
	cout << endl;
}

int buscarMinimoArray( const int v[], const int & p1, const int & p2){
	int minimo = v[p1];
	int pos_min = p1;
	for (int i=p1+1; i<p2; i++)
		if ( v[i] < minimo){
			minimo = v[i];
			pos_min = i;
		}
	return pos_min;
}

void ordenarPorSeleccion( int v[], const int & utiles){
	for (int i=0; i<utiles; i++)
		for(int j=i+1; j<utiles; j++){
			int pos_min = buscarMinimoArray(v, j, utiles);
			if ( v[i] > v[pos_min] ){
				int aux = v[i];
				v[i] = v[pos_min];
				v[pos_min] = aux;
			}
		}
}

int main(){
	const int TAMANO = 100;
	int numeros[TAMANO];
	int util_numeros;
	
	//LECTURA DEL ARRAY
	cout << "¿Cuántos datos va a introducir? ";
	cin >> util_numeros;
	while ( util_numeros > 100){
		cerr << "Error. No se pueden introducir más de 100 datos" << endl;
		cout << "¿Cuántos datos va a introducir? ";
		cin >> util_numeros;
	}	
	leerArray( numeros, TAMANO, util_numeros);
	
	//MOSTRAR EL ARRAY
	cout << "El vector introducido es: " << endl;
	imprimirArray(numeros, util_numeros);
	
	//ORDENAR EL ARRAY
	clog << "Ordenando vector..." << endl;
	ordenarPorSeleccion( numeros, util_numeros);
	cout << "El vector ordenado es: " << endl;
	imprimirArray(numeros, util_numeros);
}
