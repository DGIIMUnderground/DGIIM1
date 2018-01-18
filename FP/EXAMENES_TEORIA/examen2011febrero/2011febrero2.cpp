// By Mapachana, Ric.

/*
Desarrolle un programa para localizar una cadena dentro de otra. El programa
leerá dos cadenas desde la entrada estándar, buscará la primera en la segunda,
y escribirá en la salida estándar la posición donde se encuentra -en caso de
encontrarla- o un mensaje indicando que no se ha localizado.

Un ejemplo de ejecución es el siguiente:

Introduzca la primera cadena: mundo
Introduzca la segunda cadena: Hola mumumundo

"mundo" Se encuentra en la posición 5 de "Hola mundo".

Tenga en cuenta que no podrá usar ningún método de la clase string salvo
el acceso a cada uno de los caracteres de las cadenas y al tamaño de las
cadenas. En particular, no se puede utilizar el método find.
*/

#include <iostream>
#include <string>

using namespace std;

// Advertencia:
// El uso de tildes en las cadenas introducidas rompe
// el programa, pues la longitud de una cadena de tipo string ("áá")
// es 4!
// Para solucionar esto se podría usar el tipo de dato wstring

/**
 @brief: Devuelve la posición de una subcadena de una cadena.
 @param subcad: subcadena a buscar.
 @param cad: cadena en la que buscar.
 @return: el índice de la subcadena en cadena si es encontrada.
 -1 en caso contrario, y, en particular, cuando la subcadena es de mayor
 longitud que la cadena.
*/
int buscar_subcadena(string subcad, string cad) {

    int nletras = 0; // Numero de letras de subcad encontradas en cad
    
    if (subcad.length() > cad.length())
        return -1;

    for (int i=0; i < cad.length(); i++) {

        // Cuando nletras es igual a 0, recorremos cad
        // hasta llegar que se coincida con la primera letra de subcad
        if (cad[i] == subcad[nletras]) {
            nletras++; // Nueva letra identificada

            // Si subcad está al completo, devolvemos el índice por
            // el que comienza
            if (nletras == subcad.length()) {
                return (i - subcad.length()+1);
            }
        } else if (nletras != 0)
            nletras = 0; // Esto permite saltar las letras
    }
    return -1;
}

int main() {
    string cadena, subcadena;

    cout << "Introduzca la primera cadena: ";
    getline(cin, subcadena);

    cout << "Introduzca la sugunda cadena: ";
    getline(cin, cadena);

    int pos = buscar_subcadena(subcadena, cadena);

    cout << "\"" << subcadena << "\"";
    if (pos != -1) {
        cout << " Se encuentra en la posición " << pos;
        cout << " de ";
    } else {
        cout << " no se encuentra en ";
    }
    cout  << "\"" << cadena << "\"" << endl;
}
