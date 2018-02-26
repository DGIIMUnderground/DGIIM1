/* 5. Construir una función que permita ordenar de forma descendente los elementos de un
array usando el algoritmo de inserción.

José L. Ruiz
*/

#include <iostream>

using namespace std;

void LecturaArrayEnteros( int v[], const int & util_v){
	for (int i=0; i<util_v; i++){
		cout << "[" << i << "]: ";
		cin >> v[i];
	}
}

void MostrarArrayEnteros( int v[], const int & util_v){
	for( int i=0; i<util_v; i++)
		cout << v[i] << "  ";
}

void OrdenaArrayEnterosMayorMenorInsercion( int v[], const int & util_v){
	int elemento, j;
	for( int i=0; i<util_v; i++){
		elemento = v[i];
		for(j=i; j>0 && elemento > v[j-1]; j--) //para ordenar de menor a mayor cambiar esta línea por: for(j=i; j>0 && elemento < v[j-1]; j--)
			v[j] = v[j-1];
		v[j] = elemento;
	}
}

int main(){
	const int TAMANO = 100;
	int numericos[TAMANO];
	int util_numericos;
	
	//~Comienzo de la entrada de util_numericos:
	Entrada_util_numericos: //etiqueta de la instrucción para poder utilizar la orden goto
	cout << "¿Cuántos numericos va a introducir? ";
	cin  >> util_numericos;
	if(util_numericos > TAMANO){
		cerr << "Error. No se pueden introducir más de " << TAMANO << " numericos" << endl;
		goto Entrada_util_numericos; //utilizo goto porque quiero y porque puedo
	}
	//~fin de la entrada de util_numericos
	
	/* ACLARACIÓN: NO es acosejable utilizar goto, pero también es bueno saber que existe.
	La entrada de util_numericos se puede hacer de forma equivalente con un bucle while (o con un do-while):
		
		//~Comienzo de la entrada de util_numericos:
		cout << "¿Cuántos numericos va a introducir? ";
		cin  >> util_numericos;
		while(util_numericos > TAMANO){
			cerr << "Error. No se pueden introducir más de " << TAMANO << " numericos" << endl;
			cout << "¿Cuántos numericos va a introducir? ";
			cin  >> util_numericos;
		}
		//~fin de la entrada de util_numericos
	*/
	
	cout << "Introduza numericos: ";
	LecturaArrayEnteros(numericos, util_numericos);
	
	clog << "Se procederá a ordenar el vector de mayor a menor por el algoritmo de inserción" << endl;
	OrdenaArrayEnterosMayorMenorInsercion( numericos, util_numericos);
	
	cout << "\nVector ordenado:" << endl;
	MostrarArrayEnteros( numericos, util_numericos);
}
