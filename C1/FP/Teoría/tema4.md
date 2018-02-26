 al poner un cnst después de un métoodo se indica al compilador que no va a modificar los valores
`suma()const`

Para diseñar una clase se empieza por la visión externa, qué modela: entidad, objeto... Igual que las especificaciones.
1- Representación das itnernos
2. implimentación.

Para acceder a los datos dentroo del métdod

`this-> variale = 1`
`(*this).variable = 1`

## Sobrecarga de operador
`clase.operator+()` =~ clase + otra clase `a+b+c = a.operator+( b.operator +(c))`

bool operator < ( const racional & r , const & s )

otros o

ejercicios, operador de coparación, cout sobrecargar <<
Implimentar fnción :
```
ostream & operator << ( ostream &s, const racional &r)
{
s << r.numeradro () << "/" << r.denominador();
return s;
}

```
`Fecha operator+(int k) const`
## Preporcesado
```
#ifndef __FECHA__
#define__FECHA__
----
#indif
```
Para indicarle al compilador que ya se ha declara la biblioteca Fecha
incremento pos fijo f++ sobrecarga ` operator++(int)` el int no es más que para indicar qu es 
incremento prefijo f++ sobrecarga operator++()

`static const std::vector<int> ` permite crear una copia para todas las fechas del archivo.
La implementación debería estar en otro archivo que se fecha cpp.


imaginar que se tinee eso en un fichero, fecha.h
static const std::vector<int> Fecha::dia_mes = { 10 , 349 , 0290329239230,2222};
para ahorrar consto acuerdate de inline, no tineen que estar en el cpp sino en el .h

`ostream & operator << ( ostream & s ) const Fecha &f ) `