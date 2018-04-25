/***************************************************************************/
// CLASE: GeneradorAleatorioEnteros
//
//  Ejemplo de uso:
/*
	int menor, mayor;
	......
	
	// Objeto generador de números aleatorios
	GeneradorAleatorioEnteros generador_aleat (menor, mayor);
	
	int valor_generado = generador_aleat.Siguiente();
*/   
   
/***************************************************************************/

#ifndef GENERADOR_ALEATORIO_ENTEROS
#define GENERADOR_ALEATORIO_ENTEROS
 
#include<cstdlib>
#include<cctype>

#include <random>  
#include <chrono>  

using namespace std;

/////////////////////////////////////////////////////////////////////////////
class GeneradorAleatorioEnteros
{  
private:
	
   mt19937 generador_mersenne;    // Mersenne twister
   uniform_int_distribution<int>  distribucion_uniforme;
   
public:
	
	/************************************************************************/	
	// Constructor sin argumentos: 
	// Inicializa el generador para proporcionar nums. aleatorios entre 0 y 1

	GeneradorAleatorioEnteros();
   
  	/************************************************************************/  
	// Constructor con argumentos: 
	// Inicializa el generador para proporcionar nums. aleatorios entre "min" 
	// y "max"
	
	GeneradorAleatorioEnteros(int min, int max);
   
	/************************************************************************/
	// Devuelve un nuevo número aleatorio

	int Siguiente();

	/************************************************************************/

private: 

    /************************************************************************/
	// Métodos privados de la clase
    /************************************************************************/

	long long Nanosec();

   /************************************************************************/ 

};

/////////////////////////////////////////////////////////////////////////////

#endif
