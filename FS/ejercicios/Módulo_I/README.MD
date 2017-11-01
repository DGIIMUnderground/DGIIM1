
## Exámenes módulo I primer cuatrimeste de FS
### Examen del grupo I  
####[8 puntos] 1-a. Cree un guión (script) llamado examen1.sh que tenga el siguiente
funcionamiento:
./examen1.sh  
./examen1.sh  
./examen1.sh  
--copy  
--ayuda  
--alumno  
usuario  
ó  
ó 
Si el guión (script) se ejecuta sin argumentos o con un número erróneo de argumentos, el script
mostrará la ayuda.
--ayuda: muestra esta ayuda por pantalla
--alumno: muestra el nombre y apellidos, así como el grupo al que pertenece (en el sistema) el
alumno que ha realizado el script
--copy: esta orden realiza una copia de seguridad de backup
1. Verifica que el directorio del usuario dado por argumento existe y no es un enlace.
2. Si el directorio no existe, muestra por pantalla un mensaje de error mostrando cuál
debiera ser el directorio del usuario.
3. Si el directorio existe, muestra por pantalla una pregunta: En el directorio hay X
ficheros, ¿desea hacer la copia de seguridad? Donde X será el número de archivos
(obtenidos de forma recursiva) del directorio.
4. Si el usuario responde sí, si, yes, s, ó y, se creará un directorio llamado
backup_YY_MM_DD en el directorio temporal del sistema, donde
__YY__MM__DD será la fecha actual en formato: año (dos últimos dígitos), mes (1
o dos dígitos) y día (uno o dos dígitos).
5. Se verificará que todo fue bien hasta este paso, en caso contrario se abortará la
instalación mostrando un mensaje de error apropiado.
6. Finalmente se copiará recursivamente el contenido del directorio del usuario en el
directorio temporal previamente comentado.

#### Solucciones


[2 puntos] 1-b. Cree un guión (script) para que saque por pantalla solamente aquellos
ficheros de todo el sistema que hayan sido accedidos en un número menor de minutos
que el dado como primer argumento al guión (script). (Los errores se redirigirán al
fichero /tmp/errores.txt.)

### Examen del grupo 3

####[8 puntos] 1-a. Cree un guión (script) llamado examen1.sh que tenga el siguiente
funcionamiento:
./examen1.sh
./examen1.sh
./examen1.sh
./examen1.sh
--ruta
--ayuda
--grupo
directorio
ó
ó
ó
Si el guión (script) se ejecuta con un número erróneo de argumentos, o con argumentos erróneos, el
script mostrará la ayuda.
--ayuda: muestra esta ayuda por pantalla
--grupo: muestra el nombre y apellidos, así como el grupo del alumno que ha realizado el script,
debajo mostrará dinámicamente una lista con los nombres de los grupos en Linux a los que
pertenece el usuario que ejecute el script.
--ruta: se cambiará la variable directorio_basura del script al directorio dado por argumento.
Tanto si se ejecuta con el parámetro --ruta, como si el script se ejecuta sin argumentos, el script
definirá la variable directorio_basura (que, si no se indica mediante el parámetro --ruta, por
defecto será la carpeta trash del directorio temporal del sistema).
El funcionamiento del script será:
1. Se verificará que no hay ficheros modificados más recientemente de 5 días.
2. En caso de no encontrarlos se saldrá del script añadiendo al fichero temporal llamado
tmp.log y ubicado en la carpeta home del usuario, un mensaje como el siguiente:
“[ ] Se han leído X ficheros, Y más recientes de 5 días. No se hace nada (D).”
Donde X es el número de ficheros totales en directorio_basura (sin contar ocultos). Y es el
número de ficheros más recientes de 5 días en directorio_basura, y D es la hora y fecha en
cualquier formato.
3. En caso de encontrarlos, el script creará una nuevo directorio dentro del directorio indicado
en directorio_basura que de nombre tenga la fecha actual con el siguiente formato:
.TMP-YY_MM_DD
y con los siguientes permisos: grupo: nada; usuario: todos; otros: nada
(donde YY son dos dígitos del año, MM dos dígitos del mes, y DD dos dígitos del día).
4. En ese caso, se moverán todos los ficheros no ocultos del directorio directorio_basura al
directorio temporal creado anteriormente.
Adicionalmente añadirá una entrada al fichero de mensajes (tmp.log) de la carpeta home del
usuario que diga:
“[x] No hay ficheros recientes. Se han movido Z ficheros a la carpeta C (D).”
Donde Z es el número de ficheros totales en directorio_basura (sin contar ocultos). C es el
directorio temporal creado anteriormente. Y D es la hora y fecha en el mismo formato que elpunto 1.2.
En dicho script no deben aparecer errores en la pantalla ni redirigirse a ficheros legibles por los
usuarios del sistema.

####[2 puntos] 1-b. Cree un guión (script) llamado examen2.sh en el que se indique
como comentario la orden u órdenes necesarias para que en lugar de ejecutarse rm
sobre ficheros o carpetas, dichos ficheros o carpetas se movieran al directorio dado
por defecto en el script anterior en la variable directorio_basura .
Adicionalmente implemente en el mismo script las órdenes necesarias para que se
muestren por pantalla solamente las palabras que empiecen por mayúscula del fichero
pasado como primer argumento y además indique el número de palabras encontradas
al final y el número de palabras totales del fichero.
Asuma que el fichero pasado contiene una única columna con palabras y que en una
misma línea (fila) no aparece nunca más de una palabra.