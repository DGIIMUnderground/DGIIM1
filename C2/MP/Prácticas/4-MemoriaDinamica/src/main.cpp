/** 
 * @file main.cpp
 * @author DECSAI
*/

//By Asmilex 
#include <iostream>
#include <cstring>
#include "Bigrama.h"

using namespace std;

int main() {
    char s[60];
    int frec, nv1, nv2, nv3;
    Bigrama *v1=NULL, *v2=NULL, *v3=NULL;
    
    // Lee número de elementos del primer vector
    cout <<"Introduce el ńumero de bigramas del primer vector: ";
    cin >>nv1;

    v1 = new Bigrama [nv1];
    
    // Lee el primer vector
    char * cadena_temp = new char [3];
        
    cout <<"Lectura de vector (cadena, frecuencia): \n";
    for (int i=0; i<nv1; i++){
        cin >>cadena_temp>>frec;
        
        v1[i].setFrecuencia(frec);
        v1[i].setBigrama(cadena_temp);
    }  

    // Lee número de elementos del segundo vector
    cout <<"\nIntroduce el número de bigramas del segundo vector: ";
    cin >>nv2;

    v2 = new Bigrama [nv2];
    
    // Lee el segundo vector
    for (int i=0; i<nv2; i++){
        cin >>cadena_temp>>frec;
        v2[i].setFrecuencia(frec);
        v2[i].setBigrama(cadena_temp);
    }  

    cout << endl <<"Contenido de v1" << endl; imprimeBigramas(v1, nv1);
    cout << endl <<"Contenido de v2" << endl; imprimeBigramas(v2, nv2);
   
    // Posibles operaciones intermedias sobre v1 o v2 
    
    ordenaAscBigr(v1,nv1);
    ordenaAscBigr(v2,nv2);

    v3 = new Bigrama[nv1];

    sumaBigramas(v1, nv1, v2, nv2, v3, nv3);
    ordenaAscFrec(v3, nv3);
    
    cout << endl <<"Contenido de v3" << endl; imprimeBigramas(v3, nv3);

    // Limpieza de memoria
    delete [] v1;
    delete [] v2;
    delete [] cadena_temp;
    delete [] v3;
    return 0;
}

