

/* 
 * File:   main.cpp
 * Author: Juan Helios DGIIM:
 *
 * Created on 12 de mayo de 2018, 13:23
 */

#include <fstream>
#include <iostream>
#include "VectorSD.h"
using namespace std;

#include <iostream>
#include <fstream> // ifstream
using namespace std;
int main(int argc, char* argv[]){
    VectorSD v;
    VectorSD vCopia;
    if (argc==1)
        cin >> v;
    else {
        ifstream flujo(argv[1]);
        if (!flujo) {
            cerr << "Error: Fichero " << argv[1] << " no válido." << endl;
            return 1;
    }
        flujo >> v;
    }
    
    //COMPROBAR QUE FUNCIONA LA SUMA Y DEMÁS
    vCopia = v; // se usa operador de asignación
    ordenar(vCopia); // Ordenamos la copia
    cout << "Array original:" << endl;
    cout << v;
    cout << "\nArray copia:" << endl;
    cout << vCopia << endl;
    
    v+= 5;
    cout << "Array + 5: " << endl;
    cout << v << endl;
    cout <<"Copia - 5: " << endl;
    vCopia -= 5;
    cout << vCopia << endl;
    string wenas = (v <= vCopia)? "menor": "mayor";
    cout << wenas;
}

