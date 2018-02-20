/*
 * 2. (2.5 puntos) Se dispone de un conjunto de cadenas de caracteres con los nombres de varios equipos de tenis de
mesa participantes en un torneo. Se desea crear un vector que contenga todos los emparejamientos posibles. Por
ejemplo, si se parte del conjunto { Albolote, Motril, Baza, La Zubia }, debe construirse el siguiente vector:
{{Albolote, Motril} , {Albolote, Baza} , {Albolote, La Zubia} , {Motril, Baza} , {Motril, La Zubia} , {Baza, La Zubia}}
Defina los tipos de datos y módulos necesarios para resolver el problema planteado. Tenga en cuenta que el número
de equipos puede ser cualquiera (no sólo 4 como en el ejemplo), el orden de los emparejamientos no tiene por qué ser
el anterior, sólo puede usar el tipo string para representar el nombre de cada equipo y no es necesario crear el
programa principal.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Emparejamiento{
	string pueblo_a;
	string pueblo_b;
};

void Lectura_pueblos( vector<string> & v)
{
	string p;
	getline(cin, p);
	while( p != "#" )
	{
		v.push_back(p);
		getline(cin, p);
	}
}

vector<Emparejamiento> Empareja(const vector<string> & p)
{
	vector<Emparejamiento> parejas;
	
	Emparejamiento elemento;
	
	for(int i=0; i<p.size()-1; i++)
	{
		for(int j=i+1; j<p.size(); j++)
		{
			elemento.pueblo_a = p[i];
			elemento.pueblo_b = p[j];
			
			parejas.push_back(elemento);
		}
	}
	
	return parejas;
}

void Mostrar_Vector_Emparejamiento( const vector<Emparejamiento> & v)
{
	for (int i=0; i<v.size(); i++)
	{
		cout << "{" << v[i].pueblo_a << ", " << v[i].pueblo_b << "}" << endl;
	}
}

int main()
{
	vector<string> pueblos;
	cout << "Introducir pueblos. Presione Enter para introducir el pueblo siguiente y finalice con #: " << endl;
	Lectura_pueblos(pueblos);
	
	vector<Emparejamiento> parejas = Empareja(pueblos);
	
	cout << "Los posibles emparejamientos son: " << endl;
	Mostrar_Vector_Emparejamiento(parejas);
}
