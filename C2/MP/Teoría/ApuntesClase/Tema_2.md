<!--
Autor:
    Sergio Quijano Rey
    sergiquijano@gmail.com
Descripción:
    Apuntes tomados en clase del tema 2
-->

# **Tema 2: Punteros y memoria dinámica**

## 2.1: Tipo de dato Puntero

### 2.1.1: Motivacion

* Permite manejar tipos de datos cuyo tamaño se va a saber en tiempo de ejecución, y no en tiempo de compilación.
* Por ejemplo, lo que nos permitía hacer la clase `vector`
* La memoria dinámica permite crear variables en tiempo de ejecución, no en tiempo de compilación
* La gestión de esta memoria dinámica es **responsabilidad del programador**
* Esto es lo que nos permite las variables **tipo puntero**

### 2.1.2: Definicion de tipo de dato puntero

* Contiene una dirección de memoria
* Incluye una dirección especial conocida como la **dirección nula**, con valor `0`.
* En `C`, en lugar de `0` se usaba `NULL`, en `C++` incluimos `cstdlib`
* En `C++`, es preferible usar `nullptr`, que tiene algunas características preferentes
* El tamaño de un puntero siempre es el mismo, depende de la arquitectura del sistema, es decir, 32bits o 64bits, independientemente del tipo de dato al que apunten
* La asignación de punteros solo se permite hacer entre variables del mismo tipo
* **Un puntero guarda la dirección de memoria a un dato, no el dato en sí mismo**

### 2.1.3: Declaración de tipo de dato puntero

~~~c++
<tipo> *<identificador>

int * punteroInt;
char * punteroChar;
~~~

### 2.1.4: Operaciones con punteros

#### Operador `&` direccion

* `&<var>` devuelve la dirección de la variable `<var>`
* `dato1 & dato2` es el *and* a nivel de bit
webwhat

**Ejemplo:**

En este ejemplo, vamos a hacer que `punteroEntero` apunte a `numero`

~~~c++
int numero = 5;
int * punteroEntero;

punteroEntero = & numero;   //Ahora punteroEntero tiene la dirección de memoria de numero
~~~

#### Operador `*` indireccion

* Modifica el dato contenido en la dirección del puntero

**Ejemplo:**

~~~c++
int numero = 5;
int * puntero = & numero;
*puntero = 2;   //Asigno a numero el valor 2
~~~

#### Inicialización de un puntero

~~~c++
int a;
int * puntero = &a;

int * puntero2 = 0;
~~~

Aquí vemos que la única dirección de memoria que se le puede asignar como un literal es la dirección `0`. Es decir, no puedo decirle a un puntero `int * puntero = 1023` ni tampoco `int * puntero = & 1001`

#### Casting de punteros

Esto no es del nivel de la asignatura, pero conviene saberlo

~~~c++
int a = 6;
int *p1 = &a;
char *p2 = reinterpet_cast<char*> &a
~~~

### 2.1.5: Operadores Relacionales:

* Se suponen que los punteros se comportan como números enteros

#### Operador `==`, `!=`

* `p1 == p2`: comprueba si apuntan al mismo dato
* `*p1 == *p2`: comprueba si coincide lo almacenado en las direcciones de memoria

#### Operador `<`, `<=`, `>`, `>=`

* Permiten conocer la posición relativa de dos datos relativamente a la memoria
* Tiene sentido cuando los dos punteros apuntan a objetos cuyas posiciones relativas guardan relación, por ejemplo, con datos de un mismo array
* Esto no quiere decir que no se pueda hacer, simplemente que es bastante probable que no tengan utilidad alguna

### 2.1.6: Operadores aritméticos

* Tienen sentido, igual que en caso anterior, cuando la dirección relativa entre dos punteros guardan alguna relación
* No se pueden sumar punteros

~~~c++
int v[5] = {2, 6, 3, 5, 3};
int *p;

p = &v[2];
cout << p[1];   //Imprime 5
p += 2;
cout << p[0];   //Imprime el 3 de la ultima posicion

int *q = & v[2];
int *p = & v[4];
//p - q = 2
~~~

### 2.1.7 Ejemplos:

~~~c++
char y = 5, z = 3;
char * p1;
char * p2;

p1 = &y;
p2 = *p1;
~~~

### 2.1.8 Consejos

> Conviene inicializar todos los punteros al valor `0` si no se inicializa por asignación a otra dirección de memoria

## 2.2: Punteros y arrays

* Al declarar un array de n elementos, se reserva memoria para los n elementos del mismo tipo y se crea un puntero constante que apunta a la primera dirección de memeria del array
* Así, el puntero constante apunta a `v[0]`
* De esta forma, podemos usar un puntero como un array que comienza en ese elemento

### 2.2.1 Ejemplos:

**Ejemplo 1:**:

~~~c++
int v[5] = {1, 2, 3, 4, 5};
cout << *v << endl; //Imprime 1
cout << *(v+2) << endl; //Imprime 3
//*(v+2) equivale a v[2] y a *(&v[2])
~~~

**Ejemplo 2:**

Este ejemplo simula un paso por referencia

~~~c++
void cambiasigno(int *v; int n){
    for(int i = 0; i < n; i++){
        v[i] = -v[i];
    }
}
~~~

**Ejemplo 3:**

Muestro el contenido de un vector y aumento en uno el valor de todos los elementos

~~~c++
int v[10] = {3, 4, ...};
int *p = v;

for(int i = 0; i < 10; i++){
    cout << v[i];
    p[i]++;
}
~~~

**Ejemplo 4:**

Muestro el contenido de un vector

~~~c++
v[10] = {1, 2, 3, ...};

for(int *p = v; p < v+10; p++){
    cout << *p << endl;
}
~~~
## 2.2: Arrays de caracteres C

Como ya hemos visto, una cadena de caracteres `c` es un array de char. Y como también hemos visto, los arrays son, en su implementación, un puntero constante.

## 2.2.1: Ejemplos de Cadenas y punteros

**Ejemplo 1: Medir la longitud de una cadena**

~~~c++
const char *cadena = "Hola mundo";
const char *p;  //p no es constante, es contante el dato que almacena

int longitud = 0;
for(p = cadena, *p != '\0'; p++){
    longitud++;
}

cout << "Longitud: " << longitud << endl;
~~~

**Ejemplo 2: Eliminar los primeros caracteres de memoria**

~~~c++
const char *cadena = "Hola y adios";

cout << "Original: " << cadena << endl;
cout << "Sin la primera palabra: " << cadena +5 << endl;
cout << "La cadena se encuentra en: " << (char*)cadena << endl;

~~~

### 2.2.2: Inicialización de cadenas con literales

~~~c++
//Copia el literal en la cadena
char cadena1[] = "Hola mundo";
cardena1[0] = 'j';  //jola mundo

//Se asignan punteros
const char *cadena2 = "Hola mundo dos";
cadena2[0] = 'j';   //Error de compilacion
~~~

## 2.3: Punteros con `Struct` o `Class`

### 2.3.1: Ejemplo de uso

~~~c++
strut Persona{
    int edad;
    int altura;
}

Persona pepe;
pepe.edad = 10;
pepe.altura = 180;
Persona *puntero;
puntero = &pepe

cout << "La edad de pepe es: " << (*puntero).edad << endl;
~~~

Este ejemplo puede usarse de forma indistinta para `struct` o para `class`. En un `class` hay que tener en cuenta que no se pueden acceder a datos privados de la clase, aunque estemos en un puntero.

### 2.3.2: Operador `->`

* Si p es un puntero a un `struct` o `class`, podemos acceder a sus datos miembros de dos formas:
    * (*p).miembro
    * p->miembro

### 2.3.3: Datos miembros puntero

* Un objeto puede tener un dato miembro como puntero

~~~c++
struct Persona{
    string nombre;
    Persona * pareja;
}

Persona Pepe={"Pepe", 0};
Persona Maria={"Maria", 0};
Persona * puntero = & Pepe;

Pepe.pareja = &Maria;
Maria.pareja = &Pepe;

cout << "La pareja de " << puntero->nombre << " es " << puntero->pareja->nombre << endl;
~~~

## 2.4: Punteros y funciones

### 2.4.1: Simular el paso por referencia

Se puede usar el paso por referencia con el uso de punteros. Esto es lo que se hacía en la programación en `c`

~~~c++
void incrementa(int *num){
    (*num)++;
}

int main(){
    int var = 1;

    cout << var << endl; //1
    incrementa(&var) << endl;
    cout << var << endl;    //2

    //Otra posibilidad
    int *puntero = &var;
    incrementa(puntero);
    cout << var << endl;    //3
}
~~~

### 2.4.2: Paso de puntero por referencia

~~~c++
void incrementa(int * & p){
    (*p)++;
    p = 0;  //Anulamos el puntero tras usarlo
}
~~~

**Error típico**

Este programa debería volver un puntero. Sin embargo este puntero señala a una variable que se ha destruido tras terminar la función. Señana a una zona de memoria destruida, que puede ser reutilizada en el futuro por cualquier tipo de dato o, incluso, otro programa.

~~~c++
int *doble(int x){
    int a = x * 2;
    return &a;
}
~~~

## 2.5: Punteros a punteros

### 2.5.1: Uso

~~~c++
int a;
int *pEntero;
int **pPunteroEntero;

pEntero = &a;
pPunteroEntero = &pEntero;

//a equivale a (*pEntero) que equivale a (**pPunteroEntero)
~~~

## 2.6: Errores en el uso de punteros

* Asignar punteros a distintos tipos
* Mostrar la dirección de punteros a `char` como `cout << puntero << endl` y no como `cout << (void *) puntero << endl`. En el primer caso muestra los caracteres hasta encontrar un `\0`
* Usar

### 2.5.2: Consideraciones

* Hay que tener mucho cuidado con el uso de punteros constantes. Su dirección de memoria que se ha especificado en la declaración no puede modificarse (la dirección, no el contenido)
* Un puntero a dato no constante no puede apuntar a un dato constante, ni viceversa
