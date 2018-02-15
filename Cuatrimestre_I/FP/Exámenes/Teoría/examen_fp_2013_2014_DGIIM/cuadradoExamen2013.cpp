#include <iostream>
#include <vector>
using namespace std;

/**
Implementación clase cuadrado
Examen de FP 2013 11 de febrero.
*/


/** Implementacion del TDA Cuadrado.
  "Me falta hacer las especificacion de la funcion con la correspondiente funcion de abstraccion"
*/
struct CPunto{
  int x;
  int y;
};
class Cuadrado{
public:

  Cuadrado (){
    Punto.x = 0;
    Punto.y = 0;
    longitud = 1;
  }

  Cuadrado (CPunto puntoi, int longi){
    Punto.x = puntoi.x;
    Punto.y = puntoi.y;
    longitud = longi;
  }

  Cuadrado (const Cuadrado & cuadradoi){
    Punto.x = cuadradoi.Punto.x;
    Punto.y = cuadradoi.Punto.y;
    longitud = cuadradoi.longitud;
  }

  //POR ALGUNA EXTRAÑA RAZON NO ME FUNCIONA EL CONSTRUCTOR POR REFERENCIA
  //Entonces lo he puesto por defecto hehe.

  int puntox(){
    return Punto.x;
  }
  int puntoy(){
    return Punto.y;
  }
  int rlongitud(){
    return longitud;
  }



  double area () const {
    return longitud * longitud;
  }
  double perimetro () const {
    return longitud*4;
  }

  bool mayor_area(const Cuadrado & cuadradoi) const{
    bool comprobador;
    if ( area() > cuadradoi.area() )
      comprobador = true;
    else if ( area() != cuadradoi.area() )
      comprobador = false;

    return comprobador;
  }
  bool is_square_in(const Cuadrado & cuadradoi) const{
    bool comprobador;
    if ( cuadradoi.Punto.x >= Punto.x &&
      (cuadradoi.Punto.x + cuadradoi.longitud) <= ( Punto.x + longitud) &&
      cuadradoi.Punto.y >= Punto.y &&
        (cuadradoi.Punto.y + cuadradoi.longitud) <= ( Punto.y + longitud) ){
      comprobador = true;
        }
    else
      comprobador = false;

    return comprobador;
  }


private:
  CPunto Punto;
  int longitud;
};


Cuadrado leerCuadrado(){
  CPunto puntoi;
  int longitud;

  cout << "Introduzca el punto (x,y) donde se haya el cuadrado" << endl;
  cin >> puntoi.x >> puntoi.y;
  cout << "introduzca la longitd del cuadrado" << endl;
  cin >> longitud;

  Cuadrado cuadradoi (puntoi, longitud);

  return cuadradoi;
}
//En el examen solo piden el modulo pero para comprobar que funciona tengo que hacer tambien la lectura etc.
int main(){
  vector <Cuadrado> vector_cuadrados;
  Cuadrado cuadradop;
  bool comprobador = true;

  cout << "Introduce el cuadrado a comparar con el vector" << endl;
  cuadradop = leerCuadrado();

  while (comprobador){
    vector_cuadrados.push_back( leerCuadrado() );
    cout << "Para parar de introducir cuadrados teclee 0 de lo contrario teclee 1" << endl;
    cin >> comprobador;
  }

  int contador = 0;

  for (unsigned int i; i < vector_cuadrados.size() ; i++ ){
    if (cuadradop.is_square_in(vector_cuadrados[i]) )
      contador += 1;
  }
  cout << " Hay " << contador << " cuadrados contenidos en el primero" << endl;
}
