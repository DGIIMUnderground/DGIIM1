/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2017-2018
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// EXAMEN PRÁCTICO 2
//
// ¡RELLENAD LOS SIGUIENTES DATOS!
//
// Apellidos:  Villegas Yeguas
// Nombre:  Antonio David
//
// GRUPO DE PRÁCTICAS: A3
//
// Fecha:  30 / 05 / 18
// 
// Ordenador (ver etiqueta): ei142176
//
/***************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>


using namespace std; 

/***************************************************************************/
/***************************************************************************/

void LeerTareas (istream & in);
bool LineaVacia(const string & cadena);
bool ExisteFichero(const char * fichero);

/***************************************************************************/
/***************************************************************************/

int main (int argc, char **argv)
{

	// Completar

	//Comprobamos el numero de argumentos
	if (argc < 1 || argc > 2){
		cerr << "ERROR: Numero de argumentos invalido." << endl
			 << "Uso: " << endl
             <<  "  1) " << argv[0] << " <fichero> " << endl
			 <<  "  2) " << argv[0] << endl;

		exit(1);

	}

	//Si se ejecuta sin argumentos, lectura con cin
	if(argc == 1){
		LeerTareas(cin);
	}
	else{
		//Si se manda un fichero, comprobamos que existe
		if (!ExisteFichero(argv[1])){
			cerr << "ERROR: No se puede leer el fichero " << argv[1] << endl;
			exit(2);
		}

		//Si existe, realizamos la lectura desde ese fichero
		ifstream fi;

		fi.open(argv[1]);

		LeerTareas(fi);

		fi.close();
	}

	return (0);
}

/***************************************************************************/
/***************************************************************************/


void LeerTareas (istream & in){
	
	const int TAM_CAD = 100;
	const string PALABRA_MAGICA = "TAREAS";
	const string MAYUS = "MAYUSCULAS";
	const string MINUS = "MINUSCULAS";

	string cadena;
	bool a_mayus;

	//Leemos lineas, hasta alcanzar una no vacia
	getline(in, cadena);

	while( !in.eof() && LineaVacia(cadena) ){

		getline(in, cadena);
	}

	//Comprobamos que la primera linea sea la palabra magica, si no, salimos
	if (cadena != PALABRA_MAGICA){
		cerr << "ERROR: Inconsistencia en la entrada de datos." << endl;
		exit (3);
	}

	//Seguimos leyendo lineas, hasta la siguiente no vacia
	getline(in, cadena);

	while( !in.eof() && LineaVacia(cadena) ){

		getline(in, cadena);
	}

	//La siguiente no vacia, sera orden
	if (cadena == MAYUS){
		a_mayus = true;
	}
	else if (cadena == MINUS){
		a_mayus = false;
	}
	else{
		//Si mandan una orden desconocida, salimos
		cerr << "ERROR: Inconsistencia en la entrada de datos." << endl;
		exit (4);
	}

	
	//Comprobamos el tipo de orden, para despues crear los ficheros
	string tipo_cambio = (a_mayus) ? ("_MAYS") : ("_MINS");



	char archivo[TAM_CAD];

	char confirmacion;


	//Comenzamos la lectura
	getline(in,cadena);

	while(!in.eof() ){

		// Comenzamos con que queremos escribir los nuevos fichero
		//(si no existen, los crearemos por defecto, y si existen, preguntaremos
		// por el valor de confirmacion)
		confirmacion = 's';

		//Si es una linea no vacia, la procesamoss
		if (!LineaVacia(cadena)){

			//Guardamos en una cadena clasica la linea, para posteriormente
			//abrir este archivo si existe
			strcpy(archivo, cadena.c_str());

			if(!ExisteFichero(archivo)){
				cout << "\nNo se ha podido abrir " << archivo << endl ;
			}
			else{
				ifstream fi;
				fi.open(archivo);				
				
				//Creamos un flujo a string para el nuevo nombre
				ostringstream oss;
			
				oss << cadena << tipo_cambio;

				//Si existe el archivo con el nuevo nombre, preguntamos
				if (ExisteFichero(oss.str().c_str() ) ){
					
					
					cout << "\nAVISO: El fichero " << oss.str() << " ya existe"
						 << " ¿desea sobreescribirlo? [S/N]: ";

					do{
						cin >> confirmacion;
						confirmacion = tolower(confirmacion);

					}while(confirmacion != 's' && confirmacion != 'n');

				}
				//Si la confirmacion es valida, procesamos
				if (confirmacion == 's'){
					ofstream fo (oss.str() );
					//Comprobamos que podemos crear archivo
					if (fo.fail()){
						cout << "\nNo se ha podido crear " << oss.str() <<  endl;
					}
					else{
						char c;
				
						// Copiamos la entrada en la salida, en mayusculas
						//o minusculas, dependiendo de la orden
						if (a_mayus){
							while(!fi.eof()){
								fi.get(c);
								fo.put(toupper(c));
							}
						}
						else{
							while(!fi.eof()){
								fi.get(c);
								fo.put(tolower(c));
							}
						}

						cout << endl
						     << "El archivo " << oss.str() << " ha sido creado"
		                     << " con exito." << endl;
					}

					
					fo.close();
				}
				fi.close();
			}

		}

		getline(in,cadena);

	}

}

/*****************************************************************************/

//Comprobar que una cadena string esta vacia, o esta llena de espaciadores
bool LineaVacia(const string & cadena){
	bool vacia = true;

	for (int i = 0 ; i < cadena.size() && vacia ; i++){
		vacia = isspace(cadena[i]);
	}


	return vacia;
}


//Comprobar si existe un fichero
bool ExisteFichero(const char * fichero){

	bool existe;
	ifstream fi(fichero);

	if (!fi.fail())
		existe = true;
	else
		existe = false;

	fi.close();

	return existe;

}



















 
