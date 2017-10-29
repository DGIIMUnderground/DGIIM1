## COMANDO APARIENCIA SHELL 

- C-l limpiar terminal
- clear limpiar terminal

## combinaciones de teclado para cerra

- para cerrar al termial C-alt-w
- cerrar una vneta que no sea la terminal C-quit 

## APLICACIONES DESDE TERMINAL

- <programa> &  lo ejecuta en "backgraund" dejando disponible la terminal
- xdg-open <archivo> abre ese archivo con el programa predeterminado

 
## Comados relacionados con archivos y direcctorios

- **ls**

- **cd**

- **pwd** Imprime el camino absulo del direcctorio actual

- **mkdir** Y **rmdir** rmdir -r borra si tienes también archivos dentro

- **cat**

- **cd <archivo1> <archivo2>**

- **mv**

- **file** muestra el tipo de archivo.

- **more** **pager**  **pg**  visualiza un archivo fraccionándolo en la pantalla cada vez.

- **rm**

- **touch** modifica fecha y hora de un archivo, si no los crea

- **clear** borra el contenido de la terminal actual

- **tail** -<entero> <archivo> muestra las líneas finales de un fichero

- **head** -<entero> <archivo> muestras las "numero de líneas iniciales de un fichero.

- **sort** <archivo> ordena bajo un critero elegido las líneas de un archivo.

- **wc** cuenta el número de algo de un fichero

-**echo** escribe un mensaje en termminal

- **printf ** muestra en el bash lo que se especifique

- secuencia de escape

  - \b espacio atrás 

  - \n nueva línea

  - \t \'  \\  \0n

- código de formato

  - %d número con signo

  - %f  número en coma flotante

  - %q entrecomilla una cadena

  - %s muestra una cadena sin entrecomillar

  - %x núemro en hexadecimal

  - %o número en octal

- Ejemplo: blanca@debian:$printf "Quededan %i semanas para fin año \n" $( expr $DIFERENCIA / 7)
Quededan 10 semanas para fin año 





## Modificación de los permisos de un archivo

- **chmod** [u,g,o,a][-+][r,w,x]

## Metacaracteres

- ** < nombre ** redirecciona la entrada de una orden para que la tenga el ficero nombre

- ** > nombre ** redirige la salida de una orede, si existe lo sobreescribe

- ** &> nomre** la salida estándar y la de error

- ** >> nombre** igual que la simple pero escribe al final de fichero nombre

- ** &>> nombre**

- ** | ** crea un cauce entre varia
s órdes, la salida de una es la entrada de la otra

- ** |& ** crea un cauce pero con los errores también

- ** ;** separador de órdenes que se ejecutan secuencialmente

- () aislar órdenes

- && separador de órdenes en el que uno se ejecuta solo si la orden primera es exitosa

- || separador de órdenes donde la segunda solo se ejecuta si falla la primera

## Variables

- <NOMBRE_DE_VARIABLE>=valor así se declaran variables simples

- **declare** [opción] <NOMBRE>=VALOR esto sirve para declarar valores especiales. Opciones posibles:
 - -i para hacer variables con enteros. (ejemplo)

## Variables especiales

- $BASH contiene la ruta de acceso del terminal

- $HOME alamacena el directorio raís de la carpeta home

- $PATH guarda el camino local de las órdenes

- $? contiene el código de retorno hacia la última orden o guión

- export <variable> para que la variable no sea local 

## Alias

- **alias** para crear una orden predetermina o cambiar el nombre a una orden

- **unalias** para bprrar el nombre de una orden

## find y grep

- **find** para buscar por la estructura de directorios los archivos quebcumplan con criterios especificados  
  - ' find <directorio> -size <+- tamaño> ' busca archivos de un determinado tamaño, + si son mayores, - si son menor que	

- **grep** permite buscar cadena en archivos

  - -x línea que coincidan totalmente

  - -v línea que no contengan dicho patrón

  - -c recuento de las línea que cumplen con dicho patrón

  - -i ignora la distinción entre mayúscula sy minúsculas

  - -n añade el número de líneas en el fichero fuente

  - -l selecciona solo los nombre de los fichero con la coincidencia

  - -e especial para el uso de patrones múltiples

## Operaciones

- ** expr ** <operaciones separadas por espacio > sin ser exacto en decimales
Ejemplo: 

blanca@debian:~/cultutrilla$ expr 2 + 1
3

- ** calc ** igua que expr pero siendo exacto en los decimales

- * expaciones aritméticas * o *sustituciones aritméticas*: evalúan el resultado utilizado y lo sustituyen, opciones:

  - $( ( <operaciones> ) ) > $((($YEAR-$DIA)/7))
  - $ [ <operaciones> ] > $[($YEAR-$DIA)/7]

 Los operadóres son los típicos de C 
 bash solamente trabaja con número enteros, para cambiar esto, en caso de necesita los decimales:

- ** bc ** bc es un lenguaje calclualdor con precisión. 
    blanca@debian:~/Documentos/FS/prácticas$ echo  '10/3' |bc -l
3.33333333333333333333
blanca@debian:~/Documentos/FS/prácticas$ echo  "10/3" |bc -l
3.33333333333333333333


- ** let ** evalua cada argumento como una expresión aritmética.
  

## Guiones, script o programas de shell

- Para invocar el scritp el scrip *bash <nombre_script>

- para simplificar la llemada anterior:
     
     - * #!/bin/bash*  comenzar el archivo con *!/* seguido del shell que estemos utilizando, en nuestro caso /bin/bash
     
     - Hacemso el archivo ejecutable, cambiamos su privilegios > chmod +x <nombre_script>

     - Ejecutamos como se haría normalmente > .\<nombre_script>

## Operadores de consulta de archivos.

- **test** sintaxis *test <expresión>* si la expresión evaluada es verdadera devuelve 0, en caso de que sea falsa o el argumento es no válido,  devuelve 1

Capacidades

operador | descripción de resutado verdadero
 ... | ...
-a <archivo> | <archivo> existe
-b <archivo> | <archivo> existe u es un dispositivo de bloques
-c <archivo> | <archivo> existe y es un dispositvo de caracteres
-d <archivo> | <archivo> existe y es un disposito de directorio
-e <archivo> | igual que -a
-f <archivo> | existe y es un archo plano regular
-G <archivo> | existe y es propiedad del grupo usuario
-h <archivo> | existe y es un enlace simbólicp
-L <archivo> | igual que -h
-O <archivo> | existe y es propieda del usuario
-r <archivo> | existe y el usuario tiene permiso de lectura
-s <archivo> | existe y no es vacío
-w <archivo> | existe y el usuario tiene permiso de ecritura en él 
-x <archivo> | <archivo> existe y e ususrio tiene permiso de ejecución, o si es u directorio tiene permiso de búsqueda.
<archivo> -nt <archivo2> | si el <archivo> es más nuevo o simplemente existe y el otro no
<archivo> -ot <archivo2> | si <archivo> es más antiguo o no existe y el otro sí 
<archivo> -ef <archivo2> | si <archivo> es un enlace duro al <archivo2>, es decir si ammbos refieren los mismos números de dispositivos de inode
