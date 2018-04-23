/**
   @file secuenciapaquete.cpp
   @author decsai.ugr.es
   @warning Código incompleto
**/
#include "secuenciapaquete.h"
#include "paquete.h"

void cleanSecuenciaPaq(Paquete s[], int & util){
    for (unsigned int i=0; i<util; i++)
        s[i].setPaquete(-1, 0, 0, 0, 0);
    
    util = 0;
}

bool addSecuenciaPaq(Paquete s[], int & util, const Paquete p){
    if (util < MAXPAQ){
        util++;
        s[util] = p;
        return 1;
    }
    else
        return 0;
}

double getTotalSecuenciaPaq(const Paquete s[], const int util){
    double sumatoria = 0;
    
    for (unsigned int i=0; i<util; i++)
        sumatoria += s[i].getFactura();
    
    return sumatoria;
     
}

Paquete paqueteMayorSecuenciaPaq(const Paquete s[], const int util){
    int max = 0;
    
    for (unsigned int i=0; i<=util; i++)
        if (s[i].getVolumen() > max)
            max = i;
    
    return s[max];
    
}

double getMediaSecuenciaPaq(const Paquete s[], const int util){
    return getTotalSecuenciaPaq(s, util)/util;
}

int numPaqueteAltosSecuenciaPaq(const Paquete s[], const int util, int altura){
    int paquetes_mayores = 0;

    for (unsigned int i=0; i<util; i++){
        if (s[i].getAlto() > altura)        //Entiendo mayor estricto según la documentación
            paquetes_mayores++;
    }
    return paquetes_mayores;   
}

int numPaquetesSuperiorSecuenciaPaq(const Paquete s[], const int util){
    double media         = getMediaSecuenciaPaq(s, util);
    int paquetes_mayores = 0;
    
    for (unsigned int i=0; i<util; i++)
        if (s[i].getFactura() > media)       //Vuelvo a entender mayor estricto
            paquetes_mayores++;
    
    return paquetes_mayores;
}           