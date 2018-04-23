//By Mapachana

#include <iostream>
#include <fstream> // ifstream

using namespace std;

class VectorSD
{
public:
    VectorSD ();
    VectorSD (int _reservado);
    int getDato (int posicion) const;
    int nElementos () const;
    void copia(const VectorSD &vector);
    void aniadir (int dato);
    void liberar ();
    void mostrar (ostream& flujo) const;
    void leer (istream& flujo);

private:
    int * info;
    int util;
    int reservado;
};

void redimensionar (int* puntero, int tamano, int incremento);

VectorSD::VectorSD ()
{
    info = 0;
    util = 0;
    reservado = 0;
}

VectorSD::VectorSD(int _reservado)
{
    util = 0;
    reservado = _reservado;
    info = new int [reservado];
}

int VectorSD::getDato(int posicion) const
{
    if (posicion < util)
        return *(info+posicion);
    else
        cout << "Esa posicion no es valida" << endl;
}

int VectorSD::nElementos () const
{
    return util;
}

void VectorSD::copia(const VectorSD& vector)
{
    int * q = new int [vector.util];
    delete[] info;
    for (int i = 0; i < vector.util; i++)
        *(q+i) = vector.info[i];
    info = q;
    delete[] q;
}

void VectorSD::liberar ()
{
    delete[] info;
}

void VectorSD::mostrar(ostream& flujo) const
{
    for(int i = 0; i < util; i++)
    {
        flujo << info[i] << " ";
    }
    flujo << endl;
}

void VectorSD::aniadir(int dato)
{
    if (util >= reservado)
    {
        if (reservado == 0)
            reservado = 1;
        reservado = 2*reservado;
        int* q = new int [reservado];
        for (int i = 0; i < util; i++)
            q[i] = info[i];
        delete[] info;
        info = q;
    }
    info[util] = dato;
    util++;
}

void VectorSD::leer (istream& flujo)
{
    /*int contador = 0;*/
    int dato;
    /*int* q = new int [30];
    delete[] info;
    info = q;
    q = 0;*/
    while(flujo>>dato)
    {
        aniadir(dato);
        /*info[contador] = dato;
        cout << dato;
        cout << info[contador];
        contador++;
        util++;*/
    }

}



int main(int argc, char* argv[])
{
VectorSD v;
if (argc==1)
v.leer(cin);
else {
ifstream flujo(argv[1]);
if (!flujo) {
cerr << "Error: Fichero " << argv[1] << " no válido." << endl;
return 1;
}
v.leer(flujo);
}
v.mostrar(cout);
v.liberar(); // Libera la memoria dinámica reservada
}

