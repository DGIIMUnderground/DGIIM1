/*
 * 2. (3 puntos) Se quiere almacenar el nombre de un alumno junto con las notas que ha sacado en varias asignaturas.
El número de asignaturas puede variar de un alumno a otro y las notas son de tipo de dato entero. Con estos
datos, se quiere construir una clase, es decir, un conjunto de alumnos y ordenarlos de menor a mayor según la
media aritmética de sus calificaciones. Por ejemplo, si tenemos
[Ana de Gober, (9,7,8,9)] , [Sergio Garcı́a, (3,4,2)] , [David Rodriguez, (5,4)]
La nota media de Ana de Gober serı́a 8.25, la de Segio Garcı́a 3 y la de David Rodriguez 4.5 , por lo que el
vector resultante deberı́a quedarse como sigue:
[Sergio Garcı́a, (3,4,2)] , [David Rodriguez, (5,4)] , [Ana de Gober, (9,7,8,9)]
Defina las clases necesarias para resolver este problema. Si lo necesita, puede usar y/o ampliar la clase definida
en el primer ejercicio de este examen. No hace falta crear el programa principal ni ninguna clase para la lectura
o escritura de los datos.
* 
* José L. Ruiz
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Alumno
{
	private:
		string nombre;
		vector<int> notas;
		
	public:
		
		double NotaMedia() const
		{
			double suma=0;
			
			for (int i=0; i<notas.size(); i++)
			{
				suma = suma+notas[i];
			}
			
			return suma/notas.size();
		}
};

class ListaAlumnos
{
	private:
		vector<Alumno> lista;
		
	public:
	
		void Ordena()
		{
			for (int i=lista.size()-1; i>=0; i--)
			{
				for (int j=i; j<lista.size(); j++)
				{
					if( lista[j].NotaMedia() > lista[j+1].NotaMedia() )
					{
						Alumno aux = lista[j];
						lista[j] = lista[j+1];
						lista[j+1] = aux;
					}
				}
			}
		}
};

int main()
{
	
}
