/*10. Haz un programa que lea un texto desde cin y que, al finalizar la entrada de datos,
muestre cuántas veces aparece cada letra (a..z), teniendo en cuenta lo siguiente:
• la entrada de datos finaliza con el carácter #.
• no se diferenciarán mayúsculas y minúsculas.
• el texto se lee carácter a carácter en una función que guarda los caracteres en un
array de char recibido como parámetro.
• usaremos una función que reciba como parámetro un array de caracteres y construya
un array de enteros con la frecuencia para cada carácter.

José L. Ruiz
*/

#include <iostream>

using namespace std;

struct ElementoFrecuencia{
	char elemento;
	int frecuencia;
};

void Lectura( char t[], const int & tamano_t, int & util_t){
	util_t = 0;
	
	cin >> t[util_t];
	while( util_t <= tamano_t && t[util_t]!='#'){
		util_t++;
		cin >> t[util_t];
	}
	
}

/**
 * @brief Localiza la posición de un elemento en un vector del objeto ElementoFrecuencia
 * @return posicón. si no se encuentra devuelve -1
 */
int Busca( const char & un_elemento, const ElementoFrecuencia frecuencias[], const int & util_frecuencias){
	int posicion = -1;
	for (int i=0; i<util_frecuencias && posicion == -1; i++)
		if( un_elemento == frecuencias[i].elemento )
			posicion = i;
	return posicion;
}

void CalculaFrecuencias( const char texto[], const int util_texto, ElementoFrecuencia frecuencias[], int & util_frecuencias){
	util_frecuencias = 0;
	int posicion;
	
	for( int i=0; i<util_texto; i++){
		char elemento = texto[i]; //elemento para añadir al vector frecuencias
		if( elemento>='a' && elemento<='z' )
			elemento = elemento + 'A' - 'a';
		if( elemento >= 'A' && elemento <= 'Z'){
			posicion = Busca(elemento, frecuencias, util_frecuencias);
			if (posicion != -1)
				frecuencias[posicion].frecuencia++;
			else{
					frecuencias[util_frecuencias].elemento = elemento;
					frecuencias[util_frecuencias].frecuencia = 1;
					util_frecuencias++;
			}
		}
	}	
}

void OrdenaAlfabeticamenteFrecuencias( ElementoFrecuencia vfrec[], const int util_vfrec ){
	char minimo;
	int pos_min;
	for (int i=0; i<util_vfrec; i++){
		minimo = vfrec[i].elemento;
		pos_min = i;
		for( int j=i+1; j<util_vfrec; j++)
			if( vfrec[j].elemento < minimo){
				minimo = vfrec[j].elemento;
				pos_min = j;
			}
		if (minimo != vfrec[i].elemento){
			ElementoFrecuencia aux = vfrec[i];
			vfrec[i] = vfrec[pos_min];
			vfrec[pos_min] = aux;
		}
	}
}

void MostrarFrecuencias( const ElementoFrecuencia vfrec[], const int & util_vfrec){
	for(int i=0; i<util_vfrec; i++)
		cout << vfrec[i].elemento << ": " << vfrec[i].frecuencia << " veces" << endl;
}

int main(){
	int TAMANO = 10000;
	char texto[TAMANO];
	int util_texto;
	
	cout << "Introduca texto. No exceda de 10 000 caracteres y finalize con '#' " << endl;
	Lectura(texto, TAMANO, util_texto);
	
	ElementoFrecuencia frecuencias[25]; // con 25 letras es suficiente
	int util_frecuencias;
	
	CalculaFrecuencias(texto, util_texto, frecuencias, util_frecuencias);
	
	OrdenaAlfabeticamenteFrecuencias(frecuencias, util_frecuencias);
	
	cout << "La frecuencia con la que aparece cada letra es:" << endl;
	MostrarFrecuencias(frecuencias, util_frecuencias);
}
