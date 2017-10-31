//ASIGNATURA:Fundamentos de programación
//EJERCICIO: 1.3 Profundidad de campo
//CENTRO: ETSIIT UGR
//FECHA: 31/10/17

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{

double conf;   //Círculo de confusión
double lonf;   //Longitud focal
double foc;    //Distancia de enfoque
double apert;  //Número f, apertura de diafragma

double hiperf; //Hiperfocal
double Dmin;   //Distancia mínima a la zona enfocada
double Dmax;   //Distancia máxima a la zona enfocada
double prof;   //Profundidad de campo

double temp;   //Para realizar la inversión de f y la distancia de enfoque

cout << "Introduzca los valores de:" << endl;

cout << "Circulo de confusion(0.001-1): ";
cin  >> conf;
if (conf > 1 or conf < 0.001) {
  cout << "Valor fuera del rango, por favor vuelva a introducirlo...\n";
  return 0;
}

cout << "Longitud focal(0.5-64): ";
cin  >> lonf;
if (lonf > 64 or lonf < 0.5) {
  cout << "Valor fuera del rango, por favor vuelva a introducirlo...\n";
  return 0;
}

cout << "Distancia de enfoque(5-2000): ";
cin  >> foc;
if (foc > 2000 or foc < 5) {
  cout << "Valor fuera del rango, por favor vuelva a introducirlo...\n";
  return 0;
}

cout << "Numero f, relacionado con la apertura del diafragma(1-infinito): ";
cin  >> apert;
if (apert < 1) {
  cout << "Valor fuera del rango, por favor vuelva a introducirlo...\n";
  return 0;
}

if (foc < apert) {
  cout << "La distancia de enfoque no puede ser mayor que el número f, se entiende que se encuentran invertidos.";
  temp = foc;
  foc = apert;
  apert = temp;
}

hiperf = ( (lonf * lonf)/(apert * conf) ) + lonf;

Dmin = (foc *(hiperf - lonf)) /
       (hiperf + foc - 2 * lonf);

Dmax = (foc *(hiperf - lonf)) /
       (hiperf - foc);

prof = Dmax - Dmin;

cout << "\nLos valores obtenidos son los siguientes:" << endl;
cout << "Hiperfocal: " << hiperf << endl;
cout << "Distancia minima a la zona enfocada: " << Dmin << endl;
cout << "Distancia maxima a la zona enfocada: " << Dmax << endl;
cout << "Profundad de campo: " << prof << endl;

return 0;
}
