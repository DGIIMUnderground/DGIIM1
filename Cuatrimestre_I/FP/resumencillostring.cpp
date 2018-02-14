#include <iostream>
#include <string>

using namespace std;

int main()
{
    string ejemplo = "Hace un bonito y precioso dia"; //Inicializacion de string
    string auxiliar1; //Declaracion de string
    string auxiliar2;

    cout << ejemplo << endl; //Muestra una cadena de caracteres
    getline (cin, auxiliar1); //Como cin, pero para string
    cout << auxiliar1 << endl;

    string auxiliar3 (auxiliar1, 4, 3); //A partir del caracter 4 muetsra 3 caracteres. OJO NO INTRODUZCAS auxiliar1 CON MENOS DE 8 CARACTERES. Yo probe con 0123456789 como entrada, ilustra bien.
    cout << auxiliar3 << endl;

    string aux = auxiliar1 + auxiliar3; //LLevan el operador + sobrecargado. += lo añade al final
    cout << aux << endl;

    aux = ejemplo.substr(8, 6); //Se queda con lo que 6 caracteres a partir del 8
    cout << aux << endl;

    string aux2 = aux.erase(2, 2); //Elimina 2 caracteres a partir del caracer 2
    cout << aux2 << endl;

    aux2 = ejemplo.insert(ejemplo.size(), " para morirse"); //Añade la frase a partir del caracter indicado, en este caso el ultimo ".size()"
    cout << aux2;

//By Mapachana (?)
}
