#include <iostream>

using namespace std;

class Vector{
	private:
		int *v; ///array de enteros
		int n; ///tamaño del array
		
	public:
		/**
		 * @brief Constructor por defecto
		 */
		Vector();
		
		/**
		 * @brief Constructor con un parámetro
		 */
		Vector( int tamano);
		 
		/**
		 * @brief Observador de un elemento
		 * @pre La posición debe ser válida
		 */
		int GetElemento(int pos) const;
		 
		/**
		 * @brief Observador del tamano
		 */
		int GetTamano() const;
		 
		/**
		 * @brief Modicficador de un elemento
		 * @pre La posición debe ser válida
		 */
		void SetElemento(int nuevo, int pos);
		  
		/**
		 * @brief Amplía la memoria reservada del array en cant espacios
		 */
		void Ampliar( int cant);
		  
		/**
		 * @brief Añade un elemento
		 */
		void AddElemento( int nuevo);
		  
		/**
		 * @brief Libera la memoria dinámica
		 */
		void Liberar();
};

Vector::Vector(){
	v = NULL;
	n = 0;
}

Vector::Vector(int tamano){
	n = tamano;
	v = new int[n];
}

int Vector::GetElemento(int pos) const{
	return v[pos];
}

void Vector::SetElemento(int nuevo, int pos){
	v[pos] = nuevo;
}

int Vector::GetTamano() const{
	return n;
}

void Vector::Ampliar( int cant){
	int *aux = new int [n+cant];
	for ( int i=0; i<n; i++)
		aux[i] = v[i];
	n = n+cant;
	delete [] v;
	v = aux;
}

void Vector::AddElemento( int nuevo){
	Ampliar(1); //Esto es un ataque gratuito a la filosofía Full-Efficiency
	v[n-1] = nuevo;
}

void Vector::Liberar(){
	delete [] v;
	v = NULL;
}

//--------------------------------------------------------------------//

void LecturaVector( Vector & v){
	int elemento;
	for( int i=0; i<v.GetTamano(); i++){
		cin >> elemento;
		v.SetElemento(elemento, i);
	}
		
}

void ImprimeVector( const Vector & v){
	for( int i=0; i<v.GetTamano(); i++){
		cout << v.GetElemento(i) << " ";
	}
}

int main(){
	int tamano;
	cout << "Tamaño del vector: ";
	cin >> tamano;
	Vector mi_vector(tamano);
	
	cout << "Introduce Elementos: ";
	LecturaVector(mi_vector);
	cout << "Se ha leído el vector: ";
	ImprimeVector(mi_vector);
	
	int aniadir;
	cout << "\nValor que se añadirá: ";
	cin >> aniadir;
	mi_vector.AddElemento(aniadir);
	cout << "Nuevo vector: ";
	ImprimeVector(mi_vector);
	
	mi_vector.Liberar();
	return 0;
	
}
