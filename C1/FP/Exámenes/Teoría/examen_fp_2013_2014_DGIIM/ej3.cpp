/*
Para gestionar un campeonato de n equipos se utiliza una matriz de tamaño n×n. En cada posición
de esta matriz se pueden almacenar tres posibles valores (’1’, ’X’, ’2’).La fila f y columna c contendrá un valor
correspondiente al partido que enfrenta al equipo f con el c, de forma que si vale ’1’ indica que ha ganado f , si
vale ’X’ han empatado y si vale ’2’ ha ganado c.

Observe que dados dos equipos (m, n) habrá dos partidos: uno en el que se enfrentan m y n y el recı́proco, de n
con m. Además, el valor de la diagonal no se usa, ya que no existe el partido n contra n.
Implemente un módulo para obtener un vector con los resultados finales de la liga. En este vector se contabilizan,
para cada equipo, los puntos obtenidos teniendo en cuenta que una victoria implica 3 puntos, un empate 1 punto,
y una derrota 0 puntos.
*/

#include <iostream>
#include <vector>

using namespace std;

struct equipo_puntos //tipo de dato que almacena un equipo junto a los puntos que ha obtenido
{
	int equipo;
	int puntos;
};

/**
 * @brief Lee una matriz con los resultados de la liga
 * @param m: matriz (tabla) con el número de equipos como fila y como columna
 */
void Lectura(vector<vector<char> > & m)
{
	cout << "Escriba el ganador de cada partido: 1 para el primer equipo, 2 para el segundo, X si hubo empate." << endl;
	
	for (int i=0; i<m.size(); i++)
	{
		for (int j=0; j<m[i].size(); j++)
		{
			if( i != j) // un equipo no compite contra sí mismo
			{
				cout << "Equipo " << i << "   /vs/   Equipo " << j << ":\t";
				cin >> m[i][j];
				while ( m[i][j] != '1' && m[i][j] != '2' && m[i][j] != 'X' )
				{
					cout << "Error. Introduzca 1, 2 ó X: ";
					cin >> m[i][j];
				}
			}
		}
	}
}

/**
 * @brief Ordena un vector de equipo_puntos de mayor a menor de acuerdo con los puntos de cada equipo.
 */
void Ordena_burbuja_mayor_a_menor( vector<equipo_puntos> & v)
{
	for (int i=v.size()-1; i>0; i--)
	{
		for (int j=0; j<i; j++)
		{
			if ( v[j].puntos < v[j+1].puntos )
			{
				equipo_puntos aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
		}
	}
}

/**
 * @brief Muestra los puntos que ha conseguido cada equipo
 * @param m: tabla con los resultados de cada partido (ganador)
 */
void Clasificacion( vector<vector<char> > & m )
{
	//Hago el recuento de puntos para los equipos y lo meto en un vector de equipo_puntos;
	
	vector<equipo_puntos> equipos_y_puntos( m.size() );
	
	for (int i=0; i<equipos_y_puntos.size(); i++ ) //relleno el campo del nombre del equipo;
	{
		equipos_y_puntos[i].equipo = i;
	}
	
	for (int i=0; i<m.size(); i++)
	{	
		for (int j=0; j<m[i].size(); j++)
		{
			switch( m[i][j] )
			{
				case '1':
					equipos_y_puntos[i].puntos = equipos_y_puntos[i].puntos + 3;
					break;
				case 'X':
					equipos_y_puntos[i].puntos = equipos_y_puntos[i].puntos + 1;
					equipos_y_puntos[j].puntos = equipos_y_puntos[j].puntos + 1;
					break;
				case '2':
					equipos_y_puntos[j].puntos = equipos_y_puntos[j].puntos + 3;
					break;
			}
		}
	}
	
	/*
	 * Al tener los datos'del vector por parejas, puedo ordenarlos en función de los campos puntos, teniendo siempre identificado
	 * a qué equipo pertenecen los puntos.
	 */
	
	Ordena_burbuja_mayor_a_menor( equipos_y_puntos ); //ordeno el vector para tener los equipos odenados de más puntos a menos.
	
	//Muestro la clasificación:
	cout << "CLASIFICACIÓN: " << endl;
	
	for (int i=0; i<equipos_y_puntos.size(); i++)
	{
		cout << "Equipo " << equipos_y_puntos[i].equipo << "\t\t\t\t" << equipos_y_puntos[i].puntos << " ptos." << endl;
	}
}

int main()
{
	int num_equipos;
	cout << "Número de equipos de la liga: ";
	cin >> num_equipos;
	
	vector<vector<char> > resultados(num_equipos, vector<char> (num_equipos) );
	
	cout << endl;
	
	Lectura(resultados);
	
	cout << endl;
	
	Clasificacion(resultados);
}
