/*
Paula Villanueva Núñez

ENUNCIADO
Represente gráficamente la disposición en memoria de las variables del
programa mostrado a continuación, e indique lo que esribe la última
sentencia de salida.
*/

#include <iostream>
using namespace std;

struct Celda{
  int d;
  Celda *p1, *p2, *p3;
};

int main (int argc, char * argv [ ]){
  Celda a, b, c, d;

  a.d = b.d = c.d = d.d = 0;

  a.p1 = &c;
  c.p3 = &d;
  a.p2 = a.p1->p3;
  d.p1 = &b;
  a.p3 = c.p3->p1;
  a.p3->p2 = a.p1;
  a.p1->p1 = &a;
  a.p1->p3->p1->p2->p2 = c.p3->p1;
  c.p1->p3->p1 = &b;
  (*((*(c.p3->p1)).p2->p3)).p3 = a.p1->p3;
  d.p2 = b.p2;
  (*(a.p3->p1)).p2->p2->p3 = (*(a.p3->p2)).p3->p1->p2;

  a.p1->p2->p2->p1->d = 5;
  d.p1->p3->p1->p2->p1->p1->d = 7;
  (*(d.p1->p3)).p3->d = 9;
  c.p1->p2->p3->d = a.p1->p2->d - 2;
  (*(c.p2->p1)).p2->d = 10;

  cout << "a=" << a.d << " b=" << b.d << " c=" << c.d << " d=" << d.d << endl;
}

/*
RESULTADO:
a.d = 5
a.p1 = &c
a.p2 = &d
a.p3 = &b

b.d = 7
b.p1 = &b
b.p2 = &c
b.p3 = &c

c.d = 10
c.p1 = &a
c.p2 = &b
c.p3 = &d

d.d = 5
d.p1 = &b
d.p2 = &c
d.p3 = &d
*/
