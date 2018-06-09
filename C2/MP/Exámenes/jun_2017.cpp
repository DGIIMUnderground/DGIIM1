/*
Examen 2017 MP DGIIM
Enunciado en la página 44 del documento de decsai

jruib
*/

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

struct InfoCiudad {
	char * nombre; // Nombre
	int poblacion; // Num. habs.
};

class RedCiudades {
	private:
		int num_ciudades; // Número de ciudades
		InfoCiudad * info; // info[i]: info de la ciudad i
		double ** distancia; // distancia[i][j]: distancia entre las ciudades i y j
		
		void reservarMemoria( int n);
		void liberarMemoria();
		void copiar( const RedCiudades & otro);
	
	public:
		///Constructor por defecto
		RedCiudades();
		
		///Comprueba si una red está vacia
		bool EstaVacia();
		
		///Constructor de copia
		RedCiudades( const RedCiudades & orig );
		
		///Destructor
		~RedCiudades();
		
		///Operador de asignación
		RedCiudades& operator=( const RedCiudades & orig);
		
		///Operador de entrada
		friend std::ostream& operator<<(std::ostream& flujo, const RedCiudades &red);
		
		///Operador de salida
		friend std::istream& operator>>(std::istream& flujo, RedCiudades &red);
		
		///Lee un fichero con la descripción de la red
		void LeerRedCiudades( const char * fichero);
		
		///Constructor de un parámetro. Recibe un fichero con la descripción de la red.
		RedCiudades( const char * fichero);
		
		///Escribe una red en un fichero
		void EscribirRedCiudades( const char * fichero);
		
		///Obtiene la ciudad mejor conectada
		int CiudadMejorConectada();
		
		///Obtiene la mejor escala entre dos ciudades
		int MejorEscalaEntre( int a, int b);
		
		///Observador del número de ciudades
		int NumCiudades(){
			return num_ciudades;
		}
		
		///Observador de la distancia entre dos ciudades, a y b
		int Distancia( int a, int b){
			return distancia[a][b];
		}
};

void RedCiudades::reservarMemoria( int n){
	if( n>0){
		num_ciudades = n;
		
		info = new InfoCiudad[n];
		for( int i=0; i<n; i++){
			info[i].nombre = NULL;
			info[i].poblacion = 0;
		}
		
		distancia = new double*[n];
		for( int i=0; i<n; i++)
			distancia[i] = new double[n];
	}
	else{
		num_ciudades = 0;
		info = NULL;
		distancia = NULL;
	}
}

void RedCiudades::liberarMemoria(){
	if( info){ //if info != NULL
		for( int i=0; i<num_ciudades; i++)
			delete [] info[i].nombre;
		delete [] info;
		info = NULL;
	}
	
	if( distancia){ //if distancia != NULL
		for( int i=0; i<num_ciudades; i++)
			delete [] distancia[i];
		delete [] distancia;
		distancia = NULL;
	}
	
	num_ciudades = 0;
}

void RedCiudades::copiar( const RedCiudades & otro){
	//num_ciudades
	num_ciudades = otro.num_ciudades;
	
	//info
	for( int i=0; i<num_ciudades; i++){
		info[i].nombre = new char[strlen(otro.info[i].nombre)+1];
		strcpy( info[i].nombre, otro.info[i].nombre );
		info[i].poblacion = otro.info[i].poblacion;
	}
	
	//distancia
	for( int i=0; i<num_ciudades; i++)
		for( int j=0; j<num_ciudades; j++)
			distancia[i][j] = otro.distancia[i][j];
}

RedCiudades::RedCiudades(){
	reservarMemoria(0);
}

bool RedCiudades::EstaVacia(){
	return num_ciudades == 0;
}

RedCiudades::RedCiudades( const RedCiudades & orig ){
	reservarMemoria(orig.num_ciudades);
	copiar(orig);
}

RedCiudades::~RedCiudades(){
	liberarMemoria();
}

RedCiudades& RedCiudades::operator=( const RedCiudades & orig){
	liberarMemoria();
	reservarMemoria( orig.num_ciudades);
	copiar( orig);
	return *this;
}

std::ostream& operator<<(std::ostream& flujo, const RedCiudades &red){
	//num_ciudades
	flujo << red.num_ciudades << endl;
	
	//info
	for( int i=0; i<red.num_ciudades; i++)
		flujo << i << " " << red.info[i].nombre << " " << red.info[i].poblacion << endl;
	
	//distancia
	for( int i=0; i<red.num_ciudades; i++)
		for( int j=i+1; j<red.num_ciudades; j++)
			if( red.distancia[i][j] > 0)
				flujo << i << " " << j << " " << red.distancia[i][j] << endl;
	
	return flujo;
}

std::istream& operator>>(std::istream& flujo, RedCiudades &red){
	//num_ciudades y reserva de memoria
	red.liberarMemoria();
	flujo >> red.num_ciudades;
	red.reservarMemoria(red.num_ciudades);

	//info
	int numCiudad;
	char cadena[100];
	for(int i=0; i<red.num_ciudades; i++){
		flujo >> numCiudad >> cadena;
		red.info[numCiudad].nombre = new char[strlen(cadena)+1];
		strcpy( red.info[numCiudad].nombre, cadena);
		flujo >> red.info[numCiudad].poblacion;
	}
	
	//distancia
	int index1, index2, distancia;
	while ( flujo >> index1){
		flujo >> index2;
		flujo >> distancia;
		red.distancia[index1][index2] = red.distancia[index2][index1] = distancia;
	}
	
	return flujo;
}

RedCiudades::RedCiudades( const char * fichero){
	LeerRedCiudades( fichero); 
}

void RedCiudades::LeerRedCiudades( const char * fichero){
	ifstream fentrada;
	fentrada.open( fichero);
	char cadena_magica[3];
	if( fentrada){
		fentrada.getline( cadena_magica, 3);
		if( strcmp( cadena_magica, "RED") == 0)
			fentrada >> *this;
	}
}

void RedCiudades::EscribirRedCiudades( const char * fichero){
	ofstream fsalida;
	fsalida.open(fichero);
	if( fsalida){
		fsalida << "RED" << endl << *this;
	}
	
}

int RedCiudades::CiudadMejorConectada(){
	int ciudad_mejor_conectada, max_conexiones = 0;
	int conexiones_actual;
	for( int i=0; i<num_ciudades; i++){
		conexiones_actual = 0;
		for( int j=0; j<num_ciudades; j++)
			if( distancia[i][j] > 0)
				conexiones_actual++;
		if( conexiones_actual > max_conexiones){
			max_conexiones = conexiones_actual;
			ciudad_mejor_conectada = i;
		}
	}
	return ciudad_mejor_conectada;
}

int RedCiudades::MejorEscalaEntre( int a, int b){
	int c = -1;
	double menor_distancia = -1;
	double distancia_actual;
	for( int i=0; i<num_ciudades; i++){
		if( distancia[i][a] > 0 && distancia[i][b] > 0){
			distancia_actual = distancia[i][a] + distancia[i][b];
			if( distancia_actual < menor_distancia && menor_distancia != -1)
				menor_distancia = distancia_actual;
				c = i;
		}
	}
	
	return c;
}

int main(int narg, char * argv[]){
	if( narg < 3){
		return 1;
	}
    
	//PROBLEMA 5
	RedCiudades red(argv[1]);
	int escala;
	for(int i=0; i<red.NumCiudades(); i++)
		for( int j=0; j<red.NumCiudades(); j++){
			if( red.Distancia(i,j) ){
				escala = red.MejorEscalaEntre(i, j);
				if( escala == -1)
					cout << "NO hay escala entre la ciudad " << i << " y la ciudad " << j << endl;
				else
					cout << "La mejor escala entre la ciudad " << i << " y la ciudad " << j << " es la ciudad " << escala << endl;
			}
		}	
	return 0;
}
