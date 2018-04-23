/* 2. Escribid un programa que rellene dos arrays a y b con enteros, obtenidos de acuerdo a la
siguiente recurrencia... (mirar la relación)

Mejora: Utilizo una función recursiva. NO necesito utilizar arrays, con la función recursiva puedo calcular directamente un término k-ésimo elevado y
hacer una conjetura consistente sobre el valor de an / bn

Nota sobre la ejecución: hasta el térimino 24-eśimo se aprecia que el límite an/bn se aproxima a 0.41. A partir del término 25, revienta (o eso creo)

José L. Ruiz
*/

#include <iostream>

using namespace std;

void ObtenerTermino_k( const int & k, int & a, int & b){
	if( k == 0){
		a = 1;
		b = 1;
	}
	else{
		ObtenerTermino_k( k-1, a, b);
		int aux = a;
		a = b;
		b = aux + 2*b;
	}
}

int main(){
	int a, b, k;
	cout << "Término que se desea obtener de la recurrencia: K = ";
	cin >> k;
	ObtenerTermino_k(k, a, b);
	cout << "El término " << k << "-ésimo es:\ta = " << a << "\tb = " << b << "\ta/b = " << a*1.000/b << endl;
}
