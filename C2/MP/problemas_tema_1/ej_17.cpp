/* 17. Calcular el producto de dos matrices A y B, suponiendo que A tiene m filas y n
columnas y B tiene n filas y p columnas.

José L. Ruiz
*/

#include <iostream>

using namespace std;

const int DIM = 10;

void Lectura( double matriz[][DIM], const int & util_f, const int & util_c){
	for( int i=0; i<util_f; i++)
		for( int j=0; j<util_c; j++){
			cout << "m[" << i << "][" << j << "]:= ";
			cin >> matriz[i][j];
		}
}

void Mostrar( double matriz[][DIM], const int & util_f, const int & util_c){
	for( int i=0; i<util_f; i++){
		for( int j=0; j<util_c; j++)
			cout << matriz[i][j] << "\t";
		cout << endl;
	}
}

void Multiplica( const double matriz_a[][DIM], const int & util_f_a, const int & util_c_a, const double matriz_b[][DIM], const int & util_f_b, const int & util_c_b, double producto[][DIM], int & util_f_p, int & util_c_p){
	util_f_p = util_f_a;
	util_c_p = util_c_b;
	for ( int i=0; i<util_f_p; i++)
		for( int j=0; j<util_c_p; j++){
			int suma = 0;
			for( int k=0; k<util_c_a; k++)
				suma += matriz_a[i][k] * matriz_b[k][j];
			producto[i][j] = suma;
		}
}

int main(){
	double matriz_a[DIM][DIM];
	double matriz_b[DIM][DIM];
	int util_f_a, util_c_a, util_f_b, util_c_b;
	
	cout << "Número de filas y columnas de la matriz A: ";
	cin >> util_f_a >> util_c_a;
	cout << "Introduzca la matriz A" << endl;
	Lectura(matriz_a, util_f_a, util_c_a);
	
	cout << "Número de filas y columnas de la matriz B: ";
	cin >> util_f_b >> util_c_b;
	cout << "Introduzca la matriz A" << endl;
	Lectura(matriz_b, util_f_b, util_c_b);
	
	bool multiplicables = util_c_a == util_f_b;
	
	if( !multiplicables )
		cout << "Las matrices no se pueden multiplicar." << endl;
	else{
		double producto[DIM][DIM];
		int util_f_p, util_c_p;
		Multiplica(matriz_a, util_f_a, util_c_a, matriz_b, util_f_b, util_c_b, producto, util_f_p, util_c_p);
		cout << "El producto A·B es: " << endl;
		Mostrar(producto, util_f_p, util_c_p);
	}
}
