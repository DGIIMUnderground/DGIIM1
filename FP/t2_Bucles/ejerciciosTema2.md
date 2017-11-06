# Ejercicios resueltos del tema 2

## Ejercicio 3.9
> Ejercicio 3.9 resuelto, a la hora de calcular he metido una función para no ir teniendo que arrastrar la expresión.

```cpp

#include <iostream>
using namespace std;

/**@brief Evalúa la expresión para un valor x
 * @param Un valor x
 * @return El resultado de la expresión
 * */
 
double polinomio (double x){
	double a;

	a = 2*x*x*x + 8*x*x - 5;
	return a ;
}


int main () {
	double error;
	double intervaloI, intervaloF;
	double valoraux;
	
	int contador = 0;
	
	cout << "Introduce el error que determinará la precisión del cálculo" << endl;
	cin >> error;
	
	cout << "Introduce el primer valor del intervalo" << endl;
	cin >> intervaloI;
	cout << "Introduce el segundo valor del intervalo" << endl;
	cin >> intervaloF;
	
	while ( (intervaloF - intervaloI) > error ){
		valoraux = ( intervaloI + intervaloF ) / 2;
		if ( polinomio( intervaloI ) * polinomio (valoraux) <= 0 ){
			intervaloF = valoraux;
		}
		if ( polinomio (valoraux) * polinomio ( intervaloF ) <= 0){
			intervaloI = valoraux;
		}
		contador ++;
	}
	cout << "La solucion a la ecuacion es " << valoraux << endl;
	cout << "Se ha repetido el bucle " << contador << " veces" << endl;
}

```
