/**
   @file main.cpp
   @author decsai.ugr.es
**/

//By Asmilex 
#include <cstdlib>
#include <string>
#include <iostream>

#include "secuenciapaquete.h"

using namespace std;

// filtro para leer numeros > 0
double leeNatural(const string &msg){
    double dato;
    do {
        cout << msg;
        cin >> dato;
    } while(dato <= 0 );
    return dato;
}

int leeId(const string & msg, int id_anterior=Paquete::_SIN_IDENT){ // Parámetro con valor por defecto
    int id;
    do {
        cout << msg;
        cin >> id;
    } while(id <= id_anterior && id != Paquete::_SIN_IDENT);
    return id;
}

int main() {
    const string MSGPESO = "Introduce peso en kg (>0): ";
    const string MSGDATO = "Introduce medidas en cm (> 0): ";
    const string MSGID = "Introduce identificador de paquete:  ";
    const string SALIDATOTAL = "\nLa facturacion total es: ";
    const string SALIDANUMPACK = "Número de paquetes mas caros: ";
    const string SALIDANUMPACKMASALTOS = "Número de paquetes mas altos que 100: ";
    const string SALIDAIDMASVOL = "Identificador del paquete más grande: ";    
    const string SALIDAMASVOL = "Volumen del paquete más grande: ";
    const string SALIDAMASPESOVOL = "Peso Volumetrico del paquete más grande: ";    
    const string SALIDAMEDIA = "Precio medio de facturacion: ";
    const string NODATOS = "No se han introducido datos";
    const string DATOSLEIDOS = "Número de paquetes leídos: ";
    const int FIN_DATOS = Paquete::_SIN_IDENT;

    long identificador=Paquete::_SIN_IDENT;
    double peso;
    int  largo, ancho, alto;
    int nEnvios = 0;

    Paquete envios[MAXPAQ];
    int enviosUtiles=0;
    
    cleanSecuenciaPaq(envios, enviosUtiles);

    identificador = leeId(MSGID, identificador);
    while(identificador != FIN_DATOS && enviosUtiles < MAXPAQ) { 
        peso = leeNatural(MSGPESO);
        largo = leeNatural(MSGDATO);
        ancho = leeNatural(MSGDATO);
        alto = leeNatural(MSGDATO);

        Paquete nuevo (identificador, peso, largo, ancho, alto); 
        if (nEnvios < MAXPAQ){ 
            addSecuenciaPaq(envios, enviosUtiles, nuevo);  	
            nEnvios++;
        }
        identificador = leeId(MSGID, identificador);
    } 
    cout << endl << endl << DATOSLEIDOS << nEnvios << endl;
    if (enviosUtiles> 0) {
        Paquete grande(paqueteMayorSecuenciaPaq(envios, enviosUtiles)); 
        cout <<  SALIDATOTAL << getTotalSecuenciaPaq(envios, enviosUtiles) << endl;
        cout <<  SALIDAMEDIA << getMediaSecuenciaPaq(envios, enviosUtiles) << endl;
        cout <<  SALIDANUMPACKMASALTOS << numPaqueteAltosSecuenciaPaq(envios, enviosUtiles, 100) << endl; 
        cout <<  SALIDANUMPACK << numPaquetesSuperiorSecuenciaPaq(envios, enviosUtiles) << endl;
        cout <<  SALIDAIDMASVOL << grande.getId() << endl;
        cout <<  SALIDAMASVOL << grande.getVolumen() << endl;
        cout <<  SALIDAMASPESOVOL << grande.calculaPesoVolumetrico() << endl;
    }
    else
        cout << NODATOS << endl;
    return 0;
}
