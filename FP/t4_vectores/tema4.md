## Tema 4 vectores y matrices
*no confundir vectores con array el array es estático mientras que los vectores dinámicos*
Vectores: tipo dato estructurado homogéneo, compuesto por más de cun componente, cuyo tamaño puede variar durante la ejecución.
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
nombre_vectori.(size) // para saber el tamaño de una variable
empty() // si es vacío tipo booleano
capaticy() // la capacidad

### Gestión de espacio
- max_size //máxima capacidad
- reserve // reserva tamño
- push_back / añade dato al final del vetor
- pop_back // eliina el ultimo elemento
-  insert


### Almacenamiento
el compialdor busca un espacio para el que coa el vector, un entero tiene 4 bytes,   la implementación subyacente a los vectores es de tipo array, si no se le dice que creazco o no se utiliza ¡igual 