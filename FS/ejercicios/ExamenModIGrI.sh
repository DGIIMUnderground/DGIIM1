#!/bin/bash

ayuda="Argumentos  y funcionamiento: \n
--ayuda: muestra esta ayuda por pantalla \n
--alumno: muestra el nombre y apellidos, así como el grupo al que pertenece (en el sistema) el
alumno que ha realizado el script \n
--copy usario: esta orden realiza una copia de seguridad de backup \n"

if [[ !($# == "0") ]] #Si hay argumentos
	then
	if [[ $1 == "--ayuda" ]]
		then printf "$ayuda"
	elif [[ $1 == "--alumno" ]] #Muestra el alumno
		then printf "El usuario es: $USER\ny se encuentra en: `pwd`\n"
	elif [[ $1 == "--copy" ]] #Empieza la copia de seguridad
		then
		if [[ -d $2 ]] #Comprueba si existe el directorio dado como argumento
			then printf "Existe el directorio\n"
			ficheros=`ls | wc -l`
			printf "En el directorio hay $ficheros ficheros, ¿desea hacer la copia de seguridad? (sí, si, yes, s, y) \n"
			read respuesta
			if [[ $respuesta == "si" || $respuesta == "sí" || $respuesta == "yes" || $respuesta == "s" || $respuesta == "y" ]]
				then
				if [[ !(-d backup`date +%y_%m_%e`) ]] #Comprobamos si ya existía el directorio donde vamos a hacer la copia de seguridad
					then printf "No se puede realizar la copia de seguridad, ya existe el directorio con esa copia de seguridad.\n"
				else
				lugar=`pwd`
				cd /tmp
				mkdir backup`date +%y_%m_%e`
					if [[ -d backup`date +%y_%m_%e` ]] #Comprobamos si se ha creado el directorio
						then 
						cp -r $lugar /tmp/backup`date +%y_%m_%e` #Copiamos el directorio dado como argumento en el directorio backup		
						printf "Se ha realizado correctamente la copia de seguridad.\n"
					else
						printf "No se ha creado correctamente el directorio.\n"
					fi
				fi
				else
					printf "No se va a realizar la copia de seguridad.\n"
			fi
		else
			printf "No existe el directorio.\n"
			printf "El directorio debería ser: $(pwd)\n"
		fi
	else
		printf "$ayuda"
	fi
else #Si no hay argumentos
	printf "$ayuda"
fi
