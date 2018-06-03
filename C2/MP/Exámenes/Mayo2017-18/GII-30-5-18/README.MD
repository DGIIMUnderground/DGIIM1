# Examen Grado Ingenieria Informatica - Mayo 2018

Examen dia 30/05/2018

Se pedia:

Crear un programa, que leyera una palabra mágica al inicio ("TAREAS"), seguida de esta palabra mágica, una orden ("MAYUSCULAS" o "MINUSCULAS"), y despues una serie de ficheros, que dependiendo de la orden leida, a partir de \<fichero> crea \<fichero_MAYS> o \<fichero_MINS> , con el contenido de ese fichero totalmente en mayúscula o minúscula, respectivamente.

En el fichero de ordenes, se pueden encontrar lineas en blanco, o con espaciadores en cualquier momento, pero si la primera palabra leida y la segunda, no son respectivamente la palabra mágica y la orden, o se especifica una orden desconocida, el programa dejara de ejecutarse.

Si dentro de los ficheros, encuentra un fichero que no es capaz de encontrar, mostrara un mensaje de aviso, y continuará con los otros ficheros.

# Ejecutar

Primero compilamos:

`make`

Existen dos formas de ejecutar el programa:

-Sin argumentos:

`./bin/examen2`

La entrada del fichero antes mencionado se realizara mediante el flujo cin, es decir, la entrada por defecto (teclado en terminal).

-Con un argumento:

`./bin/examen2 prueba_1`

El fichero donde se encuentra la palabra mágica y la orden será \<prueba_1>

# Ficheros de prueba

Adjunto tres ficheros de prueba.

**\<prueba_1>** : Prueba con orden "MINUSCULAS", se crearan \<makefile_MINS> y \<src/examen2.cpp_MINS>

**\<prueba_2>** : Prueba con orden "MAYUSCULAS", se crearan \<makefile_MAYS> y \<src/examen2.cpp_MAYS>

**\<prueba_3>** : Con un error de inconsistencia en la entrada, falta la palabra mágica.
