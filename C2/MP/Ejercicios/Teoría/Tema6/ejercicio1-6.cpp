#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>


using namespace std;

/**
 * @brief: Ejercicio 1: Escribir un programa que lea una secuencai indefinida de caracteres de la entrada estándar y los copie literalmente en la salida estándar.
 * @param flujo
 * @return
 */
bool es_vocal(char c){
  bool val = false;
  char* vocales="aeiou" ;
  for (unsigned i = 0; i < 5; ++i){
    if (c == vocales[i]){
      val = true;
    }
  }
  return val;
}

void ejercicio1( istream & flujo, ostream & salida){
    int c;
    while ( (c=flujo.get()) != EOF ){
        if ( ! flujo.fail() ){
            salida.put(c);
        }
    }
}
/**
@brief: Ejercicio2: Escirbir un programa que lea una secuencia indefinida de caracteres de la entrada estandar y los copie sin vocales
*/
void ejercicio2(istream & entrada, ostream & salida){
  int c;
  while ( (c=entrada.get()) != EOF  ){
      if ( ! entrada.fail() && ! es_vocal(c) ){
          salida.put(c);
      }
  }
}
void ejercicio3(istream & entrada, ostream & salida){
  int c;
  int counter = 0;
  const int TAM_BUFFER = 10;
  char buffer[TAM_BUFFER];
  while( entrada.read(buffer,TAM_BUFFER) ){
      counter += TAM_BUFFER;
  }
  counter += entrada.gcount();
  salida << counter;
}
void ejercicio4(istream & entrada, ostream & salida){
  int c;
  int cnt = 0;
  while ( (c=entrada.get()) != EOF ){
    if (c == '\n' && entrada.get() != '\0'){ //Con este entrada ,get cojo el siguiente caracter si no es el de finde línea sumamos.
      cnt ++;
    }
  }
  salida << cnt;
}

void ejercicio5(istream & entrada, ostream & salida){
  int c;
  while( (c=entrada.get() ) != EOF){
    if(c == '#'){
      entrada.ignore(1000,'\n'); //Ignora hasta que llega a 1000
    }
    else{
      salida.put(c);
    }

  }
}

void ejercicio6(istream & entrada, ostream & salida){ //NO SE SI ESTA BIEN
  while (entrada){
    int aux;
    entrada >> aux;
    salida << aux;
  }
}
