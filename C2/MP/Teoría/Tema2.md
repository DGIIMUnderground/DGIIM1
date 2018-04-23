
# **TEMA 2: Punteros y memoria dinámica**

**************

# Parte I: Tipo de Dato Puntero

---

## **Definición y Declaración de variables**

### _Definición de una variable tipo puntero_

> El tipo de dato puntero es un tipo de dato que contiene la dirección de memoria de otro dato.

* Incluye una dirección especial llamada _dirección nula_ que es el valor 0.

* En C esta dirección nula se suele representar por la constante `NULL` (definida en `stdlib.h` en C o en `cstdlib` en C++).


#### Sintaxis

> `<tipo> *<identificador>;`


* `<tipo>` es el tipo de dato cuya dirección de memoria contiene `<identificador>`.

* `<identificador>` es el nombre** de la variable puntero.  

### _Declaración de punteros_

~~~c++
// Se declara la variable de tipo entero
int i=5;
// Se declara la variable de tipo char
char c='a';
// Se declara puntero a entero
int * ptri;
// Se declara el puntero a char
char * ptrc;
~~~

Se dice que

* `ptri` es un _puntero a enteros_.

* `ptrc` es un _puntero a caracteres_.

**¡Nota!**: Cuando se declara un puntero se reserva memoria para albergar la dirección de memoria de un dato, no el dato en sí.  
**¡Nota!**: El tamaño de  memoria reservado para albergar un puntero es el mismo independientemente del tipo del dato al que 'apunte' (será el espacio necesario para albergar una dirección de memoria, 32 o 64 bits, dependiendo del tipo de procesador usado).

---

## **Operaciones con punteros**

### _Operador de dirección &_

`&<var` devuelve la dirección de la variable `<var>` (o sea, un puntero).
* El operador `&` se utiliza habitualmente para asignar valores a datos de tipo puntero.

~~~c++
int i = 5, *ptri;
ptri = &i;
~~~

* i es una variable de tipo entero, por lo que la expresión `&i` es la dirección de memoria dónde comienza un entero y,por tanto, puede ser asignada al puntero `ptri`.

Se dice que `ptri` _apunta_ o _referencia_ a i.

### _Operador de indirección `*`_

`*<puntero>` devuelve el valor del objeto apuntado por `<puntero>`.

~~~c++
char c, *ptrc;
..........
// Hacemos que el puntero apunte a c
ptrc = &c;
// Cambiamos contenido de c mediante ptrc
*ptrc = 'A'; // equivale a c 0 'A'
~~~
`ptrc` es un puntero a carácter que contiene la dirección de c, por tanto `*ptrc` es el objeto apuntado por el puntero, es decir, c.

### _Asignación e inicialización de punteros_

#### Inicialización de un puntero

 Un puntero se puede inicializar con la dirección de una variable.

~~~c++
int a;
int *ptri = &a;
~~~

#### Asignación de punteros

A un puntero se le puede asignar una dirección de memoria de otra variable. La única dirección de memoria que se puede asignar directamente (valor literal) a un puntero es la dirección nula.

~~~c++
int *ptri = 0;
~~~

* La asignación solo está permitida entre punteros de igual tipo.

~~~c++
int a = 7;
int *p1=&a;
char *p2=&a; // ERROR
int *p3=p1;
~~~

* Un puntero debe estar correctamente inicializado antes de usarse.

~~~c++
int a=7;
int *p1=&a, *p2;
*p1 = 20;
*p2 = 30; // Error
~~~

* Es conveniente inicialiar los punteros en la declaración, con el puntero nulo: 0

~~~c++
int *p2=0;
~~~

### _Operadores relacionales_

Los operadores relacionales <, >, <=, >=, !=, == son aplicables a punteros.  
El valor del puntero (la dirección que almacena) se comporta como un número entero.

#### Operadores `!=` y `==`

* `p1==p2`: comprueba si ambos punteros apuntan a la misma dirección de memoria (ambas variables guardan como valor la misma dirección).

* `*p1 == *p2`: comprueba si coincide lo almacenado en las direcciones apuntadas por ambos punteros.

Ej:

~~~c++
int *p1, *p2, n1 = 5, n2 = 10;
p1 = &n1;
p2 = p1;
if (p1 ==p2)
  cout << "Punteros iguales \n";
else
  cout << "Punteros diferentes\n";

if (*p1 == *p2)
  cout << "Valores iguales\n";
else
  cout << "Valores diferentes\n";
~~~

#### Operadores `<`,`>`,`<=`,`>=`

Permiten conocer la posición relativa de un objeto respecto a otro en la memoria.

* Solo son útiles si los dos punteros apuntan a objetos cuyas posiciones relativas guardan relación (por ejemplo, elementos del mismo array).

#### Operadores aritméticos +,-,++,--,+= y -=

Al sumar o restar un número N al valor del puntero éste incrementa o decrementa un determinado número de posiciones, en función del tipo de dato apuntado, según la fórmula:

> `N*sizeof(tipobase)`

* Esto proporciona una forma rápida de **acceso a los elementos de un array**, aprovechando que todos sus elementos se almacenan en posiciones sucesivas.

* Al usar estos operadores, el valor del puntero (la dirección que almacena) se comporta **CASI como un número entero**.

---

## **Punteros y arrays**

Los punteros y los arrays están estrechamente vinculados. Al declarar un array `<tipo> <identif>[<n_eleme>];`

1. Se reserva memoria para almacenar `<n_elem>` elementos de tipo `<tipo>`.

2. Se crea un puntero CONSTANTE llamado `<identif>` que apunta a la primera posición de la memoria reservada.

Por tanto, el `identificador` de un array, es un puntero CONSTANTE a la dirección de memoria que contiene el primer elemento. Es decir, `v` es igual a `&(v[0])`.

Podemos usar arrays como punteros al primer elemento.

~~~c++
int v[5] = {2, 6, 3, 5, 3};
cout << *v << endl;
cout << *(v+2) << endl;
~~~

* `*v` es equivalente a `v[0]` y a `*(&v[0])`.

* `*(v+2)` es equivalente a `v[2]` y a `*(&v[2])`.

Podemos usar un puntero a un elemento de un array como un array que comienza en ese elemento.

* De esta forma, los punteros pueden poner subíndices y utilizarse como si fuesen arrays: `v[i]` es equivalente a `ptr[i]`.


**Ejemplos**

~~~c++
// EJEMPLO 1
int v[3]={1,2,3};
int *p;
p = v; // v como int*
cout << *p; // Escribe 1
cout << p[1]; // Escribe 2
v = p; // ERROR

// EJEMPLO 2
void CambiaSigno (double *v, int n){
  for (int i=0; i<n; i++)
    v[i]=-v[i];
}
int main(){
  double m[5]={1,2,3,4,5};
  CambiaSigno (m,5);
}

// EJEMPLO 3: Recorrer e imprimir los elementos de un array:
int v[10] = {3,5,2,7,6,7,5,1,2,5};
for (int i=0; i<10; i++)
  cout << v[i] << endl;

// EJEMPLO 4: Recorrer e imprimir los elementos de un array:
int v[10] = {3,5,2,7,6,7,5,1,2,5};
int *p=v;
for (int i=0; i<10; i++)
  cout << *(p++) << endl;

// EJEMPLO 5: Recorrer e imprimir los elementos de un array:
int v[10] = {3,5,2,7,6,7,5,1,2,5};

for (int *p=v; p<v+10; ++p)
  cout << *p << endl;
~~~

---

## **Punteros y cadenas**  

Una cadena de caracteres estilo C es un array de tipo `char` de un tamaño determinado acabado en un carácter especial, el carácter `'\0'` (carácter nulo), que marca el fin de la cadena.  
También vimos que un literal de cadena de caracteres es un array constante de `char` con un tamaño igual a su longitud más uno.  
**Realmente**, C++ considera que un literal de cadena de caracteres es de tipo `const char *`  

_Ejemplos de uso_  

~~~c++
// Calcular longitud de cadena
const char *cadena="Hola"; // Se reservan 5
const char *p;
int i=0;
for(p=cadena;*p!='\0';++p)
  ++i;
cout << "Longitud: " << i << endl;

// Eliminar los primeros caracteres de la cadena
const char *cadena="Hola Adios";
cout << "Original: " << cadena << endl
     << "Sin la primera palabra: " << cadena+5;
~~~

### _Inicialización de cadenas_

#### Notación de corchetes
* Se copia el contenido literal del array.
* Es posible modificar caracteres de la cadena.

~~~c++
char cad1[]="Hola"; // Copia literal "Hola" en cad1
cad1[2] = 'b'; // cad1 contiene ahora "Hoba"
~~~

#### Notación de punteros
* Copia la dirección de memoria de la constante literal en el puntero.
* No es posible modificar caracteres de la cadena.

~~~c++
const char *cad2="Hola"; // Se asignan los punteros
cad2[2]= 'b'; // Error de compilación
~~~

---

## **Punteros, struct y class**
Un puntero también puede apuntar a un **objeto de estructura** o clase.  
La asignación entre punteros funciona igual cuando apuntan a un **objeto struct** o **class** que cuando apuntan a datos de tipo primitivo.  

**Operador -> **  
Si `p` es un puntero a un objeto `struct` o `class` podemos acceder a sus datos miembro de dos formas:

* `(*p).miembro`: Cuidado con el paréntesis

* `p->miembro`  

Un `struct` o `class` puede contener campos de tipo puntero.

---

## **Punteros y funciones**
Un puntero puede ser un argumento de una función. Puede usarse por ejemplo para simular el paso por referencia.  
Si deseamos modificar el puntero original, podemos usar paso por referencia.  
La devolución de punteros a datos locales a una función es un **error típico**. Los datos locales se destruyen al terminar la función.

---

## **Punteros a punteros**
Un puntero a puntero es un puntero que contiene la dirección de memoria de otro puntero.

~~~c++
int a = 5;
int *p;
int **q;

p= &a;

q= &p;
~~~

En este caso, para acceder al valor de la variable `a` tenemos tres opciones: a, *p y **q.

---

## **Punteros y const**
Cuando tratamos con punteros manejamos dos datos:

*  El dato puntero.

* El dato que es apuntado.  

Pueden ocurrir las siguientes situaciones:

* Ninguno sea `const` (`double *p;`).

* Solo el dato apuntado sea `const` (`const double *p;`).

* Solo el puntero sea `const` (`double *const p;`).

* Los dos sean `const` (`const double *const p;`).  

Las siguientes expresiones son equivalentes:

* `const double *p;`

* `double const *p;`

Es posible asignar un puntero no const a uno const, pero no al revés (en la asignación se hace una conversión implícita).

~~~c++
double a = 1.0;
double * const p=&a; //puntero constante a double
double * q; //puntero no constante a double
q = p //BIEN: q puede apuntar a cualquier datos
p = q //MAL: p es constante
~~~  

Un puntero a dato no const no puede apuntar a un dato const. De permitirse la operación se permitiría cambiar el valor del dato al que apunta, que fue declarado como constante.

Podemos llamar a una función que espera un puntero a dato const con no a dato no const.

~~~c++
void HacerCero(int *p){
  *p = 0;
}
void EscribirEntero(const int *p){
  cout << *p;
}
int main(){
  const int a = 1;
  int b=2;
  HacerCero(&a); //Error
  EscribirEntero(&a); //CORRECTO
  EscribirEntero(&b); // CORRECTO
}
~~~

Dada la estrecha relación entre araays y punteros, podemos usar un array de constantes como un puntero a constantes, y al contrario:

~~~c++
const int matConst[5]={1,2,3,4,5};
int mat[3]={3,5,7};
const int *pconst;
int *p;
pconst = matConst; // CORRECTO
pconst = mat; //CORRECTO
p = mat; // CORRECTO
p = matConst; // ERROR
~~~

---

## **Arrays de punteros**
Un array de punteros es un array donde cada elemento es un puntero.  
**Declaración**  
Podemos declarar un array de punteros a enteros de la siguiente forma:
> `int* arrayPunts[4];`  

Podemos usar un array de punteros a los elementos de otro array para ordenar sus elementos sin modificar el array original.

---

## **Punteros a funciones**
Contiene la dirección de memoria de una función, osea la dirección donde comienza el código que realiza la tarea de la función apuntada. Con estos punteros podemos hacer las siguientes operaciones:

* Usarlos como parámetro a una función.

* Ser devueltos por una función con `return`.

* Crear arrays de punteros a funciones.

* Asignarlos a otras variables puntero a función.

* Usarlos para llamar a la función apuntada.

### _Declaración de variables o parámetro puntero a función_
Puntero a función que devuelve `bool` y que tiene dos parámetros de tipo `int`:


> ~~~c++
> bool ( *comparar )(int, int);
> ~~~

Los paréntesis alrededor de `*comparar` son obligatorios para indicar que es un puntero a función.  
Si no incluimos los paréntesis, estaríamos declarando una función que recibe dos enteros y devuelve un puntero a un valor `bool`.

#### Llamada a la función apuntada por un puntero a función
Usaremos la sintaxis:

> `(*comparar)( valorEntero1, valorEntero2 );`

Son obligatorios los paréntesis alrededor de `*comparar`.  
Otra alternativa es: `comparar( valorEntero1, valorEntero2);`   
Pero es recomendable la primera forma, ya que indica explícitamente que `comparar` es un puntero a función. En el segundo caso, parece que `comparar` es el nombre de alguna función del programa.

---

## **Errores comunes con punteros**

* Asignar puntero de distinto tipo

~~~c++
int a=10, *ptri;
double b=5.0, *ptrf;

ptri = &a;
ptrf = &b;
ptrf = ptri; // Error de compilación
~~~

* Uso de punteros no inicializados

~~~c++
char y=5, *nptr;
*nptr=5; // ERROR
~~~

* Asignación de valores al puntero y no a la variable.

~~~c++
char y=5, *nptr =&y;
nptr = 9; //Error de compilación
~~~







--------

# Parte II: Gestión Dinámica de memoria

---

## **Gestión dinámica de la memoria**
**Recordar**

1. Reservar memoria.

2. Utilizar memoria reservada.

3. Liberar memoria reservada.  

---

## **Objetos dinámicos simples**
### _Operador `new`_
Reserva una zona de memoria en el Heap del tamaño adecuado para almacenar un dato del tipo _tipo_ (`sizeof(tipo)` bytes), devolviendo la dirección de memoria donde empieza la zona reservada.

> `<tipo> *p;`  
>`p = new <tipo>`

* Si `new` no puede reservar espacio (p.e. no hay suficiente memoria disponible), se provoca una excepción y el programa termina.

* Supondremos siempre que habrá suficiente memoria.

> **no recomendable**  
>`<tipo> *p;`  
>`p = new (nothrow) <tipo>`  


En caso de que no se haya podido hacer la reserva devuelve el puntero nulo (0).

Ejemplo:

~~~c++
int main(){
  int *p;

  p = new int;
  *p = 10;
}
~~~

* `p` se declara como un puntero más.

* Se pide memoria en el Heap para guardar un dato `int`. Si hay espacio para satisfaces la petición, `p` apuntará al principio de la zona reservada por `new`.

* Se trabaja con el objeto referenciado por `p`.

### _Operador `delete`_
Libera la memoria del Heap que previamente se había reservado y que se encuentra referenciada por un puntero.

> `delete  puntero;`

Ejemplo:

~~~c++
int main(){
  int *p, q=10;

  p = new int;
  *p = q;
  .......
  delete p;
}
~~~

* El objeto referenciado por `p` deja de ser "operativo" y la memoria que ocupaba está disponible para nuevas peticiones con `new`.

---

## **Objetos dinámicos compuestos**
Con objetos `struct` y `class` la metodología a seguir es la misma:

* Operador `new`:

  * **Reserva la memoria** necesaria para almacenar todos y cada uno de los datos del objeto.

  * Y llama al **constructor** de la clase para incializar los datos del objeto.

* Operador `delete`:

  * Llama al **destructor** de la clase. (tema 4)

  * Y después **libera la memoria** de todos y cada uno de los campos del objeto.

---

## **Arrays dinámicos**
**Motivación**

* Hasta ahora, solo podíamos crear un array conociendo a _priori_ el número máximo de elementos que podría llegar a tener. Ej: `int vector [20];`

* Esa memoria está ocupada durante la ejecución del módulo en el que se realiza la declaración.

Usando memoria dinámica, podemos crear arrays dinámicos que tengan **justo el tamaño necesario**.  
Podemos, además, crearlos **justo en el momento** en el que lo necesitamos y destruirlos cuando dejen de ser útiles.

### _Arrays dinámicos de datos de tipo primitivo_
#### Operador `new[]`
Reserva una zona de memoria en el Heap para almacenar `num` datos de tipo `<tipo>`, devolviendo la dirección de memoria inicial.  
`num` es un entero estrictamente mayor que 0.

> `<tipo> *p;`  
> `p = new <tipo> [num];`

#### Operador `delete[]`
Libera la zona de memoria **previamente reservada** por una orden `new[]`, zona referenciada por `puntero`.

> `delete [] puntero`

**¡Cuidado!**  
Un error muy común a la hora de construir una función que copie un array es el siguiente:

~~~c++
int *copia_vector(const int v[], int n){
  int copia[100];
  for (int i=0; i<n; i++)
    copia[i]=v[i];
  return copia
}
~~~

Al ser `copia` una variable local no puede ser usada fuera del ámbito de la función en la que está definida.

### _Arays dinámicos de objetos_
Usando el operador `new[]` y `delete[]` podemos crear y destruir también arrays dinámicos de objetos `struct` y `class`

* Operador `new[]`:

  * **Reserva la memoria** necesaria para almacenar todos y cada uno de los objetos del array.

  * Y llama al **constructor** para cada objeto del array.

* Operador `delete[]`:

  * Llama al **destructor** de la clase con cada objeto del array.

  * Y después **libera la memoria** ocupada por el array de objetos.

---

## **Clases que contienen datos en memoria dinámica**
Una clase puede contener datos miembro puntero que pueden usarse para alojar datos en memoria dinámica. Para ello:

* Los **constructores** pueden reservar la memoria dinámica al crear los objetos.

* Otros métodos podrían aumentar o disminuir el tamaño de la memoria dinámica necesaria.

* El **destructor** liberará automáticamente la memoria dinámica que contenga el objeto. (tema 4, por ahora usaremos el método `liberar()`).

---

## **Matrices dinámicas**
### _Matriz 2D usando un array 1D_

* **Creación de la matriz**:

~~~c++
int *m;
int nfil, ncol;
m = new int[nfil*ncol];
~~~

* **Acceso al elemento `f,c`**:

~~~c++
int a;
a = m[f*ncol+c];
~~~

* **Liberación de la matriz**:

~~~c++
delete[] m;
~~~

### _Matriz 2D usando un array 1D de punteros a arrays 1D_

* **Creación de la matriz**:

~~~c++
int **m;
int nfil, ncol;
m = new int*[nfil];
for (int i=0; i<nfil; ++i)
  m[i] = new int[ncol];
~~~

* **Acceso al elemento `f,c`**:

~~~c++
int a;
a = m[f][c];
~~~

* **Liberación de la matriz**:

~~~c++
for (int i=0; i<nfil; ++i)
  delete[] m[i];
delete[] m;
~~~

### _Matriz 2D usando un array 1D de punteros a un único array_

* **Creación de la matriz**:

~~~c++
int **m;
int nfil, ncol;
m = new int*[nfil];
m[0] = new int[nfil*ncol];
for (int i=; i<nfil; ++i)
  m[i] = m[i-1]+ncol;
~~~

* **Acceso al elemento `f,c`**:

~~~c++
int a;
a = m[f][c];
~~~

* **Liberación de la matriz**:

~~~c++
delete[] m[0];
delete[] m;
~~~

---

## **Lista de celdas enlazadas**
Es una **estructura de datos lineal** que nos permite guardar un conjunto de elementos del mismo tipo usando celdas enlazadas.

* Cada celda se alojará en el Heap.

* Usaremos punteros para enlazar una celda con la siguiente.

~~~c++
struct Celda{
  double dato;
  Celda* sig;
}

~~~



## **notas**  

Los punteros se pueden restar pero no se pueden sumar

* Cuando haces un cout << puntero de char muestra la cadena si es de otro tipo muestra la dirección de memoria.
Para mostrar la dirección de memoria de un puntero char habría que escribir **cout << (void*)** puntero

~~~c++
char *puntero;
char cadena [10] ; // equivalente a char * const cadena;
cout << (void*)puntero;
cout << cadena;
~~~

**variables static:**  
(en una función)  
la inicialización de la variable en la función solo se realiza una vez (por ejemplo, para saber cuantas veces se pasa por la función)  
(en una clase)  
variable que pueden usar todos los objetos de la clase(si no fuese static cada objeto de la clase tendría una copia de esa variable)  
Hay que liberar la memoria OBLIGATORIO `delete`, el sistema operativo pone esa zona de memoria como libre después de `delete` no se puede usar dicho puntero,   
