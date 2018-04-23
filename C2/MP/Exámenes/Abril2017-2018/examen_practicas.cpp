/*By Asmilex
Si alguien tiene ganas de copiar el examen, que lo haga. No es exactamente el mismo, eso sí.
 Lo he hecho teniendo en cuenta lo que puedo sacar gracias al papel que han pasado por el grupo
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>

using namespace std;

class Bigrama {
private:
    char _bigrama[3]; /// Bigrama almacenado, incluyendo el '\0'. Ojo a desbordamientos
    int _frecuencia; /// Frecuencia almacenada
public:
    Bigrama(){    
        _bigrama[0] = '\0';
        _frecuencia = -1;
    }
    
    const char* getBigrama() const {return this->_bigrama;};

    int getFrecuencia() const {return this->_frecuencia;}; 
    
    void setBigrama(const char cadena[]){
        bool interruptor = false;

        //Comprobación de longitud correcta
        if (cadena[2] == '\0')
            interruptor = true; 


        if (interruptor == false)
            cout <<"Longitud del bigrama inválida para la cadena recibida"<<endl;
        else{
            for (unsigned int i=0; i < 2; i++)
                this->_bigrama[i] = cadena [i];
            this->_bigrama[2] = '\0';
        }

    };

    void setFrecuencia(int frec){this->_frecuencia = frec;};
    
};

/**
 * @brief Imprime un vector de bigramas
 * @param v El vector de bigramas
 * @param n Tamaño de @a v
 */
void imprimeBigramas(const Bigrama *v, int n)  {
    cout << "Lista de " << n << " bigramas:" <<endl;
    for (int i=0; i<n; i++)
        cout << v[i].getBigrama() << "-" << v[i].getFrecuencia()<< ", "; // << endl;
}

/**
 * @brief Ordena un vector de bigramas de forma ascendente por bigramas
 * @param v El vector de bigramas
 * @param n Tamaño de @a v
 */
void ordenaAscBigr(Bigrama * v, int n){
    Bigrama Intercambio;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (strcmp(v[j].getBigrama(),v[i].getBigrama()) > 0){
                                
                Intercambio.setFrecuencia(v[i].getFrecuencia());
                Intercambio.setBigrama(v[i].getBigrama());

                v[i].setFrecuencia(v[j].getFrecuencia());
                v[i].setBigrama(v[j].getBigrama());

                v[j].setFrecuencia(Intercambio.getFrecuencia());
                v[j].setBigrama(Intercambio.getBigrama());
            }
}

/**
 * @brief Ordena un vector de bigramas de forma ascendente por frecuencias
 * @param v El vector de bigramas
 * @param n Tamaño de @a v
 */

void ordenaAscFrec(Bigrama * v, int n){
    Bigrama Intercambio;
    for (int i=0; i<n; i++)
        for (int j=i; j<n; j++)
            if (v[j].getFrecuencia() < v[i].getFrecuencia()){
                Intercambio.setFrecuencia(v[i].getFrecuencia());
                Intercambio.setBigrama(v[i].getBigrama());

                v[i].setFrecuencia(v[j].getFrecuencia());
                v[i].setBigrama(v[j].getBigrama());

                v[j].setFrecuencia(Intercambio.getFrecuencia());
                v[j].setBigrama(Intercambio.getBigrama());
            }
}

/**
 * @brief Suma dos listas de bigramas y devuelve el resultado
 * @param v1 Primer vector de bigramas
 * @param nv1 Tamaño de @a v1
 * @param v2 Segundo vector de bigramas
 * @param nv2 Tamaño de @a v2
 * @param res Vector resultado creado en memoria dinámica
 * @param nres Tamaño de @a res
 * @pre @a v1 y @a v2 deben tener el mismo tamaño y los mismos bigramas aunque las frecuencias sean distintas
 */
void sumaBigramas(const Bigrama * v1, int nv1, const Bigrama * v2, int nv2, Bigrama *& res, int & nres){
    nres = nv1;                             //por pre
    
    for (unsigned int i=0; i<nres; i++){
        res[i].setFrecuencia(v1[i].getFrecuencia() + v2[i].getFrecuencia());
        res[i].setBigrama(v1[i].getBigrama());
    }
}

void Intersecador(const Bigrama * v1, const int dim1, const Bigrama * v2, const int dim2, Bigrama *& res, int & dim_res){
    //Identificacion de bigramas que coinciden
    dim_res=0;
    for (unsigned int i=0; i<dim1; i++)
        for (unsigned int j=0; j<dim2; j++)
            if (strcmp(v1[i].getBigrama(), v2[j].getBigrama()) == 0){
                res[dim_res].setBigrama(v1[i].getBigrama());
                res[dim_res].setFrecuencia(v1[i].getFrecuencia() + v2[j].getFrecuencia());
                dim_res++;               
            }
}

int main(){
    //Localización de archivos que contienen los bigramas
    string localizacion1, localizacion2;
    
    cout <<"Antes de empezar el examen, necesito que me digas dónde te has descargado los archivos Datos1 y Datos2, incluidos en el repositorio. De otra forma, no tiene sentido este código\n";
    cout <<"¿Dónde se haya Datos1? (No te olvides de incluir la extensión del archivo. Debería ser de la forma [...]/Datos1.txt)\n";
    cin >>localizacion1;
    cout <<"¿Y Datos2?\n";
    cin >>localizacion2;
    cout <<"¡Genial! Pues debería estar todo listo\n";
    
    //Lectura del primer vector
    ifstream archivo;
    archivo.open(localizacion1);
    
    if (!archivo){
        cout <<"¡Ups. Parece que te has equivocado metiendo la ruta. Como soy un vago asqueroso, te va a tocar ejectuar de nuevo el programa. Sorry!";
        return 1;
    }


    unsigned int dim1;
    archivo >>dim1;
    
    Bigrama * PrimerArray  = new Bigrama[dim1];
    char cadena_temp[3];
    cadena_temp[2] = '\0';

    for (unsigned int i=0; i<dim1; i++){
        archivo >> cadena_temp;
        PrimerArray[i].setBigrama(cadena_temp); //Por hipótesis, todos son distintos
        PrimerArray[i].setFrecuencia(1);        //Por consecuencia de la hipótesis anterior
    }
    
    archivo.close();

    //Lectura del segundo vector
    archivo.open(localizacion2);
    if (!archivo){
        cout <<"¡Ups. Parece que te has equivocado metiendo la ruta. Como soy un vago asqueroso, te va a tocar meter de nuevo la ruta. Sorry!";
        return 1;
    }
    
    unsigned int dim2;
    archivo >>dim2;
    
    Bigrama * SegundoArray = new Bigrama[dim2];
    for (unsigned int i=0; i<dim2; i++){
        archivo >> cadena_temp;
        SegundoArray[i].setBigrama(cadena_temp); //Por hipótesis, todos son distintos
        SegundoArray[i].setFrecuencia(1);        //Por consecuencia de la hipótesis anterior
    }

    //Comprobemos que está todo en orden
    imprimeBigramas(PrimerArray,  dim1);
    cout <<endl;
    imprimeBigramas(SegundoArray, dim2);
    cout <<endl;

    //Array y dimensión temporal
    int dim_res = dim1 + dim2;
    Bigrama * Interseccion_temp = new Bigrama[dim_res];
    
    Intersecador(PrimerArray, dim1, SegundoArray, dim2, Interseccion_temp, dim_res);
   
   //Array y dimensión definitivo
    Bigrama * Interseccion = new Bigrama[dim_res];
    for (unsigned int i=0; i<dim_res; i++){
        Interseccion[i].setBigrama(Interseccion_temp[i].getBigrama());
        Interseccion[i].setFrecuencia(Interseccion_temp[i].getFrecuencia());
    }

    imprimeBigramas(Interseccion, dim_res);

    //Limpieza de memoria
    delete [] PrimerArray;
    delete [] SegundoArray;
    delete [] Interseccion_temp;
    delete [] Interseccion;

    return 0;
}
