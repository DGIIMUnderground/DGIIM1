
# Tema 2: Punteros

## Tipo de dato Puntero

### Definición
La memoria dinámica permite crear variables del tamaño necesario en tiempo de ejecución, para esto usaremos los punteros.
Un **puntero** es un tipo de dato que contiene la dirección de memoria de otro dato.
Si el puntero tiene una dirección nula (  0 ) , el puntero no apunta a ningún dato concreto. En C se podía usar tanto 0 como NULL (no lo vamos a usar) o nullptr que es nuevo de C++11.
Para declararlo:
```cpp
<tipoalquepuedeapuntar> *<identificador>
```
Un puntero guarda la dirección de memoria donde empieza la dirección de la variable a la que apunta o referencia.
Se declara la variable y luego el puntero.
Todos los punteros ocupan el mismo espacio. La memoria se reserva para el puntero (32 o 64 bits), no para el dato al que apuntan en sí.

### Operaciones
- &: Hace un AND (multiplicar) bit a bit. Sirve para esconder mensajes en imágenes, por ejemplo. Devuelve la dirección de la variable (un puntero). No sirve para expresiones, debe ser una única variable.
```cpp
&<var> 
```
```cpp
int i = 5, *ptri;
ptri = &i;
```
- *: Devuelve el dato al que apunta un puntero.
```cpp
*<puntero>
```
```cpp
char c, *ptrc;
ptrc = &c;
*ptrc = 'A';
//Hace a c valer A.
```
- Inicialización: Conviene inicializar los punteros con el puntero nulo 0.
```cpp
int a;
int *ptri = &a;
```
```cpp
int *ptri = 0;
//Le asignamos la dirección nula (único valor literal que puedo asignarle directamente.
```

- Asignación entre punteros: Sólo puede ser entre punteros del mismo tipo.
```cpp
int a = 7;
int *p1 = &a;
char *p2 = &a; //Esto no se puede hacer, a es entero y p2 apunta a un char a menos que usemos *p2 = reinterpret_cast<char*>(&a)
int *p3 = *p2; // Esto sí es válido ya que son del mismo tipo
```
- Relacionales: <,>,<=,>=,!=,==: Compara números enteros.
	- p1 == p2 : Comprueba si ambos punteros apuntan al mismo dato.
	- \*p1 == \*p2 : Comprueba si el contenido al que apunta p1 es el mismo que al que apunta p2.
	- <,>,<=,>= Permite conocer la posición relativa de un dato respecto a otro en la memoria. Esto es útil cuando los punteros están apuntando a datos del mismo array.
- Aritméticos: +,-,++,-\-,,+=,-= : Tiene sentido cuando estamos a puntando a datos del array. Al sumarle 1, apunta a la siguiente dirección de memoria del array.
```cpp
int v[5] = {2,6,3,5,3};
int *p;
p = &v[2];
cout << p[1]; //Escribe 5, ya que p apunta a 3, el siguiente es 5.
p+=2; //Ahora p apunta dos posiciones más adelante, es decir, al último 3.
p = &v[2];
q = &v[4];
q-p //Devuelve 2. Los punteros se pueden restar pero no pueden sumar punteros.
```

### Punteros y arrays

Al declarar un array, realmente se crea un puntero constante (siempre apunta a la misma dirección de memoria) que apunta a la primera posición de ese array. Si un array se llama v, entonces v es equivalente a &(v[0]). v[0] equivale a *(&v[0]).
Podemos usar arrays con la sintaxis de punteros.
```cpp
int v[5] = [2,6,3,5,3};
cout << *v << endl; //escribe 2
cput << *(v+2) << endl; //escribe 3
```
También podemos usar punteros como arrays.
```cpp
int v[5] = [2,6,3,5,3};
int *p;
p = &(v[1]);
cout << *p << endl; //Escribe 6
p = v+2,
cout << *p << endl; //Escribe 3
p++;
cout << *p << endl; //Escribe 5
p = &(v[3])-2;
cout << p[0] << p[2] << endl; //Escribe 6 5
```

Por ejemplo, para recorrer los elementos de un array mediante punteros:
```cpp
int v[10] = {3,5,2,7,6,7,5,1,2,5};
int *p=v;
for (int i=0; i<10; i++)
cout << *(p++) << endl;
```
O bien:
```cpp
int v[10] = {3,5,2,7,6,7,5,1,2,5};
for (int *p=v; p<v+10; p++)
cout << *p << endl;
```
### Punteros y cadenas



_By Mapachana_
