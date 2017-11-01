//ASIGNATURA:Fundamentos de programación
//EJERCICIO: 1.1 Profundidad de campo
//CENTRO: ETSIIT UGR
//FECHA: 11/10/17

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{

string unidad; //Unidad en la que serán introducidos los valores
double conf;   //Círculo de confusión
double lonf;   //Longitud focal
double foc;    //Distancia de enfoque
double apert;  //Número f, apertura de diafragma

double hiperf; //Hiperfocal
double Dmin;   //Distancia mínima a la zona enfocada
double Dmax;   //Distancia máxima a la zona enfocada
double prof;   //Profundidad de campo

cout << "¿En que unidad desea introducir los valores?" << endl;
cin  >> unidad;

cout << "Introduzca los valores de:" << endl;
cout << "Circulo de confusion:";
cin  >> conf;
cout << "Longitud focal:";
cin  >> lonf;
cout << "Distancia de enfoque:";
cin  >> foc;
cout << "Numero f, relacionado con la apertura del diafragma:";
cin  >> apert;

hiperf = ( (lonf * lonf)/(apert * conf) ) + lonf;

Dmin = (foc *(lonf*lonf)) /
       ((lonf*lonf) + (apert * conf *(foc - lonf)));

Dmax = (foc *(lonf*lonf)) /
       ((lonf*lonf) - (apert * conf *(foc - lonf)));

prof = (2* foc * apert * conf *(lonf*lonf) *(foc - lonf) ) /
       (pow(lonf, 4) - ((apert*apert)*(conf*conf)*(foc-lonf)*(foc-lonf)));

cout << "\nLos valores obtenidos son los siguientes:" << endl;
cout << "Hiperfocal: " << hiperf << unidad << endl;
cout << "Distancia minima a la zona enfocada: " << Dmin << unidad << endl;
cout << "Distancia maxima a la zona enfocada: " << Dmax << unidad << endl;
cout << "Profundad de campo: " << prof << unidad << endl;

}
