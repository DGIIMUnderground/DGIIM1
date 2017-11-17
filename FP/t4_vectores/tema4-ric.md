## Tema 4 vectores y matrices

Diferencia vectores/arrays:
    - Arrays estáticos (mismo tamaño) (Propios de C)
    - Vectores dinámicos (tamaño variable) (Propios de C++)

*Vector*: tipo dato estructurado homogéneo, compuesto por más de un
componente, cuyo tamaño puede variar durante la ejecución.

- Un vector es realmente una clase (métodos, constructor, etc..)
- Cuando se inicializa un vector
Es necesario incluir la biblioteca vector 

```c++
#include <vector
using std::vector // Usamos solo la clase vector del namespace std
vector<tipo_base> identificador; //
vector<tipo_base> identificador(tamanio)
vector<tipo_base> identificador(tamanio, valor_inicial`) // Todas las componentes igualadas a valor inicial


vector<int> u = {1, 2, 3, 5};  // Declarar e inicializar
vector<int> v(u);  // Constructor de copia (dentro de la clase)
vector<int> v = u; // Constructor primitivo vector<int> &v = u; ``` para
// Para acceder a los elementos de un vector

identificador[indice] 
```

`nombre_vector.at(índice)` Si el índice se sale de rango se sale de programa,
antes de entrar comprueba si está bien y suma un coste de tiempo, y el modo de
gestionar los errores no es el más correcto.

Funciones inline: en vez de hacer una llamada a función lo inserta en la línea,
es decir, remplaza el código. Por esto es mucho más eficiente.

El compilador es suficientemente inteligente sobre si la función debe ser
inline o no.

## Propiedades

nombre_vectori.size()		// para saber el tamaño de una

variable, núemero que puedo almacenar empty() 	      		// si es vacío tipo
booleano capacity() 	      		// la capacidad máxima que tiene un vector,
ya qeu el compilador te asigna más de lo que pides ejemplos: ``` vector<int>v ;
// size 0 ; capacity depende del compilador, por lo general 10 ////////////////
v.size()	 // decuelve 5 v.resize(10)	 // amplio su capacidad v.size() 	 //
devuelve 5, porque no se le han añadido valores nuevos v.capacity 	 //
devolvería 10 porque ya hemos ampliado su valor ```

### Manipular vectores vector.clear() 	      		//  libera todo el espacio
del vector, tamañado de memoria vector.resize( tamaño nuevo)	// nuevo tamño
del vector, amplia o reduce

### Gestión de espacio ``` max_size //máxima capacidad reserve // reserva tamño
push_back( valor_nuevo) //se añade el dato al final del vector, su tamaño se
ampliaría si ya estuviera lleno reservando una dirección de memoria y copiando
los otros y suele reservar más espacios de los qeu tiene; pop_back() // elimina
el ultimo elemento no reasigna el espacio a no ser que esté muy reducido insert
```

``` int suma ( const vector<int> & v , const vector <int> & u , vector<int>& z
) // ojo a la declaración const vector <int>& v: paso una referencia, solo pasa
la dirección de memoria y no copia el vectori entero, pero lo pongo como const
para que no se pueda modificar // en caso del vector z si nos interesa
modificarlos ``` ### Almacenamiento el compialdor busca un espacio para el que
coa el vector, un entero tiene 4 bytes,   la implementación subyacente a los
vectores es de tipo array, si no se le dice que creazco o no se utiliza igual

### Devolver en una función un vector 



```c++
int suma (const vector<int> & v , const vector <int> & u) {
    vector<int> z( v.size());
    for(int i ; i v.size(); i++)
        z[i] = v[i] + u[i]; return z;
}
```

c = suma( a , b ); // Ahora el dato l reserva y se lo pasa a c,  antes  conste
en el proceso, se copiaba, semántica de copia de datos, ahora ``` Ahora se
pueden tener dos valores con el mismos nombre, con la firma de la función, los
parámetros que la define, en el número que lo define ese error se llama
sobrecarga de identificadores

```c++
void producto_escalar(int escalar ; vector<int>& v) {

    vector<int> z(v);
    for( auto x : z ) // Iterador para recorrer una estructura, auto palabra
                      //reservada, definir tipo dato variable sin indicar el tipo de dato, x = x * escalar;
    return 0;

}
```

## Búsquedas en vectores

El concepto de vector en programación es mucho más general que el concepto físico o
matemático. No es necesario que sea un vector sobre un cuerpo escalar. Pueden haber
vectores sobre cualquier "objeto".


### Búsqueda secuencial

Recorrer las componentes del vector hasta que se cumpla la condición.

Eficiencia lineal O(n).
Porque el número de pasos depende de n (n-pasos).

>> Metaalgoritmo para resolver un problema
>> 1. Entender bien el problema.
>> 2. Analizar el problema: identificar entradas, salidas y sus relaciones.
>> 3. Diseñar el algoritmo
>> 4. Codificar el algoritmo
>> 5. Prueba y validación del algoritmo.

Entradas: valor a buscar, y vector donde buscar
Salidas: índice del vector (0...n-1)

Estudiar los casos:
    - El valor no está en el vector
        -> ¿Qué valor devolver? -1 ¿?
    - El valor a buscar está en el vector
    - El valor aparece varias vecer
        -> ¿Qué indice devolver?
    - El vector está vacío
        -> Recorrer un vector vacío
    - El vector tiene una única componente

### Búsqueda binaria

Si el vector es de elementos ordenados, podemos
empezar por la mitad del vector. Comparar los valores,
de manera que podemos:
    
    - c > x: Eliminamos la segunda mitad |- En estos casos
    - c < x: Eliminamos la primera mitad |- repetimos el proceso.

    - c == x: Encontrado

Cuando el tamaño del vector n es par, podemos
escoger la posición (n-1)/2 o n/2.

Este algoritmo tiene eficiencia O(log(n)), pero *requiere*
un vector ordenado. Y podremos comprobar posteriormente,
que para ordenar, la eficiencia será:

    O(n^2) + O(log(n)) lo cual es peor que O(n)

m=nª búsquedas

n^2 + mlog_2 n = mn

En que valor de n, se hace uno preferente a otro

Entender el problema de la ordenación de vectores.

Es necesario definir una relación de orden entre los
elementos de un vector. Es decir, eligimos un criterio
con el que compara elementos.

Ordenar un vector: redistribuir sus elementos de manera que una vez ordenado
existe una relación de orden entre los elementos del vector.

- Ordenación interna:
    - Toda la información está en memoria principal (en el ordenador)

    - Grupos de algoritmos de búsqueda:
        - O(n^2)
            - Bubblesort (Burbuja)
                - Comparamos los elementos dos a dos
                y se deja a la izquierda el más pequeño.
                (Intercambiándolos):
                - En la primera iteración queda el más pequeño
                a la izq. En la segunda iteración el siguiente, etc.

                Por ello, son n^2 operaciónes.

                Podemos tener dos algoritmos con la misma complejidad
                pero puede uno ser más rápido que otro (3n^2 < 5n^2)

                - Dos bucles anidados
                - Menos eficiente

            - Selección
                - Insertar en la primera posición el
                elemento más pequeño.
                - En promedio n operaciones, pero exactamente
                n intercambios.
    
                - En el caso de que el vector estuviera ordenado
                al revés, realizaría n cambios. (Es el más interesante)
                (En cambio el de burbuja haría n^2)

            - Inserción

                - Por cada elemento, busca donde debería de incluirlo.
                - Si el vector está ordenado es el más interesante.
    


        - O(nlog(n))
            - Mergesort
            - Heapsort
            - Quicksort:
                -> Es el mejor e implementado
                en las bibliotecas estándar.

    O(nlog(n)) es mucho más rápido EN GENERAL, pero dependerá
del tamaño de los elementos.

- Ordenación externa:
    Datos en memoria secundaria (otro dispositivo)
    Ej. una cinta: información de forma secuencial.


No está definidio un operador de comparación para los números racionales.
Pero podemos implementarlo. De manera que podríamos luego, ordenar

El tipo vector es buena implementación como contenedor genérico. En cambio para
operaciones matemáticas, podemos utilizar valarray (STL).

Para los vectores de datos lógicos:

vector<bool> vb(1000);

## Matrices

En su sentido más general (2, 3, nxn)

Existe una forma de definir matrices en C:

```c++
int v[30]; // Array de C
int m[30][5]; // Matriz de 30 filas y 5 columnas
```

Pero no hay tipo específico para C++. En cambio, usaremos vectores de vectores.

```c++
vector<vector<int> > m; // Matriz de enteros
```
                  |
            ¡Este espacio es muy importante
            para que ciertos compiladores no den
            problemas!

Los compiladores se confunden con `>>` (operador de extracción).
