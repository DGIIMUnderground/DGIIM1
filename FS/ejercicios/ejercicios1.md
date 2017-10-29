## Ejercicios de guiones de Bash:

Resolución colaborativa del documento `ejercicios-variados-bash.pdf`.

Si vas a solucionar un problema no resulto, siéntete libre para escribir tu solución.
En el caso de que esté ya resuelto pero quieras escribir tu solución alternativa,
simplemente escribe tu código debajo (# author: tu nombre).

Si quieres corregir una solución ya existente copia y pega el código y añade
un comentario (# colaborator: tu nombre), respetando siempre (# author: ).
La gracia es que sólo el propio autor del código puede decidir si quiere que
la modificación que ha hecho otra persona sea la definitiva, de forma que puede
borrar su código.


### SIMPLES:

**1. Escriba un script que se copie a sí mismo en un fichero llamado backup.sh; el script debe
copiarse a sí mismo incluso si previamente fue renombrado.**

```bash
#!/bin/bash
# author: Blanca
cp $0 backup.sh
```

**2. Realice un script que verifique si hay algún dispositivo pendrive conectado al computador,
si lo está, escriba un listado de los dispositivos montados actualmente de forma dinámica.**

```bash
#!/bin/bash
# author: Blanca
ls /media/$USER
```


**3. Escriba un script que mediante la orden grep elimine las líneas en blanco de otro script.**

```bash
#!/bin/bash
# author: Ric

cat $1 | grep -v -e '^$'
```

> Explicación
> La expresión regular `^$` captura toda línea en blanco (`^` y `$` son comienzo y final de línea
> respectivamente.
> La gracia está en usar `-v` porque justo captura el complementario (`--invert-match`)

```bash
#!/bin/bash
# author: Paula

grep . <guionconlineasenblanco> >> <guionsinlineasenblanco>
```

> Esta solución es mucho más simple y elegante que la que escribí
> ya que no utiliza cauces.
> Sin embargo utilizar `>>` es erróneo ya que añadiría el contenido al final
> del archivo si existe. Por ello lo sustituyo por `>`.
> Además, como en el enunciado dice eliminar las líneas en blanco de un archivo
> vamos a modificarlo para que <guionconlineasenblanco> sea un argumento del script
> y utilizaremos un archivo temporal para poder renombrar la salida.
> (grep no permite redirigir al mismo archivo de entrada)
> Ric

```bash
#!/bin/bash
# author: Paula
# colaborator: Ric

grep . $1 > temp && mv temp $1
```

**4. Escriba un script que mediante la orden grep elimine los comentarios de otro script.**


```bash
#!/bin/bash
# author: Jose
grep -v "#" $1 > temp
rm $1
mv temp $1
```

> Opinión de Ric:
> Esta solución borra todas las líneas que contengan un #.
> Pero a veces un # está en medio de una línea
> No sé como hacer que se borre justo lo que viene después,
> pero sí cómo hacer para que se borren sólo las líneas que
> empiezan por #

```bash
#!/bin/bash
# author: Ric
grep -v '^#' $1 > temp && mv temp $1
```

**5. Combine los scripts 3 y 4 para que elimine las líneas en blanco y los
   comentarios. ¿Habría más formas de realizar este ejercicio?**


```bash
#!/bin/bash
#ft Blanca.

grep . $1 > temp
grep -v "#" temp > $1
rm temp
```

Una forma alternativa

```bash
#!/bin/bash
# author: internet
# ft Ric

grep -o '^[^#]*' $1 > temp && mv temp $1
```

> `^[^#]*' significa seleccionar todos los caracter excepto #.
> -o devuelve sólo lo seleccionado en lugar de la línea completa.
> Por tanto, podemos redirigirlo y desaparecen las líneas en blanco 

Otra alternativa
```bash
#!/bin/bash
#autor:Alberto
cat $1|grep -e ^[^#] > aux ##"aux" es un archivo auxilar cualquiera
grep . aux > $1
```

6. Escriba un script que devuelva todos los usuarios del sistema. Además imprima una lista de
los shells utilizados por defecto al arrancar para cada usuario.

```bash
#!/bin/bash
# author: Blanca

for linea in `cat /etc/passwd`
do
    USUARIO=`echo $linea | cut -d: -f1 `
    SHELL=`echo $linea | cut -d : -f7 ` 
    printf " El usurio $USUARIO utiliza la shell $SHELL \n"
done

```

> El bucle no parece recorrer línea por línea el archivo
> sino pararse también cuando encuentra espacios en blanco


```bash
#!/bin/bash
# author: Ric

while read linea; do
  usuario=`echo $linea | cut -d: -f1 `
  shell=`echo $linea | cut -d: -f7 `
  printf " El usurio $usuario utiliza la shell $shell \n"
done < /etc/passwd
```

> Esta solución omite además usar cat, lo cual hacer aumentar
> la eficiencia del script.


**7. lastlog es una orden que devuelve la última vez que se inició una sesión.
Realice un script que devuelva a qué hora el usuario que ejecuta el script
accedió al computador por última vez.**

```bash
#!/bin/bash
# author: Paula

last -R -n 1 $USER
```
> Comentario de Blanca: Viendo esta solución ¿lo que nos cuentan de lastlog es
> puro engaño para liarnos más y conducirnos a la desesperación u otra solución
> es con lastlog?

**8. Realice un script que, dado A, B y C como argumento resuelva la ecuación para x:
Ax² + Bx + C = 0**

```bash
#!/bin/bash
# author: Paula

discriminante=$(echo "$2^2-4*$1*$3" | bc -l)

if [ $1 != 0 ] # Vemos si el coeficiente de segundo grado es distinto de 0
	then
	if [ $discriminante -ge 0 ] # Vemos si el discriminante no es negativo
		then
		numerador1=$(echo "-$2-sqrt($discriminante)" | bc -l)
		numerador2=$(echo "-$2+sqrt($discriminante)" | bc -l)
		echo "$numerador1/(2*$1)" | bc -l
		echo "$numerador2/(2*$1)" | bc -l
	else
		echo "el discriminante es negativo"
	fi
else # Si el coeficiente de segundo grado es 0
	echo "-$3/$2" | bc -l
fi
```


### COMPLEJOS:

**1. Realice un script que permita compactar varios ficheros en uno solo. Para ello, la orden tomaría un primer argumento que sería el nombre del fichero de salida, y luego tomaría una lista de argumentos que sería la lista de archivos a compactar. Verifique que el fichero de
salida no existía previamente mostrando los errores pertinentes en caso de existir.**

```bash
#!/bin/bash
# Author: Blanca

if [[ !(-d $1) && !(-d $1.tar) ]] # hay que tener en cuenta que el fichero que no tiene que existir es el .tar
then
    mkdir $1;
    
    for archivo in $@;
    do
	
	if [[ `echo $archivo` != `echo $1` ]]; # Esta línea es la clave, no se copia a sí mismo
	then
	   
	    cp $archivo $1;
	fi;
    done;
    tar -cvf $1.tar $1;
    rm -r  $1;
else
	echo "Error, el fichero ya existe."
fi

```

> Comentario de Blanca:  Paulaaaa, yo creo que te daba error porque estabas
> intentado copiar el mismo archivo a sí mismo, he aquí mi solución,
> probablemente depurable He utilizado una carpeta auxiliar ¿Alguna idea para
> hacerlo sin ella?

```bash
#!/bin/bash
# author: Paula

if [[ !(-d $1) ]]
	then
	tar -cvf $1.tar $@
else
	echo "Error, el fichero ya existe."
fi
```

> Cuando ejecutas el script en la terminal, pone que da error.
> Pero igualmente realiza su función correctamente.

**2. Realice un script que permita la instalación del script del ejercicio 1.
Para ello, el script tendrá una parte de instalador y otra parte donde estará
el script a instalar. Ambos ficheros se encontrarán compactados en el mismo
script. Cuando el usuario lance el script instalador, ete recortará el script y
copiará el script del ejerccio 1 en el directorio dado como argumento**

```bash
#!/bin/bash
#Author: Blanca


for SCRIPT in `ls`;
do
    if [[ `echo $SCRIPT` != `echo $0` ]] ; 
    then
	cp  $SCRIPT $HOME/$1; # Dirección dese de la carptea home del usuario del equipo
    fi;
done;

```
> Comentario Blanca: 
> Como habéis podido notar por el comementario la carpeta a la que se quieran enviar el resto de archivos debe ser absoluta, eso no me gustaba
> y he intentado arreglarlo de la sigueinte manera, el script no funciona, pero por si a alguien le sirve como fuente de inspiración
> mi idea es que solo sea necesario introducir el nombre de la carpeta a la que se quiere enviar
```

for SCRIPT in `ls`;
do
    if [[  `echo $SCRIPT` != `echo $0`  ]] ;
    then
	while READ;
	do 
	   printf " % \n" $READ;
	   cp $SCRIPT ~/$READ;
	   break;
	done <echo` find $HOME -name $1`;
		
    fi;
    
done;

```

**3. ImageMagick es un programa que permite trabajar con imágenes. Haga man convert para ver su uso. Después cree un script que permita unir dos imágenes en una sola.**

```bash
#!/bin/bash
# author: Paula

#$1: imagen 1
#$2: imagen 2
#$3: imagen 1 y 2 unidas

convert -adjoin $1 $2 $3
```


> Imagen 1 e imagen 2 no pueden ser .jpeg ni .png porque el programa no puede unirlas.
> Los argumentos deben darse con su extensión (ejemplo: imagen1.gif).



