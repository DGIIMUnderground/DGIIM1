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

##Ejercicio 3.10

```cpp
#include <iostream>
using namespace std;

int main (){
	
	double conversion;
	int limitecambio;
	
	cout << "¿Cuantos euros vale un dolar?" << endl;
	cin >> conversion;
	
	cout << "¿Limite de cambio?" << endl;
	cin >> limitecambio;
	
	for (int i = 1 ; i <= limitecambio ; i++){
		cout <<  i << "$ = " << conversion*i << " € \n";
	}
}
```
- - -

##Ejercicio 3.12

```cpp
include <iostream>
using namespace std;

int main(){
	int numdatos;
	double numero;
	double mediaNumerador = 0, varianzaNumerador = 0;
	double media, varianza;
	
	cout << "¿De cuantos numeros desea calcular la media y la varianza?" << endl;
	cin >> numdatos;
	
	for ( int i = 0 ; i < numdatos ; i++){
		cout << "Introduzca el " << i + 1 << "º numero ";
		cin >> numero;
		mediaNumerador += numero;
		varianzaNumerador += numero*numero;
	}
	
	media = mediaNumerador / numdatos;
	varianza = (varianzaNumerador / numdatos) - media*media;
	
	cout << "La media vale " << media << endl;
	cout << "La varianza vale " << varianza << endl;
}
```
- - -

##Ejercicio 3.14

```cpp

#include <iostream>
using namespace std;


int main(){
	int nciudades,ciudadmaxima;
	int contador;
	
	double media, nummedia = 0, mediaux = -99;
	double temperaturas = 0;
	
	cout << "Introduce el numero de ciudades del que quieras hcaer la media" << endl;
	cin >> nciudades;
	
	for ( int i = 0; i < nciudades ; i++){
		temperaturas = 0;
		media = 0;
		nummedia = 0;
		contador = 0;
		cout << "Introduce las temperaturas para la ciudad, cuando quieras acabar pon >= -100" << endl;
		while ( true ){
			cin >> temperaturas;
			if (temperaturas > -100){
				nummedia += temperaturas;
				contador ++;
			}
			else{
				break;
			}
		}
		media =  nummedia / contador;
		if ( media > mediaux ){
			mediaux = media;
			ciudadmaxima = i + 1;
		}
		
	}
		cout << "La mayor temperatura media es: " << mediaux << endl;
		cout << "Ciudad: " << ciudadmaxima << endl; 
}

```
- - - 

##Ejercicio 3.15

```cpp

#include <iostream>
using namespace std;

int main(){
	int n;
	double min,max;
	double valorentrada;
	bool comprobacion;
	
	cout << "n, min,max " ;
	cin >> n >> min >> max;
	
	for ( int i = 0 ; i < n ; i++ ){
		cout  << "Introduzca el valor " << i << " ";
		cin >> valorentrada;
		if ( valorentrada <= max && valorentrada >= min ){
			comprobacion = true;
		}
		else{
			comprobacion = false;
			break;
		}
	}
	
	if (comprobacion){
		cout << "Los tres valores introducidos están en el intervalo [" << min << "," << max << "]" <<endl;
	}
	else{
		cout << "Error. Finalización inesperada del programa: Valor fuera de rango" << endl;
	}
}
			
		
```

- - - 

##Ejercicio 3.16

> Creo que si el profesor ve este ejercicio de lo poco optimizado que esta me escupe a la cara hehe.

```cpp
#include <iostream>
using namespace std;

int main(){
	double valorintroducido, valoraux = 0, valormax = -1  , valormin = 10000000;
	double subidamax = 0, bajadamax = 0, subida;
	bool novacio = false;
	
	cout << "Introduzca un valor: " ;
	cin >> valorintroducido;
	
	while ( valorintroducido >= 0 ){
		if ( valorintroducido >= valormax ){
			valormax = valorintroducido;
		}
		if ( valorintroducido <= valormin ){
			valormin= valorintroducido;
		}
		
		if ( valoraux != 0 ){
			subida = valorintroducido - valoraux;
			if ( subida >= subidamax ){
				subidamax = subida;
			}
			if (subida <= bajadamax ) { //Bajada max siempre negativa
				bajadamax = subida;
			}
		}
		
		valoraux = valorintroducido;
		cout << "Introduzca un valor: " ;
		cin >> valorintroducido;
		
		novacio = true;
	}
	
	
	if ( novacio ){
		cout << "Valor maximo : " << valormax << endl;
		cout << "Valor mínimo : " << valormin << endl;
		cout << "Subida maxima: " << subidamax << endl;
		cout << "Bajada maxima: " << - bajadamax << endl;
	}
	else{
		cout << "Secuencia vacía";
	}
}
		
```








