
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

Una cadena de caracteres es un array constante de char con tamaño su longitud más uno. Es considerado un _const char *_. Por ejemplo calculando la longitud de una cadena:
```cpp
const char *cadena = "Hola"; //tamaño 5
const char *p; //p puntero a caracter constante, p es modificable
int i = 0;
for (p=cadena;*p!='\0';p++)
++i;
cout << "Longitud: " << i << endl;
```
```cpp
const char *cadena = "Hola Adiós";
cout << "Original: " << cadena << endl;
<< "Sin la primera palabra: " << cadena+5;
//Escribe Hola Adios y luego Adios, normalmente escribiría la dirección de memoria a la que apunta, pero muestra por pantalla el contenido ya que está apuntando a una cadena de char (esto pasa siempre, es una excepción). Si pusiéramos *cadena sólo mostraría la primera h, ya que apunta a la primera letra. Si quisiéramos que mostrara la dirección de memoria pondríamo (char *) cadena
```
Si lo delcaramos con corchetes se puede cambiar un carácter, si se declara como puntero no se pueden modificar caracteres ya que está apuntando a caracteres constantes.

### Punteros y struct o class

También pueden apuntar a structs o class.
Un puntero apunta al primer dato del struct o clase de ese clase y se accede a sus datos como _(\*puntero).dato_ y a métodos como _(\*puntero).método()_.

Podemos usar el operador -> para acceder a datos miembros _(\*p).miembro_ o _p->miembro_.
Una clase puede tener punteros como miembros, pueden apuntar a otro dato de la misma clase que estamos definiendo, por ejemplo en el caso de una clase persona, un puntero que apunta a su pareja. Pueden dereferenciarse varios punteros (si un puntero apunta a otro puntero es válido usar esto:)
```cpp
ptr->pareja->nombre //El puntero accede a otro puntero que accede al nombre.
```
###Punteros y funciones

Un puntero puede ser un parámetro de funciones, es similar al paso po referencia.
También podemos modificar un puntero pasando por referencia el puntero
```cpp
void funcion (int *p) //Pasa puntero como argumento.
void funcion (int* & p) //Pasa puntero como argumento POR REFERENCIA
int* doble(int x) //Devuelve un puntero.
```
No se pueden devolver punteros a una variable local a la función, ya que la variable se dedstruye al acabar la función.
```cpp
int* ptr, ptr2 //ptr es puntero, ptr2 es entero.
int *ptr, ptr2; //lo mismo
int *ptr, *ptr2 //Ambos punteros
```
### Punteros a Punteros

```cpp
int a = 5;
int *p; //Puntero a entero.
int **q; //Puntero a puntero a entero.
p = &a;
q = &p;
//Para acceder al valor de a sirve a, *p, **q
```
### Punteros y const
Tenemos el dato al que apunta el puntero y el puntero, para definir constantes:
```cpp
double *p //Ninguno constante
const double *p //El dato apuntado es constante
double const *p //El dato apuntado es constante
double *const p=<valor> //El puntero es constante
const double *const p //Ambos son constantes
dpuble const *const p //Ambos son constantes
```
Un puntero a dato no constante no puede apuntar a un dato constante (permitiría cambiar el valor de una constante mediante el puntero).

Podemos llamar a una función que espera un puntero a dato constante con un puntero a dato no constante.

### Arrays de punteros
Es un array con sus elementos punteros.
```cpp
int* arrayPunts[4];
int a=5, b=7, c=3, d=2;
arrayPunts[0]=&a;
arrayPunts[1]=&b;
arrayPunts[2]=&c;
arrayPunts[3]=&d;
for (int i = 0; i<4; i++){
	cout << *arrayPunts[i] << " ";
}
cout << endl;
``` 
Por ejemplo, para ordenar un array sin modificafr el array se crea un array de punteros con tantos punteros como el array a ordenar, donde cada puntero apunta al valor de su misma posición y se ordenan los punteros en lugar de los valores.
Podemos tener un array de punteros a cadenas esstilo C.
```cpp
const char*  constpalosBaraja[4]={"Oros","Copas", "Espadas", "Bastos"};
cput << "Palos de la Baraja: ";
for (int i = 0; i<4; i++)
	cout << oalosBaraja[i] << " ";
cout << endl;
```
Ahora declararemos el main como:
```cpp
int main ( char* argv[], int argc)
```
Esto sirve para que al ejecutar un programa pasándole ficheros por la terminal, el nombre de estos ficheros se guarde en el array que recibe como parámetro main.
_argv_ es un array de cadenas de C.
_argv[0]_ es el nombre del ejecutable, _argv[1]_ escribe el primer fichero que recibe y así sucesivamente.
_argc_ almacena el tamaño del array.

Para leer datos de un fichero se usa una variable de tipo ifstream 
```cpp
int entero;
ifstream flujo;
flujo.open(argv[1]);
flujo >> entero;
```
### Punteros a funciones
Es un puntero que contiene la dirección de memoria de una función. Estos punteros se pueden pasar como parámetro a otra función o ser devuelto o hacer un array de punteros a funciones, asignarlos a otras variables o se usan para ejecutar la función a la que apuntan.
Al darle un valor, se le da como valor el nombre de una función.
```cpp
bool ( *comparar )( int, int)
//comparar es un puntero que puede apuntar a cualquier función que reciba como parametros dos enteros y devuelva un booleano.
//Si no se usan los paréntesis en *comparar estaríamos declarando una función que devuelve un puntero a bool y recibe dos enteros.
(*comparar)(valor1,valor2); //Accede a la función
```
Son útiles para, por ejemplo, con una sola función hacer una función que ordene un array de mayor a menor o de menor a mayor.

### Errores comunes con punteros
- Asignar punteros a distinto tipo (puntero entero que intenta apuntar a puntero a carácter).
- Usar de punteros no inicializados.
- Asignar valores al puntero y no a la variable.

## Gestión de memoria dinámica
### Estructura de la memoria
Un SO divide la memoria en varias partes:

- Segmento de código: Donde está el código del programa.
- Memoria estática: Memoria reservada antes de ejecutar un programa (es fija) donde se guardan las variables globales y las _static_ (Locales a una función: solo se le asigna el valor inicializador una vez (la primera que se entra; A una clase en _public_: es como una variable global de la clase, es la misma para todos los objetos).
- Pila: Aquí se guardan las variables locales de las funciones. por cada función se reserva un _entorno de programa_.
- El _heap_: Se reservan y liberan trozos según las necesidades, esta es la única zona que maneja el programador. Sirve para crear nuevas variables o variables con tamaño indeterminado.

### Gestión dinámica de la memoria
- Se pide al SO un trozo de la memoria (tamaño) .
- El SO comprueba si hay suficiente espacio libre en el _heap_.
- Si hay espacio suficiente, el SO devuelve la posición de memoria donde se ha reservado y marca la zona como ocupada.
- La ubicación de la memoria se almacena en una variable estática o local puntero.
```cpp
int *p2;
p2 = new int[200]; //Almacena la direccion de memoria
```
- La zona de memoria reservada puede allmacenar nuevas variables dinámicas que pueden almacenar la dirección de nuevas peticiones de reserva de memoria.
- Se libera la memoria dinámica que ya no necesitamos.

### Operador _new_
Reserva en el _heap_ memomria suficiente del tipo especificado.
```cpp
<tipo> *p;
p = new <tipo>;
```
Si no hay espacio suficiente para reservar esa memoria se provocaría una excepción y el programa termina.
```cpp
int *p;
p = new int;
*p = 10;
//Se reserva memoria para un entero.
```

### Operador _delete_
Sirve para liberar la memoria que ya no es necesaria.
```cpp
delete puntero
```
```cpp
int *p, q = 10;
p = new int;
*p = q;
//Aquí más código.
delete p;
```

### Objetos dinámicos compuestos
Se reservan _structs_ y _class_ de forma igual a datos simples.

- _new_ reserva la memoria y llama al constructor de la clase para inicializar los objetos.
- _delete_ llama al destructor de la clase y después libera la memoria de cada campo del objeto.
```cpp
class Estudiante {
string nombre;
int nAsignaturasMatricula;
vector<int> codigosAsignaturasMatricula;
public:
Estudiante();
Estudiante(string name);
void setNombre(string nuevoNombre);
string getNombre() const;
void insertaAsignatura(int codigo);
int getNumeroAsignaturas() const;
int getCodigoAsignatura(int index) const;
//Más métodos aquí
};

int main() {
Estudiante* ramon;
ramon=new Estudiante("Ramón Rodríguez Ramírez"); //Llama al constructor necesario de acuerdo a los parámetros que se le den.
ramon->insertaAsignatura(302);
ramon->insertaAsignatura(307);
ramon->insertaAsignatura(205);
//Más código aquí
delete ramon;
}

```
### Arrays dinámicos
Usando arrays dinámicos podemos crear arrays justo del tamaño necesario y justo en el momento necesario y destruirlos después.
Para ello usaremos [] en los operadores usuales.
```cpp
<tipo> *p;
p = new <tipo> [numeroareservar]; //num debe ser mayor que 0
delete[] p;
```
```cpp
//Programa donde se crea array dinámico (con un puntero que se trata como array)
int *v = 0, n;
cout << "Número de casillas: ";
cin >> n;
v = new int [n];

for (int i = 0;  i < n;  i++) {
	cout << "Valor en casilla " << i <<  ": ";
	cin >> v[i];
}
cout << endl;

for (int i = 0; i < n; i++)
	cout << "En la casilla " << i << " guardo: "<< v[i] << endl;

delete [] v;
v = 0;
```
```cpp
//Función para redimensionar un array dinámico.
void redimensionar (int *&v, int& tama, int aumento){
	if (tama+aumento > 0){
		int *v_ampliado = new int[tama+aumento];
		for (int i = 0; (i < tama) && (i < tama+aumento); i++)
			v_ampliado[i] = v[i];
		delete[] v;
		v = v_ampliado;
		tama = tama+aumento;
	}
}
```

### Arrays dinámicos de objetos
Funciona igual que con un tipo de dato nativo, salvo que se usa el constructor por defecto obligatoriamente al inicializar los datos de la memoria reservada.





_By Mapachana_
