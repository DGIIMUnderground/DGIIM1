#include <iostream>
#include <cmath>

using namespace std;

////////////////////////////////////////////////////////////////////////

class Punto{
	
	private:
		double x;
		double y;
		
	public:
		
		/**
		 * @brief Cosntructor por defecto
		 */
		Punto(){
			x = 0;
			y = 0;
		}
		
		/**
		 * @brief Constructor con dos parámetros
		 */
		Punto(const double & la_x, const double & la_y){
			x = la_x;
			y = la_y;
		}
		
		double X() const {
			return x;
		}
		
		double Y() const {
			return y;
		}
};

////////////////////////////////////////////////////////////////////////

class Circulo{
	
	private:
		Punto centro;
		double radio;
	
	public:
	
		/**
		* @brief Constructor por defecto
		*/
		Circulo(){
			radio = 0; //centro ya es por defecto 0,0
		}

		/**
		* @brief Constructor con tres parámetros
		*/
		Circulo( const double & la_x, const double & la_y, const double & el_radio){
			Punto el_centro(la_x, la_y);
			centro = el_centro;
			radio = el_radio;
		}

		/**
		* @brief Observador del centro
		*/
		Punto Centro() const {
			return centro;
		}

		/**
		* @brief Obervador del radio
		*/
		double Radio() const {
			return radio;
		}


		/**
		 * @brief True si interseca con otro_circulo, false si no
		*/
		bool Interseca( const Circulo & otro_circulo ) const {
			bool interseca;
			double distancia_centros = sqrt( (centro.X()- otro_circulo.centro.X() )*(centro.X()- otro_circulo.centro.X() )
			+ (centro.Y()- otro_circulo.centro.Y())*(centro.Y()- otro_circulo.centro.Y() ));
			double suma_radios = radio + otro_circulo.Radio();
			
			if ( distancia_centros <=  suma_radios ){
				interseca = true;
			}
			else{
				interseca = false;
			}
			
			return interseca;
		}

		void SetCentro( const double & la_x, const double & la_y) {
			Punto el_centro(la_x, la_y);
			centro = el_centro;
		}
		
		void SetRadio(const double & el_radio){
			radio = el_radio;
		}
		
		void Set(const double & la_x, const double & la_y, const double & el_radio){
			SetRadio(el_radio);
			SetCentro(la_x,la_y);
		}
};

int main(){
	
	Circulo mi_circulo;
	Circulo mi_otro_circulo(0, 0, 1);
	
	if (mi_circulo.Interseca(mi_otro_circulo) ) {
		cout << "Sí interseca" << endl;
	}
	else{
		cout << "No interseca" << endl;
	}
	
	
	cout << "Centro de mi_circulo: " << mi_circulo.Centro().X() << ", " << mi_circulo.Centro().Y()  << endl;
	cout << "Radio de mi_circulo: " << mi_circulo.Radio() << endl;
	
	mi_circulo.Set(1, 2, 3);
	cout << "Centro de mi_circulo: " << mi_circulo.Centro().X() << ", " << mi_circulo.Centro().Y()  << endl;
	cout << "Radio de mi_circulo: " << mi_circulo.Radio() << endl;
}
