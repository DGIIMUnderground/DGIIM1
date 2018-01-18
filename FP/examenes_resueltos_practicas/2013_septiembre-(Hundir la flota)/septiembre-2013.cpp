//AUTHOR: Gonzalo Moreno Soto
//Implementación del juego "Hundir la flota" en C++
//ACLARACION: En el pdf del examen especifica respecto a la colocación de barcos
//            "* Los barcos no pueden tocarse entre si"
//            Esto puede estar sujeto a interpretaciones, yo lo interpreté como
//            que eso suponía que unos barcos no podían solaparse con otros, es
//            decir, en mi solución es posible poner varios barcos consecutivos
//            lo que complica enormemente el método Tablero::disparar a la hora
//            de comprobar si el barco se ha hundido o no.
//            Si interpretáramos esta restricción como un impedimento para que
//            pudiera haber barcos consecutivos, la comprobación de si el barco
//            se encuentra hundido o no podría hacerse más fácilmente por medio
//            de la suma de las casillas adyacentes a él en vertical u horizon-
//            tal en el radio de la longitud del barco y comprobando si el va-
//            lor de la suma es igual al cuadrado de la longitud del barco. De
//            serlo, el barco se encontraría hundido.
//
//            Por otro lado, esto complicaría el método Tablero::colocar_barco,
//            sin embargo, opino que habría resultado más sencilla esta inter-
//            pretación que la que he hecho.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Coordenada   {
  int fila;
  int columna;
};

struct Barco  {
  Coordenada coordenadas;
  unsigned int longitud;
  char direccion;
};

class Tablero {
  private:

    vector <vector <int>> tablero;
    vector <Barco> barcos;

  public:

    /**
    * @brief: Constructor primitivo y por defecto
    * Inicializa un tablero vacío
    */
    Tablero();

    /**
    * @brief: Comprueba si la casilla asginada está libre
    * @param coordenadas: Coordenada a comprobar
    * @return: true si está libre, false si no
    */
    bool casilla_libre(Coordenada coordenadas) const;

    /**
    * @brief: Coloca un barco en el tablero
    * @param barco: Barco que se coloca en la posición indicada
    * @return: true si el barco ha sido colocalo, false si da error
    */
    bool colocar_barco(Barco barco);

    /**
    * @brief: Dispara a las coordenadas especificadas
    * @param coordenadas: Coordenadas de disparo
    * @return: "Agua/Tocado/Hundido/No válido" en función
                del resultado del disparo
    */
    string disparar(Coordenada coordenadas);
};

Tablero::Tablero() {
  vector <int> filas(10,0);
  vector <vector <int>> columnas(10,filas);
  vector <Barco> barcos(0);
}

bool Tablero::casilla_libre(Coordenada coordenadas) const {
  bool libre = false;

  if (coordenadas.fila < 10 and coordenadas.columna < 10) {

    if (tablero[coordenadas.columna][coordenadas.fila] == 0)  {
      libre = true;
    }

  }
  return libre;
}

bool Tablero::colocar_barco(Barco barco) {
  bool posible = true;

  Coordenada inicio = barco.coordenadas;

  for (int i = 0; i<barco.longitud; i++)  {

    if (barco.direccion == 'H') {

      if (Tablero::casilla_libre(inicio) == false) {
        posible = false;
      }
      inicio.columna++;

    } else if (barco.direccion == 'V') {

      if (Tablero::casilla_libre(inicio) == false) {
        posible = false;
      }
      inicio.fila++;

    } else  {

      posible = false;

    }

  }

  inicio = barco.coordenadas;

  if (posible == true) {

    if (barco.direccion == 'H') {

      for (int i = 0; i<barco.longitud; i++)  {

        tablero[inicio.columna][inicio.fila] = barco.longitud;
        inicio.columna++;

      }

    } else if (barco.direccion == 'V')  {

      for (int i = 0; i<barco.longitud; i++)  {

        tablero[inicio.columna][inicio.fila] = barco.longitud;
        inicio.fila++;

      }

    }

  }

  barcos.push_back(barco);

  return posible;

}

string Tablero::disparar(Coordenada coordenadas)  {
  string result;
  if (coordenadas.fila < 10 and coordenadas.columna < 10) {

    if (tablero[coordenadas.columna][coordenadas.fila] > 0) {

      result = "Tocado! Barco de longitud " + tablero[coordenadas.columna][coordenadas.fila];
      tablero[coordenadas.columna][coordenadas.fila] = -tablero[coordenadas.columna][coordenadas.fila];

      for (int i = 0; i < barcos.size(); i++) {
        Coordenada inicio = barcos[i].coordenadas;

        if (barcos[i].direccion == 'H') {

          for (int j = 0; j<barcos[i].longitud; j++)  {

            if (inicio.fila == coordenadas.fila and inicio.columna == inicio.columna) {
              int hundimiento = 0;

              for (int k = 0; k<barcos[i].longitud; k++)  {

                hundimiento += tablero[inicio.columna][inicio.fila];
                inicio.columna++;

              }

              if (hundimiento == barcos[i].longitud*barcos[i].longitud) {
                result = "Hundido! Barco de longitud " + tablero[coordenadas.columna][coordenadas.fila];
              }

            }

            barcos[i].coordenadas.columna++;
          }

        } else if (barcos[i].direccion == 'V') {

          for (int j = 0; j<barcos[i].longitud; j++)  {

            if (inicio.fila == coordenadas.fila and inicio.columna == coordenadas.columna) {
              int hundimiento = 0;

              for (int k = 0; k<barcos[i].longitud; k++)  {

                hundimiento += tablero[inicio.columna][inicio.fila];
                inicio.fila++;

              }

              if (hundimiento == barcos[i].longitud*barcos[i].longitud) {
                result = "Hundido! Barco de longitud " + tablero[coordenadas.columna][coordenadas.fila];
              }

            }

            barcos[i].coordenadas.fila++;
          }


        }

      }

    } else if (tablero[coordenadas.columna][coordenadas.fila] == 0) {

      result = "Agua!";
      tablero[coordenadas.columna][coordenadas.fila] = -10;

    } else  {
      result = "No valido: ya se ha disparado a esa posición.";
    }

  } else  {
    result = "No válido: se sale del tablero.";
  }
  return result;
}

int main()  {}
