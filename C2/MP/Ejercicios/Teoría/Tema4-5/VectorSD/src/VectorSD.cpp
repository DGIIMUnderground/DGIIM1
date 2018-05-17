#include "VectorSD.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
using namespace std;

VectorSD::VectorSD (){
    reservado = 10;
    info = new int [reservado];
    for (size_t i = 0; i < reservado; i++) {
      info[i] = 0;
    }
    util = 0;
  }

VectorSD::VectorSD ( int reserva ){
    reservado = reserva;
    util = 0;
    info = new int [reservado];

    for (size_t i = 0; i < reservado; i++) {
      info[i] = 0;
    }
 }

VectorSD::VectorSD(const VectorSD& vect){
    util = vect.util;
    reservado = vect.reservado;
    info = new int [reservado];
    for (unsigned i = 0; i < util; ++ i){
        info[i] = vect.info[i];
    }
}
VectorSD::~VectorSD(){
    delete [] info;
    util = 0;
    reservado = 0;
}
int VectorSD::getDato( int posicion ) const{
    return info[posicion];
  }

VectorSD& VectorSD::operator=(const VectorSD & vec){
    if (&vec != this){
        delete[] this->info;
        this->util = vec.util;
        this->reservado = vec.reservado;
        this->info = new int [reservado];
        for (unsigned i = 0; i < this->util; ++i)
            this->info[i] = vec.info[i];
    }
    return *this;
}

bool VectorSD::operator==(const VectorSD & vec) const{
    bool igual = (vec.util == this->util)? true: false;
    if (igual){
        for(unsigned i = 0; i < this->util && igual; ++i ){
            if ( this->info[i] != vec.info[i] )
                igual = false;
        }
    }
    return false;
    
}
bool VectorSD::operator != (const VectorSD & vec) const{
    bool distinto = (vec == *this)? false : true;
    return distinto;
}
bool VectorSD::operator>(const VectorSD &vec) const{
    bool mayor = true;
    int menor_util = (vec.util < this->util)? vec.util: this->util;
    
    for(unsigned i = 0; i < menor_util && mayor; ++i){
        if (this->info[i] < vec.info[i] ){
            mayor = false;
        }
    }
    if (mayor && menor_util == this->util){   //Si el primer vector tiene menos tamaño que el otro no es mayor
        mayor = false;
    }
    return mayor;
}
bool VectorSD::operator<(const VectorSD &vec) const{
    bool menor = true;
    int menor_util = (vec.util < this->util)? vec.util: this->util;
    
    for(unsigned i = 0; i < menor_util && menor; ++i){
        if (this->info[i] > vec.info[i]){
            menor = false;
        }
    }
 
    return menor;
}

bool VectorSD::operator>=(const VectorSD &vec) const{
    bool mayor_igual = (*this > vec || *this == vec)? true: false;
    return mayor_igual;
}

bool VectorSD::operator<=(const VectorSD &vec) const{
    bool menor_igual = (*this < vec || *this == vec)? true: false;
    return menor_igual;
}

const int & VectorSD::operator [](int i) const{
    assert(i>= 0); assert(i < util);
    return info[i];
}

int & VectorSD::operator [](int i){
    assert(i>= 0); assert(i < util);
    return info[i];
}

VectorSD VectorSD::operator+(const int aumento){
    int anterior = info[util - 1] + 1;
    VectorSD aux (*this);
    for(unsigned i = this->util; i < aumento + util; ++i){
        aux.aniadir(anterior);
        anterior = aux[i] + 1;
    }
    return aux;
}
VectorSD VectorSD::operator+=(const int aumento){
    (*this) = (*this) + aumento;
    return *this;
}
VectorSD VectorSD::operator-(const int decremento){
    assert(this->util - decremento > 1);
    VectorSD aux;
    for (unsigned i = 0; i < util - decremento; ++i){
        aux.aniadir(info[i]);
    }
    return aux;
}
VectorSD VectorSD::operator -=(const int decremento){
    (*this) = (*this) - decremento;
    return *this;
}

void VectorSD::aniadir(int dato){

    if (util >= reservado ){
        reservado = reservado*2;
      int* info_aux = new int [reservado];
      for (size_t i = 0; i < util; ++i) {
        info_aux[i] = info[i];
      }
      delete [] info;
      info = info_aux;
    }
    info[util] = dato;
 
    util ++;

  }
void VectorSD::mod_casilla(int pos , int dato){
    assert (pos >= 0 && pos < this->nElementos() );
    info[pos] = dato;
}

//Posible mejor en no repetir aserciones no llamando la funcion de modificacion. Se hace esto
//Para mantener el encapsulamiento.
void VectorSD::insertar(int pos, int dato){
    assert (pos >= 0 && pos < this->nElementos() );
    
    VectorSD aux ( *this );
    
    this->aniadir(dato);
    
    unsigned j = 0;
    
    for (unsigned i = 0; i < this->nElementos(); ++i){
        if ( i != pos){
            this->mod_casilla(i,aux.getDato(j) );
            j++;
        }
    }
    mod_casilla(pos , dato);
}

void VectorSD::borrar(int pos){
    assert (pos >= 0 && pos < this->nElementos() );
    VectorSD aux ( *this );
    
    unsigned j = 0;
    for ( unsigned i = 0; j < this->nElementos() - 1; ++i){
        if ( i != pos ){
            this->mod_casilla(i, aux.getDato(j) );
            j++;
        }
    }
    util --;
}


void VectorSD::mostrar( ostream & flujo) const {
   for(int i=0; i<util;i++){
      flujo << info[i] << " ";
    }
    flujo << endl;
}
void VectorSD::leer(istream& flujo){
    int dato;
    while(flujo>>dato){
      aniadir(dato);
    }
}

void ordenar(VectorSD & vector){
    int minimo = 3000000;
    int pos = 0;
    for (unsigned i = 0; i < vector.nElementos() ; ++i){
        for(unsigned j = i; j < vector.nElementos();++j){
            if (vector.getDato(j) < minimo){
                minimo = vector.getDato(j);
                pos = j;
            }
        }
        int aux = vector.getDato(i);
        vector.mod_casilla(i,minimo);
        vector.mod_casilla(pos,aux);
        minimo = 300000;
    }
}

ostream& operator<<(ostream &flujo, const VectorSD vect){
    for (unsigned i = 0; i < vect.nElementos(); ++i){
        flujo << vect[i] << " ";
    }
    return flujo;
}
istream& operator>>(istream &flujo, VectorSD & vect){
    string dato = "";
    do{
        flujo >> dato;

        if ( isNumeric(dato)  ){
            vect.aniadir( stoi(dato) );
        }
    }while(dato != "*");
    return flujo;
   
}

bool isNumeric(string cadena){
    bool ver = true;
    for(unsigned i = 0; i < cadena.length(); ++i){
        if ( isdigit( cadena[i] ) == 0  ){
            ver = false;
        }
    }
    return ver;
}