#include <iostream>
#include <vector>

using namespace std;

//Porfa no editeis este codigo que estoy haciendo modificaciones y me faltan muchas cosas, lo subo solo para que haya algo de sobrecarga de operadores en el repo.

class Matriz
{
public:
    Matriz (const vector<vector<double> >& f, int c);
    Matriz ();
    Matriz (Matriz& m);
    vector<vector<double> > getelementos() const;
    int gettamano() const;
    void setnumber(int a, int b, double c);
    void inicializador (int num);
    double operator() (int i, int j) const;
    Matriz operator+ (const Matriz& m) const;

private:
    vector<vector<double> > elementos;
    int tamano;
};

Matriz::Matriz (const vector<vector<double> >& f, int c)
{
    elementos = f;
    tamano = c;
}


Matriz::Matriz ()
{
    tamano = 0;
    elementos = vector<vector<double> > (tamano, vector<double> (tamano));
}


Matriz::Matriz (Matriz& m)
{
    elementos = m.getelementos();
    tamano = m.tamano;
}

void Matriz::setnumber(int a, int b, double c)
{
     elementos[a][b] = c;
}

void Matriz::inicializador (int num)
{
    elementos = vector<vector<double> > (num, vector<double> (num));
    tamano = num;
}

vector<vector<double> > Matriz::getelementos() const
{
    return elementos;
}

int Matriz::gettamano() const
{
    return tamano;
}

Matriz Matriz::operator+ (const Matriz& m) const
{
    Matriz resultado (vector<vector<double> > (tamano, vector<double> (tamano)), tamano);
    if (tamano == m.tamano)
        for (int j = 0; j < tamano; j++)
            for (int k = 0; k < tamano; k++)
                resultado.elementos[j][k] = elementos[j][k] + m.elementos[j][k];
    else
        cout << "Las matrices deben ser del mismo tamano" << endl;

    return resultado;
}

double Matriz::operator() (int i, int j) const
{
    return elementos[i][j];
}

ostream& operator<<(ostream& os, Matriz& n)
{
    for (int j = 0; j < n.gettamano(); j++)
    {
        for (int k = 0; k < n.gettamano(); k++)
        {
            os << n(j,k) << " ";
        }
        os << endl;
    }
    return os;
}

istream& operator>>(istream& in, Matriz& n)
{
    double numero;
    double num = 3;
    cout << "Introduzca un numero";
    in >> num;
    n.inicializador(num);

    for (int j = 0; j < num; j++)
        for (int k = 0; k < num; k++)
        {
            in >> numero;
            n.setnumber(j,k,numero);
        }

    return in;
}


int main ()
{
    Matriz mimatriz;
    Matriz tumatriz;
    Matriz suma;


    cin >> mimatriz;
    cout << mimatriz;
    cin >> tumatriz;
    cout << tumatriz;
    suma = mimatriz + tumatriz;
    cout << suma << endl;
    cout << (mimatriz) (1,1);

    return 0;
}

//By Mapachana.
