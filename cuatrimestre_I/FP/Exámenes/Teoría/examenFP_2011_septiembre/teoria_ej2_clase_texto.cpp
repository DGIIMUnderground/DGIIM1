#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Texto{
	private:
		vector<string> txt;
	
	public:
		
		int NumeroCadenas() const{
			return txt.size();
		}
		
		string ObtenerCadena( const int & pos) const{
			if ( pos>=0 && pos<txt.size() ){
				return txt[pos];
			}
		}
		
		void AnadirCadena( const string & nueva_cadena){
			txt.push_back(nueva_cadena);
		}
		
		void InsertarCadena( const string & nueva_cadena, const int & pos){
			if( pos>=0 && pos<txt.size() ){
				txt.resize( txt.size()+1 );
				
				for (int i=txt.size()-1; i>pos; i--){
					txt[i] = txt[i-1];
				}
				
				txt[pos] = nueva_cadena;
			}
		}
		
		void EliminarCadena(const int & pos){
			if( pos >= 0 && pos<txt.size() ){
				for ( int i=pos; i<txt.size()-1; i++){
					txt[i] = txt[i+1];
				}
				
				txt.pop_back();
			}
		}
		
		void EliminarBlancosIniciales(){
			for (int i=0; i<txt.size(); i++){
				while( txt[i][0] == ' ' ){
					txt[i].erase(0,1);
				}
			}
		}
		
		void EliminarBlancosFinales(){
			for (int i=0; i<txt.size(); i++){
				while( txt[i][ txt[i].size()-1] == ' '){
					txt[i].erase( txt[i].size()-1,1);
				}
			}
		}
		
		void EliminarBlancos(){
			EliminarBlancosIniciales();
			EliminarBlancosFinales();
		}
		
		/**
		 * @brief Calcula el índice de ocupación de una cadena
		 * @param cad: posición de la cadena en el texto
		 * @return índice de ocupación
		 */
		double IndiceOcupacion(const int & cad) const{
			int no_espacios=0; //cantidad de caracteres distintos de ' ' de la cadena
			
			for (int i=0; i<txt[cad].size(); i++){
				if (txt[cad][i] != ' '){
					no_espacios++;
				}
			}
			
			double indice_ocupacion = (double) no_espacios / txt[cad].size();
			
			return indice_ocupacion;
		}
		
		/**
		 * @brief Ordena las cadenas de mayor a menor índice de ocupación (voy a utilizar el algoritmo de burbuja, en función del índice de ocupación)
		 */
		void Reorganiza(){
			for(int i=txt.size()-1; i>0; i--){
				for (int j=0; j<i; j++){
					if ( IndiceOcupacion(j) < IndiceOcupacion(j+1) ){
						string aux = txt[j];
						txt[j] = txt[j+1];
						txt[j+1] = aux;
					}
				}
			}
		}
};

void MostrarTexto( const Texto & texto){
	for (int i=0; i<texto.NumeroCadenas(); i++){
		cout << texto.ObtenerCadena(i) << endl;
	}
}



int main(){
	cout << "Bienvenido a la clase TEXTO" << endl;
	
	Texto mi_texto;
	
	cout << "Mi texto: " << endl;
	MostrarTexto(mi_texto);
	
	mi_texto.AnadirCadena("Hola hola hola");
	mi_texto.AnadirCadena("Adios        ");
	mi_texto.InsertarCadena("    caracola", 1);
	
	cout << "Mi texto: " << endl;
	MostrarTexto(mi_texto);
	cout << endl;
	
	cout << "Índice de ocupación de la cadena 0: " << mi_texto.IndiceOcupacion(0) << endl;
	
	mi_texto.EliminarCadena(0);
	cout << "Mi texto: " << endl;
	MostrarTexto(mi_texto);
	cout << endl;
	
	mi_texto.EliminarBlancos();
	cout << "Mi texto: " << endl;
	MostrarTexto(mi_texto);
	cout << endl;
	
	cout << "Índice de ocupación de la cadena 0: " << mi_texto.IndiceOcupacion(0) << endl;
	
	
	cout << endl << endl;
	
	Texto nuevo;
	nuevo.AnadirCadena("Eráse un hombre");
	nuevo.AnadirCadena("Francisco de Quevedo");
	nuevo.InsertarCadena("a una nariz pegado", 1);
	
	cout << "Nuevo Texto:" << endl;
	MostrarTexto(nuevo);
	cout << endl;
	
	cout << "Ordenemos las líneas de mayor a menor índice de ocupación" << endl;
	nuevo.Reorganiza();
	MostrarTexto(nuevo);
	cout << endl;
}
