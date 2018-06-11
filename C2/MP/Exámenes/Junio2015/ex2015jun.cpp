#include <iostream>
#include <fstream>

using namespace std;

struct Pareja {
    int dato;
    int nveces;
};
class Frecuencias {
    private:
        Pareja *parejas; // "npares" datos de tipo "Pareja" ordenados por "dato". 0 si no hay parejas.
        int npares;

        void copiar(const Frecuencias& otro);
        void reservarmemoria(int num);
        void liberarmemoria();
    public: // ... interfaz pública de la clase
        Frecuencias();
        Frecuencias(const Frecuencias& otro);
        Frecuencias& operator=(const Frecuencias& otro);
        Frecuencias& operator+=(int n);
        void add(int n);
        void ordenar();
        ~Frecuencias();

        friend std::ostream& operator<<(std::ostream& os,const Frecuencias& frec);
        friend std::istream& operator>>(std::istream& is, Frecuencias & frec);
};

Frecuencias::Frecuencias(){
    npares = 0;
    parejas = NULL;
}

Frecuencias::Frecuencias(const Frecuencias& otro){
    if (parejas != NULL)
        delete [] parejas;
    npares = otro.npares;
    parejas = new Pareja [npares];
    for (int i = 0; i < npares; i++)
        parejas[i] = otro.parejas[i];
}

void Frecuencias::ordenar(){
    Pareja auxiliar;
    for (int i = 0; i < npares-1; i++){
        if (parejas[i].dato > parejas[i+1].dato){
            auxiliar = parejas[i];
            parejas[i] = parejas[i+1];
            parejas[i+1] = auxiliar;
        }
    }
}

Frecuencias& Frecuencias::operator=(const Frecuencias& otro){
    if (parejas != NULL)
        delete [] parejas;
    npares = otro.npares;
    parejas = new Pareja [npares];
    for (int i = 0; i < npares; i++)
        parejas[i] = otro.parejas[i];
}

void Frecuencias::add(int n){
    int cont = 0;
    bool encontrado = false;

    while (cont < npares && !encontrado){
        if (n == parejas[cont].dato){
            parejas[cont].nveces++;
            encontrado = true;
        }
        cont++;
    }

    if (!encontrado){
        Frecuencias auxiliar;
        int pos = 0;
        auxiliar.reservarmemoria(npares+1);
        for (int i = 0; i<npares-1; i++){
            if (parejas[i].dato < n && parejas[i+1].dato > n)
                pos = i+1;
        }
        for (int i = 0; i < pos; i++)
            auxiliar.parejas[i] = parejas[i];

        auxiliar.parejas[pos].dato = n;
        auxiliar.parejas[pos].nveces = 1;

        for (int i = pos; i < npares; i++)
            auxiliar.parejas[i+1] = parejas[i];

        (*this) = auxiliar;
    }
}

Frecuencias& Frecuencias::operator+=(int n){
    (*this).add(n);
    return *this;
}

Frecuencias::~Frecuencias(){
    if (parejas != NULL)
        delete [] parejas;
    npares = 0;
}


std::ostream& operator<<(std::ostream& os,const Frecuencias& frec){
    for (int i = 0; i < frec.npares; i++)
    os << frec.parejas[i].dato << " " << frec.parejas[i].nveces << endl;

    return os;
}

std::istream& operator>>(std::istream& is, Frecuencias & frec){
    int num;
    while (is >> num && num != 15121999)
        frec+=num;
    return is;
}

void Frecuencias::copiar(const Frecuencias& otro){
    if (parejas != NULL)
        delete [] parejas;
    npares = otro.npares;
    parejas = new Pareja [npares];
    for (int i = 0; i < npares; i++)
        parejas[i] = otro.parejas[i];
}

void Frecuencias::reservarmemoria(int num){
    if (parejas != NULL)
            delete [] parejas;
        npares = num;
        parejas = new Pareja [npares];
}

void Frecuencias::liberarmemoria(){
    if (parejas != NULL)
        delete [] parejas;
    npares = 0;
}

int main (int argc, char* argv[]){
    Frecuencias mifrecuencia;

    if (argc == 1){
        cout << "Leyendo de consola, introduzca 15121999 para terminar la lectura" << endl;
        cin >> mifrecuencia;
    }
    else{
        ifstream fichero;
        cout << "Leyendo de fichero " << argv[1] << endl;
        fichero.open(argv[1]);
        if (fichero)
            fichero >> mifrecuencia;
        else
            cerr << "El fichero no se ha abierto correctamente" << endl;
        fichero.close();
    }

    cout << mifrecuencia;

    return 0;
}

//By Mapachana


