<!--
Autor:
    Sergio Quijano Rey
    sergiquijano@gmail.com
Descripción:
    Apuntes tomados en clase del tema 3
-->

# **Tema 3: Memoria dinámica**

* Esta es la parte más importante de la asignatura
* Va a ser muy útil en la práctica

## 3.1: Memoria al ejecutar un programa

* **Segmento de código**: contiene las instrucciones a ejecutar del programa
* **Memoria dinámica**: se reserva un espacio fijo de memoria que no cambia. Contiene **constantes globales** y variables estáticas.
    * **Variables estáticas**: se usan sobre todo en funciones y en clases. En una función, se mantienen tras la finalización de una función. La inicialización en una función solo se hace una vez. Por ejemplo, podemos tener un contador de las veces que se ejecuta una función. En una clase, las variables constantes que son las mismas para todas las instancias, se usan como `static`. De este modo, solo se usa una constante para todas las instancias, y no una constante para cada instancia. Se suelen usar en la parte pública de la clase. Esto puede usarse también para llevar un contador del número de objetos que se han creado.
* **Pila o stack**: se guardan las variables locales. Gestiona las llamadas a funciones, lo que se conoce como **call stack**, es decir, guarda los parámetros de llamada a funciones. Es lo que se llama también el **entorno de programa**. De esto se encarga el `OS`.
* **Heap**: donde se reservan y liberan trozos según nuestras necesidades. La gestión de esta región de memoria corre a cargo del programador. Ahí colocamos variables nuevas en tiempo de ejecución, con el fin de optimizar el uso de memoria. Es lo que hacíamos con el `push_back` de la clase `vector`

El uso de memoria dinámica nos va a permitir usar arrays de los elementos que nosotros queramos. Por ejemplo, si nuestra constante de control del array es de 100, no podemos usar más de 100 elementos, de querer hacerlo, tendríamos que cambiar el programa y volver a crear el binario. O si la variable de control es 200, y solo usamos 20 posiciones de memoria, estaríamos desperdiciando mucha memoria.

## 3.2: Esquema del uso de memoria

* Petición al `OS` de la memoria. Se comprueba si hay espacion en el *heap*
* Si hay espacio suficiente, reserva esa memoria y el `OS` devuelve la zona de memoria que se ha reservado, que la guardaremos en un puntero
* El puntero donde guardamos esta zona de memoria se puede situar en cualquier zona del programa y en cualquier zona de memoria
* Es frecuente usar variables dinámicas creadas nuevas para almacenar la dirección de nuevas peticiones de memoria. Es lo que se denomina **listas enlazadas**:
~~~c++
strutc celda{
    int numero;
    celda * siguiente;
}
~~~

## 3.3: Metodología de la memoria dinámica

* Reservar memoria dinámica
* Usar memoria dinámica
* Liberar memoria dinámica

## 3.4: Objetos dinámicos simples

### 3.4.1: Operador `new`

~~~c++
<tipo> * puntero;
puntero = new <tipo>;
~~~

* Si `new` no puede encontrar memoria dinámica en el *heap*, se provoca una **excepción** y el programa acaba (el uso de excepciones se estudia en cursos superiores)
* El puntero utilizado se usa como un puntero al uso

**Ejemplo 1:**

~~~c++
int *p;
p = new int;
*p = 10;
~~~

### 3.4.2: Operador `delete`

* Libera la memoria reservada del *heap*
* El puntero no se elimina, apunta a la misma zona de memoria. Lo único que ocurre es que la zona de memoria ha sido liberada y ya no puede ser usada por el programa.

**Ejemplo de uso**:

~~~c++
int *p;
int num = 10;

p = new int;
*p = num;
delete p;
~~~

## 3.5: Objetos dinámicos compuesto

* Se usa la misma filosofía que con tipos de datos simples
* `New` llama al constructor de la clase automáticamente, se cual sea, igualmente con los `struct`.
* `Delete` llama al destructor de la clase, el `~Nombre_clase()`, tras esto libera la memoria usada. El destructor suele liberar la memoria dinámica que usa el propio objeto.

**Ejemplo de uso con struct:**

~~~c++
struct Persona{
    char nombre[100];
    char dni[10];
}

Persona *yo;

yo = new Persona;
(*yo).nombre = "Sergio Quijano Rey";
(*yo).dni = "72103503k";

cout << "Me llamo " << (*yo).nombre << " con dni " << (*yo).dni << endl;

Persona *tu;
tu = new Persona;

cin >> tu->nombre;
cin >> tu->dni;

delete yo;
delete tu;
~~~

**Ejemplo de uso con class:**

~~~c++
class{
public:
    Estudiante();
    Estudiante(string nombre, int edad);

    void aumentarEdad(int num);
private:
    string nombre;
    int edad;    
};

int main(){
    Estudiante *Ramon;
    Estudiante *Jorge;
    Ramon = new Estudiante("Ramon Jimenez", 20);    //Constructor con parámetros
    Jorge = new Estudiante();   //Constructor por defecto

    Ramon->aumentarEdad(12);
    (*Ramon).aumentarEdad(2);
}
~~~

## 3.6: Arrays dinámicos

Con arrays dinámicos conseguiremos justo el tamaño que nos haga falta, justo en el momento en el que lo necesitemos

### 3.6.1: Operador `new[]`

~~~c++
<tipo> *puntero;
puntero = new <tipo> [numero_de_datos];
~~~

### 3.6.2: Operador `delete[]`

~~~c++
delete [] puntero;
~~~

### 3.6.3: Ejemplo completo de uso

~~~c++
int main(){
    int *v = 0;
    int n;

    //Se eligen las posiciones de memoria
    cout << "Numero de casillas: ";
    cin >> n;

    //Creo un array dinámico
    v = new int [n];

    //Introduzco los datos
    for(int i = 0; i < n; i++){
        cout << "Introduce un numero: ";
        cin >> v[i];
    }
    cout << endl;

    //Muestro los datos almacenados
    for(int i = 0; i < n; i++){
        cout << "Posicion " << i << ": " << v[i] << endl;
    }

    //Elimino el array dinamico
    delete [] v;
    v = 0;  //Para decir que ahora v es puntero nulo
}
~~~

### 3.6.4: Copiar un array en un array dinámico

~~~c++
int *copia_vector(v1, tam){
    int *copia = new int [tam];

    for(int i = 0; i < tam; i++){
        copia[i] = v1[i];
    }

    return copia;
}

int main(){
    int v1[30];
    int *v2;
    int tam = 0;
    int numero;
    bool acabado = false;

    for(int i = 0; i < 30 && !acabado; i++){
        cout << "Introduce un elemento: ";
        cin >> numero;

        if(numero == -1){
            acabado = true;
        }else{
            v[i] = numero;
            tam++;
        }
    }

    v2 = copia_vector(v1, tam);

    for(int i = 0; i < tam; i++){
        cout << i << ": " << v2[i] << endl;
    }
}
~~~

### 3.6.5: Modificación del espacio de un array dinamico

~~~c++
void redimensionar(int *&v, int & tam, int variacion){
    if(tam + variacion > 0){
        int newSize = tam + variacion;
        int *v_ampliado = new int [newSize];

        //Copio los datos del array antiguo
        for(int i = 0; i < tam && i < newSize; i++){
            v_ampliado[i] = v[i];
        }

        //Cambio la dirección del puntero
        delete [] v;
        v = v_ampliado;
        tam = newSize;
    }else{
        cout << "No se ha podido cambiar, no se hace nada" << endl
    }
}
~~~

Aqui el puntero a `v` se pasa por referencia porque la dirección a la que apunta el puntero cambia al nuevo array creado.

### 3.7: Arrays dinámicos de objetos

* Uso del `new[]`: reserva la memoria para guardar los objetos, y además, llama al constructor de cada objeto que se ha metido en el array dinámico.
    * En este caso, no podemos elegir el constructor que se va a llamar, se usa siempre el **constructor por defecto** (sin parametros)
* Uso del `delete[]`: se llama al destructor de la clase para cada uno de los objetos, y luego liberaría la memoria del array

**Ejemplo:**

~~~c++
class Estudiante{
public:
    Estudiante();   //Constructor por defecto

    void setNombre(string newName);
    void setEdad(int newEdad);

    void showInfo() const;
private:
    int edad;
    string Nombre;    
};

Estudiante *arrayEstudiante;
arrayEstudiante = new Estudiante[50];
arrayEstudiante[0].setNombre("Sergio Quijano Rey");
arrayEstudiante[0].setEdad(18);
arrayEstudiante[0].showInfo();

delete [] arrayEstudiante;
~~~

## 3.8: Matrriz Dinamica

Queremos guardar la siguiente matriz:

| 1 | 2  | 3 |
| --- | --- | --- |
| 4 | 5 | 6 |
| 7 | 8 | 9 |
| 10 | 11 | 12 |

### 3.8.1: Disposicion secuencial

**Uso general:**

~~~c++
int *matriz;
int rows = 4;
int cols = 3;

//Creo la matriz dinamica secuencial
matriz = new int[rows * cols];


//Accedo al elemento row = f col = c
int a = matriz[f * rows + c];

//Libero la matriz
delete [] matriz;
matriz = NULL;
~~~

**Funciones especificas:**

~~~c++
int * inicializar(int n_rows, int n_cols){
    int * auxiliar = new int[n_rows * n_cols];
    return auxiliar;
}

int getValue(int * matriz, int matriz_rows, int matriz_cols, int row, int col){
    //El numero de columnas de la matriz en verdad no hace falta
    int val = matriz[row * matriz_rows + col];
    return val;
}

void showMatriz(int * matriz, int rows, int cols){
    for(int r = 0; r < rows; r++){
        for(c = 0; c < cols; c++){
            cout << matriz[rows * r + c] << " ";
        }
        cout << endl;
    }
}

void liberar(int *& matriz, int rows, int cols){
    delete[] matriz;
    matriz = NULL;
}
~~~

### 3.8.2: Disposicion secuencial con `struct`

~~~c++
struct MatrizSecuencial{
    int rows;
    int cols;
    int * data;
}

int inicializar(Matriz & matriz, int _rows, int _cols){
    matriz.rows = _rows;
    matriz.cols = _cols;

    matriz.data = new int[_rows * _cols];
}
~~~

### 3.8.3: Array de punteros a fila

Usaré un puntero a un array de punteros a vectores de enteros (vector fila)

~~~c++
//Creo la matriz
int **matriz;
int rows;
int cols;

matriz = new int* [rows];
for(int i = 0; i < rows; i++){
    matriz[i] = new int[cols];
}

//Acceso a la posicion m[f][c]
int a = m[f][c];

//Liberacion de la memoria
for(int i = 0; i < rows; i++){
    //Libero filas
    delete[] m[i];
}

//Libero el array de punteros
delete[] m;
m = NULL;
~~~

## 3.9: Listas de celdas enlazadas

* En los exámenes no suele valer más de un punto. En *Estructura de Datos* se verá esta estructura, y otras más complejas
* Su uso es recomendable cuando continuamente añadimos y eliminamos datos a la colección. Redimensionar un array dinámico simple estas operaciones son mucho más costosas, aunque el acceso a un elemento es más rápido en este caso.
