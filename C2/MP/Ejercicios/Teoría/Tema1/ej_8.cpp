/* Haz un programa que obtenga la mayor secuencia monótona creciente de un array
de enteros leı́do de la entrada estándar, guardándola en otro array que se mostrará en la
salida estándar.

NOTA: He considerado que me piden la sucesión parcial creciente de mayor longitud, caso en el que los elementos no tienen por qué ser consecutivos. El profesor lo ha reselto en clase considerando que me piden la subsecuencia creciente (de términos positivos de mayor longitud). La función propuesta por el profesor es void MayorSecuenciaMonotonaCreciente2.

José L. Ruiz
*/

#include <iostream>

using namespace std;

void leerArray( int v[], const int & utiles){
	for (int i=0; i<utiles; i++){
		cout << "Elemento " << i << " : ";
		cin >> v[i];
	}
}

void imprimirArray(const int v[], const int & utiles){
	cout << "Número de elementos del vector: " << utiles << endl;
	cout << "Elementos: ";
	for (int i=0; i<utiles; i++)
		cout << v[i] << "  ";
	cout << endl;
}

void AsignaArray( int array[], const int nuevo_valor[], int & util_array, const int & util_nuevo_valor){
	if ( util_array < util_nuevo_valor)
		util_array = util_nuevo_valor;	
	for (int i=0; i<util_array; i++)
		array[i] = nuevo_valor[i];
}


void MayorSecuenciaMonotonaCreciente(const int v[], const int & util_v, int monotona[], int & util_monotona){
	int candidata[util_v]; //variable temporal en la que se almacenan las secuencias monótonas encontradas.
	util_monotona = 0;
	for (int i=0; i<util_v; i++){ //i indica el comienzo de la secuecia monótona temporal
		int util_candidata = 1; //al menos habrá un elemento que forme la secuencia monótona candidata
		candidata[0] = v[i];
		for (int j=i+1; j<util_v; j++)
			if(v[j] > candidata[util_candidata-1]){
				util_candidata++;
				candidata[util_candidata-1] = v[j];
			}
		if( util_candidata > util_monotona)
			AsignaArray( monotona, candidata, util_monotona, util_candidata);
	}
}

//////////////// PROFESOR /////////////////
void MayorSecuenciaMonotonaCreciente2(const int array[], int util, int salida[], int & util_salida){
	int longitud = 1;
	int pos_max = 0; //guarda donde empieza la secuencia de mayor longitud encontrada
	util_salida = 0;
	for (int i=1; i<util; i++)
		if( array[i] > array[i-1])
			longitud++;
			if(longitud > util){
				util_salida = longitud;
				pos_max = i-longitud;
		else
			longitud = 1;
	for (int i=0; i<util_salida; i++)
		salida[i] = array[pos_max+i];
				
}

int main(){
	const int TAMANO = 100;
	int numericos[TAMANO];
	int util_numericos;
	
	//LECTURA DEL ARRAY
	cout << "Número de elementos que se introducirán: ";
	cin >> util_numericos;
	while (util_numericos > 100){
		cerr << "No pueden introducirse más de 100 elementos" << endl;
		cout << "Número de elementos que se introducirán: ";
		cin >> util_numericos;
	}
	
	cout << "Introducir elementos:" << endl;
	leerArray(numericos, util_numericos);
	
	//CÁLCULOS
	int monotona[util_numericos]; //no necesito más longitud
	int util_monotona;
	MayorSecuenciaMonotonaCreciente(numericos, util_numericos, monotona, util_monotona);
	
	//SALIDA
	cout << "La mayor secuencia monótona creciente es" << endl;
	imprimirArray(monotona, util_monotona);
}
