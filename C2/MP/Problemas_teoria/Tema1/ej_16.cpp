/* 16. Haz un programa que calcule la traspuesta de una matriz 2D. La inversión se hace
por medio de una función.

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

void Trasponer(const double matriz[][DIM], const int & util_f, const int & util_c, double traspuesta[][DIM], int & util_f_t, int & util_c_t){
	util_f_t = util_c;
	util_c_t = util_f;
	
	for (int i=0; i< util_f_t; i++)
		for (int j=0; j< util_c_t; j++)
			traspuesta[i][j] = matriz[j][i];
}

int main(){
	double matriz[DIM][DIM];
	int util_f, util_c;
	cout << "Número de filas y columnas de la matriz: ";
	cin >> util_f >> util_c;
	cout << "Introduzca la matriz" << endl;
	Lectura(matriz, util_f, util_c);
	
	double traspuesta[DIM][DIM];
	int util_f_t, util_c_t;
	Trasponer(matriz, util_f, util_c, traspuesta, util_f_t, util_c_t);
	
	cout << "Matriz traspuesta:" << endl;
	Mostrar(traspuesta, util_f_t, util_c_t);
}
