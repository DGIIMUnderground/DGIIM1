/*
2. Haz un programa que lea el número de elementos (como máximo 100) para un array
(vector-c) y un conjunto de números enteros y los guarde en un array e indique cuál
es el menor de todos. Debe incluirse un programa principal (main) para probar las
funciones implementadas. El programa contendrá las siguientes funciones:
• La función main para probar que todo funciona de forma correcta.
• La función imprimirArray para mostrar en la salida estándar el número de elementos
(y un salto de lı́nea a continuación) y los elementos de un array de enteros (separados
por espacios en blanco).
• La función leerArray para leer de la entrada estándar los elementos de un array.
Para ello recibe como parámetro un array de enteros, su dimensión y el número de
elementos útiles finalmente leı́dos (este último parámetro se pasa por referencia).
• La función buscarMinimoArray que reciba un array de enteros, y dos enteros (ı́ndices
inicial y final del array donde buscar el mı́nimo) y devuelva la posición donde se
encuentra el mı́nimo elemento del subarray que comienza en la posición inicial y
acaba en la posición final (ambas inclusive).

FALTA POR HACER:
También podrı́amos ejecutar este programa redireccionando la entrada estándar a partir
del fichero datos1.txt que se generó en el ejercicio 1, y ası́ no hay que meter manualmente
los datos mediante el teclado.


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
	for (int i=p1+1; i<=p2; i++)
		if ( v[i] < minimo){
			minimo = v[i];
			pos_min = i;
		}
	return pos_min;
}

int main(){
	const int TAMANO = 100;
	int numeros[TAMANO];
	int util_numeros;
	
	//LECTURA DEL ARRAY
	cout << "¿Cuántos datos va a introducir? ";
	cin >> util_numeros;
	leerArray( numeros, TAMANO, util_numeros);
	
	//MOSTRAR EL ARRAY
	cout << "El vector introducido es: ";
	imprimirArray(numeros, util_numeros);
	
	//CALCULAR POSICIÓN DEL MÍNIMO ELEMENTO
	int p1, p2;
	cout << "Calcular la posición del elemento mínimo entre dos posiciones";
	
	cout << "Inserte dos posiciones: ";
	cin >> p1 >> p2;
	while ( p1 < 0 || p2 > util_numeros || p1 > p2 ){
		cerr << "Error. No sea idiota e introduzca valores válidos";
		cout << "Inserte dos posiciones: ";
		cin >> p1 >> p2;
	}
	
	cout << "La posición del mínimo es: " << buscarMinimoArray(numeros, p1, p2);
}
