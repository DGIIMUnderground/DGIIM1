## Ejercicios de guiones de Bash:

Resolución colaborativa del documento `ejercicios-variados-bash.pdf`. Si vas a
solucionar un problema no resulto, siéntete libre para escribir tu solución.
En el caso de que esté ya resuelto pero quieras escribir tu solución alternativa,
simplemente escribe tu código debajo (# author: tu nombre)

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
$ cat $1 | grep -v -e '^$'
```
> Explicación
> La expresión regular `^$` captura toda línea en blanco (`^` y `$` son comienzo y final de línea
> respectivamente.
> La gracia está en usar `-v` porque justo captura el complementario (`--invert-match`)

4. Escriba un script que mediante la orden grep elimine los comentarios de otro script.

```bash
#!/bin/bash
# author: Ric
$ cat $1 | grep -v -e '^#'
```

(Suponemos que los comentarios están en la primera línea) 

