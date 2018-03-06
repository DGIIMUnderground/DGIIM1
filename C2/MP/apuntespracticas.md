#Apuntes de MP día 26/02/2018

## Introducción

Para compilar:
```console 
g++ -o nombreejecutable nombrecpp.cpp
```
Para ejecutar:
```console
./nombreejecutable
```
En c++, podemos definir una constante de la siguiente forma:
```cpp
#define MSG "Hola mundo"
cout << MSG << endl;
```
En el programa anterior MSG es una constante que vale "Hola Mundo", es decir, el programa muestra por pantalla: "Hola mundo".
Las \# son cosas del precompilador que hace cositas antes del compilador
```console
g++ -E hw2.cpp
```
Salen cosas raras, pasa el precompilador. y sustituye los MSG por Hola mundo (es como macros).

```cpp
#def SPANISH
#ifdef SPANISH
	#define MSG holamundo
#else
	#define MSG Hello
#endif
```
Básicamente si se ha definidio spanish imprime holamundo y si no Hello.
Esto no ocupa memoria, al contrario que un const int ya que se hace buscar y reemplazar.

Para incluir cabeceras
```cpp
\#include "micabecera.h"
```
Coge el fichero y lo mete donde pone include, pero a veces no deja huella.
Al poner los <> es un fichero que el ya sabe donde está, es decir, se va a buscarlo a donde está (una carpeta donde estan los includes de c++)


## Pasamos al ejemplo círculo medio
### Doxygen
Comienza con /**
- @file Nos dice del fichero
- @author nos dice el autor de un fichero o función.
- @brief resumen de fichero o función.
- @param parámetro de una función.
- @return que devuelve la función.
- ///< es comentario corto de doxygen
- /// Comentario extendido de doxygen
El archivo doxy nos ayudará a generar la documentacion. De un proyecto a otro basta con cambiar el nombre para lo basico.
Doxygen soporta más lenguajes de programación.
Para instalar el doxygen basta el gestor de paquetes o sudo apt-get install
el dot lo mismo, lo que hace es generar diagramas chulos de funciones.

```console
doxygen circulomedio.doxy
```
Además genera un manual de referencia en pdf que mola mucho.

### Redirección de datos
```console
g++ -o circulomedio circulomedio.cpp
```
Ya tenemos todo el ejecutable.
```console
./circulomedio < circulomedio.dat
```
Redirijo la entrada para que todos los datos que se leen desde cin los coge del fichero. El cin no llega hasta el resultado.

### Compilación separada
Dividimos el fichero anterior (circulomedio.cpp) y lo dividimos en punto.h (declaraciones) y punto.cpp (implementaciones) y circulo.h y circulo.cpp (dividido de igual manera) y central.cpp (contiene al main).
Con el g++ genero arhivos objetos (.o) de punto.cpp circulo.o central.o
Uso g++ con los 5 ficheros y obtengo el circulomedio de antes.

```console
g++ -c punto.cpp -o punto.o
g++ -c circulo.cpp -o circulo.o
g++ -c central.cpp -o central.o 
g++ -o circulomedio central.o punto.o circulo.o
```
### Carpetas
- include donde estan lo .h
- obj donde estan los .o 
- src donde estan los cpp
- data donde estan ficheros de validación
- bin donde estan los binarios
- doc donde estan doxy y documentacion
- lib donde estan las bibliotecas.

Compilación en distintas carpetas:
```console
g++ -c src/punto.cpp -o obj/punto.o -I include/
g++ -c src/circulo.cpp -o obj/circulo.o -I include/
g++ -o bin/circulomedio obj/punto.o obj/circulo.o obj/central.o

bin/circulomedio < data/circulomedio.dat
```
##Archivos y separaciones
Normalmente haremos srchivos diferentes para:

- main La función main irá en unn archivo aparte (main.cpp)
- Declaración de una clase: Incluirá el nombre de la clase, especificación, métodos y funciones auxiliares. (nombredelaclase.h)
- Implementación: Todas las implementaciones de métodos o funciones irán en otro fichero aparte (nombredelaclase.cpp)

Si nuestro programa requiere de una clase, tendremos 3 archivos, si requiere de dos clases, tendremos 5 archivos, etc.
Todos los archivos tendrán al comienzo unas líneas como estas:
```cpp
/**
 * @file   iarchivo.cpp ó miarchivo.h
 * @author Mapachana
 * @brief  Definicion de la clase mi clase ó Implementación de la clase miclase ó Programa principal
 *
 */
```
 
Donde se indica en qué archivo se está, quién es el autor del mismo y qué función tiene.

###main.cpp
Contiene la función main, incluyendo las bibliotecas usuales y los .h necesarios:
```cpp
#include<iostream>
#include "miclase.h"
using namespace std
```
###miclase.h
Este archivo contendrá las especificaciones, nombres de métodos y funciones.
No se pondrá los includes usuales (solo e pondrán includes de otros .h de clases necesarias en la clase actual, por ejemplo, una clase circulo que dependa de una clase punto).
Se suelen añadir estas líneas:
```cpp
/** blabla */
#include "miotraclase.h" //no es siempre necesario
#ifndef _INTERVALO_H
#define _INTERVALO_H
//Todo el código viene aquí.
#endif
```
Esto evita que se añada un fichero de cabecera dos veces, lo cual da lugar a errores.
###miclase.cpp
En este archivo se encuentran todas las implementaciones de funciones y métodos. En él se debe incluir el .h de la declaración de la clase.
Se pondrán los includes necesarios y el espacio de nombres.

## Práctica de esta semana
Debemos separarlo en 3 ficheros: Intervalo.h Intervalo.cpp main.cpp cada uno en su carpeta y comprimirlas todas para entregarlas.

# Apuntes del 5/3 MP

## Makefile
Los makefiles sirven para compilar solo lo necesario de forma automatica al hacer cambios.
La primera regla es la de enlazado. Es necesario tabulador, no espacios.
Las librerías e includes se ponen al final.
Si hacemos touch y luego make solo se hacen las ordenes necearias.
El makefile se ejecuta con make.

## Bibliotecas
Se crean con ar rvs lib/intervalo.a obj/intervalo.o
g++ obj/intervalo.o -lintervalo -Llib -o bin/intervalo

/usr/local/include/ para meter bibliotecas del sistema

Los .a enlazan solo las cosas necesarias, el .o mete todo.

## Makefile y macros
Los comentarios son con #.
Las macros son variables con valor dentro solamente del makefile.
EN LOS APUNTES LA PRIMERA REGLA FALTA $(LIB) EN LA LIBRERIA

- -Wall activa los warnings. Se puede poner en una variable OPT
- -g Le mete en depurador.
OPT=-Wall -g
NUNCA SE ENTREGA UN PROYECTO CON LA OPCION -g

_By Mapachana_