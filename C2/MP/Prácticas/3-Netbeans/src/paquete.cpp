/**
   @file paquete.cpp
   @author decsai.ugr.es
   @warning Código incompleto
**/
#include "paquete.h"
using namespace std;

Paquete::Paquete(int id, double peso, int largo, int ancho, int alto){
    _id    = id;
    _peso  = peso;
    _largo = largo;
    _ancho = ancho;
    _alto  = alto;
}

//Set
void Paquete::setId(int id){
    _id    = id;
}
void Paquete::setPeso(double peso){
    _peso  = peso;
}
void Paquete::setLargo(int largo){
    _largo = largo;
}
void Paquete::setAncho(int ancho){
    _ancho = ancho;
}
void Paquete::setAlto(int alto){
    _alto  = alto;
}
void Paquete::setPaquete(int id, int peso, int largo, int ancho, int alto){
    _id    = id;
    _peso  = peso;
    _largo = largo;
    _ancho = ancho;
    _alto  = alto;

}

//Get
int Paquete::getId() const{
    return _id;
}
int Paquete::getLargo() const{
    return _largo;
}
int Paquete::getAncho() const{
    return _ancho;
}
int Paquete::getAlto() const{
    return _alto;
}
double Paquete::getPeso() const{
    return _peso;
}

double Paquete::getVolumen() const{
    return _largo * _ancho * _alto;
}

double Paquete::calculaPesoVolumetrico() const{
    double pesoVol_tmp = (_largo * _ancho * _alto)/_FACTORVOLUMETRICO;
    
    if (pesoVol_tmp > _peso)
        return pesoVol_tmp;
    else
        return _peso;
} 

double Paquete::getFactura() const{
    double pesoVol = this->calculaPesoVolumetrico();
    double factura = 0;

    if (pesoVol <= _RANGO1)
        factura = _TARIFA1 + _TARIFA1 * _IVA;
    if (pesoVol > _RANGO1 && pesoVol <= _RANGO2)
        factura = _TARIFA2 + _TARIFA2 * _IVA;
    else
        factura = _TARIFA3 + _TARIFA3 * _IVA;
    
    return factura;
};
