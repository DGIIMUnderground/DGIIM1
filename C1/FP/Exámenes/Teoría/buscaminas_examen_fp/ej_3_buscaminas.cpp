#include <iostream>
#include <vector>

using namespace std;

class TableroBuscaMinas{
	private:
		vector<vector<bool> > tablero;
		
	public:
		
		/**
		 * @brief Constructor
		 */
		TableroBuscaMinas(const int & nfilas, const int & ncolumnas){
			vector<vector<bool> > el_tablero(nfilas,vector<bool> (ncolumnas, false));
			tablero = el_tablero;
		}
		
		/**
		 * @brief Modifica una casilla, si hay mina la quita y si no la pone
		 */
		void SetCasilla(const int & la_i, const int & la_j){
			if ( tablero[la_i][la_j] )
				tablero[la_i][la_j] = false;
			else
				tablero[la_i][la_j] = true;
		}
		
		/**
		 * @brief Minas que hay alrededor de una casilla. -1 si la casilla es una mina.
		 */
		int MinasAlrededor(const int & la_i, const int & la_j){
			int nminas_alrededor;
			
			if ( tablero[la_i][la_j] == true ){
				nminas_alrededor = -1;
			}
			else{	
				nminas_alrededor = 0;
				
				int comienzo_k, comienzo_l;
				
				if( la_i-1 >= 0 ){
					comienzo_k = la_i -1;
				}
				else{
					comienzo_k = la_i;
				}
				
				if( la_j-1 >= 0 ){
					comienzo_l = la_j -1;
				}
				else{
					comienzo_l = la_j;
				}
				
				
				for(int k = comienzo_k; k<= la_i+1 && k<tablero.size(); k++){
					for(int l = comienzo_l; l<= la_j+1 && l<tablero[k].size(); l++){
						if( !( k == la_i && l == la_j) && tablero[k][l] == true ){
							nminas_alrededor++;
						}
					}
				}
			}
			return nminas_alrededor;
		}
		
		bool HayMina( const int & la_i, const int & la_j){
			return tablero[la_i][la_j];
		}
};

int main(){
	
	TableroBuscaMinas partida(5, 5);
	
	if( partida.HayMina(2, 1) ){
		cout << "Explosión" << endl;
	}
	else{
		cout << "Hay " << partida.MinasAlrededor(2,1) << " minas alrededor." << endl;
	}
	
	partida.SetCasilla(2,1);
	
	if( partida.HayMina(2, 1) ){
		cout << "Explosión" << endl;
	}
	else{
		cout << "Hay " << partida.MinasAlrededor(2,1) << " minas alrededor." << endl;
	}
	
	partida.SetCasilla(2,0);
	
	if( partida.HayMina(1, 1) ){
		cout << "Explosión" << endl;
	}
	else{
		cout << "Hay " << partida.MinasAlrededor(1,1) << " minas alrededor." << endl;
	}
}
