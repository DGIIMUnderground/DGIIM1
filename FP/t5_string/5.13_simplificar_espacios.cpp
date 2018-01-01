/*
Ejercicio 5.13 — Simplificar espacios. Escriba un programa que limpie una cadena de texto leída desde la entrada
estándar como una línea. Esta limpieza consistirá en eliminar los espacios iniciales, los espacios finales, y en caso de que
haya varios espacios consecutivos intermedios, simplificarlos en un único espacio. Tenga en cuenta que si la cadena tiene
sólo espacios, deberá convertirla en la cadena vacía.

José L. Ruiz

*/

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Mirar el enunciado al comienzo del fichero
 */
void Simplificar_espacios( string & f)
{
	//Quito los espacios que haya al comienzo de la frase:
	while(f.at(0) == ' ')
	{
		f.erase(0, 1);
	}
	
	//Quito los espacios que haya al final de la frase:
	while( f.at( f.size()-1) == ' ' )
	{
		f.erase( f.size()-1, 1);
	}
	
	//Quito los espacios entre palabras repetidos:
	for (int i=1; i<f.size()-1; i++)
	{
		if ( f.at(i) == ' ' && f.at(i+1) == ' ' )
		{
			f.erase(i+1, 1);
			i--; //para que no se salta nada
		}
	}
}

/* ACLARACIÓN SOBRE LA FUNCIÓN Simplificar_espacios:
 * 
 * Aunque pueda parecer un poco cutre quitar primero los espacios iniciales y los finales, así consigo reducir mucho el tamaño de la frase pronto,
 * con lo que se gana en eficiencia, ya que el bucle for (que ha simple vista parece más costoso) iterará menos veces.
 */

int main()
{
	string frase;
	
	cout << "Introducir frase: " << endl;
	getline(cin, frase);
	
	Simplificar_espacios(frase);
	
	frase += "x";
	
	cout << "Resultado: " << frase << endl;
}
