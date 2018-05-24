/** 
 * @file Bigrama.cpp
 * @author Andres Millan - DECSAI
*/

#include <cstring>
#include <iostream>
#include "Bigrama.h"

using namespace std;


Bigrama::Bigrama() {
    _bigrama[0] = '\0';
    _frecuencia = -1;
}

inline const char * Bigrama::getBigrama() const{
    return this->_bigrama;
}

inline int Bigrama::getFrecuencia() const{
    return this->_frecuencia;
};

void Bigrama::setBigrama(const char cadena[]){
    bool interruptor = false;

    //Comprobación de longitud correcta
    if (cadena[2] == '\0')
        interruptor = true; 

    //Nota: originalmente, había un mensaje de error para comprobación de longitud correcta, pero fallaba con las tildes
    if (interruptor == true){
        this->_bigrama[0] = cadena [0];
        this->_bigrama[1] = cadena [1];
        this->_bigrama[2] = '\0';
    };
};

inline void Bigrama::setFrecuencia(int frec){
    this->_frecuencia = frec;
}


void imprimeBigramas(const Bigrama *v, int n)  {
    cout << "Lista de " << n << " bigramas:" <<endl;
    for (int i=0; i<n; i++)
        cout << v[i].getBigrama() << "-" << v[i].getFrecuencia()<< ", "; // << endl;
}

void ordenaAscBigr(Bigrama * v, int n){
    Bigrama Intercambio;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (strcmp(v[j].getBigrama(),v[i].getBigrama()) > 0){
                                
                Intercambio.setFrecuencia(v[i].getFrecuencia());
                Intercambio.setBigrama(v[i].getBigrama());

                v[i].setFrecuencia(v[j].getFrecuencia());
                v[i].setBigrama(v[j].getBigrama());

                v[j].setFrecuencia(Intercambio.getFrecuencia());
                v[j].setBigrama(Intercambio.getBigrama());
            }
}

void ordenaAscFrec(Bigrama * v, int n){
    Bigrama Intercambio;
    for (int i=0; i<n; i++)
        for (int j=i; j<n; j++)
            if (v[j].getFrecuencia() < v[i].getFrecuencia()){
                Intercambio.setFrecuencia(v[i].getFrecuencia());
                Intercambio.setBigrama(v[i].getBigrama());

                v[i].setFrecuencia(v[j].getFrecuencia());
                v[i].setBigrama(v[j].getBigrama());

                v[j].setFrecuencia(Intercambio.getFrecuencia());
                v[j].setBigrama(Intercambio.getBigrama());
            }
}

void sumaBigramas(const Bigrama * v1, int nv1, const Bigrama * v2, int nv2, Bigrama *& res, int & nres){
    nres = nv1;                             //por pre
    
    for (unsigned int i=0; i<nres; i++){
        res[i].setFrecuencia(v1[i].getFrecuencia() + v2[i].getFrecuencia());
        res[i].setBigrama(v1[i].getBigrama());
    }
}