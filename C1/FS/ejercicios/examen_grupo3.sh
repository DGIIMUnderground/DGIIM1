#!/bin/bash
# Blanca Cana

directorio_basura="~/.local/share/Trash/" #En nuestro caso la carpeta "papelera" no está en /temp/trash, sino aquí

case $1 in
    "--ayuda")
	echo "Esta es la ayuda";;
    "--ruta")
	directorio_basura=$2;;
    "--grupo")
	echo "Alumna: Blanca Cano Camarero"
	echo "Grupo: 1?"
	echo "Pertenece a los grupos `groups $USER | cut -d : -f2`" ;;
	## Otra posible solución que muetra los grupos en líneas diferentes es:
	# echo "Grupos: "
	#printf "%s \n" `groups $USER | cut -d : -f2`
	
    *) ARCHIVOS=`find . -atime +5`
	if [[ ! $ARCHIVOS  == "" ]]
       then
	   echo "Hay archivos modificados hace más de 5 días"
	   DIRECTORIO=$directorio_basura/.TMP`date +%y_%m_%d`
	   mkdir $DIRECTORIO
	   chmod a-rwx
	   chmod u+rwx
	   mv $ARCHIVOS $DIRECTORIO
	else
	    #Nos daba to el palo escribir el mensaje que te pide exacto
	    echo "Se han leído $( ls ./ | wc -l )  de los cuales $(expr  $(find .  -atime -5 | wc -l) - 1) se han modificado hace menos de 5 días. No se ha hecho nada `date`"  >> ~/temp.log
       fi
       ;;
	  
	
	
esac
