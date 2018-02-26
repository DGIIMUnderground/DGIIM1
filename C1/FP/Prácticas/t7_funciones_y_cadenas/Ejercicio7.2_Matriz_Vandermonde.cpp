// Ejercicio 7.2 - Matrices de Vandermonde

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void leer_vector (vector<int> &v){
	int n, x;
	
	cout << "Introduzca tamano de la matriz: ";
	cin >> n;
	
	v.resize(n);
	
	cout << "Introduzca los valores: ";
	
	for (int i=0; i<v.size(); i++){
		cin >> x;
		v[i] = x;
	}
}

vector<vector<int> > matrizV (vector<int> & v){
	vector<vector<int> > matriz (v.size(), v);
	
	for (int i=0; i<matriz.size(); i++){
		for (int j=0; j<matriz.at(i).size(); j++){
			matriz[i][j] = pow (v[j], i);
		}
	}
	
	vector<vector<int> > matrizt (v.size(), v);
	
	for (int i=0; i<matriz.size(); i++){
		for (int j=0; j<matriz.at(i).size(); j++){
			matrizt[i][j] = matriz [j][i];
		}
	}
	
	return matrizt;
}

void presentar (vector<vector<int> > & matriz){
	for (int i=0; i<matriz.size(); i++){
		for (int j=0; j<matriz.at(i).size(); j++){
			cout << matriz[i][j] << " ";
		}
		
		cout << endl;
	}
	
	matriz;
}

int main(){
	vector<int> v;

	leer_vector(v);

	vector<vector<int> > matriz;
	matriz = matrizV(v);
	
	presentar (matriz);
}
