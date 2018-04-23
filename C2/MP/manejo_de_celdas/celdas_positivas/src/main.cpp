/**
   @Maneja celdas positivas 
   @author: Doña Blanca 
 **/

#include <iostream>
#include <fstream>
#include "celdas.h"

using namespace std;

int main()
{
  ifstream fichero;
  char ms [100];
  fichero.open("./data/mensajes.txt");
  Celda * lista;
  lista = NULL;

  Mensaje mensaje;
  
  if (fichero)
    {
      do
	{
	  
	  fichero.getline( ms , 100 );
	  mensaje.set_mensaje(ms);
	  insertar_celda( lista , mensaje);
	  
	  
	  
	}while( !fichero.eof());
      
      fichero.close();
    }
  else
    cerr << "Fichero no encontrado" << endl;
  
  recorrer_celda( lista );
  cout << "\nAhora la voy a recorrer del revés, porque puedo y porque quiero \n"; 
  recorrer_inversa( lista);

  cout << "Buaaah ¿te has dado cuenta de lo corta que es esta lista positiva?"
       << " sólo tiene " << dimension_celda( lista ) << endl
       << "VAMOS A AMPLIARLA ¿QUÉ PROPONE?" << endl;
  
  cin.getline(ms,100);
  cout << "Me gusta ese mensaje, tiene pinta de poder añadirse en la posición 5...\n";

  Celda *nueva;
  nueva = new Celda;
  nueva->mensaje.set_mensaje(ms);
  inserta_celda( nueva , lista , 5);

  cout << "Ayyy qué mona ha quedado, te la vuelvo a mostrar: \n";
  recorrer_celda( lista);

  cout << "Bueno, llegó la hora de acostarse... \n";
  
  destruir_celda( lista); // Esto es una destrucción pacífica, ningún puntero murió contra su voluntad, ahora son punteros salvajes
  

  return 0;
}
