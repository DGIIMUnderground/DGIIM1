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

Estos lenguajes son de "ALTO NIVEL", lo que hacien (lenguaje de sóimbolos) que incorporaban estructura :
- datos: estructuras, valores agrupaos que se pueden reconocer, ejemplos que : array, string, struct (tipo regsistro), con esto aparece la idea de tipo de dato: fichero, array, entero....
  - primitivos: el entero el real, naturales que permite manejar la máquina física: char, int, real  EL LENGUAJE LO CONOCE TODO
  - estructurados: tinen alguna estrucutura en base de primitivos : CONOCE MACROSCÓPICAMENTE LA ESTRUCTURA. del género lo conoce, pero tienei que afinarlo, tines que decir los campos que tiene y com afinarlo,
    - aparece la idea de expresión: (a+b)*f, esto antes no se podía hcer con macro ensambladores,
    - CONTROL DE FLUJO: en repertorio máquina lo que hacía que hacer era el acumulador o la dirección de memoria
      - if
      - bucles definido (en los 70 indefinido)
  (más tarde: - TDA tipos de datos abstractos, el lenguaje no conoce ni la estructura, ni el lenga)
Con esto aparecen dos tipos de sentencias (una sentencia es una ordden) 
- semanticamente simples : su signifiado solo depende de ella y de nada más, ejemplo una asignación , operación de entradas y salida de una sola variabe
- semanticamente compuestas, en esamblador no hay otra, una sentencia se ejecuta, y otra igual, en macro emsamblador, en alto nivel apareccen los dos, 
se formaliza tipo como terna tipo (G gereno (tipo, conjunto valores posoble) , Operaciones , Propiedads)  (GOP) ejemplo
int
- género: desde {-2 elevado aknl , 2 elecakjd}
- operacones susma rect
- propiedades : communtativa...
lo estructurados, array, ficheros, lo que conoce el lenguaje es la estrucutura del tipo èro no la composición (género), ejemplo array:
conoce el tipo de filas y columnas, luego abría que dar el tipo de dato, los valores primitivos con los que trabaja.
- instruciones: construiir sentencia de alto de nivel que haga de macro 