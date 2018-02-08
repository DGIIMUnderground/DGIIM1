#include <vector>
#include <string>

using namespace std;

class NotasAlumno {
	string nombre_;
	vector<int> notas_;
	public:
		NotasAlumno () {
			nombre_ = "Miguel Angel Fernandez Gutierrez";
		}
		NotasAlumno( const string & nombre, const vector<int> & notas ) {
			nombre_ = nombre;
			notas_ = notas;
		}
		NotasAlumno ( const NotasAlumno & notas_alumno ) {
			nombre_ = notas_alumno.nombre_;
			notas_ = notas_alumno.notas_;
		}
		string nombre () {
			return nombre_;
		}
		vector<int> notas () {
			return notas_;
		}
		double media () {
			double media_aritmetica = 0;
			for ( int i = 0; i < notas_.size(); i++ )
				media_aritmetica += notas_[i];
			media_aritmetica /= notas_.size();
			return media_aritmetica;
		}
};

void ordenarNotasAlumno ( vector<NotasAlumno> alumnos ) {
	NotasAlumno menor;
	int loc_menor;
	for ( int i = 0; i < alumnos.size() - 1; i++ ) {
		menor = alumnos[i];
		for ( int j = i + 1; j < alumnos.size(); i++ ) {
			if ( alumnos[j].media() < menor.media() )
				menor = alumnos[i];
				loc_menor = j;
		}
		NotasAlumno aux = alumnos[i];
		alumnos[i] = menor;
		alumnos[loc_menor] = aux;
	}
}
