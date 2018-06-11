# Celdas enlazadas

> Alumno: Miguel Ángel Fernández Gutiérrez ([@mianfg](https://github.com/mianfg))

## Operaciones básicas

### Struct `Celda`

~~~c++
struct Celda {
    int dato;
    Celda* sig;
}
~~~

### Crear una lista de celdas enlazadas

~~~c++
void crearLista(Celda* &lista, int primer_dato) {
    lista = new Celda;
    lista->dato = primer_dato;
    lista->sig = 0;
}
~~~

### Añadir elemento al principio de la lista

~~~c++
void aniadirDatoLista(Celda* &lista, int dat) {
    Celda* aux = new Celda;
    aux->dato = dat;
    aux->sig = lista;
    lista = aux;
}
~~~

### Mostrar lista (por `cout`)

~~~c++
void mostrarLista(Celda* lista) {
    Celda* aux = lista;
    while ( aux != 0 ) {
        cout << aux->dato << " ";
        aux = aux->sig;
    }
}
~~~

### Eliminar lista

~~~c++
void deleteLista(Celda* &lista) {
    Celda* aux;
    while ( lista != 0 ) {
        aux = lista;
        lista = lista->sig;
        delete aux;
    }
}
~~~

### Contar número de elementos de la lista

~~~c++
int sizeofLista(Celda* lista) {
    int contador = 0;
    Celda* aux = lista;
    while ( aux != 0 ) {
        contador++;
        aux = aux->sig;
    }
    return contador;
}
~~~

### Añadir elemento tras posición determinada de la lista

~~~c++
bool insertarDespuesLista(Celda* &lista, int dat, int loc) {
    int size = sizeofLista(lista);
    // comprobarmos que podemos colocarlo ahí
    if ( loc >= size )
        return false;
    
    // creamos la celda que añadiremos
    Celda* aniadir = new Celda;
    aniadir->dato = dat;
    
    // recorremos hasta llegar a la celda que estará antes de la que queremos añadir
    Celda* aux = lista;
    int pos = 0;
    while ( pos != loc ) {
        aux = aux->sig;
        pos++;
    }
    
    // hacemos que el siguiente del que queremos añadir sea el siguiente de aux
    // si queremos añadirlo al final
    if ( loc == size - 1 )
        aniadir->sig = 0;
    else
        aniadir->sig = aux->sig;
    
    // hacemos que el siguiente de aux sea el que queremos añadir
    aux->sig = aniadir;
    
    return true;
}
~~~

### Añadir elemento antes de posición determinada de la lista

~~~c++
bool insertarAntesLista(Celda* &lista, int dat, int loc) {
    // si queremos añadirlo al principio
    if ( loc == 0 ) {
        Celda* aniadir = new Celda;
        aniadir->dato = dat;
        aniadir->sig = lista;
        lista = aniadir;
        return true;
    } else
        return insertarDespuesLista(lista, dat, loc-1);
}
~~~

### Eliminar elemento de posición determinada de la lista

~~~c++
bool eliminarPosicionLista(Celda* &lista, int loc) {
    int size = sizeofLista(lista);
    // comprobar que podemos llegar a esa posición
    if ( loc >= size )
        return false;
    
    int pos = 0;
    Celda* aux = lista;
    while ( pos < loc - 1 ) {
        aux = aux->sig;
        pos++;
  }
    
    // llegado aquí, aux apunta a la celda que está justo antes de la que queremos eliminar
    Celda* eliminar = aux->sig;
    
    // si la celda que queremos eliminar es la última, es decir, aux apunta a la celda que está antes que la última
    if ( loc == size-1 ) {
        // apuntamos a 0 (indicar terminación) el siguiente de aux, para que ahora sea el último
        aux->sig = 0;
    } else {
        // hacemos que apunte al que está por delante de la que queremos eliminar
        aux->sig = eliminar->sig;
    }
    
    // eliminamos el que no queremos
    delete eliminar;
    
    return true;
}
~~~

_**Nota:** las funciones para eliminar aquí descritas tienen un pequeño fallo: no pueden eliminar una lista de celdas que tenga un solo elemento, ya que si no, no funcionaría la función `mostrarLista`._

## Ejercicios

### **Ejercicio 1, examen junio 2014.** Dividir lista

Se desea dividir una lista de celdas enlazadas en secuencias de celdas de tamaño t. Escriba una función que recibe una lista de celdas enlazadas que almacena enteros y devuelva un vector de listas que contiene cada una de estas secuencias.

###### Código completo compilable (main.cpp)
~~~c++
struct Celda{
    int dato;
    Celda* sig;
};

// suponemos implementadas las funciones anteriores
...

void devolverSegmentos(Celda** &lista, Celda* &L, int t) {
    int pos = 0;
    Celda* aux = L;
    
    // comprobamos si hemos llegado ya al final
    while ( L != 0 ) {
		// vemos si estamos al principio de uno de los segmentos
        if ( pos % t == 0 ) {
			// hacemos que en nuestra lista la coordenada pos/t apunte a como está ahora L
            lista[pos/t] = L;
            aux = L->sig;
        // vemos si está al final de alguno de los segmentos
        } else if ( pos % t == t - 1 ) {
            aux = L->sig;
            L -> sig = 0;
            L = aux;
        // si no, seguimos avanzando
        } else
			aux = L->sig;
        pos++;
        // L = L->sig (seguir avanzando, solo que hemos hecho perrerías con L antes y por eso lo hemos guardado en aux)
        L = aux;
    }
}

int main() {
    int TAM;
    
    Celda* L = 0;
    int entrada, loc;
    
    cout << "7. Crear lista (centinela -1):" << endl;
    cin >> entrada;
    crearLista(L, entrada);
    cin >> entrada;
    while ( entrada != -1 ) {
        aniadirDatoLista(L, entrada);
        cin >> entrada;
    }

    cout << "Insertar tamaño de división (t): ";
    cin >> TAM;

    int reservar = sizeofLista(L) / TAM;
    if ( sizeofLista(L) % TAM != 0 )
        reservar++;

    Celda** list = new Celda*[reservar];
	
	cout << "Lista insertada: " << endl;
	mostrarLista(L);
	
	devolverSegmentos(list, L, TAM);
	
    for ( int i = 0; i < reservar; i++ ) {
		cout << "Segmento " << i << ": ";
        mostrarLista(list[i]);
    }
    
    for ( int i = 0; i < reservar; i++ )
        deleteLista(list[i]);
    
    delete[] list;
}
~~~