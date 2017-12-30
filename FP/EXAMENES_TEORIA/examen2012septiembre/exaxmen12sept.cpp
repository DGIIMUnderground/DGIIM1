/* ENUNCIADO DE UN PROBLEMA DE EXAMEN

1. (3 puntos) Se está desarrollando una aplicación para automatizar la realización de exámenes tipo test. El
software incluirá una clase Examen que debe almacenar: el nombre de la asignatura, la lista de enunciados de las
preguntas (cada enunciado es una cadena de caracteres) y la lista de respuestas correctas para cada pregunta
(cada respuesta es un carácter). Implementa la clase junto con los siguientes métodos:
	
	- Un constructor que inicialice un objeto de tipo Examen dando el nombre de la asignatura y con la lista de
	preguntas vacía.
	- Un método NuevaPregunta que reciba un enunciado y la respuesta correcta y que los añada a la lista de
	preguntas del examen. Cada nueva pregunta siempre se añade al final de la lista.
	- Un método NumPreguntas que devuelva el número de preguntas de que consta el examen.
	- Un método GetEnunciado que devuelva el enunciado de la pregunta i-ésima.
	- Un método GetRespuesta que devuelva la respuesta de la pregunta i-ésima.

Recuerda que los métodos deben ser robustos frente a entradas de datos erróneas. 

A continuación, se pide realizar un programa que permita evaluar a una serie de alumnos utilizando la clase
Examen. El programa comenzará creando un objeto de tipo Examen y dándole contenido, es decir, leyendo las
preguntas y respuestas correctas desde la entrada estándar y almacenándolas.
Una vez leído el examen se procederá a la evaluación de un número de alumnos dado desde la entrada estándar.
Para ello el programa le mostrará las preguntas del examen a cada alumno y leerá sus respuestas. Al finalizar
cada alumno la prueba, el programa le dirá su nota de acuerdo a los siguientes criterios:
	Por cada pregunta sin responder se suman 0 puntos.
	Por cada respuesta correcta se suma 1 punto.
	Por cada respuesta incorrecta se resta 1 punto.
La nota final estará en el intervalo [0, 10]. Un 10 significa que ha respondido y acertado todas las preguntas.
Si la calificación es negativa se sustituye por cero.
Observe que no es necesario almacenar las notas de los alumnos ya que se pueden ir mostrando al terminar
cada uno de ellos la prueba. Además, podrá añaadir nuevos métodos a la clase Examen si lo considera oportuno,
así como implementar funciones externas a la misma. Se tendrá en cuenta la calidad del diseño propuesto.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;


/**
    Clase examen, realiza preguntas para un examen tipo test.
    DEBE HABER EL MISMO NUMERO DE PREGUNTAS QUE DE RESPUESTAS.
*/
class Examen
{
public:
    /**
        @brief: Constructor por defecto.
        @param: asig: Nombre de la asignatura a evaluar.
    */
    Examen(string asig);
    /**
        @brief: Añade una pregunta y su respuesta al examen
        @param: en: Enunciado de la pregunta.
        @param: resp: Respuesta a la pregunta añadida.
    */
    void nuevapregunta(string en, char resp);
    /**
        @brief: Muestra cuantas preguntas tiene el examen.
        @return: Devuelve un entero que es e l numero de preguntas.
    */
    int numpreguntas() const;
    /**
        @brief: Muestra el enunciado de una pregunta
        @param: num: Numero de la pregunta a mostrar. empiezan en 0.
        @return: Devuelve el enunciado.
    */
    string getenunciado(int num) const;
    /**
        @brief: Muestra la respuesta de una pregunta
        @param: num: Numero de la respuesta a mostrar. empiezan en 0.
        @return: Devuelve la respuesta.
    */
    char getrespuesta(int num) const;

private:
    string asignatura;
    vector <string> enunciados;
    vector <char> respuestas;
};

/**
    @brief: Realiza el examen a cada alumno y muestra su nota.
    @param: n: numero de alumnos que realizaran el examen.
    @param: ex: Examen a evaluar.
*/
void evaluacion (int n, const Examen& ex);

Examen::Examen(string asig)
{
    asignatura = asig;
    enunciados = vector <string> ();
    respuestas = vector <char> ();
}

void Examen::nuevapregunta (string en, char resp)
{
    enunciados.push_back(en);
    respuestas.push_back(resp);
}

int Examen::numpreguntas() const
{
    return enunciados.size();
}

string Examen::getenunciado (int num) const
{
    return enunciados[num];
}

char Examen::getrespuesta (int num) const
{
    return respuestas[num];
}

void evaluacion (int n, const Examen& ex)
{
    for (int j = 0; j < n; j++)
    {
        char resp;
        double nota = 0;

        for (int i = 0; i < ex.numpreguntas(); i++)
        {
            cout << ex.getenunciado(i) << endl;
            cout << "Pulse x para no responder" << endl;
                cin >> resp;
                if (resp == 'x')
                    nota = nota;
                else if (resp == ex.getrespuesta(i))
                    nota++;
                else
                    nota--;
        }
        nota = 10*nota/ex.numpreguntas();
        if (nota < 0)
            nota = 0;
        cout << "Su nota es " << nota << "/10";
    }
}

int main ()
{
    string asignat;
    int numpreguntas;
    int numalumnos;
    string pregunt;
    char respuesta;
    cout << "Introduzca la asignatura del examen" << endl;
    cin.ignore();
    getline (cin, asignat);
    Examen miexamen(asignat);

    cout << "Introduzca el número de preguntas que va a introducir" << endl;
    cin >> numpreguntas;

    for (int i = 0; i < numpreguntas; i++)
    {
        cout << "La pregunta " << i+1 << " es:" << endl;
        cin.ignore();
        getline (cin, pregunt);
        cout << "Y su respuesta:" << endl;
        cin >> respuesta;

        miexamen.nuevapregunta(pregunt,respuesta);
    }

    cout << "Se procederá a evaluar, introduzca el numero de alumnos" << endl;
    cin >> numalumnos;
    evaluacion(numalumnos, miexamen);

    return 0;

}















