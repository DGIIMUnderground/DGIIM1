#include <iostream>
#include <string>

using namespace std;

int main()
{
	int curso;
	char grupo;
	string asignatura;
	
	cout << "Introducir curso, grupo y asignatura: ";
	cin >> curso >> grupo;
	cin.get();
	getline(cin, asignatura);
	
	int n_alumnos;
	
	cout << "Número de alumnos matriculados: ";
	cin >> n_alumnos;
	
	string alumno;
	double nota;
	string mejor_alumno;
	double mejor_nota=0;
	
	for (int i=0; i<n_alumnos; i++)
	{
		cout << "Nombre y apellidos del alumno " << i << ": ";
		cin.get();
		getline(cin, alumno);
		
		//Lo ideal sería leer nombre y apellidos y nota en la misma línea, pero no sé como hacer para que el getline() no coja también la nota.
		
		cout << "Nota del alumno " << alumno << ": ";
		cin >> nota;
		
		if (nota > mejor_nota)
		{
			mejor_nota = nota;
			mejor_alumno = alumno;
		}
	}
	
	cout << "\nCurso: " << curso << "\nGrupo: " << grupo << "\nAsignatura: " << asignatura << "\nAlumno con mayor nota: " << mejor_alumno << endl;
}
