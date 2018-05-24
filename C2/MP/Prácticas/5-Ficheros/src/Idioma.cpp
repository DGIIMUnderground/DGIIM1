/**
 * @file Idioma.cpp
 * @author DECSAI
 * @warning Código incompleto. Implementar la clase completa
*/

#include "Idioma.h"
#include "Bigrama.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

//Constructores
Idioma::Idioma(){
    this->_idioma    = "NULL";
    this->_conjunto  = nullptr;
    this->_nBigramas = -1;
}

Idioma::Idioma(int nbg){
    this->_idioma    = "NULL";
    reservarMemoria(nbg);
}


void Idioma::reservarMemoria(int n){
    if (this->_conjunto != nullptr)
        this->liberarMemoria();
    
    if (n > 0){
        this->_nBigramas = n;
        this->_conjunto  = new Bigrama [this->_nBigramas];
    }
}

void Idioma::ampliarMemoria(int n){
    //Copia de la memoria a uno temporal
    if (n > 0){
        Bigrama * temporal = new Bigrama [this->_nBigramas + n];
        for (unsigned int i=0; i<this->_nBigramas; i++){
            temporal[i].setBigrama(this->_conjunto[i].getBigrama());
            temporal[i].setFrecuencia(this->_conjunto[i].getFrecuencia());
        }
        delete [] this->_conjunto;

        this->_nBigramas += n; 
        this->_conjunto   = temporal;
    }
}

void Idioma::liberarMemoria(){
    this->_nBigramas = -1;
    delete [] this->_conjunto;
}

Bigrama Idioma::getPosicion(int p) const{
    if (p>=0 && p < this->_nBigramas)
        return this->_conjunto[p];
    else
        cerr << "Error: índice p erróneo";
}

void Idioma::setPosicion(int p, const Bigrama & bg){
    if (p < this->_nBigramas && p>=0){
        this->_conjunto[p].setFrecuencia(bg.getFrecuencia());
        this->_conjunto[p].setBigrama(bg.getBigrama());
    }
    else
        cerr << "Error: índice p erróneo";
}

int Idioma::findBigrama(const string bg) const {   
    for (unsigned int i=0; i < this->_nBigramas; i++){
        if (strcmp( this->_conjunto[i].getBigrama(), bg.c_str()) == 0){
            return i;
        }
    }

    return -1;
}

void Idioma::addBigrama(const Bigrama & bg){
    int posicion = this->findBigrama(bg.getBigrama());
    
    if (posicion > -1)
        this->_conjunto[posicion].setFrecuencia(bg.getFrecuencia() + this->_conjunto[posicion].getFrecuencia());
    else{
        Idioma::ampliarMemoria(1);
        this->_conjunto[this->_nBigramas-1].setFrecuencia(bg.getFrecuencia());
        this->_conjunto[this->_nBigramas-1].setBigrama(bg.getBigrama());
    }
}

bool Idioma::cargarDeFichero(const char * fichero){ //El argumento es el fichero a leer
    ifstream entrada;
    entrada.open(fichero);
    
    if (entrada){
        string codificacion, idioma;
        int dimension;
        
        entrada >> codificacion;
        if (codificacion == "MP-BIGRAMAS_IDIOMA-T-1.0")
            cout <<"Codificación correcta"<<endl;
        else{
            cerr <<"Fallo en la codificación"<<endl;
            entrada.close();
            return false;
        }
        
        entrada >> idioma;
        if (this->_idioma == idioma || this->_idioma == "NULL"){
            cout <<"Idioma captado: "<<idioma<<endl;
            this->setIdioma(idioma);
        }
        else{
            cerr <<"Fallo en la lectura del idioma. El idioma actual "<<this->_idioma<<" no es compatible con "<<idioma<<endl;
            entrada.close();
            return false;
        }
        
        entrada >> dimension;
        cout <<"Recibida dimensión de tamaño "<<dimension<<endl;
        
        int contador_lineas = 0;
        int frecuencia_temp;
        string bigrama_temp;
        this->reservarMemoria(dimension);

        for (contador_lineas; contador_lineas < dimension; contador_lineas++){
            if (!entrada.eof()){
                entrada >> bigrama_temp;
                entrada >> frecuencia_temp;
   
                this->_conjunto[contador_lineas].setBigrama(bigrama_temp.c_str());
                this->_conjunto[contador_lineas].setFrecuencia(frecuencia_temp);

            }
            else{
                cerr <<"Error: dimensión dada es menor de la cantidad de bigramas que hay"<<endl;
                entrada.close();
                return false;
            }
        }

        if (dimension > contador_lineas + 2){
            cerr <<"Error: la dimensión dada es mayor que el número de bigramas presente"<<endl;
            entrada.close();
            return false;
        }
    }
    else{
        cerr <<"No existe el archivo "<<fichero<<endl;
        return false;
    }

    entrada.close();
    return true;
}

bool Idioma::addDeFichero(const char * fichero){
    ifstream entrada;
    entrada.open(fichero);
    
    //No hay diccionario => 
     if (this->_conjunto == nullptr){
        if (this->cargarDeFichero(fichero))
            return true;
        else
            return false;    
    }
 
    //Si hay idioma cargado
    if (fichero){
        string codificacion, idioma;
        int dimension;

        entrada >> codificacion;
        entrada >> idioma;

        if (this->getIdioma() == idioma){
            int dimension;
            entrada >>dimension;

            Bigrama bigrama_temp;
            string bigrama_leido;
            int frecuencia_temp;

            for (unsigned int i=0; i<dimension; i++){
                entrada >>bigrama_leido;
                entrada >>frecuencia_temp;
                
                bigrama_temp.setBigrama(bigrama_leido.c_str());
                bigrama_temp.setFrecuencia(frecuencia_temp);
                
                this->addBigrama(bigrama_temp);
            }
        }
        else{
            cerr <<"Error: los idiomas leídos son diferentes";
            entrada.close();
            return false;
        }

    }
    else{
        cerr <<"No se ha encontrado el archivo";
        return false;
    }

    entrada.close();
    return true;
}
