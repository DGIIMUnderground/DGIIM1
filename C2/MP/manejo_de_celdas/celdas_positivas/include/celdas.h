/**
@file celdas.h
@author Doña Blanca
 **/


#ifndef _CELDAS_H
#define _CELDAS_H
#include <string>

class Mensaje
{
 private:
  char  mensaje [101];
  int positividad;

 public:
  ///construcctures
  Mensaje();
  Mensaje( char mensaje[]);
  Mensaje( char mensaje[] , int positividad );
  
  ///modificadores
  void set_positividad( int n);
  void set_mensaje(  char  mensaje [] );

  /// informantes
  int get_positividad() const ;
  void show_mensaje() const;
  char * get_mensaje();
  
};

struct  Celda
{
  Mensaje mensaje;
  Celda *sig=NULL;

};

//funciones para trabajar con celdas 
void insertar_celda( Celda* &lista , Mensaje ms );
void recorrer_celda( Celda* lista );
void destruir_celda( Celda* &lista );

/**
   @brief muestra por orden inverso los datos de las celdas dadas,
   Utiliza recursividad, por que es lo más binico del mundo
 **/
void recorrer_inversa( const Celda * lista);

/**
   @brief Devuelve el tamaño de la celda 
 */

int dimension_celda( const Celda *lista);

/**
   @brief añade nueva celda en la posicón @a pos
   @param pos, posición en la que insertar
   @param lista: celda en la que se va a insertar el nuevo elemento
   @param celda_nueva: celda a ser insertada
 */
void inserta_celda( Celda* &celda_nueva , Celda* &lista , const int pos );

/**
   @brief aux para insertal celda una vez que se ha comprobado que es buena
 */

void inserta_celda_aux( Celda* &celda_nueva , Celda* &lista , const int pos , const int  estado=1 );


#endif
