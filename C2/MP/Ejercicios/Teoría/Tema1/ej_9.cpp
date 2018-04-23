/*9. Implemente una función mezclarUnico de tipo int que reciba como entrada dos arrays
ordenados de datos de tipo double y los mezcle en un tercer array. Tenga en cuenta que:
• Los arrays de entrada están ordenados y sin valores repetidos.
• El array de salida tendrá los elementos ordenados y sin repetidos.
6• Puede asumir que el array de salida tiene capacidad suficiente para todos los ele-
mentos.
• La función devuelve un entero que es el número de elementos que contiene el array
de salida. Nota: Será menor o igual que la suma de los de entrada.

MEJORA DEL EJERCICIO PROPUESTO: Mezcla dos arrays cualesquiera obteniendo uno ordenado y sin elementos repetidos.

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

/**
 * @brief Elimina los elementos repetidos de un array
 */
void EliminarRepetidosArray(int v[], int & util_v){
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

/**
 * @brief busca el mínimo del array entre p1 y p2
 * Se utiliza para la ordenación por selección
 */
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

void OrdenarPorSeleccion( int v[], const int & utiles){
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

void MezclarUnico( int resultado[], int & util_resultado, const int array1[], const int & util_array1, const int array2[], const int & util_array2 ){
	util_resultado = util_array1 + util_array2;
	for(int i=0; i<util_array1; i++)
		resultado[i] = array1[i];
	for(int i=util_array1; i<util_resultado; i++)
		resultado[i] = array2[i-util_array1];
	EliminarRepetidosArray(resultado, util_resultado);
	OrdenarPorSeleccion(resultado, util_resultado);
}

int main(){
	int TAMANO = 100;
	int array1[TAMANO], array2[TAMANO], util_array1, util_array2;
	
	//ENTRADA
	cout << "ARRAY 1" << endl;
		cout << "Número de elementos que se introducirán: ";
		cin >> util_array1;
		while (util_array1 > TAMANO){
			cerr << "No pueden introducirse más de " << TAMANO << " elementos" << endl;
			cout << "Número de elementos que se introducirán: ";
			cin >> util_array1;
		}
		cout << "Intruducir elementos:" << endl;
		leerArray(array1, util_array1);
	
	cout << "\nARRAY 2" << endl;
		cout << "Número de elementos que se introducirán: ";
		cin >> util_array2;
		while (util_array2 > TAMANO){
			cerr << "No pueden introducirse más de " << TAMANO << " elementos" << endl;
			cout << "Número de elementos que se introducirán: ";
			cin >> util_array2;
		}
		cout << "Intruducir elementos:" << endl;
		leerArray(array2, util_array2);
		
	//CONSTRUCCIÓN DEL NUEVO ARRAY
	int array_guay[2*TAMANO];
	int util_array_guay;
	MezclarUnico(array_guay, util_array_guay, array1, util_array1, array2, util_array2);
	
	//SALIDA
	cout << "\nArray resultante:" << endl;
	imprimirArray(array_guay, util_array_guay);
}
