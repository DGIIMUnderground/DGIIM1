// Ric
#include <iostream>
#include <string>

using namespace std;

/**
    @brief: Indica el ganador de un partido
    @param puntosA: el número de puntos anotados por
    el equipo A.
    @param puntosB: el número de puntos anotados por
    el equipo B.
    @return: Equipo X (donde X es el ganador) 
             O empate
**/
string ganador(int puntosA, int puntosB) {
    string resultado;

    if (puntosA > puntosB)
        resultado = "Equipo A";
    else if (puntosB > puntosA)
        resultado = "Equipo B";
    else
        resultado = "Empate";
    return resultado;
}


int main() {

    char equipo;
    string ganador_parcial, ganador_final;
    int puntos, puntosA=0, puntosB=0;
    int triples=0, minutos, tiempo_antes=0;

    while (true) {

        cin >> equipo;

        // Finalizamos con la letra S
        if (equipo == 'S')
            break;

        cin >> puntos;
        cin >> minutos;


        // Detecta cuando se produce el cambio de la segunda a
        // la primera parte, y calcula el ganador de la primera
        // parte.
        
        if (tiempo_antes <= 19 && minutos > 19) {
            ganador_parcial = ganador(puntosA, puntosB);
        }


        // Preguntamos al usuario hasta que equipo sea A o B
        while (equipo != 'A' && equipo != 'B') {
            cout << "Sólo permitidos equipos A/B" << endl;
            cout << "Introduzca de nuevo el equipo: ";
            cin >> equipo;
        }

        
        // Preguntamos al usuario hasta que los puntos estén en [1,3]
        while (puntos < 1 || puntos > 3) {
            cout << "Un equipo sólo puede anotar 1,2 o 3 puntos." << endl;
            cout << "Introduzca de nuevo el valor de los puntos: ";
            cin >> puntos;
        }

        // Minutos positivos
        while (minutos < 0) {
            cout << "No están permitidos los minutos negativos: " << endl;
            cout << "Introduzca de nuevo el valor de los minutos: ";
            cin >> minutos;
        }

        if (puntos == 3) 
            triples++;

        switch (equipo) {
            case 'A':
                puntosA += puntos;
                break;
            case 'B':
                puntosB += puntos;
                break;
        }

        // Esto nos permite registrar el tiempo anterior.
        tiempo_antes = minutos;
    } 

    ganador_final = ganador(puntosA, puntosB);
    cout << "Ganador de la primera parte: " << ganador_parcial << endl;
    cout << "Ganador del partido: " << ganador_final << endl;
    cout << "Marcador final: " << puntosA << "-" << puntosB << endl;
    cout << "Número total de triples: " << triples << endl;
}
