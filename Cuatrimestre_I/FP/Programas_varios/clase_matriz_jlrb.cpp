/*
 * Clase Matriz
 * 
 * Incluye:
 * 		Datos miembros:
 * 			- Un vector de vectores de números reales
 * 
 * 		Constructores:
 * 			- Por defecto
 * 			- Con dos parámetros
 * 			- Constructor de copia
 * 
 * 		Métodos:
 * 			- Observador del  Número de filas
 * 			- Observador del Número de columnas
 * 			- Modificar un elemento de la matriz
 * 			- Observador de un elemento de la matriz
 * 			- Operador de asiganación =
 * 			- Operador += (dice si dos matrices son sumables)
 * 			- Operador *= (dice si dos matrices son multiplicables)
 * 			- Operador + (suma)
 * 			- Operador - (resta)
 * 			- Operador * (producto matricial)
 * 			- Operador * (producto por escalar)
 * 			- Operador ^ (potencia)
 * 
 * Funciones:
 * 		Lectura de una matriz
 * 		Mostrar una matriz
 * 
 * 
 * José L. Ruiz
 */

#include <iostream>
#include <vector>

using namespace std;

class Matriz
{
	private:
		vector<vector<double> > matriz;
		
	public:
		
		/**
		 * @brief Constructor por defecto
		 */
		Matriz()
		{
			vector<vector<double> > la_matriz( 0, vector<double>(0,0) );
			matriz = la_matriz;
		}
		
		/**
		 * @brief Constructor
		 */
		Matriz(const int & nfilas, const int & ncolumnas)
		{
			vector<vector<double> > la_matriz(nfilas, vector<double> (ncolumnas, 0));
			matriz = la_matriz;
		}
		
		/**
		 * @brief Constructor por copia
		 */
		Matriz( const Matriz & la_matriz)
		{
			matriz = la_matriz.matriz;
		}
		
		int Nfilas() const
		{
			return matriz.size();
		}
		
		int Ncolumnas() const
		{
			return matriz[0].size();
		}
		
		/**
		 * @brief Modifica el elemento ij de la matriz
		 */
		void SetElemento( const int & i, const int & j, const double & un_elemento )
		{
			matriz[i][j] = un_elemento;
		}
		
		double Elemento(const int & i, const int & j) const
		{
			return matriz[i][j];
		}
		
		
		/**
		 * @brief Operador de asignación
		 */
		void operator = ( const Matriz & otra_matriz)
		{
			matriz = otra_matriz.matriz;
		}
		
		/**
		 * @brief Dice si dos matrices tienen las mismas dimensiones, esto es, si se pueden sumar
		 * @return true si tienen las mismas dimensiones, false si no
		 */
		bool operator += ( const Matriz & otra_matriz) const
		{
			return Nfilas() == otra_matriz.Nfilas() && Ncolumnas() == otra_matriz.Ncolumnas();
		}
		
		Matriz operator + ( const Matriz & otra_matriz )  const
		{
			if ( *this += otra_matriz) // si las matrices son sumables
			{
				Matriz suma(*this);
				
				for (int i=0; i<Nfilas(); i++)
				{
					for (int j=0; j<Ncolumnas(); j++)
					{
						suma.matriz[i][j] = suma.matriz[i][j] + otra_matriz.matriz[i][j];
					}	
				}
				
				return suma;
			}
		}
		
		Matriz operator - ( const Matriz & otra_matriz )  const
		{
			if ( *this += otra_matriz) //si las matrices son sumables
			{
				Matriz resta(*this);
				
				for (int i=0; i<Nfilas(); i++)
				{
					for (int j=0; j<Ncolumnas(); j++)
					{
						resta.matriz[i][j] = resta.matriz[i][j] - otra_matriz.matriz[i][j];
					}	
				}
				
				return resta;
			}
		}
		
		/**
		 * @brief Dice si dos matrices son multiplicables
		 */
		bool operator *= (const Matriz & otra_matriz) const
		{
			return Ncolumnas() == otra_matriz.Nfilas();
		}
		
		/**
		 * @brief Producto Matricial
		 */
		Matriz operator * (const Matriz & otra_matriz) const
		{
			if ( *this *= otra_matriz) // si las matrices son multiplicables
			{
				Matriz producto( Nfilas(), otra_matriz.Ncolumnas() );
				
				for (int i=0; i<producto.Nfilas(); i++)
				{
					for( int j=0; j<producto.Ncolumnas(); j++)
					{
						double elemento = 0;
						
						for (int k=0; k<Ncolumnas(); k++)
						{
							elemento = elemento + matriz[i][k]*otra_matriz.matriz[k][j];
						}
						producto.SetElemento(i, j, elemento);
					}
				}
				
				return producto;
			}
		}
		
		/**
		 * @brief Producto por escalar
		 */
		Matriz operator * (const double & escalar) const
		{
			Matriz multiplicada(*this);
			
			for (int i=0; i< Nfilas(); i++)
			{
				for (int j=0; j< Ncolumnas(); j++)
				{
					multiplicada.SetElemento(i, j, escalar*multiplicada.Elemento(i,j) );
				}
			}
			return multiplicada;
		}
		
		Matriz operator ^ (const int & exponente) const
		{
			Matriz elevada(*this);
			
			for (int i=0; i<exponente-1; i++)
			{
				elevada = elevada* *this;
			}
			
			return elevada;
		}
		
};

void Lectura(Matriz & la_matriz)
{
	for (int i=0; i<la_matriz.Nfilas(); i++)
	{
		for (int j=0; j<la_matriz.Ncolumnas(); j++)
		{
			double elemento;
			
			cout << "[" << i << "," << j << "]: ";
			cin >> elemento;
			
			la_matriz.SetElemento(i, j, elemento);
		}
	}
}

void Mostrar( const Matriz & la_matriz )
{
	for (int i=0; i<la_matriz.Nfilas(); i++)
	{
		for (int j=0; j<la_matriz.Ncolumnas(); j++)
		{
			cout << la_matriz.Elemento(i, j) << "\t";
		}
		cout << endl;
	}
}

int main()
{
	cout << "Bienvenido a la clase matriz" << endl;
	
	Matriz a(3,3), b(3,3), suma, resta;
	
	cout << "Matriz A:" << endl;
	Mostrar(a);
	cout << endl;
	
	cout << "Matriz B:" << endl;
	Mostrar(b);
	cout << endl;
	
	clog << "Modificando la matriz A..." << endl;
	Lectura(a);
	
	clog << "Modificando la matriz B..." << endl;
	Lectura(b);
	
	suma = a + b;
	
	cout << endl << "A + B = " << endl;
	Mostrar(suma);
	
	cout << endl << "A * B = " << endl;
	Mostrar(a*b);
	
	cout << endl << "2 * A = " << endl;
	Mostrar(a*2);
	
	cout << endl << "B^1 = " << endl;
	Mostrar(b^1);
	
	cout << endl << "B^2 = " << endl;
	Mostrar(b^2);
}
