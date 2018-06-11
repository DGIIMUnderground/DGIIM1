//EXAMEN DE SEPTIEMBRE DE 2017

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Hora{
	int hh;
	int mm;
	
	bool operator>(const Hora& horita) const;
	bool operator>=(const Hora& horita) const;
	bool operator<=(const Hora& horita) const;
	bool operator==(const Hora& horita) const;
};

bool Hora::operator>(const Hora& horita) const{
	bool resultado = false;
	
	if((*this).hh > horita.hh)
		resultado = true;
	else
		if((*this).hh == horita.hh && (*this).mm > horita.mm)
			resultado = true;
	return resultado;
}

bool Hora::operator>=(const Hora& horita) const{
	return (hh > horita.hh || (hh == horita.hh && mm >= horita.mm));	
}

bool Hora::operator<=(const Hora& horita) const{
	return !((*this)>horita);
}

bool Hora::operator==(const Hora& horita) const{
	return (hh == horita.hh && mm == horita.mm);
}

//----------------------------------------------------------------------

class Turista{
	friend class Grupoturista;
	private:
		char* nombre;													//Cadena-C reservada dinámicamente para nombre y apellido
		char* id;														//Cadena-C reservada dinámicamente para DNI o pasaporte
		int nacionalidad;												//Código de nacionalidad (por ej. código telefónico)
		
		void liberarmemoria();
		void reservarmemoria(int n1, int n2);
		void copiar(const Turista& turista);
	public:
		Turista();
		Turista(const Turista& turista);
		~Turista();
		Turista& operator=(const Turista& turista);
		Turista operator+(const Turista& turista) const;
		bool operator==(const Turista& turista) const;
		
		friend ostream& operator<<(ostream& flujo, const Turista& turista);
		friend istream& operator>>(istream& flujo, Turista& turista);
};

void Turista::liberarmemoria(){
	nacionalidad = 0;
	delete [] nombre;
	nombre = 0;
	delete [] id;
	id = 0;
}

void Turista::reservarmemoria(int n1, int n2){
	nombre = new char[n1];
	id = new char[n2];
}

void Turista::copiar(const Turista& turista){
	reservarmemoria( strlen(turista.nombre)+1, strlen(turista.id)+1 );
	
	strcpy(turista.nombre,(*this).nombre);
	strcpy(turista.id,(*this).id);
	nacionalidad = turista.nacionalidad;
}

Turista::Turista(){
	nombre = 0;
	id = 0;
	nacionalidad = 0;
}

Turista::Turista(const Turista& turista){
	copiar(turista);
}

Turista::~Turista(){
	(*this).liberarmemoria();
}

Turista& Turista::operator=(const Turista& turista){
	copiar(turista);
	return (*this);
}

Turista Turista::operator+(const Turista& turista) const{
	Turista mi_turista;
	mi_turista.reservarmemoria(strlen(nombre) + strlen(turista.nombre) + 2, strlen(id) + strlen(turista.id) + 2);
	
	for(int i=0; i<strlen(nombre); i++)
		mi_turista.nombre[i] = nombre[i];
	mi_turista.nombre[strlen(nombre)] = ' ';
	for(int i=0; i<strlen(turista.nombre); i++)
		mi_turista.nombre[i+strlen(nombre)] = turista.nombre[i];
	mi_turista.nombre[strlen(turista.nombre)] = '\0';
	
	for(int i=0; i<strlen(id); i++)
		mi_turista.id[i] = id[i];
	mi_turista.id[strlen(id)] = ' ';
	for(int i=0; i<strlen(turista.id); i++)
		mi_turista.id[i+strlen(id)] = turista.id[i];
	mi_turista.id[strlen(turista.id)] = '\0';
	
	mi_turista.nacionalidad = nacionalidad + turista.nacionalidad;
	return mi_turista;
}

bool Turista::operator==(const Turista& turista) const{
	return (strcmp(nombre,turista.nombre) == 0 && strcmp(id,turista.id) == 0 && nacionalidad == turista.nacionalidad);
}

ostream& operator<<(ostream& flujo, const Turista& turista){
	for(int i=0; i<strlen(turista.id); i++)
		flujo << turista.id[i];
	flujo << endl;
	
	for(int i=0; i<strlen(turista.nombre); i++)
		flujo << turista.nombre[i];
	flujo << endl;

	flujo << turista.nacionalidad;
	
	return flujo;
}

istream& operator>>(istream& flujo, Turista& turista){
	turista.liberarmemoria();
	
	flujo >> turista.id >> turista.nombre >> turista.nacionalidad;
	return flujo;
}

//----------------------------------------------------------------------

class Grupoturista{
	friend class Reservagrupos;
	private:
		Turista *turistas;												// Vector dinámico con los turistas del grupo
		int nturistas;													// Número de turistas en el grupo
		Hora hora;														// Hora de reserva del grupo
		
		void liberarmemoria();
		void reservarmemoria(int n);
		void copiar(const Grupoturista& grupo);
	public:
		Grupoturista();
		Grupoturista(const Grupoturista& grupo);
		~Grupoturista();
		inline Hora Gethora() const;
		Grupoturista& operator=(const Grupoturista& grupo);
		Grupoturista operator+(const Grupoturista& grupo) const;
		bool operator==(const Grupoturista& grupo) const;
		
		friend ostream& operator<<(ostream& flujo, const Grupoturista& grupo);
		friend istream& operator>>(istream& flujo, Grupoturista& grupo);
};

void Grupoturista::liberarmemoria(){
	for(int i=0; i<nturistas; i++)
		turistas[i].liberarmemoria();
	delete [] turistas;
	turistas = 0;
	nturistas = 0;
	hora.hh = hora.mm = 0;
}

void Grupoturista::reservarmemoria(int n){
	turistas = new Turista[n];
}

void Grupoturista::copiar(const Grupoturista& grupo){
	reservarmemoria(grupo.nturistas);

	turistas = grupo.turistas;
	nturistas = grupo.nturistas;
	hora.hh = grupo.hora.hh;
	hora.mm = grupo.hora.mm;
}

Grupoturista::Grupoturista(){
	turistas = 0;
	nturistas = 0;
	hora.hh = hora.mm = 0;
}

Grupoturista::Grupoturista(const Grupoturista& grupo){
	copiar(grupo);
}

Grupoturista::~Grupoturista(){
	(*this).liberarmemoria();
}

inline Hora Grupoturista::Gethora() const{
	return hora;
}

Grupoturista& Grupoturista::operator=(const Grupoturista& grupo){
	copiar(grupo);
	return (*this);
}

Grupoturista Grupoturista::operator+(const Grupoturista& grupo) const{
	Grupoturista grupito;
	grupito.reservarmemoria(nturistas + grupo.nturistas);
	
	for(int i=0; i<nturistas + grupo.nturistas; i++)
		grupito.turistas[i] = turistas[i] + grupo.turistas[i];
		
	grupito.nturistas = nturistas + grupo.nturistas;
	grupito.hora.hh = hora.hh + grupo.hora.hh;
	grupito.hora.mm = hora.mm + grupo.hora.mm;
	
	return grupito;
}

bool Grupoturista::operator==(const Grupoturista& grupo) const{
	bool correcto=false;
	
	if(nturistas == grupo.nturistas && hora == grupo.hora){
		for(int i=0; i<nturistas; i++)
			if(turistas[i] == grupo.turistas[i])
				correcto = true;
	}
	return correcto;
}

ostream& operator<<(ostream& flujo, const Grupoturista& grupo){
	flujo << grupo.nturistas << endl;
	for(int i=0; i<grupo.nturistas; i++)
		flujo << grupo.turistas[i] << endl;
	flujo << grupo.hora.hh << grupo.hora.mm;
	return flujo;
}

istream& operator>>(istream& flujo, Grupoturista& grupo){
	grupo.liberarmemoria();
	flujo >> grupo.nturistas;
	grupo.reservarmemoria(grupo.nturistas);
	
	for(int i=0; i<grupo.nturistas; i++)
		flujo >> grupo.turistas[i];
	flujo >> grupo.hora.hh >> grupo.hora.mm;
	return flujo;
}

//----------------------------------------------------------------------

class Reservagrupos{
	private:
		Grupoturista* grupos; 											// Vector dinámico con los grupos de turistas
		int ngrupos;													// Número de grupos con reserva
		
		void liberarmemoria();
		void reservarmemoria(int n);
		void copiar(const Reservagrupos& reserva);
	public:
		Reservagrupos();
		Reservagrupos(const Reservagrupos& reserva);
		~Reservagrupos();
		inline int Getngrupos() const;
		inline Grupoturista Getgrupos(int n) const;
		inline Grupoturista* Getgrupos() const;
		bool Eliminarreserva(const Hora& horita);
		bool Eliminarreservaentre(const Hora& h1, const Hora& h2);
		void Ordenar();
		Reservagrupos& operator=(const Reservagrupos& reserva);
		Reservagrupos operator+(const Reservagrupos& reserva) const;
		Grupoturista& operator[](int i);
		Grupoturista& operator[](int i) const;
		bool operator==(const Reservagrupos& reserva) const;
		
		friend ostream& operator<<(ostream& flujo, const Reservagrupos& reserva);
		friend istream& operator>>(istream& flujo, Reservagrupos& reserva);
		friend bool Cargar(const char* fichero, Reservagrupos& reserva);
		friend bool Salvar(char* fichero, const Reservagrupos& reserva);
};

void Reservagrupos::liberarmemoria(){
	if(grupos != 0){
		for(int i=0; i<ngrupos; i++)
			grupos[i].liberarmemoria();
		delete [] grupos;
		grupos = 0;
	}
	ngrupos = 0;
}

void Reservagrupos::reservarmemoria(int n){
	grupos = new Grupoturista[n];
}

void Reservagrupos::copiar(const Reservagrupos& reserva){
	reservarmemoria(reserva.ngrupos);
	
	grupos = reserva.grupos;
	ngrupos = reserva.ngrupos;
}

Reservagrupos::Reservagrupos(){
	ngrupos = 0;
	grupos = 0;
}

Reservagrupos::Reservagrupos(const Reservagrupos& reserva){
	copiar(reserva);
}

Reservagrupos::~Reservagrupos(){
	(*this).liberarmemoria();
}

inline int Reservagrupos::Getngrupos() const{
	return ngrupos;
}

inline Grupoturista Reservagrupos::Getgrupos(int n) const{
	return grupos[n];
}

inline Grupoturista* Reservagrupos::Getgrupos() const{
	return grupos;
}

bool Reservagrupos::Eliminarreserva(const Hora& horita){
	bool comprobar=false;
	int tamano=ngrupos;
	
	for(int i=0; i<ngrupos; i++)
		if(horita == grupos[i].hora)
			tamano--;
	
	Grupoturista* aux = new Grupoturista[tamano];
	
	for(int i=0; i<tamano; i++)
		if(horita == grupos[i].hora){
			aux[i] = grupos[i];
			comprobar=true;
		}
	
	delete [] grupos;
	grupos = aux;
	aux = 0;
	
	return comprobar;
}

bool Reservagrupos::Eliminarreservaentre(const Hora& h1, const Hora& h2){
	bool comprobar=false;
	int tamano=ngrupos;
	
	for(int i=0; i<ngrupos; i++)
		if(grupos[i].hora >= h1 && grupos[i].hora<=h2)
			tamano--;
			
	Grupoturista* aux = new Grupoturista[tamano];
	
	for(int i=0; i<tamano; i++)
		if(grupos[i].hora >= h1 && grupos[i].hora<=h2){
			aux[i] = grupos[i];
			comprobar=true;
		}
		
	delete [] grupos;
	grupos = aux;
	aux=0;
	
	return comprobar;	
}

void Reservagrupos::Ordenar(){
	Grupoturista aux;
	for(int i=0; i<ngrupos; i++)
		for(int j=0; j<ngrupos-1; j++)
			if(grupos[j].hora > grupos[j+1].hora){
				aux = grupos[j];
				grupos[j] = grupos[j+1];
				grupos[j+1] = aux;
			}
}

Reservagrupos& Reservagrupos::operator=(const Reservagrupos& reserva){
	copiar(reserva);
	return (*this);
}

Reservagrupos Reservagrupos::operator+(const Reservagrupos& reserva) const{
	int contador=ngrupos;
	
	for(int i=0; i<reserva.ngrupos; i++)
		if(!(grupos[i] == reserva[i]))
			contador++;
			
	Reservagrupos resultado;
	resultado.ngrupos = contador;
	resultado.reservarmemoria(contador);
	
	for(int i=0; i<ngrupos; i++)
		resultado[i] = grupos[i];
		
	for(int i=0; i<reserva.ngrupos; i++)
		if(!(grupos[i] == reserva[i]))
			resultado[ngrupos+i] = reserva[i];
	return resultado;
}

Grupoturista& Reservagrupos::operator[](int i){
	return grupos[i];
}

Grupoturista& Reservagrupos::operator[](int i) const{
	return grupos[i];
}

bool Reservagrupos::operator==(const Reservagrupos& reserva) const{
	bool resultado=false;
	if(ngrupos == reserva.ngrupos)
		for(int i=0; i<ngrupos; i++)
			if(grupos[i] == reserva.grupos[i])
				resultado = true;
	return resultado;
}

ostream& operator<<(ostream& flujo, const Reservagrupos& reserva){
	flujo << reserva.ngrupos << endl;
	for(int i=0; i<reserva.ngrupos; i++)
		flujo << reserva.grupos[i] << endl;
	return flujo;
}

istream& operator>>(istream& flujo, Reservagrupos& reserva){
	reserva.liberarmemoria();
	
	flujo >> reserva.ngrupos;
	reserva.reservarmemoria(reserva.ngrupos);
	
	for(int i=0; i<reserva.ngrupos; i++)
		flujo >> reserva.grupos[i];
	return flujo;
}

bool Cargar(const char* fichero, Reservagrupos& reserva){
	bool exito = false;
	char primera[24];
	
	ifstream fentrada;
	fentrada.open(fichero);
	exito = fentrada;
	if(exito){
		fentrada >> primera;
		if(strcmp(primera,"RESERVASGRUPOS-ALHAMBRA") == 0){
			fentrada >> reserva;
			exito = true;
		}else
			cerr << "Se ha producido un fallo en la lectura del fichero " << fichero << endl;
	}else
		cerr << "Se ha producido un fallo en la apertura del fichero " << fichero << endl;
	
	fentrada.close();
	return exito;
}

bool Salvar(char* fichero, const Reservagrupos& reserva){
	bool exito=false;
	
	ofstream fsalida;
	fsalida.open(fichero);
	exito = fsalida;
	if(exito){
		fsalida << "RESERVASGRUPOS-ALHAMBRA" << endl;
		fsalida << reserva;
		exito = true;
	}else
		cerr << "Se ha producido un fallo en la apertura del fichero " << fichero << endl;
	
	fsalida.close();
	return exito;
}

//----------------------------------------------------------------------

int main(int narg, char* argv[]){
	if(narg!=4){
		cerr << "Error en el número de argumentos";
		return 1;
	}
	
	Reservagrupos reservita1, reservita2;
	
	if( !(Cargar(argv[1],reservita1) && Cargar(argv[2],reservita2))){
		cerr << "Error en la carga de ficheros";
		return 2;
	}
	
	Reservagrupos reservita3;
	reservita3 = reservita1 + reservita2;
	
	Hora h1, h2;
	h1.hh = 12; h1.mm = 0;
	h2.hh = 13; h2.mm = 30;
	reservita3.Eliminarreservaentre(h1,h2);
	
	reservita3.Ordenar();
	Salvar(argv[3],reservita3);
	
	return 0;
}
