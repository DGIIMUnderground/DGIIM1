//Muestra el número perfecto inmediatamente anterior al numero dado

#include <iostream>
using namespace std;

int suma_divisores(int x){
	int divisor=2;
	int suma_divisores=1;
	
	while(divisor<=x/2){
		if(x%divisor==0){
			suma_divisores=suma_divisores+divisor;
		}
		divisor++;
	}
	
	return suma_divisores;
}

int main(){
	
	int numero, maxperfecto;
	
	cout << "Introduzca número: ";
	cin >> numero;
	
	for(int i=numero; i>=6; i--){
		if(suma_divisores(i)==i){
			maxperfecto=i;
			break;	
		}
	}
	cout << "Mayor número perfecto: " << maxperfecto << endl;
}
