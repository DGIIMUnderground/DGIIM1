/* 1. Supongamos que se eligen dos puntos de forma aleatoria (con distribución uniforme) en
el cuadrado unitario [0, 1]^2 . Escribid un programa que estime la longitud media esperada
del segmento que une dichos puntos. Hacedlo de forma que los resultados de cada prueba
(cada selección de par de números) se almacenen en un array. La implementación debe ser
lo más modular posible, incluyendo funciones auxiliares necesarias para todas las tareas
que se consideren oportunas.

José L. Ruiz
*/

#include <iostream>
#include <cmath> //floor
#include <cstdlib> //rand
#include <ctime> //time

using namespace std;

struct Punto{
	double x;
	double y;
};

double Distancia( const Punto & a, const Punto & b){
	return sqrt( (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-b.y) );
}

int uniforme(int minimo, int maximo){
	double u01= rand() / (RAND_MAX+1.0); //Uniforme 01
	return floor(minimo + u01*(maximo-minimo+1) );
}

void ObtenerDistancias(double v[], const int & longitud){
	int min=0, max=1;
	Punto a, b;
	srand ((int) time(0));
	for (int i=0; i< longitud; i++){
		a.x = uniforme(min, max);
		a.y = uniforme(min, max);
		b.x = uniforme(min, max);
		b.y = uniforme(min, max);
		v[i] = Distancia(a, b);
	}
}

double Media( const double v[], const int & longitud){
	double media = 0;
	for (int i=0; i<longitud; i++)
		media += v[i];
	media /= longitud;
	return media;
}

int main(){
	const int TAMANO = 999999;
	double distancias[TAMANO];
	
	ObtenerDistancias(distancias, TAMANO);
	double media = Media(distancias, TAMANO);
	
	cout << "La distancia media entre los pares de puntos generados aleatoriamente es: " << media << endl;
}
