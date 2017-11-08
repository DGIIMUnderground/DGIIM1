// Examen parcial FP noviembre 2013
// Enunciado: http://bit.ly/2AhrY0L
// Ric

/*

ft Jose:

OBSERVACIÓN: cuando no se introduce ninguna vocal y/o ninguna consonante, la salida muestra vocal_min=U y vocal_max=B, lo cual no puede pasar puesto que no hemos introducido ninguna letra. Lo arreglo así:

inicializo vocal_min='V', que es el carácter posterior en la tabla ascii a la última consonante (no me lo saco de manga, la letra V va después de la U. Así, cuando no tenemos ninguna vocal, la vocal mínima es V, caso en el que hago que no se muestre con un if en el cout de la salida
Igualmente, inicializo cons_max='A', que es el carácter anterior a la primera consonante. Si no tenemos consonantes, la consonante máxima es A, caso en el que no la muestro.
 
***FUNCIONA***

Si alguien ve inadecuado meter ifs entre couts que proponga otra solución ;)

 */

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

    /* Antes:
    vocal_min = 'U'; // Nos aseguramos que cualquiera sea menor que vocal_min
    cons_max = 'B';  // Nos aseguramos que cualquiera sea mayor que cons_max
    
    Ahora:			*/
    
    vocal_min = 'V'; // Nos aseguramos que cualquiera sea menor que vocal_min
    cons_max = 'A';  // Nos aseguramos que cualquiera sea mayor que cons_max
    

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

    /*
    Antes:
    cout << "Vocal mínima: " << vocal_min;
    cout << "  Cuantas: " << n_vocal_min;
    cout << "  Proporción de vocales: " << razon_vocales << endl;

    cout << "Consonante máxima: " << cons_max;
    cout << "  Cuantas: " << n_cons_max;
    cout << "  Proporción de consonantes: " << razon_consonantes << endl;
    
    Ahora: 			*/
    
    cout << "Vocal mínima: ";
    if(vocal_min!='V'){	//esto es, si en algún momento hemos encontrado alguna vocal. tmb vale vocal_min<'V'
    	cout << vocal_min;
    	cout << "  Cuantas: " << n_vocal_min;
    }
    else{
    	cout << "No hay vocales";
    }
    
    cout << "  Proporción de vocales: " << razon_vocales << endl;

    
    cout << "Consonante máxima: ";
    if(cons_max!='A'){	//esto es, si en algún momento hemos encontrado alguna consonante. tmb vale cons_max>A
    	cout << cons_max;
    	 cout << "  Cuantas: " << n_cons_max;
    }
    else{
    	cout << "No hay consonantes";
    }
   
    cout << "  Proporción de consonantes: " << razon_consonantes << endl;
    
}
