## EXAMEN 3 DE FUNDAMENTOS DEL SOFTWARE HECHO
- - -
> Enunciado
- - - 
> Examen MÓDULO I
[Fundamentos del Software]
Indique el nombre y apellidos en la parte de la cabecera del guión (script) como comentario.
[8 puntos] 1-a. Cree un guión (script) llamado examen1.sh que tenga el siguiente
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
[2 puntos] 1-b. Cree un guión (script) llamado examen2.sh en el que se indique
como comentario la orden u órdenes necesarias para que en lugar de ejecutarse rm
sobre ficheros o carpetas, dichos ficheros o carpetas se movieran al directorio dado
por defecto en el script anterior en la variable directorio_basura .
Adicionalmente implemente en el mismo script las órdenes necesarias para que se
muestren por pantalla solamente las palabras que empiecen por mayúscula del fichero
pasado como primer argumento y además indique el número de palabras encontradas
al final y el número de palabras totales del fichero.
Asuma que el fichero pasado contiene una única columna con palabras y que en una
misma línea (fila) no aparece nunca más de una palabra.


- - -
> Esta resuelto y funciona todo me he tirado la vida pero no he recurrido a internet, quizás lo más complejo sea entender como he comprobado que eran archivos recientes de menso de 5 días, lo explico en el código.

```bash 

#!/bin/bash
#Author: Juan Helios García Guzmán


ayuda="--ayuda: muestra esta ayuda por pantalla
--grupo: muestra el nombre y apellidos, así como el grupo del alumno que ha realizado el script,
debajo mostrará dinámicamente una lista con los nombres de los grupos en Linux a los que
pertenece el usuario que ejecute el script.
--ruta: se cambiará la variable directorio_basura del script al directorio dado por argumento."

if test ! -d /tmp/directorio_basura
then
	mkdir /tmp/directorio_basura
	$directorioBasura=`echo "/tmp/directorio_basura"`
fi

if [ $# != 0 ]
then

	if [ $# -gt 2 ]
		then
	echo $ayuda
	elif [ $1 = "--ayuda" ]
	then
	echo $ayuda
	elif [ $1 = "--grupo" ]
	then
		echo "Juan Helios Garcia Guzman \n GRUPO 1"
		echo "Grupos en los que está el usuario: \n `groups` "
	elif [ $1 = "--ruta" ] && [ $# = 2 ]
	then
		$directorioBasura=`echo "$2"`
	fi
fi

numarchivos=0
numarchivosREC=0
fechasistema=$((`date +%Y%m%d` -5)) #LA fecha actual expresada tal que mmdd si le restamos 5 es 5 días #menos
directorioREC=$(echo "/tmp/$directorioBasura/".TMP"`date +%y%m%d`")
	for i in $(ls) 
	do	


		numarchivos=$(($numarchivos+1))
		timearch=`ls -l $i --time-style=+%Y%m%d | cut -d' ' -f6` #Cogemos el campo del tiempo de #cada archivo de la lista
		if [ $timearch -ge $fechasistema ] #Comprobamos si es mayor que la fecha del sisteam -5 en ese caso será más reciente que 5 días.

		then 
			numarchivosREC=$(($numarchivosREC +1))
			if test ! -d $directorioREC && [ $numarchivosREC -ge 1 ] 
			then
				mkdir $directorioREC
				chmod u+rwx a-rwx g-rwx $directorioREC
				mv $i $directorioREC
			elif [ $numarchivosREC -ge 1 ]
			then
				mv $i $directorioREC
			fi
		fi
	done

	echo "Se han leído $numarchivos , $numarchivosREC más recientes de 5 días. (`date +%Y%m%d`) "


	if [ $numarchivosREC -ge 1 ]
	then	
		
		sudo touch /home/tmp.log
		sudo chmod a+xwr /home/tmp.log
		echo "[x] No hay ficheros recientes. Se han movido $numarchivosREC a la carpeta $directorioREC (`date +%Y%m%d`)" >> /home/tmp.log
	fi
```
## EJERCICIO 2
```bash

#!/bin/bash
#Author: Juan Helios Garcia Guzman

# Tendriamos que utilizar el sigueinte comando: bash examen3 ; encontrandonos en el directorio o archivo que queremos borrar

echo "Las palabras que empiezan por mayuscula son`cat $1 | grep ^[A-Z]` "
echo "Hay en total`cat $1 | grep ^[A-Z] | wc -w` palabras que empiezan por mayuscula"
echo "El total de palabras es`cat $1 | wc -w`"
```

		


