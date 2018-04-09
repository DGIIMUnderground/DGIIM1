/*
 * Ejercicio 6.3.
 * Escriba una dunción para calcular la mediana de un conjunto de valores.
 * Para ello, considere que el vector de datos que mantiene los valores no puede modificarse.
 * La solución incluirá la reserva de un vector para copiar los originales y poder ordenarlos para seleccionar la mediana.
 * 
 * Mejora: ordeno el vector utilizando un vector de punteros.
 * 
 * jruib
 */

#include <iostream>

using namespace std;

void LecturaArrayInt( int * p, int n){
	for ( int i=0; i<n; i++)
		cin  >> p[i];
}

/*
 * @brief Ordena el array de punteros de menor a mayor en función del dato apuntado por el puntero
 */
void OrdenaArrayPunteros( int **p, int n){
	int min, posmin;
	for ( int i=0; i<n; i++){
		min = *p[i];
		posmin = i;
		for (int j = i+1; j<n; j++)
			if( *p[j] < min ) {
				min = *p[j];
				posmin = j;
			}
		if ( posmin != i){
			int * aux = p[i];
			p[i] = p[posmin];
			p[posmin] = aux;
		}
	}
}

int Mediana ( int * p, int n) {
	int **arraypunts = new int*[n];
	for ( int i=0; i<n; i++)
		arraypunts[i] = p + i; // = &p[i]
	
	OrdenaArrayPunteros( arraypunts, n);
	int  mediana = *arraypunts[n/2];
	
	delete [] arraypunts;
	
	return mediana;
}

int main(){
	int *pdatos, ndatos;
	cout << "Número de datos que se introducirán: ";
	cin >> ndatos;
	pdatos = new int[ndatos];
	cout << "Introduzca datos: ";
	LecturaArrayInt(pdatos, ndatos);
	
	cout << "Mediana: " << Mediana(pdatos, ndatos) << endl;
	
	delete [] pdatos;
}
