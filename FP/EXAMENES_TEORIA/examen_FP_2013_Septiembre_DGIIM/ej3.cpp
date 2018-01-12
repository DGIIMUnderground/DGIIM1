/*
3. (3 puntos) Defina una clase Frase para almacenar un conjunto de caracteres. Como dato miembro ha de usarse
un vector (de la STL) de char. Defina un método para localizar la k-ésima palabra.
Una palabra es toda secuencia de caracteres delimitada por espacios en blanco a izquierda y derecha. La
primera palabra no tiene por qué tener espacios a su izquierda y la última no tiene por qué tener espacios
a su derecha. Puede haber varios caracteres en blanco consecutivos.
Si k es mayor que el número de palabras, se considera que no existe tal palabra.
Sólo debe definir los datos miembro y métodos necesarios para resolver este ejercicio. No puede usarse el
tipo string.
Por ejemplo, si la frase es {’ ’,’ ’,’h’,’i’,’ ’,’ ’,’b’,’i’,’ ’}. Si k = 1, la posición es 2. Si k = 2
la posición es 6. Si k = 3 la posición es -1.
Si la frase fuese {’h’,’i’,’ ’,’b’,’i’,’ ’}, entonces si k = 1, la posición es 0. Si k = 2 la posición es 3.
Si k = 3 la posición es -1.
* 
* José L. Ruiz
*/

#include <iostream>
#include <vector>

using namespace std;

class Frase
{
	private:
		vector<char> frase;
		
	public:
		
		/**
		 * @brief Constructor
		*/
		Frase (const vector<char> & v)
		{
			frase = v;
		}
		
		/**
		 * @brief Localiza en una frase la posición en la que comienza una palabra
		 * @param npalabra: número de palabra buscada
		 * @return posición en la que empieza la palabra número npalabra
		 */
		int PosicionPalabra( const int & npalabra) const
		{
			int posicion_palabra = -1;
			int contador_palabra = 0; //con esto voy contando las palabras que se han encontrado
			
			//Caso especial para frase[0]:
			if( frase[0] != ' ' )
			{
				contador_palabra++;
				
				if (npalabra == contador_palabra)
				{
					posicion_palabra=0;
				}
			}
			
			//Casos siguientes:
			for (int i=1; i<frase.size() && npalabra != -1; i++) //itero mientras que no se haya encontrado la palara
			{
				if( frase[i-1] == ' ' && frase[i] != ' ')
				{
					contador_palabra++;
					
					if (npalabra == contador_palabra)
					{
						posicion_palabra = i;
					}
					
				}
			}
			
			return posicion_palabra;
		}	
};

int main()
{
	cout << "BIENVENIDO A LA CLASE \"FRASE\"" << endl;
}
