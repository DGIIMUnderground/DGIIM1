#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Examen {
	private:
		string asignatura_;
		vector<string> enunciados_;
		vector<char> respuestas_;
	public:
		Examen ( const string & nombre_asignatura ) {
			asignatura_ = nombre_asignatura;
		}
		void NuevaPregunta ( const string & enunciado, const char & respuesta ) {
			enunciados_.push_back(enunciado);
			respuestas_.push_back(respuesta);
		}
		int NumPreguntas () const {
			return enunciados_.size();
		}
		string GetEnunciado ( const int & num_pregunta ) const {
			if ( num_pregunta >= enunciados_.size() )
				return "Indice invalido";
			else
				return enunciados_[num_pregunta - 1];
		}
		char GetRespuesta ( const int & num_pregunta ) const {
			if ( num_pregunta >= respuestas_.size() )
				return '!';
			else
				return respuestas_[num_pregunta - 1];
		}
		void InsertarPregunta ( const int & num ) {
			cout << "PREGUNTA " << num << endl;
			string input_str; char input_char;
			cout << "Inserte enunciado: ";
			cin.ignore();
			getline(cin, input_str);
			enunciados_.push_back(input_str);
			cout << "Inserte respuesta: ";
			cin >> input_char;
			respuestas_.push_back(input_char);
		}
		void Evaluar ( const int & num_alumno ) {
			int nota_alumno = 0;
			char input_respuesta;
			cout << "EVALUACION DE ALUMNO " << num_alumno << endl << endl;
			for ( int i = 0; i < enunciados_.size(); i++ ) {
				cout << "Pregunta " << i+1 << ": " << enunciados_[i] << endl;
				cout << "\tInserte respuesta (0 para no responder): ";
				cin >> input_respuesta;
				if ( input_respuesta == respuestas_[i] )
					nota_alumno += 1;
				else if ( input_respuesta == '0' )
					nota_alumno += 0;
				else
					nota_alumno -= 1;
			}
			// esto lo he hecho porque ps si
			if ( nota_alumno < 0 )
				nota_alumno = 0;
			else if ( nota_alumno > 10 )
				nota_alumno = 10;
			cout << "La nota final del alumno " << num_alumno << " es: "
				<< nota_alumno << "/" << enunciados_.size() << endl;
		}
};

int main() {
	Examen prueba("Fundamentos de Programacion");
	string input_str; char input_char;
	cout << "Inserte 10 preguntas y su respuesta a continuacion: " << endl;
	for ( int i = 1; i <= 10; i++ ) {
		prueba.InsertarPregunta(i);	
	}
	int num_alumnos;
	cout << "Inserte el numero de alumnos: ";
	cin >> num_alumnos;
	while ( num_alumnos <= 0 ) {
		cout << "ERROR. El numero de alumnos debe ser un numero entero positivo. Intentelo de nuevo: ";
		cin >> num_alumnos;
	}
	for ( int i = 1; i <= num_alumnos; i++ ) {
		prueba.Evaluar(i);
		if ( i != num_alumnos )
			cout << "- - - - - - - - - - - - - - - - - - - -"<<endl;
	}
}
