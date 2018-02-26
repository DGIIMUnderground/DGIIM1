/******************************************************************************
  @brief Espeficicacion del TDA numero complejo
  @file complejo.h

  El TDA complejo representa un número racional

  ****************************************************************************/

  #ifndef __COMPLEJO_H__

/**
  TDA complejo

  El TDA complejo representa un número racional a partir de dos valores
  reales de la forma (parte real, parte imaginaria)

  Operaciones:
    parte real, parte imaginaria, complementario, forma polar, modulo, argumento
    +, - , * , /
  */


class complejo {
public:

  struct Polar{
    double modulo;
    double argumento;
  };

  /** @brief Contructor primitivo y por defecto
      @param r: Parte real
      @param d_ Parte imaginaria
      Crea un objeto de tipo complejo (real,imaginario=
  */
  complejo (double realdado, double imaginariodado);

  /** @brief Constructor por referencia
      @param complejo a copiar
  */
  complejo(const complejo & complejoA);

  /**
  @brief Devuelve la parte real.
  @return Parte real del receptor
  */
  double preal () const;

  /**
  @brief Devuelve la parte real.
  @return Parte real del receptor
  */
  double pimaginario () const;

  /**
  @brief: Calcula el conjugado de un numero complejo.
  @return: Numero conjugado del receptor
  */
  complejo conjugado () const;

  /**
  @brief Devuelve el modulo de un numero complejo
  @return: Módulo del Numero
  */
  double modulo () const;

  /**
    @brief Devuelve el argumento de un numero complejo
    @return: Argumento del Numero
  */
  double argumento () const;

  /**
  @brief Calcula la forma polar de un numero complejo.
  @param ncomplejoA Numero del que calcular la forma polar
  @return: Numero en forma polar
  */

  Polar fpolar () const;


  /**
    @brief Suma dos numeros complejos;
    @param ncomplejoA
    @return La suma del objeto que invoca el metodo y ncomplejoA.
  */
  complejo operator+(const complejo & ncomplejoA) const;

  /**
    @brief Resta dos numeros complejos;
    @param ncomplejoA
    @return Devuelve la resta del objeto que invoca el metodo y ncomplejoA
  */
  complejo operator-(const complejo & ncomplejoA) const;

  /**
    @brief Multiplica dos numeros complejos;
    @param ncomplejoA
    @return Devuelve el producto del objeto por el argumento ncomplejoA
  */
  complejo operator*(const complejo & ncomplejoA) const;

  /**
    @brief Division dos numeros complejos;
    @param ncomplejoA
    @return Devuelve el cociente dividido por ncomplejoA
  */
  complejo operator/(const complejo & ncomplejoA) const;
  /**
    @brief Escribe el numero complejo en pantalla
    @return Representacion del numero
  */

  std::string escribirComplejo() const;
  /**
    @brief Escribe el numero complejo en forma polar en pantalla
    @return Representacion del numero

  */
  std::string escribirPolar() const;


private:
  double real;
  double imaginaria;
};

#endif //__RACIONAL_H__
