/*
 * Problema 7.1.
 * Escriba un programa que reciba en la línea de órdenes el nombre de una persona y que nos diga le nùmero de vocales de dicho nombre.
 * Por ejemplo, si nuestro ejecutable se almacena en el fichero contar, lo llamaríamos de la siguiente forma:
 * 		contar Juan Molina
 * y el programa nos diría que contiene 5 vocales.
 * 
 * jruib
 */
 
 #include <iostream>
 
 using namespace std;
 
 int main(int argc, char * argv[]) {
	int nvocales = 0;
	
	char * pnombre = argv[1]; //primer argumento
	
	for ( int i=0; pnombre[i] != '\0'; i++)
		if ( pnombre[i]=='a' || pnombre[i]=='e' || pnombre[i]=='i' || pnombre[i]=='o' || pnombre[i]=='u' || pnombre[i]=='A' || pnombre[i]=='E' || pnombre[i]=='I' || pnombre[i]=='O' || pnombre[i]=='U' )
			nvocales++;
			
	cout << "Contiene " << nvocales << " vocales" << endl;
	
	return 0;
 }
