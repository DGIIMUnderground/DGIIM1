> Aquí encontrarás lo suficiente para que con un man seas la reina del mambo


## Comandillos útiles para utilizar en terminal  
-` C-l` limpiar terminal
- `clear` limpiar terminal
- Para cerrar al termial C-alt-w
- Cerrar una ventana que no sea la terminal `C-quit` y que no se haya abierto por medio de esa
-`./ <programa> & ` lo ejecuta en "backgraund", dejando disponible la terminal
- `xdg-open <archivo>` abre ese archivo con el programa predeterminado
- `source <nombre_guión> ` ejecuta órdenes de un fichero en el shell actual, de esta manera se guardarían las variables dentro del shell  

 
## Comados relacionados con archivos y direcctorios

 COMANDOS                        | FUNCIONES
 ---		 		 | ---
 **tr**[option].., SET1 	 | traduce o borra caracteres :)
 **awk**	   		 | escanea patrocenes y procesa lenguajes
 **ls**	 	    		 | lee los directorio
 **cd** 	     		 | cambia de directorio
 **ln** 			 | Cra enlaces simbólicos
 **pwd**	      		 | Imprime el camino absulo del direcctorio actual   
 **mkdir** Y **rmdir**  	 | rmdir -r borra si tienes también archivos dentro  
 **cat**     			 | lee el condtenido de un archivo  
 **mv  /<archivo1> <archivo2>**  | mueve un archivo    
 **file** 	   		 | muestra el tipo de archivo.  
 **more** **pager**  **pg**  	 | visualiza un archivo fraccionándolo en la pantalla cada vez.  
 **rm**   	     		 | borra DEFINITIVAMENTE un archivo/directorio
 **touch**			 | modifica fecha y hora de un archivo, si no los crea  
 **clear** 			 | borra el contenido de la terminal actual
 **tail** -<entero> <archivo> 	 | muestra las líneas finales de un fichero  
 **head** -/<entero>/ <archivo>  | muestras las "numero de líneas iniciales de un fichero.  
 **sort** <archivo>   		 | ordena bajo un critero elegido las líneas de un archivo.  
 **wc**   			 | cuenta el número de algo de un fichero 
 chmod [ugoa][+-=][rwx]dir/file  | Cambio a los permisos de un archivo o direcctorio	 
 **echo** 			 | escribe un mensaje en termminal  
 `alias <nombre>='<ódener>' `	 | Definir comportamiento de una orden, sin argumentos, ves los alias creados,
 `unalias 		    	 | Borrar un alias
 `\alias`			 | Para ignorar un alias y ejecutar la orden original
 **printf ** 			 | muestra en el bash lo que se especifique 
 **sleep** <segundos>		 | Produce una pausa de los segundos introducidos como argumentos	 
 --- 	  			 | ---

- código de formato para print 
``` 
  - %d número con signo  
  - %f  número en coma flotante  
  - %q entrecomilla una cadena  
  - %s muestra una cadena sin entrecomillar  
  - %x núemero en hexadecimal  
  - %o número en octal
```
- Ejemplo: 
```bash
blanca@debian:$printf "Quededan %i semanas para fin año \n" $( expr $DIFERENCIA / 7)
Quededan 10 semanas para fin año 
```
 
 Comando			    | Utilidad					  | Ejemplo  
 --- 	 			    | --- 	    				  | ---
 `find <directorios> [expresiones]` | Busca según unos criterios y realiza acción | `find / -name "*.c" ` o `find . -atime +100 -ok rm {} \; ` 
 `grep [opciones][patrón]<fichero>` | Busca dentro de ficheros 	   	   	  | ---

## Metacarácteres

   Metacarácter | Función								          | Ejemplo
   --- 	     	| ---										  | ---
   ?		| Caraceter simple en la posición que se indique				  | `tema?.pdf`
   *		| Cualquier secuencia de 0 o más carácteres  					  | `tema* `
   []		| Designan un carácter o rango de caracteres que representan un carácter simple	  | `tema[1-3].pdf`
   {}		| Sustituyen conjuntos de palabras separadas por comas con  partes comunes	  | npi
   ~		| Abrevia el campo absoluto del directorio home	       	    	   		  | `~\Documento`  
   ---		| ---	     	   	    		   					  | ---
   < nombre	| redireciciona la entrada de una orden obtenida del ARCHIVO nombre		  | `cat < text.txt`
   > nombre	| Redirige la salida de una orden para que la escriba en el nuevo archivo nombre  | `echo "aaa" > text.txt `
   &> nombre 	| La salida estándar se combina con la salida de error estándar estritas en nombre| idem
   >> nombre	| Igual que *>* añadiendo al final del archivo si existe		    	  | idem
   &>> nombre	| Igual que  “&>”, pero añadiendo las dos salidas combinadas al final del archivo | idem
   2> nombre	| Igual que &>	   		      	  	  	     	      	  	  | idem
   `| ` 	| Para crear cauces SÚPER ÚTIL							  | `cat text | grep -e ^[A-B]`
   `|& `	| Cauce con errores 	  							  | similar  
   --- 		| ---	    									  | ---
   ;   		| Separador entre órdenes que se ejecutan					  | ` cat archivo ; echo "aaa"`
   ()		| Aislar órdenes, siendo trada como una única					  | --
   &&		| La orde siguiente se ejecuta si la anterior ha tenido éxito			  | aa
   || 		| La orden siguiente se ejecuta sólo si la anterior no ha funcionadp		  | `ls -l notas || pwd`  

## Variables  

  Tipos			| Ejemplo o utiliadad
  ---			| --- 
  vectories o string	| ` num=(uno dos tres); echo ${num[*]}; uno dos tres`  
  $BASH       		|  contiene la ruta de acceso del terminal
  $HOME			| alamacena el directorio raís de la carpeta home
  $PATH			| guarda el camino local de las órdenes
  $? 			| contiene el código de retorno hacia la última orden o guión

*Si eres un profano en depuración lee el [apartado de depuración](#depuracion-de-programas)*
 Variables de  depuración   |  **utilidad**  
  --- 			    | ---
  $LINENO   		    | representa el número de línea que está leyendo de un archivo
  PS4			    | Variable empotrada que ajusta el valor de *xtrace* de la línea<br>`export PS4='+ línea $LINENO: ' `	
  $FUNCNAME 		    | Array que contiene el nombre de todas las funciones que se ejecutan en el instante  
  $BASH_ARGV 		    |  An  array  variable containing all of the parameters in the current bash execution call stack. 
info bash y hartate información
  


    Operaciones con varibles	| Utilidad 
    ---		    		| ---
    `declare -[i,s,a] <nombre>`	| declara variables 
    `declare -p <nombre>	| Ver el contenido de una variable  
    `export <variable>`		| para que el sistema la reconozca 
    \` orden \`			| Sustitución de orden como si guera un avariable  
    `$(orede) `			| Sustitución de orden como si fuera una variable  
    `expre <operación>`		| Permite operaciones con variables ```numero=`expr $numero + 1` ```
    ` $(( expresión )) `	| Evalua expresiones aritméticas y sustituye su valor, LOS ESPACIOS CUÍDAMELOS  
    ` $[ expresión ] ` 		| Evalua expresiones aritméticas y sustituye su valor
    `operacioens | bc -l `	| Permite operaciones con decimales <3  
    `let varInt=asignación`	| Asigna valor a una variable entera SIN ESPACIO EN BLANCO `let a='a +   4'`  o `let a=a+4`

     
## Guiones 
1. Comenzar con `#!/bin/bash` 
2. Cambiarle los permisos a ejecución ` chmod +x <script>`  
3. Ejecutar indicando directorio en el que se encuentra `./<script.sh>` si se encuentrn en el direcctorio actual 

 Argumento  	   | Descripción 
 --- 	   	   | ---
 `$0 `	  	   | Nombre del scrips que se llama 
 `$1..$9 ${10}..`  | Referencia a distintos argumentos  
 `$@ $* ` 	   | Todos los argumentos que se le han pasado  
 `$#`		   | Número de argumentos que se le han pasado 
 `${arg:-val}`	   | Si el argumento es nulo se le asigna val  
 `${arg:?val }`	   | Si el argumento es no nulo le asigna ese valor  
 `${!#}`     	   | Muestra el último argumento

## Operadores de consulta de archivos  
  Operador    	      | Función							 | Ejemplo  
  --- 	   	      | ---     						 | ---
  `test <expresión>`  | Comprobación de características de archivos y directorio | `test -x cat && echo “true” || echo “false”`  

### Orden if else 
- con un 0 entra, con un 1 no.		 
```bash 
if <condición>
then
	<órdenes>
elif <condicióin>
then 
     <orden>
else
	<orden>
fi
```

### Orden for  
Repite una secuencia, por ejemplo imaginemos que queremos contar del 1 hasta el 10
 `for n in \`seq 1 1 10\` `  es equivalente también `for n in {1..10}` 
Puedes trabajar también con otras órdenes `for i in $(ls)`

O podemos hacer un bule for al estilo c  
``` bash 
for (( i=0 ; i<$2 ; i++ ))
do
    touch ficherito_del_amor_$i" :) "
done;
```

 
### Depuración de programas  
 - para activarlo, + para desactivarlo, 

 Comando                  | Función 
 --- 	     		  | --- 
 `bash -n`  `set -n` 	  | Chequea errores sintácticos sin ejecutar una orden  
 `bash -v`  `set -v`	  | Visualiza cada orden antes de ejecutarla
 `bash -x`  `set -x`	  | Igual que -v pero con todas las sustituciones y expansiones realizadas

#### Orden trap 
Traza,especifica una acción a reaizar cada vez que recive una señal (mecanismos de comunicación entre distintos procesos en linux <3) 
colocar después del #!/bin/bash 
trap <lo que quieras que haga tras cada ejecución de una línea> DEBUG
DEBUG  es un tipo de señal, como también lo son EXIT , ERR ,  RETURN
- EXIT cuando el código que se esté ejecutando finalice  
- ERR cuando una orden devuelve un código de finalización distinto de 0  

#### Función de aserción  
Función que comprueba una variable o función en puntos críticos del guión.	

### Control de trabajo en bash  

- Función ejecutada en primer plano **foreground**  
- Función en segundo plano **baskgroun** declarada con `&` al final de su declaración  

órdenes para hacer referencia a un trabajo y así poder manipularlo: 
Especificador  	     | Trabajo que es denotado con dicho especificador
 --- 		     | ---
%		     | Trabajo actual (%+ y %% son sinónimos de este especificador)
%- 		     | Trabajo previo al actual
%n 		     | Trabajo número n
%<cadena> 	     | Trabajo cuya línea de órdenes comienza por <cadena>
%?<cadena> 	     | Trabajo cuya línea de órdenes contiene <cadena>

 órdenes más frecuentes de control de trabajos:
Órdenes | Descripción
 --- 	| ---
jobs 	| Lista los trabajos activos bajo el control del usuario (help jobs)
fg 	| Trae a primer plano un trabajo que se encuentra suspendido o en segundo plano (help fg)
bg 	| Envía a segundo plano un trabajo (help bg)
%	| Permite cambiar el estado de un trabajo (help %)
wait 	| Espera la finalización de procesos en segundo plano (help wait)
disown	| Suprime un trabajo de la lista de trabajos activos (help disown) `disown -r ` elimina los trabajos en ejecución `disown -a` todos los trabajos	
kill 	| Envía una señal a un/os proceso/s. Por defecto, finaliza la ejecución de un proceso (man kill)
ps 	| Muestra el estado de los procesos actuales en el sistema (man ps)
top	| Muestra los procesos en ejecución con actualización de su información en tiempo real (man top)  


## Compilación de programas  
### Compilación con g++  
#### Procesos de la compilación
1. **Procesar** procesador acepta como entrada un archivo con código fuente, elimina los comentarios e interpreta las **directivas de procesamiento**  
2. **Compilador** analiza el código fuente y lo traduce a un código objeto, **módulo objeto** con la extensión `.o`, en este porceso no se resuelven las referencias externa a variable o funciones.  
`g++ -c archivo.cpp` genera si no hay errores de programación el módulo objeto.  
3. **Enlazador** resuelve las referencias externas y genera un archivo ejecutable.  

órdenes de compilación en g++  

 órden				 | Función  
 ---		       	       	 | --- 
 `g++ -o archivo.cpp`  	       	 | Realiza etapa de procesado y compilación generando módulo objeto si no hay error 
 `g++ archivo.o ach.o` 	       	 | Crea el ejutable, a.out 
 `g++ -o nom_ejecuta archivo.o`  | Igual que el anterior pero en vex de nombrar al archivo con a.out, lo nombra nom_ejecuta.out 
 `ar -rvs biblio.a modulo.o mod.o`| Genera una librería <br>genera un archivo .a <br>> r inserta los miembros del archivo, s crea índice, v amplia información en verbose   
`$ g++ -L./ -o programa2 main2.o factorial.o hello.o -lmates` | crea ejecutable especificando las librerias con la raiz mates, esta se debe encontra en el direcorio  
`g++ -I./directorio -L./ -o programa2 main2.cpp factorial.cpp hello.cpp -lmates` | igual que la anterior pero especificando el directorio  


## Uso de archivos del tipo makefile  

Makefile permite gestionar las depedencias, comprobando que archivos se han modificado desde la última vez que se ejecutó y vuelve a construir el ejecutable cambiando solo lás modificaciones.
