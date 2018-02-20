#include <iostream>
#include <vector> //!!!!!
using namespace std;

const int victoria = 3;
const int empate = 1;
const int derrota = 0;

vector<int> resultados_liga ( const vector<vector<char> > & partidos ) {
	vector<int> resultados_liga(partidos.size(), 0);
	for ( int i = 0; i < partidos.size(); i++ ) {
		for ( int j = 0; j < partidos.size(); j++ ) {
			if ( i != j ) {
				if ( partidos[i][j] == '1' ) {
					resultados_liga[i] += victoria;
					resultados_liga[j] += derrota;
				} else if ( partidos[i][j] == '2' ) {
					resultados_liga[j] += victoria;
					resultados_liga[i] += derrota;
				} else if ( partidos[i][j] == 'X' ) {
					resultados_liga[i] += empate;
					resultados_liga[j] += empate;
				}
			}
		}
	}
	return resultados_liga;
}

int main() {
	// hellouu
}
