## EXAMEN 1 MODULO 1
Solución al examen 1 del grupo	 del módulo 1 de FS por Blanca Cano
### 1.A
```bash
#!/bin/bash

case $1 in
    "" | "--ayuda") 
	printf " --alumno: muestra el nombre y apellidos, así como el grupo al que pertenece (en el sistema) el alumno que ha realizado el script \n --copy: esta orden realiza una copia de seguridad de backup.\n --ayuda: muestra este mensaje\n"
	;;
    "--alumno" )
	printf "Blanca Cana\n"
	echo "Grupo al que pertenece $(groups $USER | cut -d : -f2) ";;
    "--copy") # realiza un backup
	if  ` test -d $2` && ! `test -h $2`
	then
	    echo "En el directorio hay  $(expr $(find . | wc -l) - 1) fichreos ¿Desea hacer una copia de seguridad?"
	    read respuesta
	    if [[ $respuesta == "sí" || $respuesta == "s" || $respuesta == "yes" || $respuesta == "y" || $respuesta == "si" ]]
	    then

		if  mkdir ./../tmp/`date +%y%m%d` # he creado otra carpeta, no la que me dice el examen, sería cambiar la dirección
		then
		    echo "creado"
		    cp -r ./ ./../tmp/`date +%y%m%d`
		else
		    echo "No se ha podido crear el directorio "
		fi 
	    fi
	    
	else
	   printf "sus opciones dentro de esta carpeta debieron ser %s" `ls`
	    
	fi
esac
```

### 1.b 
```bash
#!/bin/bash
#author Alberto

find / -mmin $1 2> ./../tmp/errores.txt
```