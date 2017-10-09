# Git/Github básico

Github sobre todo al princio puede resultar un lío, así que he aquí lo básico.

## ¿Cómo "subo" mis "cosas"?

0. `git status`

El comando 0 es realmente un comando sin orden. Ejécutalo siempre que
quieras información sobre que estás haciendo. La información que da siempre es
útil aunque no la entiendas porque ¡la mayoría de las respuestas a tus preguntas
se obtienen copiando y pegando en Google!


1. `git pull <remote <branch-name>` (Normalmente git pull origin master)

<remote>: Es la dirección remota del repositorio, en nuestro caso apunta a
nuestro lugar en los repositorios de Github
<branch-name>: La predeterminada a utilizar suele ser master.

Este comando te descarga todo el trabajo realizado por los otros.
Es importante ejecutarlo siempre antes de escribir nada, aunque si 
se te olvida e intentas sobrescribir, `git` es bastante inteligente
para no dejarte hacerlo!


(Aquí es cuando creas archivos, modificas otros y pasas un rato de diversión).


2. `git add <ruta-archivo>` (Así, `git add .` añadiría al repositorio

Este comando añade a la fase de `staging`, que podríamos llamar como
almacnamiento o pre-commit. Para entendernos, es como que el registro de los
cambios no es total. Los cambios ya quedan registrados con `git commit`

3. `git commit [-a -m "Título"]`

Este comando registra los cambios en la historia del repositorio. No te
preocupes si te llegas a equivocar registrando cambios, porque en git no hay
prácticamente nada que no se pueda recuperar... pero mejor ¡controla un
mediante `git status` qué cambios quieres realmente registrar!

El significado del corchete en la orden es que `-a -m "<Título>"` son
parámetros opcionales.

Por ejemplo:

`git commit`: Llamará a tu editor por defecto para escribir el mensaje de
commit. Deberás escribir en la primera línea, citando a Blanca "un Título
exclarecedor sin aaaaa". (Recuerda que utilizamos un sistema de gestión de
versiones que es git para controlar mejor los cambios que vamos realizando).

`git commit -a`: Sera un atajo que realizará `git add .` y `git commit` en el
mismo comando. Úsalo sólo si sabes que todo lo que puede añadirse al
repositorio, quieres que sea añadido.


`git commit -m "Mensaje del commit"`: Registra el commit con una línea de
mensaje (que se correspondería con la primera línea del archivo que se editaría
con la orden `git commit`.). Recuerda escribir un mensaje de commit adecuado.

Consejos genéricos: 

    - Utiliza `git commit -m `: A no ser que quieras escribir descripciones al
      estilo Blanca con `git commit`, no suele ser necesario añadir otra cosa
más que el título (si este está suficientemente claro).

    - Debes intentar que un commit reúna en un mensaje cambios relacionados.
      Ejemplos de títulos pasables son:
        "Corregir erratas" "Actualizar ejercicio tal" "Ejercicio x portado a latex". 

    - No valen mensajes como: "mejorando cosas" "ejercicios" "bomba nuclear".
      Los dos primeros por ser ambiguos y el siguiente por absurdo.

4. `git push <remote> <branch-name>` (Normalmente `git push origin master`)

Una vez tienes tus cambios registrados en tu ordenador es hora de compartirlos
con los demás.

<remote> y <branch-name> actúan como en `git pull`.  Sin embargo, este comando
es para justo lo contrario, subir tus cambios locales al repositorio remoto.

Recomendación: intenta ejecutar `git push origin master` cada vez que hayas
hecho un commit para evitar conflictos.

## Trabajar con ramas

- `git branch`
- `git checkout <rama>`