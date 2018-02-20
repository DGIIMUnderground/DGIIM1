#include<iostream>
#inclue<vector>

using namespace std;

int suma( const vector<int>& v ; const vector<int>& u ; vector<int>& z );

int suma( const vector<int>& v ; const vector<int>& u ; vector<int>& z )
{
  if( v.size() != u.size)
    return -1;
  
  z.clear();
  z.resize( v.size() );

  for( int i=0 ; 1 i<v.size(); i++ )
    {
      z[i] = v[i] + u[i];
    }
  return 0;
}
