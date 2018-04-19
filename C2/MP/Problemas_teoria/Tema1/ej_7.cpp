/* Haz un programa que lea una serie de números enteros (como máximo 100) y que elimine
los elementos repetidos guardándolos en un nuevo array.
El algoritmo empleado para eliminar los elementos repetidos consistirá en recorrer suce-
sivamente el array a partir de la posición 1, buscando si el elemento actual está en el sub-
array que comienza en la posición 0 y acaba en la posición anterior a la actual. Si es ası́,
lo borraremos desplazando hacia la izquierda todos los elementos siguientes al elemento
actual. Como puede verse, podemos hacer uso de la función busquedaSecuencialArray
que hicimos en el ejercicio anterior.
El programa contendrá las siguientes funciones:
• La función main para probar que todo funciona de forma correcta.
• La función imprimirArray para mostrar en la salida estándar el número de elementos
(y un salto de lı́nea a continuación) y los elementos de un array de enteros (separados
por espacios en blanco).
• La función leerArray para leer de la entrada estándar los elementos de un array.
Para ello recibe como parámetro un array de enteros, su dimensión y el número de
elementos finalmente leı́dos (este último parámetro se pasa por referencia).
• La función eliminarRepetidosArray para eliminar los elementos repetidos de un
array. Recibe el array de entrada, su número de elementos útiles, el array de salida
y el número de elementos útiles del array de salida (este último por referencia).
Haz una segunda versión de la función (eliminarRepetidosArray2) para eliminar los
elementos repetidos de forma que la eliminación se haga sobre el mismo array de entrada,
sin usar un segundo array auxiliar.

José L. Ruiz
*/

#include <iostream>

using namespace std;

void leerArray( int v[], const int & utiles){
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

/**
 * @brief Determina si un elemento existe en un subvector
 * @param elemento: elemento que se buscará
 * @param v[]: vector
 * @param p: primera posicion del subvector
 * @param q: ultima posicion del subvector
 * @return true si elemento se encuentra en el subvector, false en otro caso
 * @pre p y q deben ser índices que se encuentren en la zona válida del vector
 */
bool ExisteElemento( const int & elemento, const int v[], const int & p, const int & q){
	bool existe = false;
	for (int i=p; i<=q && !existe; i++)
		if ( v[i] == elemento)
			existe = true;
	return existe;
}

void EliminarRepetidosArray( const int v[], const int & util_v, int w[], int & util_w){
	util_w = 1;
	w[0] = v[0];
	for (int i = 1; i<util_v; i++)
		if ( !ExisteElemento(v[i], v, 0, i-1) ){
			w[util_w] = v[i];
			util_w++;
		}	
}

void EliminarRepetidosArray2(int v[], int & util_v){
	for (int i=1; i<util_v; ){
		if ( ExisteElemento(v[i], v, 0, i-1) ){
			for (int j=i; j< util_v-1; j++)
				v[j] = v[j+1];
			util_v--;
		}
		else
			i++;
	}
}

int main(){
	const int TAMANO = 100;
	int numericos[TAMANO];
	int util_numericos;
	
	cout << "Número de elementos que se introducirán: ";
	cin >> util_numericos;
	while (util_numericos > 100){
		cerr << "No pueden introducirse más de 100 elementos" << endl;
		cout << "Número de elementos que se introducirán: ";
		cin >> util_numericos;
	}
	
	cout << "Intruducir elementos:" << endl;
	leerArray(numericos, util_numericos);
	
	clog << "El vector leído es:" << endl;
	imprimirArray(numericos, util_numericos);
	
	//UTILIZO EliminarRepetidosArray:
	clog << "Aplicando la función 1..." << endl;
	int sin_repetir[TAMANO];
	int util_sin_repetir;
	EliminarRepetidosArray(numericos, util_numericos, sin_repetir, util_sin_repetir);
	cout << "Sin repetir: " << endl;
	imprimirArray(sin_repetir, util_sin_repetir);
	
	//UTILIZO EliminarRepetidosArray2:
	clog << "Aplicando la función 2..." << endl;
	EliminarRepetidosArray2(numericos, util_numericos);
	cout << "Sin repetir: " << endl;
	imprimirArray(numericos, util_numericos);
}
