<!--
Autor:
    Sergio Quijano Rey
    sergiquijano@gmail.com
Descripción:
    Resumen del tema de punteros, algo más claro que en las diapositivas
-->
# **Esquema sobre el uso de punteros y memoria dinamica**

Escrito por:

*   Sergio Quijano Rey
*   sergiquijano@gmail.com

a partir de los apuntes de **DECSAI**

## 1: Uso de punteros con datos simples

### 1.1: Operadores básicos

**Declaración de un puntero:**

~~~c++
<tipo> * <id>;
~~~

**Operador \***:

~~~c++
*<puntero>
~~~

Devuelve el contenido del puntero. También permite modificar el contenido, y con ello, permite usar el puntero como si de una variable se tratase

**Operador &:**

~~~c++
& <variable>
~~~

Devuelve la dirección de `<var>`, es decir, devuelve un puntero. Con ello podemos hacer que un puntero apunte a la variable que queramos. Es la única forma de hacer que un puntero apunte donde queramos, el único valor entero que podemos pasarle al puntero es el valor `0`, que indica que el puntero es nulo

### 1.2: Ejemplo de uso

~~~c++
int numero = 5;
int *puntero;   //Declaro el puntero

puntero = &numero;  //El puntero apunta a la variable numero
*puntero = 10;      //Cambio el contenido del puntero
puntero = 0;        //Anulo el puntero
~~~

## 2: Punteros y arrays

Los punteros y los arrays guardan una estrecha relación, como vamos a ver a continuación:

### 2.1: inicialización de un array

Al declarar un array del modo `<tipo> <identificador> [n_elementos]` lo que ocurre es lo siguiente:

* Se reserva memoria para los *n_elementos*
* Se crea un puntero **constante** llamado `<identificado>` que referencia a la primera posición de memoria del array

Es decir:

~~~c++
int lista[20];
lista == &(lista[0])
~~~

Esto lo podemos utilizar para jugar con punteros y arrays

### 2.2: Uso de punteros y arrays

~~~c++
int lista[20];

//Estas dos lineas equivalen
int *puntero = lista;
puntero = &(lista[0]);

//Estas dos lineas equivalen
puntero = &(lista[4]);
puntero = lista + 4;

//Estas dos lineas equivalen
cout << puntero[2];     //Imprime lista[4 + 2]
cout << *(puntero + 2); //Imprime lista[4 + 2]
~~~

### 2.3: Arrays de punteros

Son tremendamente útiles para ordenar grupos de datos. Se usa un array de punteros como si fuese el array del tipo de dato con el que se trabaja, y para ordenarlo, se cambia la dirección de memoria de los punteros. Así no hace falta cambiar el contenido del array, que supone crear una variable temporal, borrar el dato, copiar el dato... Esto con objetos grandes puede hacerse muy tedioso. Con un puntero solo hay que cambiar una variable de unos pocos bits

```c++
int a = 0;
int b = 1;
int c = 2;

int * lista[3];

lista[0] = & a;
lista[1] = & b;
lista[2] = & c;

```

## 3: Punteros y cadenas char C

* `char <id> [n_elementos] = {'a', ... , 'b', '\0'}` se considera en baja implementación como un puntero a `array char`.
* Un literal de cadena es un `const char`, `"hola" == const char [4 + 1] == const char *`

Con esto, hay que tener las siguientes consideraciones

* `char cad1[] = "hola mundo"`
    * Se puede modificar el contenido
    * No se puede modificar el tamaño
* `const char * cadena2 = "hola"`
    * No se puede modificar el contenido
    * Se puede modificar la dirección de memoria a la que hace referencia el puntero (es *const* el *char*, no el puntero)

## 4: Punteros en funciones

Podemos pasar como parámetros a una función punteros, por copia, por referencia constante y por referencia. A continuación se muestra un ejemplo ilustrativo

```c++
void dobla1(int *p){
    *p = *p * 2;
}

void dobla1(int * const & p){
    *p = *p * 2;
}

void dobla2(int * & p){
    *p = *p * 2;
    p = 0;  //Anulo el puntero, el paso es por referencia
}

int main(){
    int num = 5;
    int *p = & num;

    dobla1(&num);
    dobla1(p);
}
```

## 5: Punteros y `struct`/`class`

### 5.1: Ejemplo de uso con lo visto hasta ahora

```c++
struct Persona{
    int edad;
    string nombre;
}

int main(){
    Persona pepe = {18, "Jose andres"};
    Persona * puntero_persona;

    puntero_persona = & pepe;

    (*puntero_persona).edad = 19;
}
```

### 5.2: Operador `->`

En el ejemplo anterior, hemos visto que para acceder a los miembros o métodos con punteros tenemos que escribir `(*puntero).miembro`. Esto se puede hacer, partiendo del ejemplo anterior, tal que:

```c++
Persona pepe = {18, "Jose Andres"};
Persona puntero_persona = & pepe;

puntero_persona->edad = 20;
```

## 6: Punteros y constantes

| Puntero | Dato | Ejemplo |
| --- | --- | --- |
| variable | variable | `double *p;` |
| variable | const | `const double *p;` |
| const | variable | `double * const p;` |
| const | const | `const double * const p;` |

### 6.1: Consideraciones

* `const double *p == double const * p`, para que la direccioón del puntero sea constante, el `const` tiene que ir después del asterisco
* Puedo asignar un puntero dirección no const a uno dirección const, pero no al revés
* Un puntero a dato no const **nunca** puede apuntar a un dato const
* Podemos llamar a una función con parámetro puntero const con un puntero no const, al igual que con el paso por referencia usual
* Un array de constantes equivale a un puntero a datos constantes
