/**
 * @file main.cpp
 * @author DECSAI
 * @warning Código incompleto. Completar donde se indica
*/
#include <iostream>
#include <cstring>
#include "Bigrama.h"
#include "Idioma.h"
using namespace std;

int main(int narg, char * args[]) {
    cout <<endl;

    if (narg  < 3)  {
        cerr << "Error en la llamada.\n   idioma <bigrama> <fich1.bgr> <fich2.bgr> ..."<<endl;
        return 0;
    }

    Idioma nuevo_idioma;
    bool checker = true;

    checker = nuevo_idioma.cargarDeFichero(args[2]);
    if (checker)
        checker = nuevo_idioma.cargarDeFichero(args[3]);

    if (!checker){
        nuevo_idioma.liberarMemoria();
        return 0;
    }

    if (nuevo_idioma.addDeFichero(args[2]))
        cout <<"Archivos sumados correctamente\n";
     
    int localizacion = nuevo_idioma.findBigrama(args[1]);
    Bigrama bigrama_deseado;
    
    if (localizacion == -1)
        cerr <<"Error: no se ha encontrado "<<args[0]<<" en la lista del idioma";
    else{
        bigrama_deseado.setBigrama(nuevo_idioma.getPosicion(localizacion).getBigrama());
        bigrama_deseado.setFrecuencia(nuevo_idioma.getPosicion(localizacion).getFrecuencia());
    }

    cout <<"El bigrama "<<bigrama_deseado.getBigrama()<<" tiene una frencuencia de "<<bigrama_deseado.getFrecuencia();
    cout <<" en el idioma "<<nuevo_idioma.getIdioma()<<" ("<<nuevo_idioma.getSize()<<" bigramas)";
        
    nuevo_idioma.liberarMemoria();
    
    cout<<endl;
    return 0;
}