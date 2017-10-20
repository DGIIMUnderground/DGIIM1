*Me proponía a hacer unos apuntes de FS cuando caí en lo bonicos que quedaría haerlos en Markdown, así que para que todos podáis disfrutar de las maravillas de Markdown (y contribuir):*

## MANUAL BÁSICO DE MARKDOWN
### Estéticas
- Para hacer títulos anteponer dos almohadillas \##
- Los subtítulos con \## y \###
- <--- este punto tan molón se hace con \- al princio de la línea
- **Texto en negrita**:  \** texto en negrita \**
- *la cursiva es un bien preciado* para escribir en cursiva es suciciente con  \* texto que va en cursiva \*
- Tachar texto no sé para qué puede servir, pero se hace así \~~ texto tachado \~~
  - Tarea pendiente: ~~busacrle una utilidad a los \~\~ ~~
- Respecto a escribir código... 
  - línea corta con \` código \`  `printf " Multiplĺcate por %i " , $CERO `
  - Código extensísimo  \`\`\` [ejemplo](#tablas) \`\`\` 
 - Para salto de línea  
 dos espacios y tabulador.  
 `Para salto de línea  [tecla espacio][tecla espacio] [tecla enter] continuae scribiendo`
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

### Link
- Un sitio interesante para aprender sobre Markdown es [manuales github](https://help.github.com/articles/basic-writing-and-formatting-syntax/#links)
los link tienen la siguiente sintaxis `[<mensaje>](<link>).`
- Un caso particular son las **referencias a títulos**. Puedes crear un enlace hacia un título
definido con almohadillas \##. Para ello utilizas la sintaxis descrita anteriormente, pero
escribiendo como link el título en minúsculas y sustituyendo espacios por guiones.
Ejemplo.: `[<mensaje>](#visualización-del-contenido) `

### Imágenes

- La sintaxis es `!\[<Texto ayuda>](<link de la imagen>) `
 ![Ejemplo de imagen](https://media.giphy.com/media/aRmAPxula4i7C/giphy.gif)

### Tablas

Hacer tablas en emacs es moco de pavo:

columna 1 | columna 2
---|---
dato 1 | dato 2
dat 3 | dat 4

mirad qué código más sumamente sencillo, se pude pones  más bonito alineando las columanas sin alterarse el resultado, pero ¿ES O NO ES ESTO A CASO UN MANUAL CHAPUCERO?
```
columna 1 | columna 2
       ---|---
   dato 1 | dato 2
    dat 3 | dat 4
``` 
