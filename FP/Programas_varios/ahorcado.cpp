#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef string str;


bool alphasolo (const str & palabra){
    bool comprobacion = true;

    for (int i = 0; i < palabra.length(); ++i){
      if ( ! islower(palabra[i]))
        comprobacion = false;
    }
    return comprobacion;
}

str tolowerStr (const str & palabra){
  str palabra2("-",palabra.length());

  for (int i = 0; i < palabra.length(); ++i)
    palabra2[i] = tolower(palabra[i]);
  return palabra2;

}


str inicioJuego(){
  str palabra;

  cout << "Hay dos jugadores:" << endl;
  cout << "\t 1.- El que se inventa la palabra" << endl;
  cout << "\t 2.- El adivina la palabra" << endl;
  cout << "\n \n Jugador1: Escriba una palabra" << endl;
  cout << "Jugador 2 : ¡No Mires!" << endl;
  cout << "La palabra debete tener al menos una letra: " << endl;
  getline( cin, palabra);

  while ( ! alphasolo( tolowerStr (palabra) ) || palabra.length() <= 0 ){
    cout << "La palabra debete tener al menos una letra: ";
    getline(cin, palabra);
  }
  return palabra;
}

bool comprobarPalabra(const char & letra, const str & palabra){
  bool comprobacion = false;

  for (int i = 0; i < palabra.length(); ++i){
    if (palabra[i] == letra)
      comprobacion = true;
  }
  return comprobacion;
}
int numeroRepeticiones(const char & letra, const str & palabra){
  int numero = 0;

  for (int i = 0; i < palabra.length(); ++i){
    if (palabra[i] == letra)
      numero ++;
  }
  return numero;
}


int main (){
  int intentos_permitidos;
  int intentos_hechos = 0;
  bool acertar = false;
  str palabra (tolowerStr (inicioJuego() ) );
  str palabra2 (palabra);
  str palabra_cubierta (palabra.length(),'-');
  str caracteresusados (palabra.length(),' ');
  char letra;

  cout << "Jugador 1: ¿De cuántos intentos disponemos?" << endl;
  cin >> intentos_permitidos;

  while (intentos_permitidos > 0 && acertar == false ){
    cout << "La palabra es: " << palabra_cubierta << endl;
    cout << "Letras usadas: " << caracteresusados << endl;
    cout << "Intentos     : " << intentos_permitidos << endl;
    cout << "Dime una letra: " << endl;
    cin >> letra;

    if (comprobarPalabra(letra,palabra) && ! comprobarPalabra(letra,caracteresusados)){
      cout << "Bien la letra está en la palabra oculta" << endl;
      int numero_repeticiones = numeroRepeticiones(letra,palabra);

      for (int i = 0; i < numero_repeticiones ; i++){
        int posicion_letra = palabra2.find(letra);
        palabra_cubierta[posicion_letra] = letra;
        caracteresusados[intentos_hechos] = letra;
        palabra2[posicion_letra] = '-';
      }
    }
    else if (comprobarPalabra(letra,caracteresusados))
      cout << "Esa letra ya la dijiste" << endl;
    else{
      cout << "Mal, la letra no esta" << endl;
      intentos_permitidos --;
    }
    if (palabra_cubierta == palabra){
      cout << "¡Has ganado!" << endl;
      acertar = true;

    }

    intentos_hechos ++;
  }


  }
