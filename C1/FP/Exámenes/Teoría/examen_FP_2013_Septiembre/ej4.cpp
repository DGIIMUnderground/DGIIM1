/*
 * 4. (3 puntos) Sudoku es un juego muy popular que consiste en rellenar una cuadrı́cula de 9 × 9 celdas que
está dividida en subcuadrı́culas de 3 × 3 (denominadas regiones) con cifras del 1 al 9. Un sudoku se considera
resuelto si verifica que:
En cada fila aparecen todos los números del 1 al 9 (sin repetir)
En cada columna aparecen todos los números del 1 al 9 (sin repetir)
En cada región aparecen todos los números del 1 al 9 (sin repetir)
Realizar un programa que lea todos los elementos de un sudoku y determine si está resuelto o no. Se valorará la
correcta modularización del programa.
* 
* José L. Ruiz
* 
*/

#include <iostream>
#include <vector>

using namespace std;

class TableroSudoku
{
	private:
		vector<vector<int> > tablero;
		
		////////////////////// Métodos privados ////////////////////////
		/**
		 * @brief true si el elemento n se encuentra en el vector de enteros v)
		 */
		bool Existe( const int & n, const vector<int> & v)
		{
			bool existe = false;
			
			for (int i=0; i<v.size(); i++)
			{
				if ( n == v[i] )
				{
					existe = true;
					break;
				}
			}
			
			return existe;
		}
		
	public:
	
		///////////////////// Métodos públicos /////////////////////////
	
		/**
		 * @brief Constructor por defecto
		 */
		TableroSudoku()
		{
			vector<vector<int> > el_tablero(9, vector<int>(9, 0) );
			tablero = el_tablero;
		}
		
		/**
		 * @brief Cambia un elemento del tablero
		 */
		void Cambia(const int & la_i, const int & la_j, const int & numero)
		{
			tablero[la_i][la_j] = numero;
		}
		
		int Nfilas()
		{
			return 9;
		}
		
		int Ncolumnas()
		{
			return 9;
		}
		
		/**
		 * @brief Determina si un sudoku está correctamente resuelto
		 * @return true si está correctamente resuelto, false en otro caso
		 */
		bool Resuelto()
		{
			bool resuelto = true; //comienzo suponiendo que está resuelto
			
			//Veamos que en cada fila aparecen todos los números sin repetir
			vector<int> elementos;
			
			for( int i=0; i<9 && resuelto; i++) //sólo itero mientras esté resuelto=true
			{
				elementos.resize(0);
				
				for (int j=0; j<9 && resuelto; j++)
				{
					if ( Existe(tablero[i][j], elementos) || (tablero[i][j] < 1 && tablero[i][j] >9) )
					{
						resuelto = false;
					}
					else
					{
						elementos.push_back( tablero[i][j] );
					}
				}
			}
			
			//Veamos que en cada columna aparecen todos los números sin repetir
			for (int j=0; j<9 && resuelto; j++)
			{
				elementos.resize(0);
				for (int i=0; i<9 && resuelto; i++)
				{
					if ( Existe(tablero[i][j], elementos) || (tablero[i][j] < 1 && tablero[i][j] >9) )
					{
						resuelto = false;
					}
					else
					{
						elementos.push_back( tablero[i][j] );
					}
				}
			}
			
			//Veamos que en cada subtablero de 3x3 aparecen todos los números sin repetir
			
			for (int i=0; i<3 && resuelto; i++)
			{
				for (int j=0; j<3 && resuelto; j++) //Los dos primeros for para ir seleccionando cada subtablero
				{
					elementos.resize(0);
					
					for (int k=i*3; k<i*3+3 && resuelto; k++)
					{
						for (int l=j*3; k<j*3+3 && resuelto; k++) //los dos siguientes for para irme moviendo por los elementos de cada subtablero
						{
							if( Existe(tablero[k][l], elementos) || (tablero[i][j] < 1 && tablero[i][j] >9) )
							{
								resuelto = false;
							}
							else
							{
								elementos.push_back( tablero[k][l] );
							}
						}
					}
				}
			}
			
			
			return resuelto;
		}
		
		
};

/**
 * @brief Lee el valor de cada casilla de un sudoku
 */
void Lectura( TableroSudoku & un_tablero)
{
	for (int i=0; i<un_tablero.Nfilas(); i++)
	{
		for (int j=0; j<un_tablero.Ncolumnas(); j++)
		{
			int nuevo_valor;
			
			cout << "[" << i << "," << j << "]: ";
			cin >> nuevo_valor;
			
			un_tablero.Cambia(i, j, nuevo_valor);
		}
	}
}

int main()
{
	TableroSudoku partida;
	
	cout << "Introducir las casillas del sudoku: " << endl;
	Lectura(partida);
	
	if ( partida.Resuelto() )
	{
		cout << "El sudoku está resuelto" << endl;
	}
	else
	{
		cout << "El sudoku NO está resuelto" << endl;
	}
}
