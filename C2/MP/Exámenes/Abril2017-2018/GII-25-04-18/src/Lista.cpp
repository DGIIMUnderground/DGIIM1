/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2017-2018
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// EXAMEN PRÁCTICO 1
//
// Implementación de las funciones que gestionan listas simples.
//
// Fichero: Lista.cpp
//
/***************************************************************************/

#include <iostream>
#include <iomanip>

#include "GeneradorAleatorioEnteros.h"
#include "Lista.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/
// Crea una lista y rellena sus nodos con los valores leidos de cin.
// El número de valores es indefinido --> en esta implementación la lectura 
// se detiene al leer un valor negativo.  
//  
// Recibe y devuelve (a través de referencia): l, la lista.

void LeeLista (Lista & l) 
{
	l = 0; // Por si no se introdujera ningún valor -> lista vacía
	
	PNodo fin, nuevo; 
	TipoBase valor; 

	const char * mensaje = "Valor (para finalizar, un negativo): ";
	
	cout << endl;

	cout << mensaje; 
	cin >> valor;

	if (valor >= 0)	{

		// crear e inicar el primer nodo 
		l = new Nodo;
		l->valor = valor; 
		l->sig = 0; 

		fin = l; // marcamos el ultimo nodo

		cout << mensaje; 
		cin >> valor;

		while (valor >= 0) {

			// crear e iniciar un nuevo nodo
			nuevo = new Nodo;
			nuevo->valor = valor; 

			fin->sig = nuevo; // enlazar (al final)
			fin = nuevo;      // actualizar el ultimo

			cout << mensaje; 
			cin >> valor;
		}

		fin->sig = 0; // marcar el final
	}

	cout << endl;
}

/***************************************************************************/
/***************************************************************************/
// Crea una lista y rellena sus nodos con los valores aleatorios.
//  
// Recibe y devuelve (a través de referencia): l, la lista.
// Recibe: 	
//		num_datos, número de datos a generar y guardar. 
//		min, mínimo valor aleatorio que se puede generar.
//		max, máximo valor aleatorio que se puede generar.			

void RellenaListaAleatoriamente (Lista & l, int num_datos, int min, int max) 
{
	l = 0; // Por si no se introdujera ningún valor -> lista vacía
	
	if (num_datos > 0) {

		PNodo fin, nuevo; 
		TipoBase valor; 

		// Iniciar generador de números aleatorios
		GeneradorAleatorioEnteros generador (min, max);
	

		// crear e inicar el primer nodo 
		l = new Nodo;
		l->valor = generador.Siguiente();
		l->sig = 0; 

		fin = l; // marcamos el ultimo nodo

		for (int n=1; n<num_datos; n++)	{

			// crear e iniciar un nuevo nodo
			nuevo = new Nodo;
			nuevo->valor = generador.Siguiente(); 

			fin->sig = nuevo; // enlazar (al final)
			fin = nuevo;      // actualizar el ultimo
		}

		fin->sig = 0; // marcar el final

	} // if (num_datos > 0)
}

/***************************************************************************/
/***************************************************************************/
// Libera la memoria ocupada por los nodos de una lista
// Recibe y devuelve (a través de referencia): l, la lista.

void LiberaLista (Lista & l)
{
   if (l != 0) { // Importante: prevenir de la lista vacía

        PNodo aux = l; // Colocar "aux" al principio

        while (aux->sig != 0) {
            aux = aux->sig;   // Adelantar "p"
            delete l;         // Borrar el primero
            l = aux;          // Actualizar "aux"
        }
        delete l; // Borrar el único nodo que queda
    }
    l = 0; // El puntero que da acceso a la lista queda con valor 0
}
 
/***************************************************************************/
/***************************************************************************/
// Muestra los valores guardados en los nodos de una lista enlazada
// Recibe: l, puntero al primer nodo de la lista

void PintaLista (const Lista l)
{
	int num_datos = CuentaElementos(l);
	PNodo p=l;

	for (int n=0; n<num_datos; n++) {
		cout << "Valor " << setw(2) << n+1 << " = " << p->valor << endl;
		p=p->sig;
	}
	cout << endl;

}

/***************************************************************************/
/***************************************************************************/
// Cuenta el número de nodos de la lista
// Recibe:  l, puntero al primer nodo de la lista
// Devuelve: número de nodos de la lista

int CuentaElementos (const Lista l)
{
	PNodo p = l; 
	int contador = 0; 

	for (PNodo p=l; p!=0; contador++, p=p->sig);

	return (contador);
}

/***************************************************************************/
/***************************************************************************/
// Consulta si una lista está vacía (sin nodos)
// Recibe:  l, puntero al primer nodo de la lista
// Devuelve: true, si la lista está vacía
   
bool ListaVacia (const Lista l)
{
	return (l==0);	
}


/***************************************************************************/
/***************************************************************************/
// Ordena una lista por el algoritmo de intercambio
// Recibe y devuelve (a través de referencia): 
//		l, la lista (puntero al primer nodo de la lista). 
//			Si ese puntero se modifica (es probable) el resultado  
//			será correcto, al recibirse en una referencia.  

void OrdenaIntercambioLista (Lista &l)
{
	//Si la lista no esta vacia
	if(l != 0){
		
		//Contamos el numero de nodos disponibles
		int num_nodos = CuentaElementos(l);

		//Creamos dos puntero a nodos auxiliares, que recorreran la lista
		//
		//    lista : apunta al principio de la lista y la recorrera hasta 
		//  el penultimo elemento de la parte desordenada
		//		
		//    siguiente : apuntara al siguiente elemento apuntado por lista
		//  por lo que llegara hasta el final de la parte desordenada

		PNodo lista = l;
		PNodo siguiente = lista->sig;

		//Elemento auxiliar para realizar el cambio entre dos valores
		TipoBase auxiliar;

		//  Booleano para hacer las iteraciones necesarias, sin tener que 
		// recorrer la lista más veces de las necesarias
		//  Iniciamos a true para entrar, aunque su valor por defecto
		// sea false
		bool hay_intercambio = true;

		for (int i = 0; i < num_nodos && hay_intercambio; i++){
	
			//En cada vuelta, lista y siguiente vuelven a sus valores iniciales
			lista = l;
			siguiente = lista->sig;

			//Una vez dentro ponemos hay_intercambio a false
			hay_intercambio = false;

			//  Recorremos la parte desordenada de la lista, realizando 
			// intercambios parando en num_nodos - i - i :
			//
			//     num_nodos - i : fin de la parte desordenada
			//
			//  Le tenemos que restar 1 para que el siguiente se quede en el
			// final, y no se acceda a memoria no reservada
		
			for (int j = 0; j < num_nodos - i - 1; j++){

				//Si el anterior es mayor al siguiente, los intercambiamos
				if ( lista->valor > siguiente->valor ){
					//Intercambiamos
					auxiliar = lista->valor;
					lista->valor = siguiente->valor;
					siguiente->valor = auxiliar;

					hay_intercambio = true;
		
				}

				//Avanzamos lista y siguiente para recorrer la lista
				lista = lista->sig;
				siguiente = siguiente->sig;
			}	
		}
	}
}

void OrdenaListaIntercambioDescendente (Lista &l){

	OrdenaIntercambioLista (l);

	InvierteLista (l);
	
}


void InvierteLista(Lista &l){
	
	//Si la lista no esta vacia
	if (l){

		PNodo lista = l;
		PNodo auxiliar;	
		Lista otra_lista;

		//Comenzamos la lista con el primer elemento de la original
		otra_lista = new Nodo;
		otra_lista->sig = 0;
		otra_lista->valor = lista->valor;

		lista = lista->sig;

		while(lista){

			//    Creamos nuevos nodos, con los valores de la lista original,
			//pero en lugar de colocarlos al final, los insertamos al principio
			//de la lista.
			auxiliar = new Nodo;
			auxiliar->valor = lista->valor;
			auxiliar->sig = otra_lista;

			otra_lista = auxiliar;
	
			lista = lista->sig;

			auxiliar = 0;
		}

		//Liberamos la lista
		LiberaLista(l);
	
		//La lista original pasara a ser la nueva lista, ordenada descendientemente
		l = otra_lista;

	}

	

}























/***************************************************************************/
/***************************************************************************/
