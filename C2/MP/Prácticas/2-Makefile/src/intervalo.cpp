#include <iostream>
#include <assert.h>
#include "intervalo.h"
using namespace std;

bool Intervalo::validar(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior){
    bool comprobador = 1;
    if (cotaInferior > cotaSuperior)
        comprobador = 0;
    if (cotaInferior == cotaSuperior && cerradoInferior != cerradoSuperior)
        comprobador = 0;
    return comprobador;
};

Intervalo::Intervalo(){
    this->cotaInf = 0;
    this->cotaSup = 0;
    this->cerradoInf = 0;
    this->cerradoSup = 0;
};

Intervalo::Intervalo(double cinf,double csup){
	assert (validar(cinf,csup, true, true));
	cotaInf = cinf;
	cotaSup = csup;
	cerradoInf = true;
	cerradoSup = true;
};

Intervalo::Intervalo(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior){
    assert (validar(cotaInferior, cotaSuperior, cerradoInferior, cerradoSuperior));
    cotaInf = cotaInferior;
    cotaSup = cotaSuperior;
    cerradoInf = cerradoInferior;
    cerradoSup = cerradoSuperior;
};

double Intervalo::getCotaInf() const{
    return this->cotaInf;
};

double Intervalo::getCotaSup() const{
    return this->cotaSup;
};

bool Intervalo::esCerradoSup() const{
    return this->cerradoSup;
}

bool Intervalo::esCerradoInf() const{
    return this->cerradoInf;
};

bool Intervalo::esVacio() const{
    if (cotaInf == cotaSup && cerradoInf == cerradoSup && cerradoInf == false)
        return true;
    else
        return false;
};

bool Intervalo::estaDentro(double n) const{
    if (cotaInf < n && n < cotaSup)
        return true;
    if (n == cotaInf && cerradoInf == true)
        return true;
    if (n == cotaSup && cerradoSup == true)
        return true;
    else
        return false;
};

Intervalo interseccion(const Intervalo & i1, const Intervalo & i2){
    bool cerradoInf_intersec, cerradoSup_intersec;
    double cotaInf_intersec, cotaSup_intersec;
    bool es_vacio=0;

    //Veamos si es posible hacer la intersección
    if (i1.cotaSup < i2.cotaInf) 
        es_vacio = 1;
    
    if (i1.cotaSup == i2.cotaInf && (i1.cerradoSup == 0 || i2.cerradoInf == 0))
        es_vacio = 1;
    
    if (es_vacio){
        Intervalo ir;
        return ir;
    }

    //Minorante
    if (i1.cotaInf > i2.cotaInf){
        cerradoInf_intersec = i1.cerradoInf;
        cotaInf_intersec = i1.cotaInf;
    }
    if (i1.cotaInf < i2.cotaInf){
        cerradoInf_intersec = i2.cerradoInf;
        cotaInf_intersec = i2.cotaInf;
    }
    else{
        cotaInf_intersec = i1.cotaInf;

        if (i1.cerradoInf != i2.cerradoInf)
            cerradoInf_intersec = 0;
        else
            cerradoInf_intersec = i1.cerradoInf;
    }

    //Mayorante
    if (i1.cotaSup < i2.cotaSup){
        cerradoSup_intersec = i1.cerradoSup;
        cotaSup_intersec = i1.cotaSup;
    }
    if (i1.cotaSup > i2.cotaSup){
        cerradoSup_intersec = i2.cerradoSup;
        cotaSup_intersec = i2.cotaSup;
    }
    else{
        cotaSup_intersec = i1.cotaSup;

        if (i1.cerradoSup != i2.cerradoSup)
            cerradoSup_intersec = 0;
        else
            cerradoSup_intersec = i1.cerradoSup;
    }

    Intervalo ir(cotaInf_intersec, cotaSup_intersec, cerradoInf_intersec, cerradoSup_intersec);
    return ir;

    //Comentario para la correción: no he conseguido arreglar lo de los ifs que me comentó en clase. La verdad es que 
    //tampoco he tenido mucho tiempo para mirarlo, pero la única solución que se me ocurre es alternar todos los ifs 
    // con || (ORs), rehaciendo todas las condiciones cambiando inferiores por superiores, y > por < y viceversa.
    //¿Es así como se haría? En clase le pregunto si quiere, no hace falta que sea por correo.
}

void escribir(const Intervalo & i){
    if (i.esCerradoInf())
        cout <<"[";
    else
        cout <<"(";
    cout <<i.getCotaInf()<<","<<i.getCotaSup();
    if (i.esCerradoSup())
        cout <<"]";
    else
        cout <<")";
};


void leer(Intervalo & i){
    char inclusion_inf, inclusion_sup, coma;
    double minorante, mayorante;
    bool inclusion_inf_bool, inclusion_sup_bool;

    cin >>inclusion_inf>>minorante>>coma>>mayorante>>inclusion_sup;
    
    if (inclusion_inf == '[')
        inclusion_inf_bool = 1;
    else
        inclusion_inf_bool = 0;
    
    if (inclusion_sup == ']' )
        inclusion_sup_bool = 1;
    else
        inclusion_sup_bool = 0;

    Intervalo aux(minorante, mayorante, inclusion_inf_bool, inclusion_sup_bool); 
    i = aux;
}
