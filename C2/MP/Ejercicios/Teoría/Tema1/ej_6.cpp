/* Haz un programa que lea el número de elementos (como máximo 100) para un array
(vector-c) y un conjunto de números enteros ordenados de menor a mayor y los guarde en
un array. Luego debe pedir que se introduzca un número entero y mostrará la posición
donde el número entero se encuentra en el anterior array (o -1 si no está). El algoritmo
a seguir será el de búsqueda binaria.

José L. Ruiz
*/

#include <iostream>

using namespace std;

void leerArrayOrdenado( int v[], const int & dimension, const int & utiles){
	cout << "Elemento " << 0 << " : ";
	cin >> v[0];
	for (int i=1; i<utiles; i++){
		cout << "Elemento " << i << " : ";
		cin >> v[i];
		while(v[i] < v[i-1]){
			cerr << "Error, el vector debe estar ordenado de menor a mayor. Introduzca un elemento mayor o igual al anterior" << endl;
			cout << "Elemento " << i << " : ";
			cin >> v[i];
		}
	}
}

void imprimirArray(const int v[], const int & utiles){
	cout << "Número de elementos del vector: " << utiles << endl;
	cout << "Elementos: ";
	for (int i=0; i<utiles; i++)
		cout << v[i] << "  ";
	cout << endl;
}

int BusquedaBinaria( const int a_buscar, const int v[], const int & utiles){
	int izq=0;
	int der=utiles-1;
	int central = (izq+der)/2;
	int posicion = -1;
	
	while(posicion == -1 && izq!=der){
		if ( v[central] == a_buscar )
			posicion = central;
		else{
			if( a_buscar < v[central])
				der = central;
			else
				izq = central;
			central = (izq+der)/2;
		}
	}
	return posicion;
}

int main(){
	const int TAMANO = 100;
	int numeros[TAMANO];
	int util_numeros;
	
	//LECTURA DEL ARRAY
	cout << "¿Cuántos datos va a introducir? ";
	cin >> util_numeros;
	while ( util_numeros > TAMANO){
		cerr << "Error. No se pueden introducir más de 100 datos" << endl;
		cout << "¿Cuántos datos va a introducir? ";
		cin >> util_numeros;
	}	
	leerArrayOrdenado(numeros, TAMANO, util_numeros);
	
	//MUESTRO EL ARRAY LEÍDO
	clog << "El vector leído es" << endl;
	imprimirArray(numeros, util_numeros);
	
	//BUSCO UN ELEMENTO
	int a_buscar;
	cout << "Introducir elemento que se desea buscar: ";
	cin >> a_buscar;
	int posicion = BusquedaBinaria(a_buscar, numeros, util_numeros);
	if ( posicion != -1 )
		cout << "El elemento " << a_buscar << " se encuentra en la posición " << posicion << endl;
	else
		cout << "El elemento " << a_buscar << " no se encuentra en el vector introducido" << endl;
	
}
