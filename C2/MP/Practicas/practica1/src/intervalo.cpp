/**
 * @file intervalo.cpp
 * @author MP - DGIM - Grupo A, Ana Martínez Sabiote
**/


#include <iostream>
#include <cmath>
#include <assert.h>
#include "intervalo.h"

using namespace std;

bool Intervalo::validar(double cinf, double csup, bool cerradoinferior, bool cerradosuperior)
{
	bool comprobador = false;
	if (cinf < csup)
		comprobador = true;
	if ((cinf == csup) && (cerradoinferior == cerradosuperior))
		comprobador = true;
		
	return comprobador;
}

Intervalo::Intervalo()
{
	cotaInf=0;
	cotaSup=0;
	cerradoInf = false;
	cerradoSup = false;
}

Intervalo::Intervalo(double cinf,double csup)
{
	assert (validar(cinf,csup, true, true));
	cotaInf = cinf;
	cotaSup = csup;
	cerradoInf = true;
	cerradoSup = true;
}

Intervalo::Intervalo(double cinf, double csup, bool cerradoinferior, bool cerradosuperior)
{
	assert (validar(cinf,csup, cerradoinferior, cerradosuperior));
	cotaInf = cinf;
	cotaSup = csup;
	cerradoInf = cerradoinferior;
	cerradoSup = cerradosuperior;
}

double Intervalo::getCotaInf()const
{
	return cotaInf;
}

double Intervalo::getCotaSup()const
{
	return cotaSup;
}

bool Intervalo::esCerradoInf()const
{
	bool comprobador=false;
	if ( cerradoInf == true)
		comprobador=true;
	
	return comprobador;
}

bool Intervalo::esCerradoSup()const
{
	bool comprobador=false;
	if ( cerradoSup == true)
		comprobador=true;
	
	return comprobador;
}

bool Intervalo::esVacio() const
{
	bool comprobador=false;
	if ((cotaInf == cotaSup) && (cerradoInf==false) && (cerradoSup==false))
		comprobador=true;
		
	return comprobador;
}

bool Intervalo::estaDentro(double num) const
{
	bool comprobador=false;
	if ((getCotaInf()<num && getCotaSup()>num) || (esCerradoInf()==true && cotaInf==num)||(esCerradoSup()==true && cotaSup==num))
		comprobador=true;
	return comprobador;
}

///Funciones auxiliares clase intervalo

/** 
* @brief Imprime los valores de un intervalo de forma visual según lo indicado en el guión
* @param i El intervalo
*/
void escribir(const Intervalo & ab)
{
	if (ab.esCerradoInf() == true)
		cout<<"[";
	if (ab.esCerradoInf() == false)
		cout <<"(";
	cout<<ab.getCotaInf()<<","<<ab.getCotaSup();
	if (ab.esCerradoSup() == true)
		cout<<"]";
	if (ab.esCerradoSup() == false)
		cout<<")";
	cout<<endl;	
}

/** 
* @brief Lee los valores del intervalo según el formato indicado en el guión
* @param i El intervalo
*/
void leer(Intervalo & ab)
{
	//Formato de lectura del intervalo [ ó ( a,b ] ó )
	char car;
	char coma;
	char cor;
	double cotainferior;
	double cotasuperior;
	bool cerradoinferior;
	bool cerradosuperior;
	
	cin>>car>>cotainferior>>coma>>cotasuperior>>cor;
	
	if (car == '[')
		cerradoinferior = true;
	if (car == '(')
		cerradoinferior = false;
		
	if (cor == ']')
		cerradosuperior = true;
	if (cor == ')')
		cerradosuperior = false;
		
	Intervalo unintervalo(cotainferior,cotasuperior,cerradoinferior,cerradosuperior);
	ab=unintervalo;	
		
}

 
