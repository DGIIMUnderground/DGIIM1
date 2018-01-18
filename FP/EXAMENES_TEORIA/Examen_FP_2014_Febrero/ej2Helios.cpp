#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Emparejamiento{
  string equipo1;
  string equipo2;
};

int ncombinaciones (vector <string> lista){
  int n_combinaciones;
  for (int i = 1; i <  lista.size(); i++)
    n_combinaciones += i;

  return n_combinaciones;
}

vector <Emparejamiento> constructor_emparejamientos (vector <string> vector_equipos){
  vector <Emparejamiento> vector_final;
  int n_combinaciones = ncombinaciones( vector_equipos );


  for (int i = 0; vector_equipos.size() - i > 0; ++i ){
    for (int j = i; j < vector_equipos.size() - 1 ; ++ j){
      Emparejamiento emparejamiento_n;
      emparejamiento_n.equipo1 = vector_equipos[i];
      emparejamiento_n.equipo2 = vector_equipos[j + 1];
      vector_final.push_back(emparejamiento_n);
    }
  }
  return vector_final;
}
int main(){
  vector <string> wenas;
  string palabra;
  int n = 0;


  while (n <= 9) {
    getline(cin,palabra);
    wenas.push_back(palabra);
    n++;
  }
  vector <Emparejamiento> alolo = constructor_emparejamientos( wenas );
  for (size_t i = 0; i < alolo.size() ; i++) {
    cout << alolo[i].equipo1 << " " << alolo[i].equipo2 << endl;
  }
}
