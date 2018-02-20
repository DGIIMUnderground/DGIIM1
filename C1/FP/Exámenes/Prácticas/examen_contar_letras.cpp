// Examen parcial FP noviembre 2013
// Enunciado: http://bit.ly/2AhrY0L
// Ric

#include <iostream>

using namespace std;

/**
    @brief Evalua si un carácter es una letra o no.
    @param letra: letra a evaluar
    @return true si es letra, false si no.
    (Rango de mayúsculas [A-Z]-> [65-90])
*/
bool es_letra(char letra) {
    return (letra >= 65 && letra <= 90);
}

/**
    @brief Evalua si una letra es vocal o no.
    @param letra. Letra a evaluar
    @return true si es vocal, false si no lo es.
*/
bool es_vocal(char letra) {
    return (letra == 'A' ||
            letra == 'E' ||
            letra == 'I' ||
            letra == 'O' ||
            letra == 'U');
}

int main() {

    char letra, vocal_min, cons_max;
    int n_vocal_min=0, n_cons_max=0;
    int n_vocales=0, n_cons=0, n_letras=0;
    float razon_vocales, razon_consonantes;

    cin >> letra;

    vocal_min = 'U'; // Nos aseguramos que cualquiera sea menor que vocal_min
    cons_max = 'B';  // Nos aseguramos que cualquiera sea mayor que cons_max

    while (letra != '.') {

        if (es_letra(letra)) {
            n_letras++;

            if (es_vocal(letra)) {

                // Encontramos nueva vocal mínima
                if (letra < vocal_min) {
                    vocal_min = letra;
                    n_vocal_min = 1;
                } else if (letra == vocal_min) {
                    n_vocal_min++;
                }

                n_vocales++;
            } else {

                // Encontrada nueva consonante máxima
                if (letra > cons_max) {
                    cons_max = letra;
                    n_cons_max = 1;
                } else if (letra == cons_max) {
                    n_cons_max++;
                }
            }
        }
        cin >> letra;
    }

    razon_vocales = (float) n_vocales/ (float) n_letras;
    razon_consonantes = 1 - razon_vocales;

    cout << "Vocal mínima: " << vocal_min;
    cout << "  Cuantas: " << n_vocal_min;
    cout << "  Proporción de vocales: " << razon_vocales << endl;

    cout << "Consonante máxima: " << cons_max;
    cout << "  Cuantas: " << n_cons_max;
    cout << "  Proporción de consonantes: " << razon_consonantes << endl;
}
