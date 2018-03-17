# Introducción a latex para principiantes  
> Como ya habrá tiempo para pelearse con emacs autex y orgmode he aquí un manual basiquísimo de latex, a modo de resumen de lo que conozco de latex  
Antes que nada estás son páginas de interés:
- Puede encontrar variedad de plantillas [latex templates](https://es.sharelatex.com/templates) ( nada mejor como aprender del que sabe).
- Si no se acuerda de algún simbolo [detexify](http://detexify.kirelabs.org/classify.html) le permitirá dibujarlo.


## Primeros pasos  
Las distribuciones de linux ya suelen traer instalada una distribución de latex, pero para asegurarnos de que no nos faltan paquetes y enloquecer en busca de erros sintáxticos haga usted un 
`sudo apt-get install texlive-full`

Mientras se instalan, disfrute usted de la buena lectura de esta guía básica (aunque con lo que tarda te recomiendo ir a por un té)

Al pricipio, cuando no estamos familiriacidados con la sintaxis la forma más rápida de trabajar es ver lo que se está haciendo Gummi es una gran opción para ello:  

`sudo apt-get install gummi`  Así de simple

## Estructura de un documento latex  

La estructura mínima para un docuemnto en español 

```tex
\documentclass[a4paper , 11pt, spanish ]{article}

% Codificación e idioma, para las tildes crucial
\usepackage[utf8]{inputenc}
\usepackage[spanish]{babel}
\usepackage[T1]{fontenc}
\usepackage{textcomp}

%comenzo del cuerpo 
\begin{document}
Texto súper 
\end{document}
```

### Órdenes y macros  
Instrucciones que comienzan por el caracter \ 

Sintaxis | Significado   
--- | ---  
\title{TÍTULO} | Escribir títulos  
\date | Escribir la fecha  
\author | Para autores 

## Tipos de secciones con el begin

sintaxis:

```tex
\begin{<ALGO>}
<Texto>
\end{<ALGO>}
```

Tipo de sección (`<algo>`)  | comentario 
--- | --- 
enumerate  | Para numerar secciones (como ejercicios) `\item` para un nuevo número   
itemize | Listas sin orden, por defecto un cuadrado, se crea con `item` de nuevo   
equation | Comenzar fórmula con numeración a la izquierda  
figure | Para colocar una imagen en formato jpeg, jpg o pdf, [h] para indicar que se coloque en la zona en la que se escribió la isntrucción   
tabular | Realizar tablas [ alineación]  
table | para crear tablas, detro tienen distintas tabulaciones :) `\centering` para centrar  




## Salto de línea y de página   

Sintaxis | Utilidad  
---  | ---
\\ | Nuevo párrafo  
\\* | Nueva línea sin párrafo  
\newpage | Para saltar a na nueva página
## Fórmulas en latex

- la fórmula se de una línea se pueden escribir entre llaves, la otras entre `\[ ... ]\ ` 
- también se puede utilizar `$... $` para fórmulas cortas, aunque no es muy recomendado   


 Sintaxis		        | significado  
 --- 			   	| ---  
 `\sum_{abajo}^{arriba}` 	| sumatoria  
 `\prod_{subíndice}^{supe}` 	| productorio  
 `\in `				| pertenece  
` \frac{numerador}{denominador}`

## Caraceters especiales  
letra | sintaxis  
--- | ---   
letra con raya arriba, como la media | ` \bar{x}`   


## Alfabeto griego

 letra		| sintaxis
 --- 		| ---
 \alpha 	| `\alpha`
 \beta 		| `beta`

## Tipografías y estilos varios  

### Familias  
Este nombre es el que recoge una variación de fuentes de Latex 

Sintaxis  | Significado  
--- | ---  
\rmfamily | letras con remate  
\sffamily | letras sin remate  
\ttfamily | letras mecanografiadas    

## Tablas  
El ejemplo habla por sí solo:  
```tex
	\begin{tabular}{|c|c|c|c|} %rayas para indicar que lo quieres separado, c indica centrado
	\hline
	$x_{i}$ & $n_{i}$ & $N_{i}$ & $fi$\\ %importante que detecte que es una fórmula y escriba el subíndice
	\hline
	0 & 80  &      & 0.16 \\
	1 & 110 &     &   	  \\
	2 &     & 320 &   	  \\ 
	3 &    	& 	  & 0.18  \\
	4 & 40  &     &       \\
	5 &     &     &    	  \\
	6 & 20  &     &   	  \\
	\hline
\end{tabular}
\\
```

## Fuentes de aprendizaje  

Página | Apreciación  
--- | --- 
[el club del autodidacta](http://elclubdelautodidacta.es/wp/indice-latex/) | Manual por excelencia sin lugar a dudad, enhorabuena a quién lo escribió
[ wikibook latex ](https://es.wikibooks.org/wiki/Manual_de_LaTeX)  | Altamente recomenda: amplia, clara y con ejemplo  
[latex fácil ](http://nokyotsu.com/latex/curso.html) | Aunque un tanto anticuada, muy buena para aprender también, un blog cuidado con gran variedad de ejemplos  
[ wed muy del 200 ](http://www.personal.ceu.hu/tex/)  | Para consultas puntuales, te redirecciona a otras páginas  
[Trabajar con mútliples ficheros simultáneos](https://es.sharelatex.com/learn/Multi-file_LaTeX_projects) | Indica cómo trabajar con múltiples ficheros simultaneamente  
