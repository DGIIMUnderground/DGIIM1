/** 
 * @file Bigrama.h
 * @author DECSAI
 */

#ifndef BIGRAMA_H
#define BIGRAMA_H

/**
 * @class Bigrama
 * @brief Gestión individual de bigramas: pares de letras consecutivas de un texto y su frecuencia asociada dentro del texto   
 */
class Bigrama {
public:
    /// @brief Constructor base
    Bigrama();
    
    /**
     * @brief Devuelve el bigrama almacenado
     * @return el bigrama
     */
    const char* getBigrama() const;
    
    /**
     * @brief Devuelve la frecuencia almacenada
     * @return la frecuencia
     */
    int getFrecuencia() const;
    
    /**
     * @brief Actualiza el bigrama, siempre que sea de la longitud adecuada, 
     *  en otro caso, no se actualiza, para evitar desbordamientos del vector
     * @param cadena El nuevo valor del bigrama
     */
    void setBigrama(const char cadena[]);

    /**
     * @brief Actualiza la frecuencia almacenada
     * @param frec La nueva frecuencia
     */
    void setFrecuencia(int frec);
    

private:
    char _bigrama[3]; /// Bigrama almacenado, incluyendo el '\0'. Ojo a desbordamientos
    int _frecuencia; /// Frecuencia almacenada
};

/**
 * @brief Ordena un vector de bigramas de forma ascendente por frecuencias
 * @param v El vector de bigramas
 * @param n Tamaño de @a v
 */
void ordenaAscFrec(Bigrama *v, int n);

/**
 * @brief Ordena un vector de bigramas de forma ascendente por bigramas
 * @param v El vector de bigramas
 * @param n Tamaño de @a v
 */
void ordenaAscBigr(Bigrama *v, int n);

/**
 * @brief Imprime un vector de bigramas
 * @param v El vector de bigramas
 * @param n Tamaño de @a v
 */
void imprimeBigramas(const Bigrama *v, int n);

#endif /* BIGRAMA_H */

