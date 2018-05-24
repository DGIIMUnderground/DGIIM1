/** 
 * @file Idioma.h
 * @author DECSAI
*/

#ifndef IDIOMA_H
#define IDIOMA_H

#include "Bigrama.h"
#include <string>
/**
 * @class Idioma
 * @brief Representa el conjunto los bigramas asociados a un idioma junto con el 
 * identificador del idioma
 */
class Idioma {
public:

    /**
     * @brief Constructor base
     */
    Idioma();
    
    /**
     * @brief Constructor para pre-reservar memoria
     * @param nbg Número de bigramas pre-reservados
     */
    Idioma(int nbg);
    
	 /**
	  * @brief reserva memoria para @a n bigramas,
	  * en caso de que ya hubiese memoria reservada, esta
	  * debe eliminarse
	  * @param n número de bigramas a reservar
	  */
	 void reservarMemoria(int n);

	 /**
	  * @brief reserva memoria para @a n bigramas adicionales
	  * a los que ya ha ya reservados, manteniendo los datos
	  * que hubiese podido haber reservados
	  * @param n número de bigramas a ampliar
	  */
	 void ampliarMemoria(int n);

    /**
     * @brief Libera la memoria
     */
    void liberarMemoria();
    
    /**
     * @brief Consulta el ID del idioma
     * @return ID del idioma
     */
    inline std::string getIdioma() const {return _idioma; };  
    
    /**
     * @brief Establece el ID del idioma
     * @param id Nuevo ID del idioma
     */
    inline void setIdioma(const std::string& id){this->_idioma = id;};
    
    /**
     * @brief Consulta la lista de bigramas
     * @param p La posición de la lista que se quiere consultar
     * @precond La posición @p p es correcta
     * @return El bigrama que ocupa la posición @p p
     */
    Bigrama getPosicion(int p) const;
    
    /**
     * @brief Añade un nuevo bigrama
     * @param p La posición en la que se quiere insertar el bigrama
     * @precond La posición @p p es correcta
     * @param bg El bigrama a insertar
     */
    void setPosicion(int p, const Bigrama & bg);
    
    /**
     * @brief Consulta el número de bigramas existentes. 
     * @return El tamaño de la lista de bigramas
     */
    inline int getSize() const { return _nBigramas; };

    /**
     * @brief Busca un bigrama en la lista de bigramas
     * @param bg El bigrama que se está buscando
     * @return La posición que ocupa @p bg en la lista, -1 si no está en la lista
     */
    int findBigrama(const std::string bg) const;

	 /**
	  * @brief Añade un nuevo bigrama a la lista. Si el bigrama se añade por primera vez
	  * se debe incrementar el tamaño del vector para alojar el nuevo bigrama. Si el bigrama
	  * ya existe, se deben de sumar ambas frecuencias, la existente y la nueva
	  * @param bg El bigrama a añadir
	  */
	 void addBigrama(const Bigrama & bg);
	 
    
    /**
     * @brief Recupera una serialización de un idioma desde un fichero y 
     * reconstruye el idioma. Muestra en pantalla el idioma cargado
     * @param fichero Fichero que contiene un idioma serializado
     * @return @b false si ha habido algún tipo de error, @b true en otro caso
     */
    bool cargarDeFichero(const char *fichero);
	 
	 /**
	  * @brief Método similar a @a cargarDeFichero pero en vez de cargar un idioma nuevo
	  * desde el fichero (que debe contener un idioma serializado), los bigramas del fichero
	  * se añaden al diccionario que ya existe.
	  * @param fichero Contiene los bigramas a añadir al idioma existente
      * @return @b false si ha habido algún tipo de error, @b true en otro caso
	  * @pre El objeto ya debe tener un idioma cargado y deben coincidir ambos
	  */
	 bool addDeFichero(const char *fichero);
	 
private:
    std::string _idioma;    /// Identificador del idioma
    Bigrama* _conjunto;     /// Vector dinámico de bigramas
    int _nBigramas;         /// Número de bigramas en el vector dinámico

};

#endif