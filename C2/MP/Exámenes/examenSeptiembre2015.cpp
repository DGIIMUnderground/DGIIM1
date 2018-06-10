#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

struct Valor{
    int fila;
    int columna;
    double valor;
};

class MatrizDispersa {
    private:
        int nfilas;          // N ́umero de filas
        int ncolumnas;       // N ́umero de columnas
        Valor *valores;      // Vector-C no ordenado, solo valores significativos
        int numeroValores;   // N ́umero de valores significativos almacenados
    public:
            MatrizDispersa(){
                nfilas        = 0;
                ncolumnas     = 0;
                numeroValores = 0;
                valores       = nullptr;
            }
            
            MatrizDispersa(const int filas,const int columnas,const int* vector_filas,const int* vector_columnas,const double* vector_valores, const int dim_valores){
                nfilas = filas;
                ncolumnas = columnas;

                ReservarMemoria(dim_valores);
                for (int i=0; i<dim_valores; i++){
                    valores[i] = {vector_filas[i], vector_columnas[i], vector_valores[i]};
                }
            }
            MatrizDispersa(const MatrizDispersa& peasomatriz){
                Copiar(peasomatriz);
            }

            ~MatrizDispersa(){
                if (valores != nullptr)
                    delete [] valores;
            }
            void ReservarMemoria(int n){
                if (valores != nullptr)
                    delete [] valores;

                numeroValores = n;
                valores = new Valor [numeroValores];
            }

            MatrizDispersa& operator=(const MatrizDispersa& peasomatriz){
                Copiar(peasomatriz);
                return *this;
            }

            void Copiar(const MatrizDispersa& peasomatriz){
                ReservarMemoria(peasomatriz.numeroValores);
                ncolumnas = peasomatriz.ncolumnas;
                nfilas    = peasomatriz.nfilas;

                for (int i=0; i<numeroValores; i++)
                    valores[i] = peasomatriz.valores[i];

            }

            double obtenerValor(int fila, int columna) const {
                for (int i=0; i<numeroValores; i++){
                    if (valores[i].fila == fila && valores[i].columna == columna)
                        return valores[i].valor; 
                }
                return 0;
            }

            void asignarValor(int fila, int columna, double valor){
                bool no_encontrado = true;

                //Búsqueda de existente
                for (int i=0; i<numeroValores && no_encontrado; i++){
                    if (valores[i].fila == fila && valores[i].columna == columna){
                        no_encontrado = false;

                        if (valor != 0)
                            valores[i].valor = valor;
                        
                        if (valor == 0){
                            Valor* valores_temp = new Valor [--numeroValores];
                            
                            //Copia de la memoria sin el pasado
                            for (int i=0; i<numeroValores; i++)
                                if (valores[i].fila != fila || valores[i].columna != columna)
                                    valores_temp[i] = valores[i];
                            
                            //Reorganización del espacio de memoria
                            delete [] valores;
                            numeroValores--;
                            valores = valores_temp;
                        }

                    }
                }

                if (!no_encontrado)
                    exit;

                //Proceso de añadido
                bool existe_fila = false, existe_columna = false;
                
                for (int i=0; i<numeroValores; i++){
                    if (valores[i].fila == fila)
                        existe_fila = true;
                    if (valores[i].columna == columna)
                        existe_columna = true;
                }

                if (!existe_fila)
                    nfilas++;
                if (!existe_columna)
                    ncolumnas++;

                Valor* valores_temp = new Valor [++numeroValores];
                            
                //Copia de la memoria sin el pasado
                for (int i=0; i<numeroValores; i++)
                    valores_temp[i] = valores[i];
                
                //Añadido del nuevo valor
                Valor valor_temp;
                valor_temp = {fila, columna, valor};
                valores_temp[++numeroValores] = valor_temp;
                
                delete [] valores;
                numeroValores++;
                valores = valores_temp;
            }

            MatrizDispersa operator+(const MatrizDispersa& matrisilla){
                MatrizDispersa resultado;
                resultado.nfilas    = this->nfilas;
                resultado.ncolumnas = this->ncolumnas;

                ReservarMemoria(this->numeroValores);

                for (int i=0; i<matrisilla.numeroValores; i++){
                    resultado.asignarValor( matrisilla.valores[i].fila, 
                                            matrisilla.valores[i].columna, 
                                            matrisilla.valores[i].valor);
                }
                
                return resultado;   
            }

            friend ostream&  operator<<(ostream& flujo, const MatrizDispersa& matrisilla);
            friend istream& operator>>(istream& flujo,       MatrizDispersa& matrisilla);
};

ostream& operator<<(ostream& flujo, const MatrizDispersa& matrisilla){
    flujo<<matrisilla.nfilas       <<endl;
    flujo<<matrisilla.ncolumnas    <<endl;
    flujo<<matrisilla.numeroValores<<endl;

    //Formato del array: fila columna valor
    for (int i=0; i<matrisilla.numeroValores; i++){
        flujo<<matrisilla.valores[i].fila<<matrisilla.valores[i].columna<<matrisilla.valores[i].valor<<endl;
    }
    
    return flujo;
};

istream& operator>>(istream& flujo, MatrizDispersa& matrisilla){
    int nfilas, ncolumnas, num_valores;
    flujo >> nfilas >> ncolumnas >> num_valores;

    matrisilla.ReservarMemoria(num_valores);
    int fila, columna;
    double valor;

    for (int i=0; i<num_valores; i++){
        flujo >> fila >> columna >> valor;
        matrisilla.valores[i].fila    = fila;
        matrisilla.valores[i].columna = columna;
        matrisilla.valores[i].valor   = valor;
    }
    
    return flujo;
}

bool LoadFile(string archivo, MatrizDispersa& matrisilla){
    ifstream carga;
    carga.open(archivo);

    if (!carga){
        cout <<"No se ha podido abrir el archivo";
        return false;
    }
    
    string codificacion;
    carga >> codificacion;

    if (codificacion != "MP-MATRIZDISPERSA-1.0"){
        cout << "No es un tipo de archivo correcto";
        return false;
    }

    carga >> matrisilla;

    return true;
};

bool SaveFile(string archivo, const MatrizDispersa& matrisilla){
    ofstream salida;
    salida.open(archivo);

    if (!salida){
        cout <<"No se ha podido abrir el archivo";
        return false;
    }

    salida <<"MP-MATRIZDISPERSA-1.0";
    salida <<matrisilla;

    return true;
}

int combinarSuma(const Valor* v1, const int dim1, const Valor* v2, const int dim2, Valor*& resultante){
    int dim_resultante = 0;
    
    for (dim_resultante; dim_resultante<dim1; dim_resultante++){        
            resultante[dim_resultante] = v1[dim_resultante];
    }

    for (int i=0; i<dim2; i++){
        if (resultante[i].fila == v2[i].fila && resultante[i].columna == v2[i].columna)
            resultante[i].valor += v2[i].valor;
        else{
            resultante[dim_resultante] = v2[i];
            dim_resultante++;
        }
    }

    return dim_resultante;
} 

int main(){

    return 0;
}