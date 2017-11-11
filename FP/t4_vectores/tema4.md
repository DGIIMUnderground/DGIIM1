## Tema 4 vectores y matrices
*no confundir vectores con array el array es estático mientras que los vectores dinámicos*
Vectores: tipo dato estructurado homogéneo, compuesto por más de un componente, cuyo tamaño puede variar durante la ejecución.
Para declararlos (este tipo de vector es una clase, qeu tiene operaciones y construcctores)
inicializar la c
```
#include <vector>
using std::vector; //de la biblioteca std utilizo vectores sin necesitar de los otros 
vector< tipo_base> identificador; //este vector es de tamaño 
vector< tipo_base> identificador(tamaño);
vector< tipo_base> identificador(tamaño , valor_inicial); //todos las componentes tienen el valor inicial

vector<int> u = { 1 , 2 , 3 ,5 };
vector<int> v(u); //constructor de compia
vector<int> v = u; //constructori primitivo
vector<int> &v = u; 
```
para acceder:
`nombre_vector[índice] `
para hacerlo más seguro `nombre_vector.at(índice)` si el índice se sale de rango se sale de programa, antes de entrar comprueba si está bien y suma un coste de tiempo, y el modo de gestionar los errores no es el más correcto.


funciones inline: en vez de hace una llamada a fución lo inserte en la línea, reempla el código, si el código es mjuy constoso no lo hace,
a parte necesita conocer también el cuerpo

## Propiedades
nombre_vectori.size()		// para saber el tamaño de una variable, núemero que puedo almacenar
empty() 	      		// si es vacío tipo booleano
capacity() 	      		// la capacidad máxima que tiene un vector, ya qeu el compilador te asigna más de lo que pides
ejemplos:
```
vector<int>v ;  // size 0 ; capacity depende del compilador, por lo general 10
////////////////
v.size()	 // decuelve 5
v.resize(10)	 // amplio su capacidad
v.size() 	 // devuelve 5, porque no se le han añadido valores nuevos
v.capacity 	 // devolvería 10 porque ya hemos ampliado su valor 
```

### Manipular vectores 
vector.clear() 	      		//  libera todo el espacio del vector, tamañado de memoria
vector.resize( tamaño nuevo)	// nuevo tamño del vector, amplia o reduce

### Gestión de espacio
```
 max_size //máxima capacidad
 reserve // reserva tamño
 push_back( valor_nuevo) //se añade el dato al final del vector, su tamaño se ampliaría si ya estuviera lleno reservando una dirección de memoria y copiando los otros y suele reservar más espacios de los qeu tiene;
 pop_back() // elimina el ultimo elemento no reasigna el espacio a no ser que esté muy reducido
 insert
```

```
int suma ( const vector<int> & v , const vector <int> & u , vector<int>& z )
// ojo a la declaración const vector <int>& v: paso una referencia, solo pasa la dirección de memoria y no copia el vectori entero, pero lo pongo como const para que no se pueda modificar
// en caso del vector z si nos interesa modificarlos
```
### Almacenamiento
el compialdor busca un espacio para el que coa el vector, un entero tiene 4 bytes,   la implementación subyacente a los vectores es de tipo array, si no se le dice que creazco o no se utiliza igual

### Devolver en una función un vector
```
int suma ( const vector<int> & v , const vector <int> & u)
{
	vector<int> z( v.size());
	for( int i ; i v.size(); i++ )
	     z[i] = v[i] + u[i];
  return z;
}

c = suma( a , b ); // ahora el dato l reserva y se lo pasa a c,  antes  conste en el proceso, se copiaba, semántica de copia de datos, ahora 
```
Ahora se pueden tener dos valores con el mismos nombre, con la firma de la función, los parámetros que la define, en el número que lo define
ese error se llama sobrecarga de identificadores

```
void producto_escalar( int escalar ; vector<int>& v)
{
	vector<int> z(v);
	for( auto x : z ) //iterador para recorrer una estructura, auto palabra reservada, definir tipo dato variable sin indicar el tipo de dato,
	     x = x * escalar;

	 return 0;

}
```