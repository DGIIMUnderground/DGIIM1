/**
@file celdas.cpp
@brief implementación de lo implemetable de la clase celda, es decir del mensaje
 **/

#include <iostream>
#include <cstring>
#include "celdas.h"

using namespace std;

Mensaje::Mensaje()
{
  const char* ms_vacio = "Eres maravillamente genial :)";
  strcpy(mensaje ,ms_vacio);
  this->positividad = 3;
}
Mensaje::Mensaje( char ms [])
{
  strcpy(mensaje ,ms);
  this->positividad = 7;
}

Mensaje::Mensaje( char ms [], int n)
{
  strcpy(mensaje ,ms);
  this->positividad = n;
}

void Mensaje::set_positividad( int n)
{
   this->positividad = n;
}

void Mensaje::set_mensaje(char ms [])
{
  strcpy(mensaje ,ms);
}

int Mensaje:: get_positividad() const
{
  return positividad;
}
void Mensaje::show_mensaje() const
{
  cout << mensaje << endl;
}
char* Mensaje::get_mensaje()
{
  return mensaje;
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ fin método mensaje ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  
void insertar_celda( Celda* &lista , Mensaje ms )
{
  Celda* aux = new Celda;
  
  aux->mensaje.set_mensaje( ms.get_mensaje());
  aux->mensaje.set_positividad(ms.get_positividad());
  aux->sig=lista;
  lista=aux;

  
}

void recorrer_celda( Celda* lista )
{
  Celda *aux = lista;

  while (aux != NULL)
    {
      aux->mensaje.show_mensaje();
      aux = aux->sig;
      
    }
}

void destruir_celda( Celda* &lista )
{
  while (lista != NULL)
    {
      Celda *aux = lista;
      lista = lista->sig;
      delete aux;
    }
}

void recorrer_inversa( const Celda * lista)
{
  if ( lista->sig != NULL)
    recorrer_inversa(lista->sig );
  lista->mensaje.show_mensaje();
}

int dimension_celda( const Celda *lista)
{
  int salida = 1;
  if ( lista->sig != NULL)
    salida += dimension_celda(lista->sig);
  return salida;
    
}

void inserta_celda_aux( Celda* &celda_nueva , Celda* &lista , const int pos ,  int estado )
{
  if (estado < pos )
    inserta_celda_aux( celda_nueva , lista->sig ,pos , ++estado);
  else
    {
      celda_nueva->sig = lista->sig;
      lista->sig = celda_nueva;
    }
}
  
void inserta_celda( Celda* &celda_nueva , Celda* &lista , const int pos )
{
  if (pos > dimension_celda(lista))
    cerr << "Cariño, mira que te acabo de decir el tamaño...\n";
  else
    {
      inserta_celda_aux( celda_nueva , lista , pos );
    }
}

