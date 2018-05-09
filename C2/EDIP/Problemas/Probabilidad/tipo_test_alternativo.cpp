/*
Descripcion:
	Simula la realizacion de examenes tipo test bajo las condiciones propuestas
	por el profesor
Autor:
	Sergio Quijano Rey
	sergiquijano@gmail.com
Version:
	9 de Mayo de 2018
*/

#include <iostream>
#include<stdlib.h>
#include<time.h>
#include <cmath>
using namespace std;

//DECLARACION DE FUNCIONES
void startRandom();
int randomInt(int min, int max);
double get_probabilidad(int intentos);

int main(int narg, char * argv[]){
    const int default_intentos = 1000;
    int intentos;
    int aprobado;
    double probabilidad_acumulada;
    double porcentaje;
    double real_val = ((double)91/(double)(5*5*5*5*5));
    double error;
    double error_porcentaje;

    //Selecciono el numero de intentos a llevar a cabo
    if(narg != 2){
        intentos = default_intentos;
        cout << "No se ha introducido un numero de intentos: se hacen " << default_intentos << " pruebas" << endl;
    }else{
        intentos = (int)*argv[1];
    }

    //Inicio la generacion de numeros aleatorios
    startRandom();

    //Calculo la media de probabilidades
    for(int i = 0; i < intentos; i++){
        probabilidad_acumulada = probabilidad_acumulada + get_probabilidad(intentos);
    }
    
    probabilidad_acumulada = probabilidad_acumulada / (double)intentos;
    porcentaje = probabilidad_acumulada * (double) 100;

    //Calculo errores
    error = abs(real_val - probabilidad_acumulada) / real_val;
    error_porcentaje = error * (double) 100;

    //Muestro los resultados
    cout << "La probabilidad de aprobar el examen es: " << porcentaje << "%" << endl;
    cout << "La probabilidad calculada matematicamente es, aproximadamente: " << real_val * (double)100 << "%" << endl;
    cout << "El error de la simulacion es: " << error_porcentaje << "%" << endl;
}


//IMPLEMENTACION DE FUNCIONES
void startRandom(){
    srand(time(NULL));     //Inicializo los numeros aleatorios
}
int randomInt(int min, int max){
    int value =  min + rand() % (max +1 - min) ;
    return value;
}

double get_probabilidad(int intentos){
    int aprobado = 0;
    double probabilidad;

    //Realizo el numero de intentos
    for(int i = 0; i < intentos; i++){
        int nota = 0;

        //Examen de 5 preguntas
        for(int j = 0; j < 5; j++){
            int random_num = randomInt(0, 4);

            if(random_num >= 0 && random_num <= 2){
                nota--;
            }else if(random_num == 3){
                nota = nota + 2;
            }
        }

        //Se comprueba si se ha aprobado
        if(nota >= 5){
            aprobado++;
        }
    }

    //Calculo el porcentaje
    probabilidad = (double) aprobado / (double) intentos;

    return probabilidad;
}
