// Examen septiembre 2013/2014
// 17 septiembre 2014
// Ejercicio 2 - Algoritmo Counting Sort
// Paula Villanueva Núñez

#include <iostream>
#include <vector>
using namespace std;

int main(){
	int x, tam, n, m, contador=0;
	
	cout << "Introduce tamanio del vector: ";
	cin >> tam;
	
	vector<int> v(tam);
	
	cout << "Introduce los valores del vector: ";
	
	// Creamos el vector de enteros positivos
	for (int i=0; i<v.size(); i++){
		cin >> x;
		
		if (x>0)
			v[i] = x;
		else{
			while (x<=0){
				cout << "Introduce un valor positivo: ";
				cin >> x;
			}
			
			v[i] = x;
		}
	}
	
	// Elegimos el rango
	cout << "Introduce dos enteros positivos: ";
	cin >> n >> m;
	
	vector<int> frecuencias;
	
	// Creamos el vector frecuencias para almacenar cuántas veces se almacenan
	// los enteros del n al m
	for (int i=n; i<=m; i++){
		contador = 0;
		
		for (int j=0; j<v.size(); j++){
			if (i == v[j])
				contador++;
		}
		
		frecuencias.push_back(contador);
	}
	
	vector<int> salida;
	
	// Creamos el vector salida según el número de frecuencias
	for (int i=0; i<frecuencias.size(); i++){
		if (frecuencias[i] != 0){
			while (frecuencias[i] != 0){
				salida.push_back(n);
				frecuencias[i]--;
			}
		}
		
		n++;
	}
	
	for (int i=0; i<salida.size(); i++)
		cout << " " << salida[i] << " ";
	
}
