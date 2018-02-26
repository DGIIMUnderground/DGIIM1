//Author: José Luis Ruiz Benito

/*Da una cantidad de numeros primos*/
/* Mejora (versión 3.1): evalua solo los divisores menores que la raiz cuadradada del numero.
De esta forma, el tiempo de ejecución se reduce considerabalemente*/


#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	int primer_primo=2;
	int numero=3;
	int divisor=int(sqrt(numero));
	int primo;
	int cantidad;
	
	cout << "CRIBA DE ERATÓSTENES\n" << endl;	

	cout << "¿Cuándos primos desea mostrar? ";
	cin >> cantidad;
	
	
	cout << primer_primo << "\t";

	for(int i=1; i<cantidad;){
		while(numero%divisor!=0 && divisor>=primer_primo){
			divisor--;
		}
		if(divisor==1){
			primo=numero;
			cout << primo << "\t";
			i++;
		}
		
		numero++;
		divisor=int(sqrt(numero));
	}

	cout << endl;
}

//Defecto: debido al uso de la tabulación, los primos mostrados al final de línea aparecen cortados y continúan en la siguiente.
