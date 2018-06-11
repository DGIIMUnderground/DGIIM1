/**
   @file celdas2.cpp 
   @author Blanca Cano 
   @brief: manejo de celdas muy básico
*/

#include <iostream>
#include <math.h> //para utilizar ceil (redondeo hacia arriba)

using namespace std;

struct Celda
{
  int dato;
  Celda * sig;
};

/// Inserata
void insertarFinalLista ( Celda* &lista, double valor )
{
  Celda * nuevo = new Celda;
  nuevo->dato = valor;
  nuevo->sig = NULL;

  Celda * aux = lista;
  while ( aux->sig != NULL)
    {
      aux = aux->sig;
    }
  
  aux->sig = nuevo ;
}

void insertarPrincipioLista(Celda* &lista , double valor)
{
  Celda *aux = new Celda;
  aux->dato = valor;
  aux->sig = lista;
  lista = aux;
    
}
void mostrarLista( Celda* lista )
{
  if(lista != NULL)
    {
      cout << lista->dato << " ";
      mostrarLista( lista->sig);
    }
  else
    cout << endl;
}

void liberarMemoria(Celda* & c)
{
  int cnt= 0;
  while ( c != NULL)
    {
      Celda *aux = c;
      c = aux->sig;
      delete aux;
    }
}
///tamaño de la lista de celdas
int profundidad ( Celda * c)
{
  if( c != NULL)
    return 1+ profundidad( c->sig);
  else
    return 0;
}

/*
  @brief inserta dato en la posición de memoria siguiente a la del la celda dada
 */
void insertarDato ( Celda *& c , double valor )
{
  Celda * aux = new Celda;
  aux->dato = valor;
  aux->sig = c->sig;
  c->sig = aux;
  
}

void insertarDatoPos( int pos , Celda * & c , double valor)
{
  Celda * aux = c;
  //recorro lista hasta posicionarme en el lugar deseado
  for( int i = 0; i < pos ; i++)
    aux = aux->sig;
  
  insertarDato( c , valor);
  
}

void listaSegmentos( Celda** &lista , Celda * & celda , int t)
{
  int i = 0 , j = 0;
  Celda * aux;
  cout << "Entra" << endl;
  while( celda != NULL )
    {
      cout << "El valor del índice es" << i << endl;
      lista[i++]=celda;
      while ( ++j < t && celda != NULL)
	{
	  celda = celda->sig;
	}
      j=0;
      aux = celda;
      celda=celda->sig;
      aux->sig = NULL;
      mostrarLista( lista[i-1]);
    }
}


//~~~~~~~~~~~~~~~~~~~~~~~~ main ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main()
{
  const int TAM = 2;
  Celda* c = new Celda;
  c->dato = 0;
  c->sig = NULL;
  for( int i= 1; i<9 ; i++)
    {
      //insertarFinalLista(c ,i*i );
      insertarDato(c , i); //equivalente a insertar al PRINCIPIO
    }

  insertarDatoPos( 2 , c , 100000);
  mostrarLista(c);

  /// División en fragmentos de dos
  int tam = ceil(profundidad(c)*1.0/TAM);
  cout << "La profundidas de esta lista es " << tam << endl;
  Celda **lista = new Celda* [tam];

  listaSegmentos(lista , c , 2);

  for( int i= 0; i< tam ; i++)
    mostrarLista( lista[i]);

  for( int i = 0; i < tam ; i++ )
    liberarMemoria(lista[i]);
  delete [] lista;
}
