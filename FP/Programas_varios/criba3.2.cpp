/*

Autor: José Luis Ruiz Benito. 1º DGIIM
Fecha: 20/10/2017

Versión 3.2: Da los primos menores que el numero indicado, respetando la esencia de la criba de Eratóstenes. (Las versiones 3 y 3.1 daban la cantidad indicada de números primos.)

Mejora (versión 3.1): evalúa sólo los divisores menores que la raíz cuadradada del número.
Así, el tiempo de ejecución se reduce considerabalemente.

*/


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

	cout << "Calcular números primos hasta (introduzca número natural): ";
	cin >> cantidad;
	
	
	cout << primer_primo << "\t";

	for(int i=1; i<cantidad; i++){
		while(numero%divisor!=0 && divisor>=primer_primo){
			divisor--;
		}
		if(divisor==1){			//Si divisor disminuye hasta 1, numero no tiene divisores mayores que 1 y numero es primo.
			primo=numero;
			cout << primo << "\t";
			
		}
		
		numero++;				//El siguiente numero a evaluar será el natural inmediatamente superior a numero.
		divisor=int(sqrt(numero));
	}

	cout << endl;
}

/*NOTA: El primer divisor con el que opera es la parte entera de la raíz cuadrada de numero, por el siguiente Teorema:
"Si un número n es compuesto, se verifica que ha de tener un divisor primo menor o igual que su raíz cuadrada"*/ 

//Defecto: debido al uso de la tabulación, los primos mostrados al final de línea aparecen cortados y continúan en la siguiente.
