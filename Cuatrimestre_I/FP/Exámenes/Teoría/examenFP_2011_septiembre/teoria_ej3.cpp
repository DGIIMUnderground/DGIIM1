#include <iostream>
#include <vector>

using namespace std;

vector<int> Lectura(){
	vector<int> v;
	int x;
	
	cin >> x;
	while( x>=0 && x<= 100){
		v.push_back(x);
		cin >> x;
	}
	
	return v;
}

void MostrarVector (const vector<int> & v)
{
	for (int i=0; i<v.size(); i++)
	{
		cout << v[i] << " ";
	}
}

int main(){
	vector<int> secuencia = Lectura();
	
	vector<int> subsecuencia;
	vector<int> mayor_subsecuencia;
	int posicion_mayor;
	
	for (int i=0; i<secuencia.size(); i++)
	{
		subsecuencia.resize(0);
		subsecuencia.push_back(secuencia[i]);
		
		for (int j=i+1; j<secuencia.size(); j++)
		{
			if ( secuencia[j] >= subsecuencia[ subsecuencia.size()-1] )
			{
				subsecuencia.push_back( secuencia[j] );
			}
			else{
				break;
			}
		}
		
		if( subsecuencia.size() > mayor_subsecuencia.size() )
		{
			mayor_subsecuencia = subsecuencia;
			posicion_mayor = i;
		}
	}
	
	//SALIDA:
	
	cout << "La mayor subsecuencia encontrada es: ";
	MostrarVector(mayor_subsecuencia);
	cout << endl;
	
	cout << "Posición: " << posicion_mayor+1 << endl;
	cout << "Longitud: " << mayor_subsecuencia.size() << endl;
	
	
}
