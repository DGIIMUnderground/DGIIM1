#include "mates.h"

using namespace std;

void print_cos(float valor){
   float local;

   local=valor*M_PI/180.0;
   cout << endl;
   cout << "cos\(" << valor << ")=" << cos(local);
   cout << endl;
}
