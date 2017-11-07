/*

Author: José L. Ruiz Benito

Fundamentos de Programación. Tema 3: Bucles. Ejercicio 3.14

DESCRIPCIÓN: Lee una serie de temperaturas correspondiente a cada ciudad (hay que indicarle el número de ciudades) y calcula la mayor de las medias.

*/

#include <iostream>

using namespace std;

int main(){
	int n; //número de ciudades
	double temp;
	double sumatemp_i; //almacena la suma de las temperaturas de cada ciudad.
	double media=0; //mayor de las medias
	double media_i;
	int ciudad;
	int contador; //contador de numero de temperaturas
	
	cout << "Número de ciudades: ";
	cin >> n;
	
	for(int i=1; i<=n; i++){	//i almacena el numero de fila, es decir, la ciudad
		
		sumatemp_i=0;
		contador=0;
		cin >> temp;
		
		while(temp!=-100){
			sumatemp_i=sumatemp_i+temp;
			contador++;
			
			cin >> temp;
		}
		
		media_i=sumatemp_i/contador;
		
		if(media_i>media){
			media=media_i;
			ciudad=i;
		}
	}
	
	cout << "Media más alta: " << media << endl;
	cout << "Ciudad: " << ciudad << endl;

}
