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

1. Escriba un script que se copie a sí mismo en un fichero llamado backup.sh; el script debe
copiarse a sí mismo incluso si previamente fue renombrado.

```bash
#!/bin/bash
# author: Blanca
cp $0 backup.sh
```

2. Realice un script que verifique si hay algún dispositivo pendrive conectado al computador,
si lo está, escriba un listado de los dispositivos montados actualmente de forma dinámica.

```bash
#!/bin/bash
# author: Blanca
ls /media/$USER
```

3. Escriba un script que mediante la orden grep elimine las líneas en blanco de otro script.

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
> Sin embargo utilizar >> es erróneo ya que añadiría el contenido al final
> del archivo si existe. Por ello lo sustituyo por (>).
> Además, como el enunciado dice eliminar las líneas en blanco de un archivo
> vamos a  sin embargo voy a modificarlo
> para que <guionconlineasenblanco> sea el primer argumento del script
> y <guionsinlineasenblanco> sea el segundo. Además utilizar >> no es
> correcta ya que si <guionsinlineasenblanco> existe se añadirá el contenido,
> y lo que queremos es que sea sobrescrito. (>)"
> Además, como grep no nos permite redirigir al mismo archivo de entrada
> es necesario utilizar cp para renombrar el archivo
> Ric

```bash
#!/bin/bash
# author: Paula
# colaborator: Ric

grep . $1 > temp && mv temp $1
```

4. Escriba un script que mediante la orden grep elimine los comentarios de otro script.


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

5. Combine los scripts 3 y 4 para que elimine las líneas en blanco y los
   comentarios. ¿Habría más formas de realizar este ejercicio?


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
#ft Ric

grep -o '^[^#]*' $1 > temp && mv temp $1
```

> -o devuelve sólo las líneas seleccionadas
> de manera que podemos redirigirlo hacia un
> archivo temporal que luego renombramos.
