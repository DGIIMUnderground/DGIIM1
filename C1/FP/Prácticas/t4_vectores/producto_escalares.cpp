#include<iostrem>
#inlude<vector>

void producto_escalar( int escalar ; vector<int>& v)
{
	vector<int> z(v);
	for( auto x : z ) //iterador para recorrer una estructura, auto palabra reservada, definir tipo dato variable sin indicar el tipo de dato,
	     x = x * escalar;

	 return 0;

}

int main ()
{

  vector<int>v(10);
  for( int i = 0; i < 10)
    
  return 0;
}
