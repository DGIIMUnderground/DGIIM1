#include <iostream>
#include <string.h>
using namespace std;

struct Electrica {
  char corriente[30];
  int voltios;
};

int main() {
  Electrica *p = new Electrica(), *q = new Electrica();
  strcpy(p->corriente,"ALTERNA");
  p->voltios = 12; q -> voltios = 14;
  *q = p;
  cout << p->corriente << " - " << p->voltios << endl;
  cout << q->corriente << " - " << q->voltios << endl;
}
