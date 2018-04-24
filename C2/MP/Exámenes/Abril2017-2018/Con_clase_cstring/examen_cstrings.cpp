#include <iostream>
#include <cstring>
using namespace std;

class Bigrama{
private:
    char bigrama[3];
public:
    Bigrama(){
        this->bigrama[2] = '\0';
    };

    Bigrama(const char cadena[]){
        this->bigrama[0] = cadena[0];
        this->bigrama[1] = cadena[1];
        this->bigrama[2] = '\0'; 
    }

    void Setter(const char cadena[]){
        this->bigrama[0] = cadena[0];
        this->bigrama[1] = cadena[1];
        this->bigrama[2] = '\0'; 
    }

    const char * Getter() const {return this->bigrama;};
};

void PrintVector(const Bigrama * array, unsigned int dim){
    cout <<"Bigramas del array mandado, de dimensión "<<dim<<":\n";
    for (unsigned int i=0; i<dim; i++){
        cout << array[i].Getter()<<" ";        
    }
    cout<<endl;
}

void Intersecador(const Bigrama * array1, const int dim1, const Bigrama * array2, int dim2, Bigrama * & interseccion, int & dim_intersec){
    dim_intersec = 0;
    for (unsigned int i=0; i<dim1; i++){
        for (unsigned int j=0; j<dim2; j++){
            if (strcmp( array1[i].Getter(), array2[j].Getter() ) == 0){
                interseccion[dim_intersec].Setter(array1[i].Getter());
                dim_intersec++;
            }
        }
    }
}
int main(){
    unsigned int dim1;
    cout <<"¿Dimensión del primer vector?\n";
    cin >>dim1; 

    Bigrama * array1 = new Bigrama [dim1]; 
    char cadena_temp[3];
    cadena_temp[2] = '\0';

    cout <<"Ve diciéndome los bigramas:\n";
    for (unsigned int i=0; i<dim1; i++){
        cin >>cadena_temp;
        array1[i].Setter(cadena_temp);
    }

    unsigned int dim2;
    cout <<"\n¿Dimensión del segundo vector?\n";
    cin >>dim2;
    
    Bigrama * array2 = new Bigrama [dim2];
    cout <<"Ahora los otros:\n";

    for (unsigned int i=0; i<dim2; i++){
        cin >>cadena_temp;
        array2[i].Setter(cadena_temp);
    }
    
    PrintVector(array1,dim1);
    PrintVector(array2,dim2);

    int dim_intersec = dim1 + dim2;
    Bigrama * interseccion_temp = new Bigrama [dim_intersec];

    Intersecador(array1,dim1,array2,dim2,interseccion_temp,dim_intersec);
    Bigrama * interseccion = new Bigrama [dim_intersec];

    for (unsigned int i=0; i<dim_intersec; i++){
        interseccion[i].Setter(interseccion_temp[i].Getter());
    }

    delete [] interseccion_temp;

    PrintVector(interseccion,dim_intersec);
    
    //char (*array3)[2] = new char [dim1][2];

    //Limpieza
    delete [] array1;
    delete [] array2;
    //delete [] array3;
    delete [] interseccion;

    return 0;
}   