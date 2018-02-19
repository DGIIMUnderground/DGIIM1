/*4. Haz un programa que lea el número de elementos (como máximo 100) para un array
(vector-c) y un conjunto de números enteros y los guarde en un array y lo invierta,
mostrando el resultado. Si la secuencia introducida es 1, 100, 34, 48, 53, entonces
el resultado final mostrado debe ser 53, 48, 34, 100, 1. El programa contendrá las
siguientes funciones:
• La función main para probar que todo funciona de forma correcta.
• La función imprimirArray para mostrar en la salida estándar el número de elementos
(y un salto de lı́nea a continuación) y los elementos de un array de enteros (separados
por espacios en blanco).
• La función leerArray para leer de la entrada estándar los elementos de un array.
Para ello recibe como parámetro un array de enteros, su dimensión y el número de
elementos finalmente leı́dos (este último parámetro se pasa por referencia).
• La función invertirArray que reciba un array de enteros y el número de elementos
útiles del array, e invierta el array de entrada (sin usar ningún otro array auxiliar).
* 
* José L. Ruiz
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

void invertirArray( int v[], const int & utiles){
	for(int i=0; i<utiles/2; i++){
		int aux = v[i];
		v[i] = v[utiles-1-i];
		v[utiles-1-i] = aux;
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
	
	//INVERTIR EL ARRAY
	clog << "Invirtiendo elementos del vector..." << endl;
	
	invertirArray(numeros, util_numeros);
	
	cout << "El vector invertido es: " << endl;
	imprimirArray(numeros, util_numeros);
}
