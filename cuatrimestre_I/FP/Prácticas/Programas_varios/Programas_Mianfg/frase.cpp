#include <vector>

using namespace std;

class Frase {
	vector<char> frase_;
	public:
		Frase ( const vector<char> & frase ) {
			frase_ = frase;
		}
		Frase ( const Frase & frase ) {
			frase_ = frase.frase_;
		}
		int donde_esta ( const int & k ) {
			vector<char> busqueda;
			busqueda.push_back(' ');
			// esto no se puede hacer: busqueda.push_back(frase_);
			for ( int i = 0; i < frase_.size(); i++ )
				busqueda.push_back(frase_[i]);
			int contador = 0;
			int loc = -1;
			char actual = ' ';
			char anterior = ' ';
			for ( int i = 0; i < busqueda.size() - 1 && loc == -1; i++ )
				if ( busqueda[i] == ' ' && busqueda[i+1] != ' ' ) {
					contador++;
					if ( contador == k )
						loc = i; // no es i+1 porque le he sumado el espacio
				}
			return loc;
		}
};
