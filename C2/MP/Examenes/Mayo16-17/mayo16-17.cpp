#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class ArrayDinamico{
  private:
    char vector[20];

  public:
    ArrayDinamico(){
      vector[1] = '\0';
    }

    const char* getVector() const{
      return vector;
    }

    void setVector (const char cadena[]){
      int i=0;

      while (cadena[i] != '\0'){
        i++;
      }

      for (int j=0; j<i; j++){
        vector[j] = cadena[j];
      }
      vector[i] = '\0';
    }

};

void imprimir (const ArrayDinamico *v, int n){
  for (int i=0; i<n; i++){
    cout << v[i].getVector() << " ";
  }
  cout << endl;
}

void unionArrays (const ArrayDinamico *v1, int long1, const ArrayDinamico *v2, int long2, ArrayDinamico *&v3, int &long3){
  bool existe;
  int z=0, j;

  for (int i=0; i<long1; i++){
    v3[i].setVector(v1[i].getVector());
  }

  for (int i=0; i<long2; i++){
    existe = false;
    j=0;

    while(j<=long1 && !existe){
      if (strcmp(v3[j].getVector(), v2[i].getVector()) == 0){
        existe = true;
      }
      j++;
    }
    if(!existe){
      v3[long1+z].setVector(v2[i].getVector());
      z++;
    }
  }

  long3 = long1 +z;
}

int main (){
  int long1, long2, long3=0;
  ArrayDinamico *v1=NULL, *v2=NULL, *v3=NULL;
  char cadena[20];

  ifstream fentrada;
  fentrada.open("ficheroA.txt");
  if(fentrada){
    fentrada >> long1;

    v1 = new ArrayDinamico[long1];

    for (int i=0; i<long1; i++){
      fentrada >> cadena;
      v1[i].setVector(cadena);
    }

    fentrada.close();
  }
  else
    cerr << "Error de apertura del fichero A\n";

  fentrada.open("ficheroB.txt");
  if(fentrada){
    fentrada >> long2;

    v2 = new ArrayDinamico[long2];

    for (int i=0; i<long2; i++){
      fentrada >> cadena;
      v2[i].setVector(cadena);
    }

    fentrada.close();
  }
  else
    cerr << "Error de apertura del fichero A\n";

  long3 = long1 + long2;
  v3 = new ArrayDinamico[long3];

  unionArrays (v1, long1, v2, long2, v3, long3);

  imprimir(v3, long3);

  delete[] v1;
  v1 = NULL;
  delete[] v2;
  v2 = NULL;
  delete[] v3;
  v3 = NULL;
  return 0;
}
