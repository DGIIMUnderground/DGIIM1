#include <cmath>
#include <iostream>
#include <string>
#include "complejo.h"
using namespace std;

/*********************************************************************
  @brief Implementacion del TDA complejo
  @file complejo.cpp
**********************************************************************/


complejo::complejo(double realdado = 0, double imaginariodado = 0){
real = realdado;
imaginaria = imaginariodado;
}
complejo::complejo(const complejo & complejoA){
real = complejoA.real;
imaginaria = complejoA.imaginaria;
}

double complejo::preal () const{
return real;
}

double complejo::pimaginario()const {
return imaginaria;
}

complejo complejo::conjugado () const {

  complejo conjugadoa(real, - imaginaria);
  return conjugadoa;
}

double complejo::modulo () const{
  return sqrt(real * real +
    imaginaria * imaginaria );

  }
double complejo::argumento () const{
  double argumento;
  const double PI = 3.14159265359;

  if ( real > 0)
      argumento = atan ( imaginaria / real );
    else if (real < 0 && imaginaria >= 0)
      argumento = atan ( imaginaria / real + PI);
    else if (real < 0 && imaginaria < 0 )
      argumento = atan ( imaginaria / real - PI );
    else if (real == 0 && imaginaria > 0 )
      argumento = PI/2;
    else if (real == 0 && imaginaria < 0 )
      argumento = - PI/2;
    else if (real == 0 && imaginaria == 0 )
      argumento = 0 ;

    return argumento;
  }

complejo::Polar complejo::fpolar () const{
  double modulo1 = modulo() ;
  double argumento1 = argumento() ;
  Polar polar;

  polar.modulo = modulo1;
  polar.argumento = argumento1;

  return polar;

}

complejo complejo::operator+(const complejo & ncomplejoA) const {
  complejo ncomplejoB(real + ncomplejoA.real,
    imaginaria + ncomplejoA.imaginaria);

    return ncomplejoB;
  }

complejo complejo::operator-(const complejo & ncomplejoA) const {
  complejo ncomplejoB(real - ncomplejoA.real,
    imaginaria - ncomplejoA.imaginaria);

    return ncomplejoB;
  }

complejo complejo::operator*(const complejo & ncomplejoA) const {
  double real1 = real * ncomplejoA.real
  -1*( imaginaria * ncomplejoA.imaginaria);
  double imaginaria1 = real * ncomplejoA.imaginaria
  + imaginaria * ncomplejoA.real;

  complejo ncomplejoB(real1,imaginaria1);

  return ncomplejoB;
}


complejo complejo::operator/(const complejo & ncomplejoA) const {
  complejo ncomplejoaux = ncomplejoA.conjugado() * *this;

  double multcompconj= ncomplejoA.real * ncomplejoA.real + ncomplejoA.imaginaria * ncomplejoA.imaginaria ;

  double real1 = ncomplejoaux.real /  multcompconj;
  double imaginaria1 = ncomplejoaux.imaginaria / multcompconj;

  complejo ncomplejoB(real1,imaginaria1);

  return ncomplejoB;
}
std::string complejo::escribirComplejo()const{
    std::string representacion;

    representacion =  std::to_string(real) + " + " + std::to_string(imaginaria) + "i";
    return representacion;
}

std::string complejo::escribirPolar()const{
    std::string representacion;
    Polar polar = fpolar();
    representacion = std::to_string(polar.modulo) + " e^ " + std::to_string(polar.argumento);
    return representacion;
}
