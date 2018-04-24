<!--
Autor:
    Sergio Quijano Rey
    sergiquijano@gmail.com
Descripción:
    Apuntes tomados en clase del tema 1
-->

# **Tema 1: Arrays y cadenas tipo C**


## 1.1: Pequeña introducción

Las cadenas de caracteres estilo C son muy importantes en ámbitos de `C++` como:

~~~c++
int main(int argv, char* argv[]){
    ...
}
~~~

## 1.2 Arrays

Es un tipo de dato compuesto de un **número fijo** de elementos del mismo tipo. Sus elementos son directamente accesibles a través de un índice. Es claro que su principal diferencia con un `vector` es que su tamaño no puede variar una vez declarado.

**Declaración:**

Estructura de la declaración:

~~~c++
<tipo> <identificador> [numero componentes];
double notas[500];
~~~

Algunas variaciones:

~~~c++
int numeros1[3] = {1, 2, 3};
int numeros2[500] = {1, 2 ,3};  //Los que faltan se inicializan a 0
int numeros3[] = {1, 2, 3}; //El tamaño se establece a 3
~~~

El número de elementos debe ser una expresión constante entera, nunca una variable. El estándar `C99` lo admite, así como `g++`, aunque no es lo usual. No es correcto hacer algo tal que:

~~~c++
int numero;

cout << "Introduce el numero de estudiantes: ";
cin >> numero;

double estudiantes[numero];
~~~

### 1.2.1: Asignación de valores:

~~~c++
notas[0] = 5.3;
notas[1] = 7.8;

//No se puede hacer lo siguiente
notas = notas2 //Notas2 es otro array
~~~

**Uso normal del array**

Se crea una array de un tamaño muy grande para el uso del programa, y luego se utiliza otra variable entera para mantener el control del tamaño útil o real del array.

~~~c++
const int numal = 500;
double notas[numal];
int realSize = 0;
int notaIn;

cout << "Introduce el numero de alumnos: ";
cin >> realSize;

for(int i = 0; i < realSize; i++){
    cout << "Nota " << i << ": ";
    cin >> notaIn;
    notas[i] = notaIn;
}
~~~

### 1.2.2: Ejemplo con cálculo de la nota media:

~~~c++
int main(){
    const int arraySize = 500;
    int nAlumnos;
    int notaIn;
    int media;

    int notas[arraySize];

    cout << "Introduce el numero de alumnos: ";
    cin >> nAlumnos;

    if(nAlumnos > arraySize){
        cout << "Tamaño demasiado grande" << endl;
        media = 0;
    }else{
        //Introduzco las notas de los alumnos
        for(int i = 0; i < nAlumnos; i++){
            cout << "Nota " << i << ": ";
            cin >> notaIn;

            notas[i] = notaIn;
        }

        //Calculo la media
        media = 0;
        for(int i = 0; i < nAlumnos; i++){
            media += notas[i];
        }
        media = media / nAlumnos;
    }  

    cout << "La media es: " << media << endl;  
}
~~~

### 1.2.3: Uso de arrays con centinela

~~~c++
int main(){
    const int arraySize = 500;
    int realSize = 0;
    double notaIn = 0;
    double media = 0;
    double notas[arraySize];
    bool acabado = false;

    cout << "Una nota negativa no es valida" << endl;

    //Añado los datos
    while(!acabado && realSize < arraySize){
        cout << "Introduce nota: ";
        cin >> notaIn;

        if(notaIn >= 0){
            notas[realSize] = notaIn;
            realSize++;
        }else{
            acabado = true;
        }
    }

    //Calculo la media
    if(realSize == 0){
        media = 0;
    }else{
        for(int i = 0; i < realSize; i++){
            media += notas[i];
        }
        media = media / realSize;
    }

    //Muestro la media
    cout << "La media es: " << media << endl;


}
~~~

### 1.2.4: Arrays como argumentos de funciones:

~~~c++
#include <iostream>
using namespace std;

void imprimeArray(char lista[], int size){    //El compilador ignora el tamaño del array como parametro
    for(int i = 0; i < size; i++){
        cout << lista[i] << endl;
    }
}

int main(){
    char vocales = {'a', 'e', 'i', 'o', 'u'};
    imprimeArray(vocales, 5);
}
~~~

Los arrays se pasan por **defecto por referencia**, sin necesidad de poner `&`. Para hacer un **paso por copia** podemos poner un `const`. Sin embargo, no se crea la copia, pero a efectos prácticos es lo mismo. Cuando un parámetro `array` no se pasa como `const` se asume que el `array` va a ser modificado, y por tanto no puedo pasarle un `array` que sea constante. Así, el ejemplo anterior en el que definimos una función para mostrar los elementos de un array, es más correcta tal que:

~~~c++
#include <iostream>
using namespace std;

void imprimeArray(const char lista[], int size){
    for(int i = 0; i < size; i++){
        cout << lista[i] << endl;
    }
}

int main(){
    char vocales = {'a', 'e', 'i', 'o', 'u'};
    imprimeArray(vocales, 5);
}
~~~

### 1.2.5: Devolución de array

Un array no puede ser devuelto por un `return`. Lo que hay que hacer es pasarle un parámetro para que este sea modificado, a modo práctico de `return`. En el siguiente ejemplo, se usa un array de entrada y otro array de salida:

~~~c++
calculaPares(const int num[]; int pares[], int numSize, int & sizePares){
    sizePares = 0;

    for(int i = 0; i < numSize; i++){
        if(num[i] % 2 == 0){
            pares[sizePares] = num[i];
            sizePares++;
        }
    }
}

int main(){
    int arraySize = 6;
    int paresSize = 0;
    int numeros[] = {2, 3, 2, 3, 5, 7};
    int pares[6];

    calculaPares(numeros, pares, arraySize, paresSize);
}
~~~

### 1.2.6: Restricciones y peculiaridades en el uso de arrays

* No se pueden hacer asignaciones directas entre dos arrays
* No se puede leer de la entrada estándar un array
* No se puede mostrar en consola el contenido de un array completo haciendo sobrecarga del operador `<<`
* En general, no se puede usar la sobrecarga de ningún operador. Es decir, no se podría comparar con `<=` dos arrays
* Un array puede ser un campo de un `struct`, y con esto se puede hacer lo siguiente, aunque parezca paradójico (*ejemplo1*)
* Puedo usar arrays de *struct* o de *clases*, como hacíamos con los vectores
* Si una clase tiene definido por el programador un constructor que no sea por defecto, el compilador no lo creará por nosotros, y eso puede derivar en errores posteriores, de compilación (*contrastar esto*)
* Recorrer un array es más rápido que recorrer un vector

**Ejemplo1:**

~~~c++
struct array{
    int tamaño;
    int lista[];
};

array v1 = {5, {1,2,3,5,5}};
array v2 = v1;
~~~

### 1.2.7: Consejos:

> Usar constantes para definir el tamaño de los arrays. Así es más fácil adaptar el código del programa. Así solo hay que cambiar el valor del tamaño en una parte del código.

> Es conveniente que la variable global que almacena el tamaño por defecto de los arrays se coloque como global a todo el fichero, o a otros ficheros, para que sea accesible también por funciones externas a `main`

> Valgrind es una herramienta que ayuda a detectar errores en la memoria dinámica, en el caso de los arrays, ayuda a ver donde están los errores de índice

> La clase `vector` está construido en base a un tipo de `array` que se guardan en memoria dinámica. Por eso es tan útil su dominio

## 1.3: Cadenas de caracteres estilo C

* Un array de tipo `char` usa como elemento centinela el caracter `\0`, o podemos controlarlo a través de un entero para controlar el tamaño
* Un literal de cadena de caracteres C es una secuencia de cero o más caracteres encerrados entre comillas dobles.
* Su tamaño es la longitud de la cadena más uno para el carácter de escape

### 1.3.1: Inicialización

~~~c++
char nombre[10];
char nombre[] = {'J', 'a', 'v', 'i', 'e', 'r', '\0'};
char nombre[] = "Javier";   //Asume el \0

//Esto no es una cadena C por no tener el \0
char nombre[] = {'J', 'a', 'v', 'i', 'e', 'r'};
~~~

### 1.3.2: Ejemplos de uso

**Ejemplo 1, hola mundo:**

~~~c++
int main(){
    char nombre[100];

    cout << "Introduce tu nombre: ";
    cin >> nombre;

    cout << "Hola " << nombre << endl;
}
~~~

**Ejemplo 2: medir la longitud:**

~~~c++
int longitud(const char texto[]){
    int long = 0;
    bool acabado = false;

    while(!acabado){
        if(texto[long] == '\0'){
            acabado = true;
        }else{
            long++;
        }
    }

    return long;
}
~~~

**Ejemplo 3: Concatenacion de cadenas:**

~~~c++
void concatenar(const char texto1[], const char texto2[], char textoSalida[]){
    int idx = 0;

    for(int i = 0; texto1[i] != '\0'; i++){
        textoSalida[idx] = texto1[i];
        idx++;
    }

    for(int i = 0; texto2[i] != '\0'; i++){
        textoSalida[idx] = texto2[i];
        pos++;
    }    
}
~~~

### 1.3.3: Entrada/Salida

~~~c++
int main(){
	char nombre[80];

	cout << "Introduce tu nombre: ";
	cin >> nombre;
	cout << "El nombre es: " << nombre << endl;
}
~~~

Este código tiene problemas cuando ponemos nuestro nombre con espacios, los considera un separador, y el `cin` acaba la lectura del `char[]` en ese momento. Para evitar este problema usaremos el `getline`, del siguiente modo:

~~~c++
cin.getline(<cadena>, <tamaño>);
~~~

Este `getline` lee hasta que se encuentra un salto de línea o se alcanza el tamaño de lectura. Hay que tener cuidado si mezclamos `cin.getline`, `getline(cin, <cadena>)` y Esto lo podemos evitar tal que:

~~~c++
void leerLinea(char texto[], int size){
	do{
			cin.getline(texto, size);
		}while(texto == '\0')
}

//Esto se puede hacer tambien asi:
void leerLinea(char texto[], int size){
	do{
			cin.getline(texto, size);
		}while(longitud(texto) == 0);	//Necesitamos haber definido
										//el metodo longitud previamente
}

~~~

### 1.3.4: Conversión entre cadenas C y `String`

~~~c++
char cadena1[] = "Hola mundo";
char cadena2[100];
string cadena3;

cadena2 = cadena1;
cadena3 = cadena1.c_str();
cadena3 = strcpy(cadena3, cadena1);
~~~

### 1.3.5: Biblioteca `cstring`

* `char * strcpy(char cadena1[], const char cadena2[]);`
* `int strlen(const char texto[]);`
* `char * strcat(char s1[], const char s2[])`: se concatena s2 al final de s1, y el resultado se guarda en s1
* `int strcmp(const char s1[], const char s2[])`, compara lexicográficamente.
	* Si son iguales, devuelve 0
	* Si s1 es menor que s2, devuelve un negativo
	* Si s2 es mayor que s2, devuelve un positivo

## 1.4: Matrices

* Llamaremos matriz a un array de dos o más dimensiones
* `C++` los considera arrays de arrays

### 1.4.1: Declaracion de matrices

~~~c++
//<tipo> <identificador>[dimension_fila][dimension_columna];

int main(){
	const int cols = 100;
	const int rows = 100;

	int tablero[rows][cols];
	int tablero2[2][3] = {{1, 2, 3}, {3, 4, 5}};
	int tablero3[2][3] = {1, 2, 3, 4, 5, 6};

	/*
	Tablero 3 tendra:
		1 2 3
		4 5 6
	*/
}
~~~

### 1.4.2: Conversion 2D a 1D

Para pasar de dos dimensiones a una sola dimension:

~~~c++
m[i][j] == m[idx];
idx = i * COL + j;	//COL es la constante del tamaño de columnas
~~~

### 1.4.3: Control de tamaño real de una matriz

* Usaremos dos variables para controlar el tamaño real
de filas y columnas
* Se suele usar la parte superior izquierda como el sector útil de la matriz

### 1.4.4: Funciones con matrices

* Al pasar una matriz como parámetro, hemos de especificar todas las dimensiones de la matriz menos la primera (*"Ejemplo 1"*).

**Ejemplo 1:**

~~~c++
void leerMatriz(int matrix[][COLS], int realFilas, int realCols);
//COLS no puede ser local a main, tiene que ser global a nivel de fichero
~~~
