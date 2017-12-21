#include "mates.h"

using namespace std;

void print_sin(float valor){
   float local;

   local=valor*M_PI/180.0;
   cout << endl;
   cout << "sin\(" << valor << ")=" << sin(local);
   cout << endl;
}
