/**
   @file paquete.h
   @author decsai.ugr.es
   @warning implementar la clase
**/
#ifndef PAQUETE_H
#define PAQUETE_H

/**
 * @class Paquete
 * @brief Gestión de paquetes básica para envío
 */
class Paquete{
public:                           
   static const long _SIN_IDENT = -1;			///< ID Nulo
	   
   static constexpr float _TARIFA1 = 12.97;		///< Tarifas
   static constexpr float _TARIFA2 = 16.83;		///< Tarifas
   static constexpr float _TARIFA3 = 29.32;		///< Tarifas

   static const int _RANGO1 = 2;					///< Rango de tarifas
   static const int _RANGO2 = 5;					///< Rango de tarifas
   static const int _RANGO3 = 15;				///< Rango de tarifas

   static constexpr float _IVA = 0.21;				///< IVA aplicable

   /**
   * @brief Constructor sin parámetros
   */
   Paquete() :_id(_SIN_IDENT) 
   {}   

   /**
   * @brief Constructor con ID
   */
   Paquete(int id) : _id(id), _peso(0), _largo(0), _ancho(0), _alto(0)
   {}

   /**
   * @brief Constructor con parámetros completos
   */
   Paquete(int id, double peso, int largo, int ancho, int alto);

   /**
   * @brief Actualiza el ID del paquete
   * @param id El nuevo ID
   */
   void setId(int id);  

   /**
   * @brief Consulta el ID del paquete
   * @return El ID del paquete
   */
   int  getId() const;

   /**
   * @brief Actualiza el peso del paquete
   * @param peso El nuevo peso
   */
   void setPeso(double peso);
   /**
   * @brief Consulta el peso del paquete
   * @return El peso del paquete
   */
   double getPeso() const;
   /**
   * @brief Actualiza el largo del paquete
   * @param largo El nuevo largo
   */
   void setLargo(int largo);
   /**
   * @brief Consulta el largo del paquete
   * @return  El largo del paquete
   */
   int getLargo() const;
   /**
   * @brief Actualiza el ancho del paquete
   * @param ancho El nuevo ancho
   */
   void setAncho(int ancho);
   /**
   * @brief Consulta el ancho del paquete
   * @return El ancho del paquete
   */
   int getAncho() const ;
   /**
   * @brief Actualiza el alto del paquete
   * @param alto El nuevo alto
   */
   void setAlto(int alto);
   /**
   * @brief Consulta el alto del paquete
   * @return El alto del paquete
   */
   int getAlto()const;

   /**
   * @brief modifica el estado del objeto siempre que el nuevo estado sea correcto
   * @param id Nuevo ID
   * @param peso Nuevo pPeso
   * @param largo Nuevo largo
   * @param ancho Nuevo ancho
   * @param alto Nuevo alto
   */
   void setPaquete(int id, int peso, int largo, int ancho, int alto);
   /**
   * @brief calcula el volumen real de un paquete
   * @return largo*ancho*alto
   */
   double getVolumen()const ;
   /**
   * @brief  Devuelve el peso volumétrico definitivo el maximo entre el peso y el peso calculado
   * @return El peso volumétrico
   */
   double calculaPesoVolumetrico()const;
   /**
   * @brief calcula la factura de acuerdo a los rangos y precios establecidos
   * con su iva
   * @return precio factura, incluido iva
   */
   double getFactura() const;

private:
   long _id;						 ///< Identificacion del paquete
   double _peso;					 ///< Peso en kg
   int _largo;						 ///< Largo en cm
   int _ancho;						 ///< Ancho en cm
   int _alto;						 ///< Alto en cm

   static constexpr double _FACTORVOLUMETRICO = 6000.0;	 /// Empleado por la empresa de paquetería


};

#endif 

