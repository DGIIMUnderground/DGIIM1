/*
 * Ejercicio 5.10 — Ocurrencias de una palabra. Escriba un programa que lea múltiples líneas de texto hasta que se
encuentre una que contenga únicamente los 5 caracteres "#FIN#". Después, solicitará una cadena e indicará las veces
que se repite en las líneas de texto introducidas. El programa repite la pregunta y busca la nueva cadena hasta que le damos
la cadena "#FIN#".
* 
* José L. Ruiz
* 
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	//LECTURA DEL TEXTO:
	
	string texto;
	string linea;
	
	cout << "Introducir texto. Finalize escribiendo la línea \"#FIN#\": " << endl;
	getline(cin, linea);
	while (linea != "#FIN#" )
	{
		texto += "\n" + linea;
		getline(cin, linea);
	}
	
	cout << "Texto leído: " << endl;
	cout << texto << endl;
	
	//LECTURA DE LA PALABRA A BUSCAR:
	
	string palabra;
	cout << "\nPalabra que se buscará en el texto: " << endl;
	cin >> palabra;
	
	//BÚSQUEDA DE LA PALABRA EN EL TEXTO Y CÁLCULO DE SU FRECUENCIA:
	
	int frecuencia = 0; //número de veces que aparece al palabra que se busca
	
	string::size_type posicion = texto.find(palabra); // Busco la primera ocurrencia de la palabra
	
	while( posicion != string::npos ) //npos es el valor que devolvería si no encontrase la palabra.
	{
		frecuencia++;
		posicion = texto.find(palabra, posicion+1); //busca la palabra a partir de posicion+1
	}
	
	//SALIDA DEL PROGRAMA:
	
	cout << "Se ha encontrado la palabra \"" << palabra << "\" " << frecuencia << " veces." << endl;
}
