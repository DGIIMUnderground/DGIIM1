## Tema 3 Funciones y clases
### Funciones
 - * C++ programminf: Program desing including data strctuutes* D.S Malik
 - * Metodología de la programación* Antonio Garrrido
 - github cppCoreGuidelines

#### Paradigma de programación estructurada
Construir soluciones
- subrutinas: Parte del programa que hace una parte del programa y es reutilizable
- estructuras de selección
- iteración
(Niclous Wirth *Algoritmo +estructura de datos = Programas)

### Paradigma de programación modular  
Divide programa en módulos y subprogramas (divide y vencerás) nos lleva a la descomposión progresivas de problemas.
Un módulo es cada uno de la partes del programa que descompone un programa, esta está hecha de un modo coherente
Entre ella se encuentra la POO

### Funciones
Una función es una subrutrina,
permite la reutilización y el mantenimiento, para corregir errores de tipo lógico
Estructura de una función
```
/*Declacracin o cabecera
<tipos de dato > <nombre de la función >(<parámetos formales>)
{
	/*cuerpo*/
}
```

versión interesante de la función main

```
int main (int argc , char ++ args)
```
una función sin arguentos de retorno es un **procedimiento**
el main de una función solo sabe la cabecera, el tipo y el arguento que recibe.

## Tipos de variables

- Las variables globales se declaran fuera del bucle main
- `extern int i` declaro una función que aún no he declarado pero que la utilizaré
- `static int i` cuando una variabe global la precede valor, conserva el valor entre llamadas.  /
-  `static int i ` dentro de un un fichero, cisible dentro de tadas las funciones, todos las funciones las ven, en otros fichero no.
- Paso de argumentos por valor o por copia:
  - por **valor o por copia**: la llamada de la función se copia en el argumento de la función, no se modifica al salir de la función.
  - por **referencia o variable**, para alterar el valor de los parámetros, los arguemuento se declaran de la siguiente manera ` int & i`
  Ejemplode uso, para intercambiar valores de una función, paso de parámetros de 
  ```cpp
  void intercambio( int & x , int & y)
  {
	int aux = x;
	x = y;
	y = x;
  }
  int main()
  {
	int a,b;
	(...)
	intercambio(a,b) //intercambia el valor de las variables
	return 0;
  }

  
  ```
  Hay que terner cuidado con los sigietes casos, generan errores:
  ``` intercabio (2+1 , 3)
  const int siete=2; intercamio(q, siete)
  ```
 Se pasa la drección, lo cual es mucho más eficiente en tamaño, para variables muy grandes, se tarda más, ejemplo para utilizarlo
 ejmplo
 
 ```
 int has algo(const T & VARIABLE MUY GRANDE) //donde T es un tipo de variable MUYYYY grande
 ```
 
Es posible que en otro ámbitos se utilice el paso por referencia,
- **tipo de dato referencia**
```
int & z = x // define un nombre alternativo para z
```

## Especiificación de las funciones
Especificación desccripción sin indicaciones sobre la forma de implementar una función,
- Precondicines: conjuntonto de condiciones necesarias y suficietes para que se comporte la función.
- Postcondición

Debe ser: útil, completa y deben apareces: requeiseitos, efects y elementos modificados
ejempo: `doble squrt  (double x)` sabe que devuelve y que entra
Para explicar lo que hace se utilizan las especficaciones:
Para ello eiste la función * DOXYGEN*: para ello seguir:
```
@brief Para escribir en una frase lo que hace
@param <variable>: hay un parametro <variable> explicarems que significa, vg *valor del que calculamos la raiz cuadrada. x >= 0* (he indicado los requisitos que necesita, esto lo sabe el usuario al utilizarlo, las implicaciones, son que si no las cumples, no tiene responsabilidad)
@
```
ejemplo real:

```
/**
@brief calcula el factorial de un número
@param n: valor cuyo factorial se calcula n>= 0
@reurn n!
*/
int factorial
```

otro
```
/**
@brief Intervambia el valor de dos varobeles
@param a: primera variables. ES MODIFICADO
@param b: la segunda variable. ES MODIFICADO
Intercambia los valores de a y b

*/
void intercambia( int& a , int& b)
```

ejmplo 3
```
/**

*/
int raices (double a, double b, double c , double& x1 , double& x2 ) // a,b,c parso por valor; x1, x2 pro referencia el int es por las devuelta de las raíces

```

### Argumentos o parámetros por defecto
Si a un arguemnto no se le da un valor, este se indica de la siguiente manera:
` int funcion( int x = <entero por defecto>)`

Efercicio propuesto:
Operaciones basicas para el cáculo de número racionales Suma, diferencia y producto Diseñar, especifiquemos e implimentemos ; con el representante canónico