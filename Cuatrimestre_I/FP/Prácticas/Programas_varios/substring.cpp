#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s = "Holaa señor daniel";
  string a = s.substr( 6 , 5);
  cout << s << endl;
  cout << a << endl;
  s.replace( 6 , 5 , "señoritaaaaaaaaaaa");

  int i = s.find("señorito");
  if ( i == string::npos)
    cout << "Dani no es n señorito"<< endl;
  cout << s << endl;
}
