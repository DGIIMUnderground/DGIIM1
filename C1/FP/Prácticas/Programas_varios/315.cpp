//Creado por Asmilex/Andrés Millán
/**Enunciado del problema: Ejercicio 3.15  — Números en rango.
Escriba un programa que lea un entero y dos números reales: n, min y max. Estos
valores indican que hay n números de entrada y que deberían estar en el intervalo [min,max]. A continuación, deberá leer
los n valores de entrada y confirmar que todos están en el intervalo indicado. En caso de que uno de los valores no lo esté,
parará la lectura y terminará el programa indicando que hay valores fuera de rango. Resuelva el ejercicio usando un ciclo
for
*/
#include <iostream>
using namespace std;

int main(){
    bool comp; //Valor de comprobación. Si es falso, habrá salido bien 
    int N; //Número de valores que se introducirán
    double min,max,val;

    cout <<"Introduce el número de valores, el mínimo y el máximo";
    cin >>N>>min>>max;

    for (int i=0; i < N; i++){ //Comprueba si todos los valores que se introducen a partir de aquí están dentro del rango [min,max]
        cout <<"Empieza a meter valores";
        cin >>val;
        if (val < min || val > max){
            comp=true;
            i=N;
            cout <<"Error: Valor fuera de rango";
        }
    }
    
    if (comp==false) //Si todo ha salido bien, muestra el mensaje de éxito
        cout <<"Todos los valores están en el rango deseado";
}