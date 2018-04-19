### Ejercicio 7.1. Indique cuál ha sido el error introducido en el guión anterior y cómo se corregiría.
Guión anterior:

Para arreglar el fallo, se debe colocar un doble bracket [[]]. //(En verdad no tengo ni idea de lo que hay que hacer aquí. Había que rellenar con algo)
### Ejercicio 7.2. Aplicar las herramientas de depuración vistas en la sección 2 para la detección de errores durante el desarrollo de los guiones propuestos como ejercicios en la práctica 6.

 En principio, todos los guiones funcionan como es debido.

## Ejercicio 7.3. Escribir un guion que nos dé el nombre del proceso del sistema que consume más memoria.
>Comentario Blanca: lo he resuelto de la siguiente forma, porque de su forma, no muestra el nombre sino todos los datos y además me parece innecesario tener que escribirlo en un archivo
`ps aux --sort %mem | tail -1 | cut -d ":" -f3 | cut -d " " -f2 `


```bash
    #!/bin/bash
    #El primer comando ha sido facilitado por Stack Overflow
    ps aux --sort '%mem' > temp.txt
    cat temp.txt | tail -n 1 
    rm temp.txt
```
    
## Ejercicio 7.4. Escribir un guión que escriba números desde el 1 en adelante en intervalos de un segundo ¿Cómo
se podría, desde otro terminal, detener la ejecución de dicho proceso, reanudarlo y terminar definitivamente su
ejecución?
```bash
    #!/bin/bash
    for (( i=0; i>=0; i++ )); do 
        echo $i
        sleep 1 
    done
    ```

Desde otra terminal, podemos identificar el proceso con ps -aux. Para pararlo, ponemos "kill -STOP PID_proceso". 
Para reanudarlo: `kill -CONT PID_proceso`.
Para matarlo: `kill -TERM PID_proceso`
En mi caso, PID_proceso es 2823

## Ejercicio 7.5. ¿Se puede matar un proceso que se encuentra suspendido? En su caso, ¿cómo?

 Sí, sí se puede. Para hacerlo, usamos la orden job para buscar el proceso a matar. Tras esto, usamos "kill -9 %n". n es el número asignado al proceso
 > Comentario Blanca: Otras opciones son:
`kill -TERM <PID>` o `kill %<número_proceso>`

## Ejercicio 7.6. ¿Qué debemos hacer a la orden top para que nos muestre sólo los procesos nuestros?
añadirle -u nombre_de_usuario 
>comentario Blanca: más rigurosamente sería:
`top -u $USER`
