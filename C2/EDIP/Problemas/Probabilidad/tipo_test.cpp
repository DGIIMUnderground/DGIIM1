/*
 *  TIPO TEST JAMALDO-STYLE (tipo_test.cpp)
 *
 *  Programa para resolver el problema siguiente:
 * 		Si contestamos un examen tipo test modelo Jamaldo (correctas +2 puntos, incorrectas -1 puntos, sin contestar +0 puntos)
 * 		contestando de forma aleatoria, ¿cuál es la probabilidad de aprobar?
 * 
 *  DGIIMUnderground (1º DGIIM 2017/2018, UGR)
 * 		Autor: Miguel Ángel Fernández Gutiérrez
 * 		Fecha: 9 de mayo, 2018
*/

#include <iostream>

using namespace std;

bool incrementar_vector( int* v ) {
	int s = 0;
	for ( int i = 0; i < 5; i++ )
		if ( i == s ) {
			if ( v[i] < 4 )
				v[i]++;
			else {
				v[i] = 0;
				s++;
			}
		}
	if ( v[0] == 4 && v[1] == 4 && v[2] == 4 && v[3] == 4 && v[4] == 4 ) return false;
	else return true;
}

char convert(int a) {
	char repr;
	switch (a) {
		case 0: repr = '-'; break;
		case 1: repr = 'a'; break;
		case 2: repr = 'b';	break;
		case 3: repr = 'c'; break;
		case 4: repr = 'd';	break;
		default: break;
	}
	return repr;
}

void imprimir( int* v ) {
	for ( int i = 0; i < 5; i++ )
		cout << convert(v[i]) << " ";
}

int main() {
	int v[5] = {-1,0,0,0,0};
	bool status = true;
	int total = 0;
	int nota;
	int casos = 0;
	while (status) {
		nota = 0;
		status = incrementar_vector(v);
		for ( int i = 0; i < 5; i++ ) {
			if ( v[i] == 1 )
				nota += 2;
			else if ( v[i] > 1 )
				nota -= 1;
		}
		imprimir(v); cout << " da una nota " << nota << " -> ";
		if ( nota >= 5 ) {
			cout << "APROBADO                    *****" << endl;
			casos++;
		} else
			cout << "SUSPENSO" << endl;
		total++;
	}
	cout << casos << "/" << total << "=" << casos*1.0/total << endl;
}
