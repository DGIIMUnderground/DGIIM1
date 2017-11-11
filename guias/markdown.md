*Me proponía a hacer unos apuntes de FS cuando caí en lo bonicos que quedaría haerlos en Markdown, así que para que todos podáis disfrutar de las maravillas de Markdown (y contribuir):*

## MANUAL BÁSICO DE MARKDOWN
### Estéticas
- Para hacer títulos anteponer dos almohadillas \##
- Los subtítulos con \## y \###
- <--- este punto tan molón se hace con \- al princio de la línea
- **Texto en negrita**:  \** texto en negrita \**
- *la cursiva es un bien preciado* para escribir en cursiva es suciciente con  \* texto que va en cursiva \*
- Tachar texto no sé para qué puede servir, pero se hace así \~~ texto tachado \~~
  - Tarea pendiente: ~~buscarle una utilidad a tachar~~
- Respecto a escribir código... 
  - línea corta con \` código \`  `printf " Multiplĺcate por %i " , $CERO `
  - Código extensísimo  \`\`\` [ejemplo](#tablas) \`\`\` 
 - Para salto de línea  
 dos espacios y tabulador.  
 `Para salto de línea  [tecla espacio][tecla espacio] [tecla enter] continua escribiendo`
 - Separaciones con rayas 
  ```
  ***
 Qué
 - - -
 Rayada
 ___
 ```
 ***
 Qué
 - - -
 Rayada
 ___
 
 
 ### Hacer aparecer y desaparecer caracteres
 - Para que aparezca símbolo reservado de Mardown anteponer \ al símbolo. 
  <br />	\~\~Blanca hace los mejores manuales del mundo \~\~ 
  <br />	`\~\~Blanca hace los mejores manuales del mundo \~\~ `
  
 - ¿Te ha pasado que has escito algo tipo \<¡VIVAN LOS YOGURES DE SOJA!\> y ha desaparecido?  
 No olvidemos que el objetivo de Markdown era poder escribir texto plano fácil de leer y escribir y que pudiera convertirse en texto XHTML, <p> Su sintaxis <\p> admite instrucciones de html, que si mal no recordáis era del tipo \<algo\>.
	  <br />	\~\~Blanca hace los mejores manuales del mundo \~\~ 
  <br />	`\~\~Blanca hace los mejores manuales del mundo \~\~ `
  

### Visualización del contenido
- **Pandoc** es muy útil
 Instalación:  `sudo apt-get install pandoc`
 convertir archivo a pdf:  ` pandoc <archivo>.<algo> -o <nuevo_nombre>.pdf`

Si queremos convertir a pdf un archivo markdown con la sintaxis propia de Github,
es decir "Github flavored markdown", es necesario especificarlo asi:

```console
$ pandoc ejemplo.md -f markdown_github -o ejemplo.pdf
```


### Link
- Un sitio interesante para aprender sobre Markdown es [manuales github](https://help.github.com/articles/basic-writing-and-formatting-syntax/#links)
los link tienen la siguiente sintaxis `[<mensaje>](<link>).`
- Un caso particular son las **referencias a títulos**. Puedes crear un enlace hacia un título
definido con almohadillas \##. Para ello utilizas la sintaxis descrita anteriormente, pero
escribiendo como link el título en minúsculas y sustituyendo espacios por guiones.
Ejemplo.: `[<mensaje>](#visualización-del-contenido) `

### Imágenes

- La sintaxis es `![<Texto ayuda>](<link de la imagen>) `
 ![Ejemplo de imagen](https://media.giphy.com/media/aRmAPxula4i7C/giphy.gif)
 
- También se pueden subir con la sintaxis de html, que te permite ajustar su tamaño y además indicarle que está en su mismo directorio. `<img src="carpeta\imagen.ext" width="200" heigh="600">` 
Préstese especial atención a que *img* va pegado a < y que los tamaños se escriben entre dobles comillas, estos se pueden omitir y te cogerá el tamaño propio de la imagen. 
<img src="media\haskell.png" width="200" heigh="200">  

### Vídeo 
Github no permite añadir vídeos como tales, pero podemos enlazar un vídeo a una imagen.  
Como antes dos sintaxis, la de markdown, perdiendo la capacidad de controlar el tamaño:  
`[![texto de la imagen](enlace_imagen)](enlace_del_video_en cuestión)`  
`[<img src="directori\image" width="999999" height="000000">](enlace)`  
Os dejo como ejemplo mi grupo favorito :heart:
[<img src="media\vetusta.jpeg">](https://www.youtube.com/watch?v=6EGCURYvBhw)

Si no está en github, puedes utilizar esta sintáxis`@[texto_vídeo](enlace)`  
También tenemos la sintáxis en html:
 `<a href="http://www.youtube.com/watch?feature=player_embedded&v=YOUTUBE_VIDEO_ID_HERE
" target="_blank"><img src="http://img.youtube.com/vi/YOUTUBE_VIDEO_ID_HERE/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" /></a>`

### Tablas

Hacer tablas en markdown es moco de pavo:

columna 1 | columna 2
---|---
dato 1 | dato 2
dat 3 | dat 4

mirad qué código más sumamente sencillo, se puede poner más bonito alineando las columnas sin alterarse el resultado, pero ¿ES O NO ES ESTO A CASO UN MANUAL CHAPUCERO?
```
columna 1 | columna 2
       ---|---
   dato 1 | dato 2
    dat 3 | dat 4
``` 

### Emoticonos markdown  
Esta persona se lo ha montado súper bien, os dejo su [repositorio](https://gist.github.com/rxaviers/7360908) 

