

/* 
 * File:   VectorSD.h
 * Author: juan
 *
 * Created on 12 de mayo de 2018, 13:24
 */

#ifndef VECTORSD_H
#define VECTORSD_H

#include <fstream>
#include <iostream>
#include <string>

class VectorSD{
private:
    int* info;
    int util;
    int reservado;
public:
    VectorSD();
    VectorSD(int reserva);
    VectorSD(const VectorSD & vect);
    ~VectorSD();
    int getDato( int posicion )const;
    int nElementos() const{ return util;}
    
    VectorSD & operator=(const VectorSD &vec);
    
    bool operator==(const VectorSD &vec) const;
    bool operator!=(const VectorSD &vec) const;
    /**
     * @brief Compara si los valores del primer vector son mayores que los del segundo.
     * @param vec
     * @return Si son mayores true si son menroes false.
     */
    bool operator>(const VectorSD & vec) const;
    bool operator<(const VectorSD & vec) const;
    bool operator>=(const VectorSD & vec) const;
    bool operator<=(const VectorSD & vec) const;
    
    const int& operator[](int i) const;
    int& operator[](int i);
    
    /**
     * @brief: Crea un nuevo vector con n elementos más, generado a partir del último sumando 1.
     * @param aumento: NUmero de casillas que aumenta;
     */
    VectorSD operator+(const int aumento);
    VectorSD operator+=(const int aumento);
    /**
     * @brief: Crea un nuevo vector con n elementos menos.
     * @param aumento: NUmero de casillas que decrece;
     */
    VectorSD operator-(const int decremento);
    VectorSD operator-=(const int decremento);
    
    
    void aniadir (int dato);
    void mod_casilla (int pos, int dato );
    /**
     * @brief Inserta un elemento justo en la posición dada entre el numero de esa posición y el siguiente.
     * @param pos
     * @param dato
     */
    void insertar(int pos, int dato);
    /**
     * @brief borra el elemento en la posición dada.
     * @param pos
     */
    void borrar(int pos);
    void mostrar (std::ostream& flujo) const;
    void leer (std::istream& flujo);
    
};

void ordenar(VectorSD & vector);
std::ostream& operator<<(std::ostream &flujo,const VectorSD vect);
std::istream& operator>>(std::istream &flujo, VectorSD & vect);
/**
 * @brief Comprueba que una cadena sea unicamente de valores numericos
 * @param cadena
 * @return true: Si lo es
 *         false: si no.
 */
bool isNumeric(std::string cadena);


#endif /* VECTORSD_H */

