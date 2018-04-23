/*
Paula Villanueva Núñez

ENUNCIADO
Represente gráficamente la disposición en memoria de las variables del
programa mostrado a continuación, e indique lo que escribe la última
sentencia de salida. Tenga en cuenta que el operador -> tiene más
prioridad que el operador *.
*/

#include <iostream>
using namespace std;

struct SB; // declaración adelantada
struct SC; // declaración adelantada
struct SD; // declaración adelantada

struct SA {
  int dat ;
  SB *p1 ;
};

struct SB {
  int dat ;
  SA *p1 ;
  SC *p2 ;
};

struct SC {
  SA *p1 ;
  SB *p2 ;
  SD *p3 ;
};

struct SD {
  int *p1 ;
  SB *p2 ;
};

int main ( int argc , char * argv [ ] ){
  SA a;
  SB b;
  SC c;
  SD d;
  int dat;

  a.dat = b.dat = dat = 0 ;

  a.p1 = &b ;
  b.p1 = &a ;
  b.p2 = &c ;
  c.p1 = b.p1 ;
  c.p2 = &(*(a.p1)) ;
  c.p3 = &d;
  d.p1 = &dat;
  d.p2 = &(*(c.p1)->p1);
  *(d.p1) = 9;
  (*(b.p2)->p1).dat = 1;
  (*((b.p2)->p3->p2)->p1).dat = 7 ;
  *((*((*(c.p3->p2)).p2->p3)).p1) = (*(b.p2)).p1->dat + 5 ;
  cout << "a.dat=" << a.dat << " b.dat=" << b . dat << " dat=" << dat << endl ;
}

/*
RESULTADO
a.dat = 7
a.p1 = &b

b.dat = 0
b.p1 = &a
b.p2 = &c

c.p1 = &a
c.p2 = &b
c.p3 = &d

d.p1 = &dat
d.p2 = &b

dat = 12
*/
