// Nombre: Ricardo Ruiz Fernández de Alba
// SubGrupo: A2

#include <iostream>

using namespace std;

int main() {
	int dorsal, ganador, participantes=0;
	// Inicializamos horas_min y minutos_min
	// a unos valores mucho mayores de los esperados 
	int horas, minutos, horas_min=100, minutos_min=100;
	char delimitador;
	
	cout << "Introduzca los dorsales y tiempos correspondientes. Termine con el dorsal 0:" << endl;
	cin >> dorsal;
	
	while (dorsal != 0) {
		cin >> horas >> delimitador >> minutos;
		
		// Filtramos la entrada hasta que el número de dorsal
		// sea positivo
		while (dorsal < 0) {
			cout << "El dorsal debe ser positivo" << endl;
			cout << "Vuelva a introducirlo: ";
			cin >> dorsal;
		}
		
		// Filtramos la entrada hasta que las horas sean positivas
		// los minutos estén entre [0,59] y el delimitador sea ':' 
		while (delimitador != ':' || horas < 0 || minutos < 0 || minutos >	59) {
			cout << "Valor " << horas << ":" << minutos << " erroneo";
			cout << ", vuelva a introducir el tiempo del dorsal " << dorsal << endl;
			cin >> horas >> delimitador >> minutos;
		}
		
		// Hemos encontrado un participante más rápido
		if (horas*60 + minutos < horas_min*60 + minutos_min) {
			horas_min = horas;
			minutos_min = minutos;		
			ganador = dorsal;
		}

		participantes++;
		cin >> dorsal;
	}
	
	cout << "Numero de participantes: " << participantes << endl;
	
	if (participantes != 0) {
		cout << "Primera posicion corresponde al dorsal ";
		cout << ganador << " con un tiempo de " << horas_min << ":" << minutos_min << endl;
	} else {
		cout << "No hay ganador" << endl;
	}
}
