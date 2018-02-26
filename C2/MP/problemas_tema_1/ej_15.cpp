/* 15. Haz un programa que calcule, mediante una función, la traza de una matriz 2D (suma
de los elementos de la diagonal principal).

José L. Ruiz
*/

#include <iostream>

using namespace std;

const int DIM = 10;

void Lectura( double matriz[][DIM], const int & util_matriz){
	for( int i=0; i<util_matriz; i++)
		for( int j=0; j<util_matriz; j++){
			cout << "m[" << i << "][" << j << "]:= ";
			cin >> matriz[i][j];
		}
}

void Mostrar( double matriz[][DIM], const int & util_matriz){
	for( int i=0; i<util_matriz; i++){
		for( int j=0; j<util_matriz; j++)
			cout << matriz[i][j] << "\t";
		cout << endl;
	}
}

double Traza( const double matriz[][DIM], const int & util_matriz){
	double traza = 0;
	for (int i=0; i<util_matriz; i++)
		traza += matriz[i][i];
	return traza;
}

int main(){
	double matriz[DIM][DIM];
	int util_matriz;
	
	cout << "Número de filas de la matriz cuadrada: ";
	cin >> util_matriz;
	cout << "Introduzca la matriz" << endl;
	Lectura(matriz, util_matriz);
	
	clog << "Matriz leída:" << endl;
	Mostrar(matriz, util_matriz);
	cout << endl;
	
	cout << "Traza de la matriz: " << Traza(matriz, util_matriz) << endl;
}
