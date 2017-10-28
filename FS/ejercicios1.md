## Ejercicios de guiones de Bash:
A continuación se muestra mí solución (la de una alumna de del primer cuatrimestre sin experecia en Bash) para los ejercicios propuestos para el primer  parcial de la práctica de FS.
Modificciones:
- 27/10/17 Blanca: creo el archivo ejercicio simple 1,
- 28/10/17 Blanca  2
### SIMPLES:

1. Escriba un script que se copie a sí mismo en un fichero llamado backup.sh; el script debe
copiarse a sí mismo incluso si previamente fue renombrado.
```
cp $0 backup.sh
```

2. Realice un script que verifique si hay algún dispositivo pendrive conectado al computador,
si lo está, escriba un listado de los dispositivos montados actualmente de forma dinámica.

```
ls /media/$USER
```

3. Escriba un script que mediante la orden grep elimine las líneas en blanco de otro script.

```
grep . <guionconlineasenblanco> >> <guionsinlineasenblanco>
```
