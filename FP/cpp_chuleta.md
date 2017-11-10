## CHULETA DE LO QUE VOY APRENDIENDO SOBRE C++ ENTRE LOS LIBROS QUE CONSULTO Y LAS ASIGNATURAS DE INFORMÁTICA

## Declaración de funciones
- Declaración `inline`: sugiere al compilador que copie el código de la función y lo reemplaze por cada llamada a la función, si el código no es muy extenso, esto supondría una optimización.
## Conversión de datos 
Conversión de tipos`static_cast<dataTypeName>(expresión) ` `static_cast<double>(25)`

## I/O Sream and Standard I/O Device
### Input y output

 Función                                | Utilidad                                       |Ejemplo    
  ---                                   | ---                                            | ---
 `istreamVar.get(varChar) `              | Lee un carácter                                | `cin.get(ch) `                         
 `istreamVar.ignore(intExp , chEx)`      | intExp: número de carácteres a ignorar <br>  chExp: caráceter a partir del cual deja <br> de ignorar.  Prevalece chExp    | `cin.ignore(100, '\n' ) `           
`istreamVar.putback(ch)`                | Incluye último carárcter                       |   
`ch = istreamVar.peek()`                | Devuelve el siguiente carácter sin quitarlo    |    
 `istreamVar.clear();`                  | Cuando hay un error de lectura, el<br>sitema ignora todos, esta función lo resaura    	 |`cin.clear()`                          
 ` getline(istreamVar , strVar) ` 	| Permite leer string que contengan espacios   	 | ` getline( cin , miString )`
 
[Código de ejemplo](https://github.com/BlancaCC/cultutrilla/blob/master/cpp_aprendizaje/ejemplosBasicos/input_output.cpp)

#### File input/output
Lee y escribe en fichero. Pasos a segir:
1. Include en la cabecera la biblioteca `#include<fstream>`
2. Declara las variables que contendrán al fichero y su dirección `ifstream inData` si es de entrada y `oftream outData` si es de escritura
3. Abre los ficheros `filestreamVariable.open("sourceName")` ejemplo:` inData.open("disk:\\fichero.txt")`
4. Lee y escribe en los ficheros con los operadores `<<`(escritura) y `>>` (lectura).
5. Cierra los ficheros `nombre.close()`

[Ejemplo de trabajo con fichero y de getline](https://github.com/BlancaCC/cultutrilla/blob/master/cpp_aprendizaje/ejemplosBasicos/fstream.cpp)

### Output and formating output


 Función                                | Utilidad						 |Ejemplo    
  ---                                   | ---                                           	 | ---
  `setprecition(<integer>)`		| número de decimales a utilizar, requiere *iomanip* 	 | `#include<iomanip> [omito código] cout<<setprecision(2)`
  fixed 				| vuelve al estandar  		  	   		 | `cout.unsetf(ios::fixed)`
 scientific 				| números decimales en formato científico 		 | ---
  showpoint				| supone que la perte decimal es cero, y así la muestra  | `cout << showpoint`
 setw 					| fija un tamaño específico de columnas	     		 | `cout << setw(5) << x << endl `
 flush 					| permite que todos los caracteres de un buffer se <br> escriban y limpia el buffer <br> hace lo mismo que endl pero sin saltar de línea	| ` cout << "holaaaa " << flush ; `
 `setfill(<character>)`			| sustituye los espacios 	      	 	   	| `cout << setfill(#); `
 `string ( <integer> , '<character'>)`	| Devuelve un string con <caracter> repetido <int> veces| `string(9999, 'a')`
 `ostreamVar << left ` or right	`	| alinea hacia la izquierda o hacia la derecha		| `cout << left `
 `cout.unsetf(manipulador)` 		| Desactiva un manipulador    	       			| `ostreamVar.unsetf(ios::left)`
 `getline(istreamVar , strVar )`	| Lee hasta que encuentra un salto de línea 		| `getline( cin , linea )`
 `<varialeIstream>.eof`	      		| Decuelve 1 se ha llega al final del fichero 		| `cpp_chuletilla.eof()`

[Código de ejemplo para output](https://github.com/BlancaCC/cultutrilla/blob/master/cpp_aprendizaje/ejemplosBasicos/output.cpp)

## Estrucutras de control
(Paso por alto las básicas, si a alguno le apetece hacerlas...)

### Operador condicional **( ? : )**
- Equivale a un if else.
- Sintaxis: ` <expresión1> ? <expresión2> : <expresion3>`
- Si se cumple la expresión 1 realiza la expresión 2, en caso contrario la 3.

Ejemplo súper molón de lal algoritmo de Euclides para calcular el mcd
```cpp
int Mcd( int a, int b )
{
   return (!b) ? a : Mcd( b , a % b);
}

```
### Bucle while para leer archivos
```cpp
while( ! cpp_chuletilla)
{
	cout << "Otra líne más, po si que ha escrito la niña esta " << endl;
	infile.get( linea);
}
```

## Funciones
Tipos de pasos de valores:
- Paso por parámetro hace una copia `void funcion (int hola) `
- Paso por **referencia** modifica el original `void funcion ( int& adios) `

## Variables, namespace, stringtypes

### enum
- Sirve para definir variables propias, empiezan a guardarse desde el 0, !!
- Sintaxis: `enum nombre = { valor1 , valor2 , valor99999 }`

#### Operaciones en enum
- Solo acepta suma y resta y lo que hace es coger el siguiente o el anterio elemento
- Se debe hacer con `static_cast`, sintaxis: `value = static_cast<nombre_enum>(variable_tipo_enun +- int)`
- Operadores ` < > <= >= ` compara posiciones

Ejemplo:
```cpp
int ejmploEnum()
{
  enum Z2 { cero , uno }; // declaro enum si fueran string se pondría sin ""

  Z2 a; // Declaro que a es un tipo de variable Z2

  a = cero;

  cout << " a vele:" << a << endl; //no escribirá la variable, sino la posición que ocupa en Z2

  a = static_cast< Z2 >( a + 1); //si sumas dos, no te dará error, pero carecerá de sentido ya que en Z2 no hay ningún otro elemento

    cout << " a vele:" << a << endl;
    
  return 0;
}

```

### typedef
- Crea un alias para una variable
- sintaxix: `typedef variableExistene nuevoNombre`
- ejemplo: `typedef int integer`

### Namespace
 Evita errores de sintaxis generados por dos variables que se llamen de la misma forma siendo uan global.
 #### Sintaxis
 ```cpp
  // para declarar el namespace
 namespace nombre_namespace 
 {
	miembros_del_namespace
	
 }

// para hacer referencia al namespace
nombre_namespace::identifcador

// Para ahorrase escribise nombre_namespoace::identificador

using namespace nombre_namespace; // incluye a todos los miembros
using nombre_namespace::miembro ; // para incluir un miembro concreto

```
[Ejemplo del namespace más detallado](https://github.com/BlancaCC/cultutrilla/blob/master/cpp_aprendizaje/ejemplosBasicos/namespace.cpp)

## Detecciones de errores

 Función			|  Descripción			| Ejemplo
 --- 				| --- 				| ---
 `assert ( expr) `			| Si una expresión es 0 termina el programa con un mesaje de error <br>necesita de la biblioteca `assert.h`

## Bibliografía

 Libro								| Autor		| Apreciaciones
 --- 								| --- 		| ---
 *C++ programing: Program desing including data structures* 	| D.S. Malik 	| Bien ejemplificado, nivel muy básico, recimendado como libro de iniciación
 cpp reference	  	  	 	   			| A saber quién escribirá eso | Muy útil para consultas puntuales
 