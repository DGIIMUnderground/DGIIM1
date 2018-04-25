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
// ¡RELLENAD LOS SIGUIENTES DATOS!
//
// Apellidos: Villegas Yeguas 
// Nombre:  Antonio David
//
// GRUPO DE PRÁCTICAS: A3
//
// Fecha:  25 / 04 / 2018
// 
// Ordenador (ver etiqueta): ei142177
//
/***************************************************************************/

#include <iostream>
#include <cctype>
#include <cstring>

#include "Lista.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/

const int NUM_VALORES = 10;
const int MIN_ALEAT = 1;
const int MAX_ALEAT = 100;

/***************************************************************************/
/***************************************************************************/

int main (int argc, char **argv)
{

	// Completar
	int num_nodos_a_crear = NUM_VALORES;
	int min = MIN_ALEAT;
	int max = MAX_ALEAT;

	if (argc > 4){
		cerr << "ERROR : Numero de argumentos erroneo" << endl;
		exit(1);
	}
	else if(argc > 3){
		num_nodos_a_crear = atoi( argv[1] );
		min = atoi( argv[2] );
		max = atoi( argv[3] );
	}
	else if( argc > 2){
		cerr << "ERROR : Numero de argumentos erroneo" << endl;
		exit(1);
		
	}
	else if( argc > 1){
		num_nodos_a_crear =atoi ( argv[1] );
	}
	else if( argc > 0){
		num_nodos_a_crear = NUM_VALORES;
	}	
	else{
		cerr << "ERROR : Numero de argumentos erroneo" << endl;
		exit(1);
	}

	Lista mi_lista;

	cout << "Rellenamos la lista de aleatorios : " << endl;

	RellenaListaAleatoriamente (mi_lista, num_nodos_a_crear,min, max);

	PintaLista (mi_lista);

	cout << endl << "Ordenamos la lista en sentido ascendente : " << endl;

	OrdenaIntercambioLista (mi_lista);

	PintaLista (mi_lista);

	cout << endl << "Ordenamos la lista en sentido descendente : " << endl;

	OrdenaListaIntercambioDescendente (mi_lista);

	PintaLista (mi_lista);

	LiberaLista (mi_lista);

	return (0);
}

/***************************************************************************/
/***************************************************************************/
