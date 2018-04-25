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
// Fichero de cabecera con declaraciones de los tipos "Nodo", "PNodo" 
// y "Lista", por un lado, y la declaración de las funciones sobre éstos. 
//
// Fichero: Lista.h
//
/***************************************************************************/

#ifndef LISTA
#define LISTA

/***************************************************************************/
// Definiciones de tipos

typedef int TipoBase;	// Tipo de los elementos de la lista

// Cada nodo de la lista es de tipo "Nodo"

struct Nodo {	
   TipoBase valor; 
   Nodo *sig; 
};

typedef Nodo * PNodo; 	// Para los punteros a nodos
typedef Nodo * Lista;	// Para la lista

/***************************************************************************/
/***************************************************************************/
// Crea una lista y rellena sus nodos con los valores leidos de cin.
// El número de valores es indefinido --> en esta implementación la lectura 
// se detiene al leer un valor negativo.  
//  
// Recibe y devuelve (a través de referencia): l, la lista. 

void LeeLista (Lista & l);

/***************************************************************************/
/***************************************************************************/
// Crea una lista y rellena sus nodos con los valores aleatorios.
//  
// Recibe y devuelve (a través de referencia): l, la lista.
// Recibe: 	
//		num_datos, número de datos a generar y guardar. 
//		min, mínimo valor aleatorio que se puede generar.
//		max, máximo valor aleatorio que se puede generar.	

void RellenaListaAleatoriamente (Lista & l, int num_datos, int min, int max);

/***************************************************************************/
/***************************************************************************/
// Libera la memoria ocupada por los nodos de una lista
// Recibe y devuelve (a través de referencia): l, la lista.

void LiberaLista (Lista & l);
 
/***************************************************************************/
/***************************************************************************/
// Muestra los valores guardados en los nodos de una lista enlazada
// Recibe: l, puntero al primer nodo de la lista

void PintaLista (const Lista l);

/***************************************************************************/
/***************************************************************************/
// Cuenta el número de nodos de la lista
// Recibe:  l, puntero al primer nodo de la lista
// Devuelve: número de nodos de la lista

int CuentaElementos (const Lista l);

/***************************************************************************/
/***************************************************************************/
// Consulta si una lista está vacía (sin nodos)
// Recibe:  l, puntero al primer nodo de la lista
// Devuelve: true, si la lista está vacía
   
bool ListaVacia (const Lista l);

/***************************************************************************/
/***************************************************************************/
// Ordena una lista el algoritmo de intercambio
// Recibe y devuelve (a través de referencia): 
//		l, la lista (puntero al primer nodo de la lista). 
//			Si ese puntero se modifica (es probable) el resultado  
//			será correcto, al recibirse en una referencia.   

void OrdenaIntercambioLista (Lista &l);

/***************************************************************************/
/***************************************************************************/
// Invierte una lista
// Recibe y devuelve (a través de referencia): 
//		l, la lista (puntero al primer nodo de la lista). 
//			Si ese puntero se modifica (es probable) el resultado  
//			será correcto, al recibirse en una referencia.   

void InvierteLista (Lista &l);

/***************************************************************************/
/***************************************************************************/
// Ordena una lista el algoritmo de intercambio de forma descendente
// Recibe y devuelve (a través de referencia): 
//		l, la lista (puntero al primer nodo de la lista). 
//			Si ese puntero se modifica (es probable) el resultado  
//			será correcto, al recibirse en una referencia.   


void OrdenaListaIntercambioDescendente (Lista &l);


/***************************************************************************/
/***************************************************************************/

#endif
