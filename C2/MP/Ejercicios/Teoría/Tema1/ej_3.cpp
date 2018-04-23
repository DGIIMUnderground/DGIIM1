/* 3. Haz un programa que lea el número de elementos (como máximo 100) para un array
(vector-c) y un conjunto de números enteros y los guarde en un array. Luego debe pedir
que se introduzca un número entero y mostrará la posición donde el número entero se
encuentra en el anterior array (o -1 si no está). El algoritmo consiste en una búsqueda
secuencial. El programa contendrá las siguientes funciones:
• La función main para probar que todo funciona de forma correcta.
• La función imprimirArray para mostrar en la salida estándar el número de elementos
(y un salto de lı́nea a continuación) y los elementos de un array de enteros (separados
por espacios en blanco).
• La función leerArray para leer de la entrada estándar los elementos de un array.
Para ello recibe como parámetro un array de enteros, su dimensión y el número de
elementos finalmente leı́dos (este último parámetro se pasa por referencia).
• La función busquedaSecuencialArray que reciba un dato entero a buscar, un array
de enteros, y dos enteros (ı́ndices inicial y final del array donde buscar el dato) y
devuelva la posición donde el número entero se encuentra en el anterior array (o -1
si no está)

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

int busquedaSecuencialArray( const int & dato, const int v[], const int & p1, const int & p2 ){
	int posicion = -1;
	for (int i = p1; i<=p2 && posicion == -1; i++)
		if ( dato == v[i] )
			posicion = i;
	
	return posicion;
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
	
	//BUSCAR UN DATO EN EL ARRAY
	int dato;
	cout << "Introducir dato que se buscará en el vector: ";
	cin >> dato;
	
	int p1, p2;
	cout << "Introducir posiciones entre las que se buscará el dato: ";
	cin >> p1 >> p2;
	while ( p1 < 0 || p2 >= util_numeros || p1 > p2 ){
		cerr << "Error. No sea idiota e introduzca valores válidos" << endl;
		cout << "Introducir posiciones entre las que se buscará el dato: ";
		cin >> p1 >> p2;
	}
	
	int posicion_dato = busquedaSecuencialArray(dato, numeros, p1, p2);
	
	if (posicion_dato != -1 )
		cout << "El dato introducido se encuentra en la posición " << posicion_dato << endl;
	else
		cout << "El dato no se encuentra en el vector" << endl;
}
