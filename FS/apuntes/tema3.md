lenguajes : en base a

#Lenguajes de primera generación
No cambiamos nada, le ponemos nombre que nos recuerde que es lo que hace una instrucciojn

1.Lenguajes máquina: binario -->código de instrucciones  | operandos
 

Lo habitual es que para una vez se hacen máquinas que hacen refe

2. Lenguaje ensambrador:
en lugar de escrinir en binario, a cada parte se le asigna un símbolo
ENSAMBLADOR : Símbolos en el operando para quitar los 0 y los unos se tiene otra relación en una tabla, con los nombre que sonotro queramos (en principio) , esa tabla no la trae el se construye y tiene alguna restricción (que empiece por letra TABLA DE SÍMBOLOS, (recordar mapa de los ejejcutables) 
para construir ensamblador (se tiene directoria máquina, a cada una le corresponde un código binario, a esto se e asigna un nombre ejemlo
Repertorio 
LOAd es el 001101010 (inventado9 se e asigna nombre corto
 STARD 010101001
 ADD
 Esto se hace por tablas, si coincide el nombre va a por ella

La traduccuion de ensamblador a maquen en tablas de emsamblador con la se símbolos (la variables) creadas por el programador

---
# Segunda generación de lenguajes
3. MACRO ENSAMBLADORES
(MACRO secuencia de órdenes ordenadas) Hay determinada secuencias de instrucciones que se repoiten con frecuencia, se empaqueta y se hace macro
macro ensamlador: repertorio y otra serie de macros, el traductor de un macro ensamblador se le asignna un nombre que se busca en la tabla y te dará una lista de instrucciones.

# Tercera generación de lenguajes 51-52

El problema no era diseñar el lenguaje, sino el traductor y que una persona a papel no lo hiciera mejor, el lenguaje para el que hacen un compilador eficicente FORTRAN 1957 John Backns, (un compilador es un traductor, pero el traductor puede ser compilador o intérprete ) el lenguaje de control del sistema operativo es interpretado, estsoo no te generan ningún fichero.

Estos lenguajes son de "ALTO NIVEL", lo que hacien (lenguaje de sóimbolos) que incorporaban estructura en :
##### datos: estructuras, valores agrupaos que se pueden reconocer, ejemplos que : array, string, struct (tipo regsistro), con esto aparece la idea de tipo de dato: fichero, array, entero....
  - **primitivos**: el entero el real, naturales que permite manejar la máquina física: char, int, real  EL LENGUAJE LO CONOCE TODO
  - estructurados: tinen alguna estrucutura en base de primitivos : CONOCE MACROSCÓPICAMENTE LA ESTRUCTURA. del género lo conoce, pero tienei que afinarlo, tines que decir los campos que tiene y com afinarlo,
    - aparece la idea de expresión: (a+b)*f, esto antes no se podía hcer con macro ensambladores,
    - CONTROL DE FLUJO: en repertorio máquina lo que hacía que hacer era el acumulador o la dirección de memoria
      - if
      - bucles definido (en los 70 indefinido)
  (más tarde: - TDA tipos de datos abstractos, el lenguaje no conoce ni la estructura, ni el lenga)
Con esto aparecen dos tipos de sentencias (una sentencia es una ordden) 
- semanticamente simples : su signifiado solo depende de ella y de nada más, ejemplo una asignación , operación de entradas y salida de una sola variabe
- semánticamente compuestas, en esamblador no hay otra, una sentencia se ejecuta, y otra igual, en macro emsamblador, en alto nivel apareccen los dos, 
se formaliza tipo como terna tipo (G géreno (tipo, conjunto valores posoble, cómo se representan vg complemetat a uno o a dos) , Operaciones , Propiedads)  (GOP) ejemplo
int
- género: desde {-2 elevado aknl , 2 elecakjd}
- operacones susma rect
- propiedades : communtativa...
- **lo estructurado**s, array, ficheros, lo que conoce el lenguaje es la estrucutura del tipo èro no la composición (género), ejemplo array:
conoce el tipo de filas y columnas, luego abría que dar el tipo de dato, los valores primitivos con los que trabaja, lo que define el programador es el género,  género del tipo al que poertenece un vecor es por ejmplo R^3, pero no se puede multipliar un array con un array, las operaciones predefinidas no son para las matrices. SU GÉNERO Y OPERCIONES SON es una tabla de género, su género será {0, 1, 2} -> R a cada uno de sus elemento se le asigna un género.

Lo que tienen es que manipula una estrucutra ordenada como matrices pero se trabaja de manera individual, accediendo a ellos con una applicaciones
 El tipo establece la representación, en un array a representaciń de ese tipo de tres componentes de tipo real le asigna una dirección de memoria, y a partir de esa dirección de memoria que le asigne reservará espcacio para tres.
- instruciones: construiir sentencia de alto de nivel que haga de macro

#### Sentencias:
- expresiones: 
- sentencias compuestas: Esto influye en la ruptura del flujo, sentencias : leer, escribir, asignación, condicionals, bucles definidos, e indefinidos (while)
  - secuencias semáticamentes simple de una variable, las otras condicionas son semánticamente simples, con la sentencia de asignación, a = expresión, eso se corresponde con carga *load* b y lo almacenas en b (en a = b ) si es una expresion más compleja la única que se asemeja es la anterior, el compilador  el traductor se encara solo de la última,
  si tengo la instrucciń leer a, b , c , d, esto lo que hace el leer a , leer b , leer c... el paso a un nivel de alto nive es desarrollar el nivepl de machro nivel, esas instrucciones fijas son comon n patrón ,
  ^``` if expr the ```,
  un bucle definido tiene tiene teres expresiones: la incial, el final y el incremento, la semántica dle for es: ejecuta el cuerpo tal número de veces, un determinao número de veces, determinado antes de entrar, eso se hace con la expresion final - inicial divido entre el incremento. Para implemtarlo, se calcula un nḿeor entero ((la repeticiones) crea una variable menor que eso, pregunta si es menor, si los es ejecuta el cuerpo se recta uno y si sigue siendo meno se vuelve a repetir, SEMÁNTICA DLE FOR, hay comppiladores que lo ue hacen es calcular el número, si hacemos referencia a la variaboe asociada dommy variable, variable ficticia, si solo aparece ahí ahiu compiladores que ni la pones en la tabla de signo, si se utiliza en otro sitio ni la cambia, otros en cambio si que lo emplementa, pero en teoría no es la semántca ni lo que tienen que hacer, en otro no le asignab valores, a no ser que se utiloce dentro del cuerpo. SEMÁNTICA, EJECUTA EL CUERPO TAL NÚMEOR DE VECES.


### Definición de la gramática
Para definir lenguaje se necesita solo y exclusivamente esto: 
- vocabulao: cujjunto de palabras, lexco, reglas para construir lexñico
- diccionario: le asigna un significado a cada palara, significado atómico, su signifiaco no depende de otra, (sin incluir eto)
- gramatica define un aestrucutura, o más , estruccutia sintáctica, --> estructura semantica y se asocian significados, lo idea es que la sintactica cuincida cn la semántica.
- para obtener significado de conjunto de palabras se analizan inidivida y su estructuta y se construye significado concreto. 
 - Depende del contexto,
 - preciso y conciso
 - sin ambigúedad
 ---
 En los lenguajes de programación, definida de gramaica forma:  palacreas y estructutras
 simbulos de la cuadrpla:
 gramatica sol cuerpo, sin sgnifiacao
 - los singnos terminales son las palabras, tinee estructura, le asoscio significado atómico.
 - lso no terminales son los que se construyen a partir de palabras: frases, oraciones... definen estrucutras, tienen alguna estructura en la que intervienen signos terminales y no termianles, como tienen estructura habrá reglas para conformarla, **regplas de producción**

para eliminar la abguedad sintactica, cada elemeto no terminal, tenga una sola estructuta, las forma de que cada elememto no terminal es que tengan forma de árbol, de toda la forma que cuando yo vaya a entedet todo esto converegue a la raíz, que ese es el símbolo inicial de la gramática.

Si lo que se hace es generar frases, se genera tood el ´arbol.

dada la gramatica
flecha derecha estrutura simbolo no terminal izq simolo termian, , alternativas: barra vertica  ,

la e y la o no son terminal, sin estructura, con una regla de producción que define su estructula, uno o puede ser una o un por  n mas , menos, expresión una E opert¡dad con o una expresión enre parenteses, y la id identificador, un nobre de lo que sea, a partit sde esa grapatia se pede generar árboles,
ña estructura es vn, se coge la frase, se lee de izquierda a drecha, se ve si hay aguna regla de la gramática que reconozca a id, se coge una expresión,  deeb ser sintácticamente y gramanticamente corrector gracias a la regla semántica. 