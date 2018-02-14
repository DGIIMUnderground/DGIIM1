#include "mates.h"

using namespace std;

void print_tan(float valor){
   float local;

   local=valor*M_PI/180.0;
   cout << endl;
   cout << "tan\(" << valor << ")=" << tan(local);
   cout << endl;
}
