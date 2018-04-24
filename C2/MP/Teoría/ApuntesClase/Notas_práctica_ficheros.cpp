/*
Descripcion:
	Nociones básicas sobre archivos en memoria masiva
	Clase práctica del 17 de Abril de 2018
Autor:
	Sergio Quijano Rey
	sergiquijano@gmail.com
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream file_input;
	char file_name[] = "fichero.data";
	string file_name2 = "fichero.data";
	double dat_temp;
	
	//Apertura del archivo, una con c_str y otra con string (SOLO SE HACE UNA)
	file_input.open(file_name);
	file_input.open(file_name2.c_str());

	//Control de apertura del archivo
	if(file_input == true)
		cerr << "El archivo se ha abierto correctamente" << endl;
	else
		clog << file_name << " se ha abierto correctamente" << endl;

	
	//Lectura de datos
	file_input >> dato_entero;
	file_input >> dato_double;
	file_input >> dato_string;
	
	//Control en la lectura de datos
	if(file_input == true)
		clog << "Lectura correcta" << endl;
	else
		cerr << "Lectura fallida" << endl;
		
	//Lectura de datos refinada
	bool acabado = false;
	while(!acabado){
		file_input >> dato_temp;
		
		if(file_input.eof()){	//Acabo de leer el archivo
			acabado = true;
		}else{
			//Proceso como quiera dat_temp
			cout << dat_temp * 2 << endl;
		}
	}

	//Es conveniente cerrar a mano los flujos de datos
	file_input.close();
}
