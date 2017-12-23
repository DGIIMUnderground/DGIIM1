#include <iostream>
#include <string>
using namespace  std;

int main()
{
  string tiempo = "Hoy ha sido un gran ";
  string mas;

  cout << " ¿Qué es hoy? \n";
  
  getline(cin,mas);

  string s = tiempo + mas;
  cout << s << endl;

  cout << "¿Qué varias cosas no es Hoy?" << endl;

  string verdades;

  getline( cin , verdades );

  int i = verdades.find( ' ' );
  verdades.erase( 0, i);
  
  cout << " A, NO, espera, en verdad quería decir: " << tiempo + verdades << endl;

  i = verdades.find( ' ');
  if ( i == std::string::npos)
    {
      
    }
    verdades.insert()
      
  cout << " A, NO, espera, en verdad quería decir: " << tiempo + verdades << endl;
}
