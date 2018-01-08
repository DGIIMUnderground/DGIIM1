/*Desarrolle un programa para localizar una cadena dentro de otra. El programa leerá dos cadenas desde la entrada estándar, buscará la primera en la segunda, y escribirá en la salida estándar la posición donde
se encuentra -en caso de encontrarla- o un mensaje indicando que no se ha localizado. Un ejemplo de ejecución es el siguiente:
Introduzca la primera cadena: mundo
Introduzca la segunda cadena: Hola mumumundo
"mundo" Se encuentra en la posición 5 de "Hola mundo"
Tenga en cuenta que no podrá usar ningún método de la clase string salvo el acceso a cada uno de los caracteres de las cadenas y al tamaño de las cadenas. En particular, no se puede utilizar el método find.*/

#include <iostream>
#include <string>

using namespace std;

int main ()
{
    string cadenabuscada;
    string cadenaprincipal;

    cout << "Introduzca la cadena que se desea buscar" << endl;
    getline (cin, cadenabuscada);
    cout << "Introduzca la cadena donde se buscara" << endl;
    getline (cin, cadenaprincipal);

    //Quiza seria conveniente declarar enteros con los ttamaños de las cadenas introducidas, por legibilidad, yo en est caso no lo he hecho.

    if (cadenabuscada.length() > cadenaprincipal.length())
    {
        cout << "El número de caracteres de la cadena a buscar debe ser menor que el de la cadena donde se busca" << endl;
    }
    else
    {
        int posicion = 0;
        bool encontrado = false;
        string auxiliar;
        while (!encontrado && posicion <= cadenaprincipal.length()-cadenabuscada.length())
        {
            auxiliar = cadenaprincipal.substr(posicion,cadenabuscada.length());
            //Recordatororio: substr(x,y) coge y caracteres a partir del caracter x (x incluido)

            if (auxiliar == cadenabuscada)
                encontrado = true;
            else
                posicion++;
        }
        if (encontrado)
                cout << "La cadena " << cadenabuscada << " se encuentra en la posicion " << posicion << endl;
        else
            cout << "No se ha encontrado la cadena" << endl;
    }
}

//By Mapachana
