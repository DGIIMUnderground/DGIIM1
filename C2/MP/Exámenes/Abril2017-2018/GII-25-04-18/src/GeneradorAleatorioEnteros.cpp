/***************************************************************************/
// CLASE GeneradorAleatorioEnteros
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

#include "GeneradorAleatorioEnteros.h"  

using namespace std;

/************************************************************************/	
// Constructor sin argumentos: 
// Inicializa el generador para proporcionar nums. aleatorios entre 0 y 1

GeneradorAleatorioEnteros :: GeneradorAleatorioEnteros()
	:GeneradorAleatorioEnteros(0, 1)
{
}

/************************************************************************/  
// Constructor con argumentos: 
// Inicializa el generador para proporcionar nums. aleatorios entre "min" 
// y "max"

GeneradorAleatorioEnteros :: GeneradorAleatorioEnteros(int min, int max) 
{
	const int A_DESCARTAR = 70000;
	// ACM TOMS Volume 32 Issue 1, March 2006

	auto semilla = Nanosec();
	generador_mersenne.seed(semilla);
	generador_mersenne.discard(A_DESCARTAR);
	distribucion_uniforme = uniform_int_distribution<int> (min, max);
}

/************************************************************************/
// Devuelve un nuevo número aleatorio

int GeneradorAleatorioEnteros :: Siguiente()
{
	return (distribucion_uniforme(generador_mersenne));
}
/************************************************************************/

/************************************************************************/
// MÉTODOS PRIVADOS
/************************************************************************/

long long GeneradorAleatorioEnteros :: Nanosec()
{
  return (chrono::high_resolution_clock::now().
          time_since_epoch().count());
}

/************************************************************************/ 
