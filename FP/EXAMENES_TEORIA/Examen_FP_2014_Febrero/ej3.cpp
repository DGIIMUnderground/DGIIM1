/*
 * (3 puntos) Existe un método para la clase string de C++, denominado replace, que cambia n caracteres de
una cadena cad1, empezando en una determinada posición pos, por los caracteres presentes en una segunda cadena
cad2. La llamada al método es cad1.replace(pos, n, cad2).
Realizar un módulo llamado reemplazar con la misma funcionalidad que replace, para trabajar con cadenas de
caracteres, pero con la restricción de que no se puede utilizar la clase string.
* 
* José L. Ruiz
 */

#include <iostream>
#include <vector>

using namespace std;

class String{
	private:	
		vector<char> cad;
		
	public:
		
		/**
		 * @brief Costructor por defecto
		 */
		String(){
			vector<char> la_cad(0);
			cad = la_cad;
		}
		
		/**
		 * @brief Constructor con un parámetro
		 */
		String( const vector<char> & la_cad){
			cad = la_cad;
		}
		
		/**
		 * @brief Constructor por copia
		 */
		String ( const String & otra_cad){
			cad = otra_cad.cad; // de esto no estoy seguro;
		}
		
		/**
		 * @brief Observador de cad
		 */
		vector<char> Cadena() const{
			return cad;
		}
		
		void Reemplazar( const int & pos, const int & n, const String & otra_cadena){ 
			int tamano_original = cad.size();
			
			cad.resize( cad.size() + otra_cadena.cad.size()-n );
			
			//Dejo espacio libre:
			
			for( int i=0; i<(otra_cadena.cad.size()-n); i++)
				for (int j=tamano_original; j>pos; j--)
					cad[j] = cad[j-1];
			
			//Añado la cadena:
			
			for (int i=0; i<=otra_cadena.cad.size(); i++)
				cad[i+pos] = otra_cadena.cad[i];
		}
};

void Lectura( vector<char> & v)
{
	char elemento;
	
	cin >> elemento;
	
	while( elemento != '#' ){
		v.push_back(elemento);
		cin >> elemento;
	}
}

void Mostrar( const vector<char> & v)
{
	for( int i=0; i<v.size(); i++){
		cout << v[i];
	}
}

int main()
{
	vector<char> v;
	cout << "Introduzca una cadena de caracteres (finalice con '#' : ";
	Lectura(v);
	String una_cadena(v);
	
	vector<char> s;
	cout << "Cadena para sustituir: ";
	Lectura(s);
	String otra_cadena(s);
	
	una_cadena.Reemplazar( 2, 3, s );
	cout << "Cadena transformada: ";
	Mostrar( una_cadena.Cadena() );
	
}
