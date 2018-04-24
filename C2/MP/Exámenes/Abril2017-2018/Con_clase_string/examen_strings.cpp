#include <iostream>
#include <string>
using namespace std;

void Intersecador(const string * array1, const int dim1, const string * array2, const int dim2, string * & interseccion, int & dim_interseccion){
    dim_interseccion = 0;
    for (int i=0; i<dim1; i++)
        for (int j=0; j<dim2; j++)
            if (array1[i] == array2[j]){
                interseccion[dim_interseccion] = array1[i];
                dim_interseccion++;
            }
}

void Printer(const string array[], const int dim){
    cout <<"Contenido del string de dimensión "<<dim<<":"<<endl;
    for (unsigned int i=0; i<dim; i++){
        cout <<array[i]<<" ";
    }
    cout <<endl;
}

int main(){
    unsigned int dim1;
    cout <<"¿Dimensión del primer vector?\n";
    cin >>dim1; 

    string * array1 = new string [dim1]; 

    cout <<"Ve diciéndome los bigramas:\n";
    for (unsigned int i=0; i<dim1; i++){
        cin >>array1[i];
    }

    unsigned int dim2;
    cout <<"\n¿Dimensión del segundo vector?\n";
    cin >>dim2;
    
    string * array2 = new string [dim2];
    cout <<"Ahora los otros:\n";

    for (unsigned int i=0; i<dim2; i++){
        cin >>array2[i];
    }

    Printer(array1, dim1);
    Printer(array2, dim2);

    int dim_interseccion = min(dim1, dim2);
    string * interseccion = new string [dim_interseccion];
    
    Intersecador(array1, dim1, array2, dim2, interseccion, dim_interseccion);

    Printer(interseccion, dim_interseccion);

    delete [] array1;
    delete [] array2;
    delete [] interseccion;
}