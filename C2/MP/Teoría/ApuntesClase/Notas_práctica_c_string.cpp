/*
Descripcion:
	Notas aclaratorias de c_string
	Clase práctica del 17 de Abril de 2018
Autor:
	Sergio Quijano Rey
	sergiquijano@gmail.com
*/

#include <iostream>
#include <cstring>	//Conviene estudiar las funciones de esta libreria
using namespace std;

int main(){
	char c_string[200];	//Tamaño maximo, terminador '\0'
	string modern_string;	//Tamaño dinamico, sin terminador
	
	cin >> modern_string;
	cin >> c_string;	//Añade el terminador al final automaticamente
	cin >> c_string[0] >> c_string[1] >> c_string[2];	//No añade el terminador al final, MUCHO CUIDADO

	string modern_string2 = modern_string;	//Esto esta permitido
	char c_string2 = modern_string;		//Esto no esta permitido
	strcpy(modern_string, c_string2);	//Asi es como debe hacerse
	
	if(modern_string == modern_string2);	//Esto se puede hacer
	if(c_string == modern_string);		//No se puede hacer
	if(!strcmp(c_string, modern_string));	//Esta es la forma de hacerlo
	
	modern_string = c_string;		//Esto se puede hacer
	c_string = modern_string;		//Esto no se puede hacer
	c_string = modern_string.c_str();	//Asi debe hacerse
	
	char c_string3[200] = "Sergio";		//Añade el terminador
	string modern_string3 = "Sergio";
}

//Estos dos parámetros, ambos son c_string, no significa que uno sea dinámico y otro no
void mostrar_c_string(char string1[], char * string2);
