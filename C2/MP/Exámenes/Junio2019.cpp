/*
    Autor: Asmilex
    Fotos del examen: https://imgur.com/a/MSGTmhZ
    No he puesto datos de prueba ni lo he comprobado la verdad. No me responsabilizo de los bugs que haya JAJA
*/


#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cfloat> // DBL_MAX

using namespace std;

//
// ──────────────────────────────────────────────────────────── CLASE PUNTO3D ─────
//


    class Punto3D {
    private:
        double x;
        double y;
        double z;

    public:
        /*
            El constructor por defecto proporcionado es suficiente para inicializar la clase propiamente
            Se usa los que proporciona double
        */

        double obtenerX () const {
            return x;
        }    

        double obtenerY () const {
            return y;
        }

        double obtenerZ () const {
            return z;
        }

        friend ostream & operator << (ostream & out, const Punto3D & punto) {
            out << "(" << punto.obtenerX() << ", " << punto.obtenerY() << ", " << punto.obtenerZ() << ")";
            return out;
        }

        friend istream & operator >> (istream & in, Punto3D punto) {
            in >> punto.x, punto.y, punto.z;
            return in;
        }
    };


double distancia_puntos (Punto3D a, Punto3D b); // Para que compile, se deja aquí la declaración


//
// ──────────────────────────────────────────────────────── CLASE TRAYECTORIA ─────
//

    class Trayectoria {
    private:
        Punto3D * puntos;
        int numeroPuntos;

        void clear_memory() {
            if (numeroPuntos > 0) {
                delete [] puntos;
            }
        }

    public:
        /* 
            En principio el constructor por defecto DEBE estar haciendo lo mismo que acabo de hacer yo aquí abajo. De todas formas, lo dejo puesto
            Lo que sí hace falta es el destructor, y eso no se te puede olvidar
            Por diseño, es mejor hacerlo con una función por si se repitiera código (Cof centauros bípedos cof) 
        */

        Trayectoria () {
            puntos       = nullptr;
            numeroPuntos = 0;
        }

        Trayectoria (const Punto3D * puntillos, int num_puntillos ) {
            this->numeroPuntos = num_puntillos;
            puntos = new Punto3D[numeroPuntos];

            for (int i = 0; i < num_puntillos; i++)
                puntos[i] = puntillos[i];
            
        }

        ~Trayectoria() {
            clear_memory();
        }

        Punto3D & operator [] (size_t i) const {
            return puntos[i];
        }

        int obtenerNumeroPuntos() const {
            return numeroPuntos;
        }

        void resize(int dim) {
            if (dim >= 0) {
                Punto3D * tmp = new Punto3D[numeroPuntos];

                for (int i = 0; i < numeroPuntos; i++)
                    tmp[i] = puntos[i];
                
                delete puntos;
                puntos = new Punto3D[dim];

                for (int i = 0; i < dim && i < numeroPuntos; i++)
                    puntos[i] = tmp[i];
                
                numeroPuntos = dim;
            }
        }
    };


//
// ────────────────────────────────────────────────────────────── CLASE VUELO ─────
//


    class Vuelo {
    private:
        int idVuelo;
        Trayectoria rutaOptima;
        Trayectoria rutaReal;

    public:

    //
    // ─── CONSTRUCTORES ──────────────────────────────────────────────────────────────
    //

        Vuelo () {
            // Trayectoria ya tiene un constructor por defecto que se encarga de inicializarlos correctamente
            idVuelo = -1;
        }

        Vuelo (const Vuelo & vuelo) {
            *this = vuelo;
        }

        Vuelo (const int id, const Trayectoria & ruta_optima) {
            rutaOptima = ruta_optima;
            idVuelo    = id;
        }

        Vuelo (const string & fichero) {
            ifstream in (fichero);

            if (!in)
                cerr << "No se ha podido abrir el fichero dado";
            else 
            {
                string tmp;
                in >> tmp;

                if (tmp != "FICHEROVUELO")
                    cerr << "Fallo en el fichero";
                else 
                {
                    int id;
                    in >> id;
                    this->idVuelo = id;

                    int num_coords;
                    in >> num_coords;

                    // Para la óptima, no nos vale el operador +=. Debemos hacerlo a mano
                    Punto3D * puntos = new Punto3D [num_coords];

                    for (int i = 0; i < num_coords; i++) {
                        in >> puntos[i];
                    }

                    Trayectoria optima (puntos, num_coords);
                    this->rutaOptima = optima;
                    
                    delete [] puntos;

                    /*
                        Un par de cosas antes de seguir:
                        Tengo la sensación de que aquí deberíamos haber usado el constructor Vuelo(id, ruta_optima), pero no veo cómo usarlo. No lo veo útil

                        Además, el tema del delete [] puntos depende de la implementación de Trayectoria. Si se adueña del array (es decir, se asignan directamente los punteros), 
                        no haría falta hacer el delete, pues se encargaría el destructor. Sin embargo, mi implementación hace una copia del array y ya está. Entonces, sí tenemos que borrarlo. 
                        Si hubiéramos hecho lo primero, y lo borramos, también borraríamos el que tiene trayectoria. Así que todo se iría a tomar por saco. Ojito, porque esto es peligroso.
                    */

                    // Para los puntos restantes, sí usaremos el operador +=
                    Punto3D punto;
                    in >> num_coords;
                    
                    for (int i = 0; i < num_coords; i++) {
                        in >> punto;
                        (*this) += punto;
                    }
                }
            }
        }

    //
    // ─── OTROS ──────────────────────────────────────────────────────────────────────
    //

        int obtenerIdVuelo() const {
            return idVuelo;
        }

        double calcularLongitudRutaOptima () const {
            double distancia = 0;

            for (int i = 1; i < rutaOptima.obtenerNumeroPuntos(); i++) {
                distancia += distancia_puntos( rutaOptima[i-1], rutaOptima[i] );
            }
        
            return distancia;
        }

        double calcularLongitudRutaReal () const {
            double distancia = 0;

            for (int i = 1; i < rutaReal.obtenerNumeroPuntos(); i++) {
                distancia += distancia_puntos( rutaReal[i-1], rutaReal[i] );
            }
        
            return distancia;
        }

        double calcularDistanciaMediaEntreTrayectorias () const {
            double distancia_min, distancia_tmp, distancia_final;
            
            for (int i = 0; i < rutaReal.obtenerNumeroPuntos(); i++) {
                distancia_min = DBL_MAX;

                for (int j = 0; j < rutaOptima.obtenerNumeroPuntos(); j++) {
                    distancia_tmp = distancia_puntos(rutaReal[i], rutaOptima[j]) < distancia_min;
                    
                    if (distancia_tmp < distancia_min)
                        distancia_min = distancia_tmp;
                }

                distancia_final += distancia_min;
            }

            distancia_final /= rutaReal.obtenerNumeroPuntos();

            return distancia_final;
        }

    //
    // ─── SOBRECARGA DE OPERADORES ────────────────────────────────────
    //

        Vuelo & operator = (const Vuelo & vuelo) {
            this->rutaOptima = vuelo.rutaOptima;
            this->rutaReal   = vuelo.rutaReal;
            this->idVuelo    = vuelo.idVuelo;

            return *this;
        }

        Vuelo & operator += (const Punto3D & nuevo_punto) {
            // Aquí hace falta que tengamos un resize para la clase trayectoria
            
            if (rutaReal.obtenerNumeroPuntos() == 0) {
                rutaReal.resize(2);
                rutaReal[0] = rutaOptima[0];
                rutaReal[1] = nuevo_punto;
            }
            else {
                rutaReal.resize( rutaReal.obtenerNumeroPuntos() + 1 );
                rutaReal[ rutaReal.obtenerNumeroPuntos() - 1 ] = nuevo_punto;
            }

            return *this;
        }

        friend bool operator < (const Vuelo & vuelo1, const Vuelo & vuelo2);

        friend ostream & operator << (ostream & out, const Vuelo & vuelo) {
            out << "Identificador de vuelo: " << vuelo.idVuelo << endl
                << "Número de puntos de la ruta óptima: " << vuelo.rutaOptima.obtenerNumeroPuntos() << endl;

            for (int i = 0; i < vuelo.rutaOptima.obtenerNumeroPuntos(); i++) {
                out << vuelo.rutaOptima[i] << endl;
            }

            out << "Número de puntos de la ruta real: " << vuelo.rutaReal.obtenerNumeroPuntos() << endl;
            
            for (int i = 0; i < vuelo.rutaReal.obtenerNumeroPuntos(); i++) {
                out << vuelo.rutaReal[i] << endl;
            }

            return out;
        }
    };

double distancia_puntos (Punto3D a, Punto3D b) {
    return sqrt 
    (     (a.obtenerX() - b.obtenerX()) * (a.obtenerX() - b.obtenerX())
      +   (a.obtenerY() - b.obtenerY()) * (a.obtenerY() - b.obtenerY())
      +   (a.obtenerZ() - b.obtenerZ()) * (a.obtenerZ() - b.obtenerZ())  );
}

bool operator < (const Vuelo & vuelo1, const Vuelo & vuelo2) {
    return vuelo1.calcularDistanciaMediaEntreTrayectorias() < vuelo2.calcularDistanciaMediaEntreTrayectorias();
}

//
// ───────────────────────────────────────────────────────────────────── MAIN ─────
//

int main(int argc, char const *argv[])
{
    if (argc != 4) {
        cerr << "Número incorrecto de parámetros";
        return -1;
    }

    string fichero1 = argv[1];
    string fichero2 = argv[2];
    double umbral   = atof(argv[3]);

    Vuelo vuelo1(fichero1);
    Vuelo vuelo2(fichero2);

    Vuelo mejor_vuelo;
    if (vuelo1 < vuelo2)
        mejor_vuelo = vuelo1;
    else 
        mejor_vuelo = vuelo2;
    
    
    cout << mejor_vuelo;

    if (mejor_vuelo.calcularDistanciaMediaEntreTrayectorias() < umbral)
        cout << "El menor de los vuelos tiene un valor de distancia media por debajo del umbral";
    else
        cout << "Nuestro vuelo es una caca y supera el umbral :(" ;
    
    return 0;
}
