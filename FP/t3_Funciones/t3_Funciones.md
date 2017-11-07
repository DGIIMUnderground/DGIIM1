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
