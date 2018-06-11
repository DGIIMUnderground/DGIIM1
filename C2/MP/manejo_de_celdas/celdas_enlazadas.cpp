/*
 * CELDAS ENLAZADAS
 * 
 * Funciones básicas con celdas enlazadas, y ejercicios al respecto
 * 
 * Autor: Miguel Ángel Fernández Gutiérrez
 * Fecha: 11 de junio, 2018
 */

#include <iostream>
using namespace std;

struct Celda {
	int dato;
	Celda* sig;
};

void crearLista(Celda* &lista, int primer_dato) {
    lista = new Celda;
    lista->dato = primer_dato;
    lista->sig = 0;
}

void aniadirDatoLista(Celda* &lista, int dat) {
    Celda* aux = new Celda;
    aux->dato = dat;
    aux->sig = lista;
    lista = aux;
}

void mostrarLista(Celda* lista) {
    Celda* aux = lista;
    while ( aux != 0 ) {
        cout << aux->dato << " ";
        aux = aux->sig;
    }
    cout << endl;
}

void deleteLista(Celda* &lista) {
	Celda* aux;
	while ( lista != 0 ) {
		aux = lista;
		lista = aux->sig;
		delete aux;
	}
}

int sizeofLista(Celda* lista) {
    int contador = 0;
    Celda* aux = lista;
    while ( aux != 0 ) {
        contador++;
        aux = aux->sig;
    }
    return contador;
}

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
	Celda* lista = 0;
	int entrada, loc;
	
	cout << "1. Crear lista (centinela -1):" << endl;
	cin >> entrada;
	crearLista(lista, entrada);
	cin >> entrada;
	while ( entrada != -1 ) {
		aniadirDatoLista(lista, entrada);
		cin >> entrada;
	}
	
	cout << "2. Mostrar lista:" << endl;
	mostrarLista(lista);
	
	cout << "3. Tamaño: " << sizeofLista(lista) << endl;
	
	cout << "4. Insertar elemento antes de la posición: ";
	cin >> loc;
	cout << "Elemento a insertar: ";
	cin >> entrada;
	if (!insertarAntesLista(lista, entrada, loc))
		cerr << "Elemento inválido" << endl;
	cout << "Ahora la lista es: " << endl;
	mostrarLista(lista);
	
	cout << "5. Insertar elemento después de la posición: ";
	cin >> loc;
	cout << "Elemento a insertar: ";
	cin >> entrada;
	if (!insertarDespuesLista(lista, entrada, loc))
		cerr << "Elemento inválido" << endl;
	cout << "Ahora la lista es: " << endl;
	mostrarLista(lista);
	
	cout << "6. Eliminar elemento de posición: ";
	cin >> loc;
	if (!eliminarPosicionLista(lista, loc))
		cerr << "Elemento inválido" << endl;
	cout << "Ahora la lista es: " << endl;
	mostrarLista(lista);
	
	deleteLista(lista);
	
	
	int TAM;
    
    Celda* L = 0;
    
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
