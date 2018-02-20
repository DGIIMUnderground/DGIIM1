#include <iostream>
#include <string>

using namespace std;

int main()
{
	string cadena;
	
	cout << "Escriba cosas: ";
	getline(cin, cadena);
	
	cout << "Cosas que ha escrito: " << cadena;
}
