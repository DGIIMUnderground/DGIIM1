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
  --- 			| ---
  


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

 
### Depuración de programas  
 - para activarlo, + para desactivarlo, 

 Comando                  | Función 
 --- 	     		  | --- 
 `bash -n`  `set -n` 	  | Chequea errores sintácticos sin ejecutar una orden  
 `bash -v`  `set -v`	  | Visualiza cada orden antes de ejecutarla
 `bash -x`  `set -x`	  | Igual que -v pero con todas las sustituciones y expansiones realizadas

#### Orden trap 
Traza de cuando se ejecuta un programa, por ejemlo si lo llamásemos siempre con la misma orden, 
colocar después del #!/bin/bash 
trap <lo que quieras que haga tras cada ejecución de una línea> DEBUG
DEBUG  es un tipo de señal, como también lo son EXIT , ERR ,  RETURN
- EXIT cuando el código que se esté ejecutando finalice  
- ERR cuando una orden devuelve un código de finalización distinto de 0