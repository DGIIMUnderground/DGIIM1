/**
 * @file intervalo.h
 * @brief Definición de la clase @p Intervalo
 * @author MP - DGIM - Grupo A, Ana Martínez Sabiote
**/


#ifndef _INTERVALO_H_
#define _INTERVALO_H_

class Intervalo{
private:
    bool cerradoInf;
    bool cerradoSup;
    double cotaInf;
    double cotaSup;

    /**
     * @brief comprueba que los argumentos definen un intervalo correcto
     * @param cotaInferior
     * @param cotaSuperior
     * @param cerradoInferior
     * @param cerradoSuperior
     * @pre cotaInferior < cotaSuperior 
     * @pre cotaInferior == cotaSuperior && cerradoInferior == cerradoSuperior 
     * @return @retval true si correcto @retval false en otro caso
     */
    bool validar(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior);

public:
    /** 
     *  @brief Crea un intervalo vacio 
     */
    Intervalo();
    /** 
     * @brief Crea un Intervalo cerrado 
     * @param cotaInferior
     * @param cotaSuperior
     * @pre El intervalo es válido
     */
    Intervalo(double cotaInferior, double cotaSuperior);
    /** 
     * @brief Crea un intervalo cualquiera 
     * @param cotaInferior
     * @param cotaSuperior
     * @param cerradoInferior
     * @param cerradoSuperior
     * @pre El intervalo es válido
     */
    Intervalo(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior);
    /** 
     * @brief Devuelve la cota inferior del intervalo
     * @return El valor de la cota
     */
    double getCotaInf()const ;
    /** 
     * @brief Devuelve la cota superior del intervalo
     * @return El valor de la cota
     */
    double getCotaSup()const ;
    /** 
     * @brief Consulta si el intervalo es cerrado en su cota inferior
     * @return @retval true si es cerrado @retval false si es cerrado
     */
    bool esCerradoInf()const ;
    /** 
     * @brief Consulta si el intervalo es cerrado en su cota superior
     * @return @retval true si es cerrado @retval false si es cerrado
     */
    bool esCerradoSup()const ;
    /** 
     * @brief Consulta si el intervalo almacenado es vacío o no
     * @return @retval true si es un intervalo vacío, @retval false en otro caso 
     */
    bool esVacio()const ;
    /** 
     * @brief Consulta si un determinado valor está dentro del intervalo
     * @param n El valor consultado
     * @return @retval true si el valor @p n pertenece al intervalo, @retval false en otro caso 
     */
    bool estaDentro(double n)const ;


};

void escribir(const Intervalo &i);
void leer(Intervalo &i);

#endif
