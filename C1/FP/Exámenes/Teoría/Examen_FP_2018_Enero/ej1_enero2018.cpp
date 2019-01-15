//Ejercicio 1 Examen FP enero de 2018
//Se puede encontrar el enunciado en decsai.ugr.es/jccubero/FP/FP_GuionPracticas_hasta_s9.pdf (RP-III.13)

#include <iostream>
using namespace std;

int main(){
	int n_pedidos;

	//Introduce número de pedidos
	cout << "Numero de pedidos: ";
	cin >> n_pedidos;

	//Introduce matriz de tarifas
	cout << "Tarifas: ";
	int tarifas[n_pedidos][n_pedidos];
	for(int i=0; i<n_pedidos; i++){
		for(int j=0; j<n_pedidos; j++){
			cin >> tarifas[i][j];
		}
	}

	//Creamos e inicializamos a true matriz de encargos
	bool encargos[n_pedidos][n_pedidos];
	for(int i=0; i<n_pedidos; i++){
		for(int j=0; j<n_pedidos; j++){
			encargos[i][j] = true;
		}
	}

	//Buscamos para cada técnico el encargo más barato disponible
	for(int i=0; i<n_pedidos; i++){
		int minimo = -1;
		for(int j=0; j<n_pedidos; j++){
			if(encargos[i][j]){   //si el encargo está disponible
				if(minimo == -1)  //cuando encontramos el primer encargo disponible
					minimo = j;   
				else if(tarifas[i][j] < tarifas[i][minimo]) //si el encargo es más económico
					minimo = j;
			}
		}
		for(int k=0; k<n_pedidos; k++){  //ponemos como NO disponible el encargo al resto de técnicos
			if(k!=i)
				encargos[k][minimo] = false;
		}
	}

	//Calculamos y mostramos el coste por técnico
	int coste_total = 0;
	int coste_tecnico;
	for(int i=0; i<n_pedidos; i++){
		int j = 0;
		while(!encargos[i][j])  //Ignoramos hasta encontrar el encargo asignado
			j++;

		coste_tecnico = tarifas[i][j];
		coste_total += coste_tecnico;
		cout << "Técnico " << i+1 << ": " << coste_tecnico << endl;
	}

	cout << "El coste total es: " << coste_total << endl;

	return 0;
}