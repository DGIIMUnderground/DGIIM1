#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Punto {
	char letra;
	int numero;
};

struct Barco {
	int tipo;
	Punto posicion;
	char direccion;
};

bool verificar_posicion ( const Punto & posicion ) {
	bool verificacion = true;
	if ( !( posicion.numero >= 1 && posicion.numero <= 10 ) )
		verificacion = false;
	if ( !( posicion.letra >= 'A' && posicion.letra <= 'J' ) )
		verificacion = false;
	return verificacion;
}

bool verificar ( const Barco & barco ) {
	bool verificacion = true;
	if ( !( barco.tipo >= 1 && barco.tipo <= 4 ) )
		verificacion = false;
	if ( !( barco.direccion == 'h' || barco.direccion == 'v' ) )
		verificacion = false;
	if ( !verificar_posicion(barco.posicion) )
		verificacion = false;
	return verificacion;
}

class Barquitos {
	vector<vector<int> > tablero;
	vector<Barco> barcos;
	vector<vector<int> > loc_barcos;
	public:
	Barquitos () {
		vector<int> ceros(10, 0);
		for ( int i = 0; i < 10; i++ ) {
			tablero.push_back(ceros);
		}
		for ( int i = 0; i < 10; i++ ) {
			loc_barcos.push_back(ceros);
		}
	}
	
	bool colocar( const Barco & barco ) {
		// comprobamos que los datos tienen sentido, o sea, que los datos introducidos cumplen las condiciones:
		bool done = true;
		int coord_horizontal = barco.posicion.numero - 1;
		int coord_vertical = (int)barco.posicion.letra - 65;
		if ( !verificar( barco ) )
			done = false;
		// la idea es intentar verificar si donde voy a colocar el barco es posible, o sea:
			// - si puedo colocarlo sin que se salga del tablero
			// - hay que colocarlo en lugares donde sea 0
		if ( barco.direccion == 'h' && done == true ) {
			// si se pasa del tablero, no podemos efectuar la operación
			if ( coord_horizontal > ( 10 - barco.tipo ) )
				done = false;
			else
				for ( int i = coord_horizontal; i < coord_horizontal + barco.tipo; i++ )
					if ( tablero[coord_vertical][i] != 0 )
						done = false;
			// si es posible hacerlo, done tendrá el valor true, y entonces colocamos los barcos
			if ( done ) {
				// modificamos la matriz tablero
				for ( int i = coord_horizontal; i < coord_horizontal + barco.tipo; i++ )
					tablero[coord_vertical][i] = barco.tipo;
				// incluimos el barco en la lista de barcos
				// NOTA: cada barco tendrá asociado un identificador, que será su posición en la lista de barcos
				barcos.push_back(barco);
				// incluimos el barco en la matriz identificadora de barcos
				// NOTA: en la matriz identificadora aparece el identificador del barco en cada sitio (con respecto a lo antes dicho)
				for ( int i = coord_horizontal; i < coord_horizontal + barco.tipo; i++ )
					loc_barcos[coord_vertical][i] = barcos.size();
			}
		} else if ( barco.direccion == 'v' && done == true ) {
			// si se pasa del tablero, no podemos efectuar la operación
			if ( coord_vertical > ( 10 - barco.tipo ) )
				done = false;
			else
				for ( int i = coord_vertical; i < coord_vertical + barco.tipo; i++ )
					if ( tablero[i][coord_horizontal] != 0 )
						done = false;
			// si es posible hacerlo, done tendrá el valor true, y entonces colocamos los barcos
			if ( done ) {
				// modificamos la matriz tablero
				for ( int i = coord_vertical; i < coord_vertical + barco.tipo; i++ )
					tablero[i][coord_horizontal] = barco.tipo;
				// incluimos el barco en la lista de barcos
				barcos.push_back(barco);
				// incluimos el barco en la matriz identificadora de barcos
				for ( int i = coord_vertical; i < coord_vertical + barco.tipo; i++ )
					loc_barcos[i][coord_horizontal] = barcos.size();
			}
		}
		return done;
	}
	
	char disparar ( const Punto & disparo ) {
		char mensaje = 'n';
		int coord_horizontal = disparo.numero - 1;
		int coord_vertical = (int)disparo.letra - 'A';
		if ( tablero[coord_vertical][coord_horizontal] >= 1 &&  tablero[coord_vertical][coord_horizontal] <= 4 ) {
			// si en el sitio hay una casilla de un barco no disparado, lo disparo
			tablero[coord_vertical][coord_horizontal] *= -1;
			// ahora hemos de comprobar si lo ha tocado o hundido
			// primero, buscamos a qué barco corresponde en loc_barcos
			int barco_tocado = loc_barcos[coord_vertical][coord_horizontal];
			// ahora sólo nos queda comprobar si, en este momento, todos las casillas que corresponden al barco son negativas
			//    en ese caso, el barco estará claramente hundido
			// supondremos que el barco está hundido, y si encontramos un valor positivo es porque no lo está
			//    en ese caso, el mensaje dejaría de ser hundido y pasaría a ser tocado
			mensaje = 'h';
			
			// cambiamos las coordenadas para que sean las coordenadas donde comienza el barco
			coord_horizontal = barcos[barco_tocado-1].posicion.numero - 1;
			coord_vertical = (int)barcos[barco_tocado-1].posicion.letra - 65;
			if ( barcos[barco_tocado-1].direccion == 'h' ) {
				for ( int i = coord_horizontal; i < coord_horizontal + barcos[barco_tocado-1].tipo; i++ )
					if ( tablero[coord_vertical][i] > 0 )
						mensaje = 't';
			} else if ( barcos[barco_tocado].direccion == 'v' ) {
				for ( int i = coord_vertical; i < coord_vertical + barcos[barco_tocado-1].tipo; i++ )
					if ( tablero[i][coord_horizontal] > 0 )
						mensaje = 't';
			}
			
		} else if ( tablero[coord_vertical][coord_horizontal] == 0 ) {
			// ha disparado a agua
			tablero[coord_vertical][coord_horizontal] = -10;
			mensaje = 'a';
		}
		return mensaje;
	}
	
	void mostrar( const bool & todo ) {
		if ( todo )
			cout << "Mostrando tablero:" << endl;
		for ( int i = 0; i < 10; i++ ) {
			for ( int j = 0; j < 10; j++ ) {
				cout << tablero[i][j] << "\t";
			}
			cout << endl;
		}
		if ( todo ) {
			cout << "Mostrando lista de barcos:" << endl;
			for ( int i = 0; i < barcos.size(); i++ ) {
				cout << "Barco " << i+1 << ": " << endl;
				cout << "   Tipo: " << barcos[i].tipo << endl;
				cout << "   Posicion: " << barcos[i].posicion.letra << barcos[i].posicion.numero << endl;
				cout << "   Direccion: " << barcos[i].direccion << endl;
			}
			cout << "Mostrando tablero de barcos:" << endl;
			for ( int i = 0; i < 10; i++ ) {
				for ( int j = 0; j < 10; j++ ) {
					cout << loc_barcos[i][j] << "  ";
				}
				cout << endl;
			}
		}
	}
};

string transcribir_mensaje ( const char & caracter, const bool & mayuscula ) {
	string transcrito;
	if ( mayuscula )
		switch ( caracter ) {
			case 't': transcrito = "Tocado";	break;
			case 'h': transcrito = "Hundido";	break;
			case 'a': transcrito = "Agua";		break;
			case 'n': transcrito = "No valido";	break;
		}
	else
		switch ( caracter ) {
			case 't': transcrito = "tocado";	break;
			case 'h': transcrito = "hundido";	break;
			case 'a': transcrito = "agua";		break;
			case 'n': transcrito = "no valido";	break;
		}
	return transcrito;
}

int main () {
	Barquitos juego;
	cout << "Bienvenido al juego de los barquitos!" << endl << endl;
	char read_char; int read_int;
	while (true) {
		read_char = 'X';
		while ( read_char != 'B' && read_char != 'D' ) {
			cout << "Quiere colocar un barco (B) o disparar (D)? >> ";
			cin >> read_char;
		}
		if ( read_char == 'B' ) {
			Barco nuevo_barco;
			cout << "Inserte las coordenadas del barco [A-J][1-10]: ";
			cin >> read_char >> read_int;
			nuevo_barco.posicion.letra = read_char;
			nuevo_barco.posicion.numero = read_int;
			cout << "Inserte el tipo de barco [1-4]: ";
			cin >> read_int;
			nuevo_barco.tipo = read_int;
			cout << "Inserte la direccion en la que quiere insertarlo [h|v]: ";
			cin >> read_char;
			nuevo_barco.direccion = read_char;
			if (juego.colocar(nuevo_barco))
				cout << "Barco colocado satisfactoriamente. Asi queda el tablero:" << endl;
			else
				cout << "Ha habido un error colocando el barco. El tablero se queda igual:" << endl;
			juego.mostrar( true );
		} else if ( read_char == 'D' ) {
			Punto disparo;
			cout << "Inserte las coordenadas de donde quiere disparar [A-J][1-10]: ";
			cin >> read_char >> read_int;
			disparo.letra = read_char;
			disparo.numero = read_int;
			string estado = transcribir_mensaje(juego.disparar(disparo), false);
			juego.mostrar( true );
			cout << ">> MENSAJE: " << estado << endl;
		}
	}
}
