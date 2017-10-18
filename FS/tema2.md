# TEMA 2. Introducción a los sistemas operativos

## Índice
- [Componentes de un Sistema Operatico (SO)
  multiprogramdo](#componentes-de-un-sistema-operativo-multiprogramado)

## Componentes de un Sistema Operativo multiprogramado

### Sistemas multiprogramados y de tiempo compartido.
Como el mejor sitio por donde empezar es el principio, comencemos con una breve evolución de las computadoras, hasta un sistema multiprogramado:

1. **Raimundo Lulio** en el siglo XII escribió *Ars Magna*, en el que se dedicó a diseñar y
construir una máquina lógica de naturaleza mecánica, donde las teorías, los sujetos y los predicados
teológicos estaban organizados en figuras geométricas de las consideradas "perfectas".

2. **Leibnitz**, en 1650 construye la primera máquina que multiplica, cuando descubre *Ars magna*
empieza a trabajar en la primera de algoritmo.

3. **Babbage** a principio del siglo XIX construye la primera máquina que procesa información.

4. A mediados del mismo siglo las matemáticas se empiezan a formalizar y estructurarse,
considerándose un fin por sí mismas, surgiendo los axiomas de Peano, lógica... Todo gracias a
personas y asociaciones como: **David Hilbert** y en 1950 **Burbaki**. Gracias a este movimiento,
**Turing** crea las "máquinas de Turing" y posteriormente "la máquina universal de Tuuring" que
podría considerarse uno de los precursores del ordenador.

5. A este ritmo los ordenadores iban surgiendo de manera natural. **A. Church** saca la máquina de
cálculo **Post** y comienzan a aparecer los nuevos paradigmas: operacionales, funcionales y lógicos.

6. Surge el primer ordenador, **Colosus** para generar tablas de tiro, más tarde los ingleses lo
utilizaron para manejar la información de los radares, aunque no se sabe si el primero fue alemán
por los archivos encontrados tras su muerte a **Kamrao Zure** ingeniero para el ejército alemán
durante la primera guerra mundial.

Aquí se acaba la historia con personajes y comienza la evolución de la arquitectura de los
computadores:

1. **Monoprograma** La más arcaica, requiere de mucho tiempo, ya que un humano introduce programa a
programa.

2. **Lotes** En vez de introducir un programa se introducen varios en un cinta, "lote" esto reduce
algo el tiempo. Para poder controlar los lotes hace falta otro programa, aparece el **sistema
operativo**, denominado *monitor* por el inglés **Christopher S. Strachey**, pionero también de los
lenguajes de programación con *CPL*. El problema de esto era el tiempo que empleaba el ordenador en
los periféricos.

3. Para evitar esto, surgen las **interrupcciones** de la mano de un avanace de sofware y hardware,
en el cual varios programas se desarrolla a la vez EN SITIOS DIFERENTES.

4. Lo cual daría lugar a la **multiprogramación** para evitar solapamientos por el interior
procedimiento, esto se conoce como **S.pool**, por ejemplo si varios programas requieren del uso de
una impresora, el programa que se está ejecutando escribe en un fichero lo que quiere imprimir y
después lo vuelca a esta una vez que ha terminado.

5. Teniendo en cuenta que los lotes son cerrados surgen las **colas**, sistemas de lotes abiertos,
donde el SO controla los programas que esperan y los que se ejecutan, y cuándo termina estos dan
pasos a los siguiente en orden de prioridad. Por tanto, si un programa no utilizaba periféricos u
otros recursos se podía quedar eternamente allí, así surge **el tiempo compartido**, los
programas tienen un tiempo limitado en la CPU.

6. **Multiusuarios** misma idea anterior pero con usuarios, vg: servidores.

7. **Multiprocesadores** más de varias CPU en un mismo ordenador, pueden trabajar en distintas
tareas o en **paralelo**, el mismo programa se divide en varios procesadores que trabajan
simultáneamente.

8. Finalmente distintos ordenadores, con distintos sistemas operativos que trabajan simultáneamente,
todos coordinados por un **macro sistema operativo**.

 18 / 10/ 17

## Compiladores
Sentencia de un programa a1 = b + c + 13. 77
El compialdor lee de izquierda a derecha e intenta identifiar que es cada cosa, ejomplo : a símbolo.
con esto va construyendo **tabal de simbloso ** signo + datos + dirección memoria princiola en la que está esa variable,
cada vez que se haga referencia a *a* se redirrecciona a la direccecion asignada por el compilador.

Historia: primeras compiladores: estaa en las direcciones más bajas, antes más o menso se sabía cual podria ser, antes podía ser direción absoluta.

Aora en alto nivel, la sentencias de contro (if) se lleva a una dirección, machacando contador de programa, por lo tanto tando a datos como a dirección se le asigna zona de memoria. Al igual que el programa, el compilador entonces en vez de asignar direcciones absolutas, asigna direcciones relativas, empieza en 0, dependiendo tipo suma longitud bytes y la siguiente empiez a tras esa suma, tanto en variables como en banc de instrucciones.

Compilamso encuadernamso y formasmos el ejecutables:
  1. ae carga -> se lle del disco a memoria el principal por el so. (lleva un mapa de las direccine sde memro) esto se llama **direccipn base**
  2.- durante la ejecucicio, cada ves se aceda a variale, le suma la dirección base y le da la dirrección real. De direcciones relaticas a reales.

El SO también protee sobre problemas del mismo programa. El acceso a los dispositivos lo hacen rutinas del so, y comprueba que la dirrección de memoria a a que accede es suyo. Si el acceso cae fuera, aborta el programa.

Volviendo a la constante 13.77, se supone que no cambia de valor, el tratamiento de la constante en cammbio, lo reconoce igual que una variable, y reconoce una zona de memoria cuyo nombre es 13.77 la única diferencia, sería igual que una variable que se inicializa al principio, asignándole el mismo valor que tiene el nombre, valor explícito.

Qué puede pasar si me equivoco y machcaco cosas en memero, lo forma más habitula:
  - punteros: estrucuturas dinánmianas de datos. lte equivocas y lo mandas a otra fona de tu
  - arrays: índice que no existe.
  - funciones, por argumentos que se le pasan, los argumentos se puede pasar por:
    - paso por valor, se le da argumento, saca copia y lo que pasa es la copia.
    - pasos pro referencia: lo  que se pasa del progrma princial a la función es la dirección en la que está el argumento de la función ,qué puede ocuurir: asignarle al argumento un valor, y cuando se termine de ejecutar esa función se cambia ese valor.

Por tanto las consantes son tan machacales como las varaibles, (truquillo programador: asignarle variable y ir viendo lo que vale)

Fin el compilador comforme traduce asigna direcciones relativas que empieza por cero y + longitud
cuando se carga en memeori ael sitema operatico se encarga de comprobar qu etodo va bien.

##
- la multiporgramanación no tiene por que ser de tiempo compartido, al revés sí.
- el tiempo compartido

## concepto de proceso.

Cuando hay que leer de disco el sitema usuario no lee, lso lenguajes dan sentecias, cuando se traducen son órdenes de llamadas de sistema operacito, por eemp, donde corresponde se incorporan esas unciones des so.
lo mismo lenguajes fuertemente tipado, hay cosas que el compilador no puede resolcver en tiempo de compilacion, falta informaacioń, al texto le añade instrucciones de compilador, y cuando se está ** paquete de soporte a la ejecución ** el texto del programa, oarar que se ejecute se le llama otro lLo que se ejecuta, lo que parte como inicio, la primeera instruciion esto dse denimian **proceso** lo que en un principio era mi programa.

cuaand estando en una ventana se abre otra ventana, se ejecuta el nevegador, opara cada ventanita hay una **instancia** esa sesión e historia la guarda el navegador, se tiene el mismo programa y distintas instancias, proceso distintos.
ISNTANCIA : CMPIA DEL PROGRAMA particularizado.

## Bloque de control de un proceso.
 La memoria estaría llena de procesos o instancias, el so se encarga de admisnistrar todo, mediante el procesador,
 para gestionar **boqeu control de prceso**, par aello que infromació:

- nombre
- prioridad (so algoritmoq que la modigican) 
- estado: en momoria un progrma puede estar, de disco a memoria;: estado nuevo, como está en memoria, el so gerena blo que de proceso, cuando tiene el relleno de la información esta **preparado** a estar ejecutado, cuando le toqu se ejecutará **estado bloqueado** . 
- contador de programa: dirrecion de la siguiennete que se va a ejejcuat
- datos de contexto: registros que modifica
. informacion audotoria, uso de recursos, ejemplod de uno quee esté sobrecargado, se le da al que gestiona el sitema.
- pntero de memoria: direciones entre las que está un programa, dirección base.


## implementaciín típoca de procesos

 - busca proceso en lista, le da la direcciín recuper ainformació co la qeu carga la información,
 - traza es lo que se pasa, en la cpu

## llamadas al sistema

el usuario no tiene orden para acceder a los recursos "" leer sisco?? se llma función so, para eecuatar eso, (so traa en kernl supe susacio..) la forma de hacerlo se llama **trpa** se camia de modo usuario a kernel, cuando termina deja de serlo.  


