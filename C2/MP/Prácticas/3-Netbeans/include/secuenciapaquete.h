/**
   @file secuenciapaquete.h
   @author decsai.ugr.es
   @warning completar los parámetros (valor, referencia, referencia constante) e implementar
**/
#ifndef SECUENCIAPAQUETE_H
#define SECUENCIAPAQUETE_H

#include "paquete.h"

const int MAXPAQ = 100;

/**
 * @brief Pone todos los paquetes del vector como paquetes vacíos y pone los componentes
 * útiles a 0
 * @param s Un vector de paquetes
 * @param util Número de componentes útiles de @a s 
 */
void cleanSecuenciaPaq(Paquete s[], int & util);

/**
 * @brief Añade un nuevo paquete a la lista de la clase por el final. Comprueba si cabe
 * @param s Un vector de paquetes
 * @param util Número de componentes útiles de @a s 
 * @return @retval true si se ha podido hacer la inserción @retval false en otro caso 
 */
bool addSecuenciaPaq(Paquete s[], int & util, const Paquete p);
/**
 * @brief Calcula el precio de todos los paquetes de la lista según las tarifas
 * @param s Un vector de paquetes
 * @param util Número de componentes útiles de @a s 
 * @return El precio total de la lista de paquetes
 */
double getTotalSecuenciaPaq(const Paquete s[], const int util);

/**
 * @brief Devuelve el paquete con mayor volumen.
 * @param s Un vector de paquetes
 * @param util Número de componentes útiles de @a s 
 * @return El paquete
 */
Paquete paqueteMayorSecuenciaPaq(const Paquete s[], const int util);

/**
 * @brief Calcula la media de precio facturado.
 * @param s Un vector de paquetes
 * @param util Número de componentes útiles de @a s 
 * @return La media de sprecio
 */ 
double getMediaSecuenciaPaq(const Paquete s[],  const int util);

/**
 * @brief Devuelve cuántos paquetes son mayores que un valor dado en altura
 * @param s Un vector de paquetes
 * @param util Número de componentes útiles de @a s 
 * @param altura en cm
 * @return El número de paquetes
 */
int numPaqueteAltosSecuenciaPaq(const Paquete s[],  const int util, int altura);

/**
 * @brief Devuelve el numero de paquetes que tienen precio superior a la media.
 * @param s Un vector de paquetes
 * @param util Número de componentes útiles de @a s 
 * @return El número de paquetes
 */
int numPaquetesSuperiorSecuenciaPaq(const Paquete s[], const int util);
#endif 

