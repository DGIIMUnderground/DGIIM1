/* 10. Realizar una función que lea un número natural y lo traduzca a morse. Se usa raya (-)
para codificar la señal larga y punto (.) para la señal corta. Los números se codifican de
la forma siguiente:
0 —– 1 ·—- 2 ··— 3 ···– 4 ····- 5 ····· 6 -···· 7 –··· 8 —·· 9 —-·

NOTA: me da palo leer un número entero y pasarlo a cadena de caracteres, por ello lo leo directamente como cadena de caracteres.

José L. Ruiz
*/

#include <iostream>

using namespace std;

const int TAMANO_NUM = 25;
const int TAMANO_MORS = 140;
const int TAMANO_CIFRA = 5;
const int TAMANO_TRANS = 10;

const char EQUIVALENCIA[TAMANO_TRANS][TAMANO_CIFRA] = { {'-','-','-','-','-'}, {'.','-','-','-','-'}, {'.','.','-','-','-'}, {'.','.','.','-','-'},
	{'.','.','.','.','-'}, {'.','.','.','.','.'}, {'-','.','.','.','-'}, {'-','-','.','.','-'}, {'-','-','-','.','-'}, {'-','-','-','-','-'} };


void Lectura( char p[], int & util_p){
	util_p = 0;
	cin >> p[util_p];
	while( p[util_p] != '#' && util_p<= TAMANO_NUM ){
		util_p++;
		cin >> p[util_p];
	}
}

void MostrarArrayCaracteres( char v[], const int & util_v){
	for( int i=0; i<util_v; i++)
		cout << v[i];
}

bool Traduce(const char num[], const int & util_num, char mors[], int & util_mors){
	bool satisfactorio = true;
	util_mors = 0;
	for(int i=0; i<util_num && satisfactorio; i++){
		if(num[i]>='0' && num[i] <='9'){
			for( int j=util_mors; j<util_mors+TAMANO_CIFRA+1; j++)
				mors[j] = EQUIVALENCIA[ num[i]-'0' ][ j-util_mors ];
			mors[util_mors+TAMANO_CIFRA] = ' ';
			util_mors += TAMANO_CIFRA+1;
		}
		else
			satisfactorio=false;		
	}
	return satisfactorio;
}

int main(){
	cout << "BIENVENIDO AL CONVERSOR MORSE" << endl;
	
	char numero[TAMANO_NUM], morse[TAMANO_MORS];
	int util_numero, util_morse;
	
	Entrada_numero: //etiqueta para utilizar goto
	cout << "Introduzca un número entero (no exceda de 25 cifras y finalize con '#'):" << endl;
	Lectura(numero, util_numero);
	
	bool posible_traducir = Traduce(numero, util_numero, morse, util_morse);
	
	if(posible_traducir){
		cout << "Traducción:" << endl;
		MostrarArrayCaracteres(morse, util_morse);
	}
	else{
		cerr << "No sea idiota e introduzca un valor válido" << endl;
		goto Entrada_numero;
}
