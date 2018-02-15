// EXAMEN PROGRAMACIÓN - 11 FEBRERO 2013

#include <iostream>
#include <vector>
using namespace std;

/**
	TDA cuadrado
	
	Representa un cuadrado mediante su punto inferior izquierdo y su lado
*/
class Cuadrado {
	private:
		double x_, y_;
		double lado_;
	public:
		/**
			@brief: constructor por defecto
			Crea el cuadrado por defecto, con origen en (0,0) y lado 1
		*/
		Cuadrado() {
			x_ = 0;
			y_ = 0;
			lado_ = 1;
		}
		/**
			@brief: constructor primitivo
			@param x: coordenada X del punto inferior izquierdo del cuadrado
			@param y: ídem coordenada Y
			@param lado: longitud del lado del cuadrado
			Crea un cuadrado a partir de los parámetros proporcionados
		*/
		Cuadrado(double x, double y, double lado) {
			x_ = x;
			y_ = y;
			lado_ = lado;
		}
		/**
			@brief: constructor por copia
			@param cuadr: cuadrado que se copia
			Crea un cuadrado a partir de otro
		*/
		Cuadrado(const Cuadrado & cuadr) {
			x_ = cuadr.x_;
			y_ = cuadr.y_;
			lado_ = cuadr.lado_;
		}
		/**
			@brief: devuelve la coordenada x
		*/
		double x() const {
			return x_;
		}
		/**
			@brief...
		*/
		double y() const {
			return y_;
		}
		double lado() const {
			return lado_;
		}
		/**
			@brief: devuelve el área del cuadrado
			@return: el área del cuadrado
		*/
		double area() const {
			return lado_*lado_;
		}
		/**
			@brief...
		*/
		double perimetro() const {
			return 4*lado_;
		}
		/**
			@brief: determina si un cuadrado tiene mayor área que otra
			@param cuadr: cuadrado sobre el que se desea comparar (si él es mayor)
			@return: si el cuadrado pasado es mayor
		*/
		bool operator<(Cuadrado cuadr) const {
			return area() > cuadr.area();
		}
		/**
			@brief: determina si un cuadrado está contenido en otro
			@param cuadr: cuadrado que queremos saber si está contenido
			@return: si el cuadrado pasado está contenido en el cuadrado
		*/
		bool contenido(Cuadrado cuadr) const {
			return ((cuadr.x_ >= x_) && (cuadr.x_+cuadr.lado_<=x_+lado_) && (cuadr.y_ >= y_) && (cuadr.y_ + cuadr.lado_ <= y_ + lado_));			
		}
		/**
			@brief: devuelve los cuadrados contenidos
			@param cuadrados: cuadrados que se quiere saber si están contenidos
			@return: los cuadrados contenidos
		*/
		vector<Cuadrado> incluidos(const vector<Cuadrado> & cuadrados) const {
			vector<Cuadrado> incluidos;
			for ( int i = 0; i < cuadrados.size(); i++ )
				if (contenido(cuadrados[i]))
					incluidos.push_back(cuadrados[i]);
			return incluidos;
		}
};

int main() {
	Cuadrado cuadrado1;
	Cuadrado cuadrado2(-1, -1, 3);
	Cuadrado cuadrado3(-5, -5, 100);
	Cuadrado cuadrado(-2, -2, 10);
	vector<Cuadrado> cuadrados;
	cuadrados.push_back(cuadrado1);
	cuadrados.push_back(cuadrado2);
	cuadrados.push_back(cuadrado3);
	vector<Cuadrado> incluidos;
	incluidos = cuadrado.incluidos(cuadrados);
	for ( int i = 0; i < incluidos.size(); i++ )
		cout << incluidos[i].x() << " " << incluidos[i].y() << " " << incluidos[i].lado() << endl;
	cout << (cuadrado3 < cuadrado2);
}
