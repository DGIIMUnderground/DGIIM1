/* 4. Dado un array de números reales, realizar una función que determine el primer y segundo
elemento de mayor valor.

José L. Ruiz
*/

#include <iostream>

using namespace std;

const int TAMANO = 100;

void LecturaArray( double v[], const int & util_v){
	for( int i=0; i<util_v; i++)
		cin >> v[i];
}

/**
 * @brief Obtiene los dos elementos mayores de un vector de reales
 * @pre El vector debe tener al menos dos elementos
 */
void ObtenerMayores( const double v[], const int & util_v, int & primero, int & pos_primero, int & segundo, int & pos_segundo){
	if( v[0] >= v[1] ){
		primero = v[0];
		pos_primero = 0;
		segundo = v[1];
		pos_segundo = 1;
	}
	else{
		primero = v[1];
		pos_primero = 1;
		segundo = v[0];
		pos_segundo = 0;
	}
	for (int i=2; i<util_v; i++){
		if( v[i] > primero){
			//El primer valor pasa a ser el segundo:
			segundo = primero;
			pos_segundo = pos_primero;
			//Obtego el nuevo primero:
			primero = v[i];
			pos_primero = i;
		}
		else{
			if( v[i] > segundo){
				//Actualizo el segundo elemento:
				segundo = v[i];
				pos_segundo = i;
			}
		}
	}
}

int main(){
	double numericos[TAMANO];
	int util_numericos;
	
	cout << "Número de numericos que va a introducir: ";
	cin >> util_numericos;
	while ( util_numericos > 100 || util_numericos < 2){
		cerr << "Error. No puede introducir más de 100 numericos o menos de 2." << endl;
		cout << "Número de numericos que va a introducir: ";
		cin >> util_numericos;
	}
	cout << "Introduzca numericos: ";
	LecturaArray(numericos, util_numericos);
	
	int primer_mayor, segundo_mayor, pos_primer_mayor, pos_segundo_mayor;
	ObtenerMayores(numericos, util_numericos, primer_mayor, pos_primer_mayor, segundo_mayor, pos_segundo_mayor);
	
	cout << "Primer elemento de mayor valor: " << primer_mayor << ", que se encuentra en la posición " << pos_primer_mayor << endl;
	cout << "Segundo elemento de mayor valor: " << segundo_mayor << ", que se encuentra en la posición " << pos_segundo_mayor << endl;
}
