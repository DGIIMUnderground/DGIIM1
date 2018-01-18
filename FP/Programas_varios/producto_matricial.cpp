#include <iostream>
#include <vector>
using namespace std;

void LecturaMatriz(unsigned int fila, unsigned int columna, vector<vector<double>> & matriz){
    cout <<"¿Coeficientes de la matriz?\n";
    for (int i=0; i < fila; i++){
        cout <<"Fila "<<i<<": ";
        for (int j=0; j<columna; j++){
            cout <<"Columna "<<j<<": ";
            cin >>matriz[i][j];
        }
    }

}

class Matrices{
private:
    unsigned int fila, columna;
    vector<vector<double>> matriz;
public: 
    Matrices(){
        fila = 3;
        columna = 3;
        matriz.resize(fila, vector<double>(columna));
        for (int i=0; i<fila; i++)
            for (int j=0; j<columna; j++)
                matriz[i][j]=0;

    };

    Matrices(unsigned int fila_, unsigned int columna_, bool query_lectura){
        fila = fila_;
        columna = columna_;
        matriz.resize(fila_, vector<double>(columna_));
        if (query_lectura)
            LecturaMatriz(fila, columna, this->matriz);
    };

    unsigned int Fila() const{
        return this->fila;
    };

    unsigned int Columna() const{
        return this->columna;
    };

    void Display() const{
        cout <<"Elementos de la matriz:\n";
        for (int i = 0; i < fila; i++){
            for (int j=0; j < columna; j++)
                cout <<this->matriz[i][j]<<" ";
            cout <<endl;
        }
    };

    double ProductoRowCol(Matrices matrix, unsigned int row, unsigned int column) const{
        double suma=0; 
        for (int i=0; i < this->columna; i++)
            suma += this->matriz[row][i]*matrix.matriz[i][column];          

        return suma;
    };

    Matrices operator*(Matrices matrix) const{
        Matrices resultante (this->fila, matrix.Columna(), 0);
        
        if (this->columna != matrix.Fila())
            cout <<"\nERROR: NO SE PUEDE REALIZAR LA OPERACIÓN, OCURRIRÁN FALLOS\n";
        else{
            for (int i=0; i < resultante.Fila(); i++)
                for (int j=0; j < resultante.Columna(); j++)
                    resultante.matriz[i][j] = this->ProductoRowCol(matrix, i, j); 
        }       
        return resultante;
    };

    void operator=(Matrices matrix){
        if (this->fila != matrix.Fila() && this->columna != matrix.Columna())
            cout <<"SE PRODUCIRÁN ERRORES. NO CONCUERDAN FILAS Y COLUMNAS";
        
        for (int i=0; i < this->fila; i++)
            for (int j=0; j < this->columna; j++)
                this->matriz[i][j] = matrix.matriz[i][j];  
            
    };
};
int main(){
    cout << "¿Dimensiones de la matriz? (Fila, columna)\n";
    unsigned int fila_1, columna_1;
    cin >>fila_1>>columna_1;

    Matrices mimatriz(fila_1, columna_1, 1);

    mimatriz.Display();

    cout <<"Dimemnsión de la segunda matriz?\n";
    unsigned int fila_2, columna_2;
    cin >>fila_2>>columna_2;

    Matrices matrix(fila_2, columna_2, 1);
    matrix.Display();

    Matrices producto = mimatriz*matrix;
    cout <<"\nProducto:\n";
    producto.Display();

    return 0;
}