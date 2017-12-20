#include <iostream>
#include <string>

using namespace std;

bool Es_palindromo(const string & cadena)
{
	bool palindromo=true;
	
	for (int i=0; i<cadena.size()/2; i++)
	{
		if( cadena.at(i) != cadena.at( cadena.size()-1-i ) )
		{
			palindromo = false;
			break;
		}
	}
	
	return palindromo;
}

int main()
{
	string cosa;
	
	while (cosa != "0" )
	{
		cout << "Escriba una palabra (0 para salir): ";
		getline(cin, cosa); //como pedimos sólo una palabra en este caso también se pued eutilizar cin
		
		if ( Es_palindromo(cosa) )
		{
			cout << "ES palíndromo" << endl;
		}
		else
		{
			cout << "NO es palíndromo" << endl;
		}
	}
}
