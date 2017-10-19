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


Apuntes del 18 / 10/ 17

## Compiladores

Ejemplo de sentencia de un programa a1 = b + c + 13. 77
El compilador lee de izquierda a derecha e intenta identificar cada elemento, construyendo
una **tabla de símbolos**.

Signo |  Datos |  Dirección memoria asociada
------| ------ | -----------------------------
a1    |   666  |   0xab0f20x53 (En hexadecimal)


De esta manera, cada vez que se haga referencia a *a* se redirecciona a la
dirección asignada por el compilador.

En los primeros compiladores el número de direcciones era menor y se podía
hablar de dirección de memoria absoluta. Sin embargo, en la actualidad, a alto
nivel, el uso de direcciones es más complejo, abarcando incluso direcciones de
direcciones, como es el caso de de las sentencias de control (if, while...).
Para facilitar el trabajo se hacen asignaciones de **memoria relativa** en lo
que respecta a la zona de memoria que se le otorga.  Estas direcciones
relativas comienzan en 0 y continuan dependiendo del tamaño en bytes del tipo
de dato almacenado. 

Los pasos que comprenden un programa antes de ser ejecutado son: compilación,
encuadernación y la formación del ejecutable:

- Durante la carga del programa, se lee del disco y se copia esa información en
  memoria principal por el SO. El SO contiene un *mapa* con las direcciones
relativas de memoria. Estas se suman a la llamada **dirección base**, para
obtener las direcciones reales (cada vez que se quiera acceder a una
variable durante la ejecución).

El SO también protege sobre problemas del programa. Por ejemplo, el acceso a los
dispositivos lo hacen rutinas del SO, que comprueban si la dirección de memoria
a la que accede el programa es correcta. En caso contrario, el SO se encargar
de abortar el programa.

Volviendo a cómo se almacenan la variables, en lo concerniente a las constantes,
estas se tratan exactamente igual que las simbólicas, con la única diferencia
que como identificador, el nombre de la variable es el propio símbolo, el resto
es lo mismo, como valor se guarda a ellos y tiene también una dirección de
memoria asociada.

  - **Punteros**: Es una variable que almacena una dirección de memoria.  Son
    la base de las estructuras dinámicas de datos. El riesgo de su uso radica
 en la posibilidad de sobreescribir los datos de la memoria por error.

  - **Arrays**: son realmente punteros encadenados en bloques de memoria. Así, es posible
    recorrer el *array* mediante aritmética de punteros, es decir,
aumentando en 1 la dirección de memoria asociada.

  - Existen dos formas de pasar argumentos a una función:

    - *Por valor*: en la función se trabaja sobre una copia del valor pasado. Se
      puede considerar más seguro ya que un cambio en la variable dentro de la
función no influye de ninguna forma al valor original.

    - *Por referencia:* a la función se le pasa la dirección de memoria de una
      variable. Por tanto, la función puede modifica el valor original, lo que
      constituye un riesgo en caso de error.

> En el caso de C++ existen dos subtipos de paso de referencias: por
> punteros, o por referencias. El paso por punteros es heredado de C, mientras
> que las referencias son específicas de C++, y facilitan el paso de referencias
> evitando errores debidos al trabajo con punteros.

## Resumen

El compilador conforme traduce, asigna direcciones relativas a
variables y controladores de flujo. Cuando el programa se carga en memoria el
SO es el encargado de gestionar el acceso del programa en memoria.

## Algunas preguntas

- La multiprogramación no tiene por qué ser de tiempo compartido. Pero,
  para que sea posible el tiempo compartido es necesario un SO multiprogramado.

## Concepto de proceso.

Cuando hay que leer de disco el sistema usuario no lee, los lenguajes dan
sentencias, cuando se traducen son órdenes de llamadas de SO. El SO incorpora
funciones propias donde corresponde al programa.

Lo mismo con lenguajes fuertemente tipado, como hay cosas que el compilador no
puede resolver en tiempo de compilación por falta de información, el compilador
añade instrucciones al texto (*paquete de soporte a la ejecución*), para que
poder ejecutarlo.  Así, se puede denominar *proceso* al programa original
ejecutado, es decir quitando la lógica añadida por el SO.

Ejemplo:

Cuando, con el navegador abierto, se abre otra ventana del navegador,
para cada ventanita hay una **instancia** con la sesión y la historia
que guarda el navegador. Es decir, se tiene el mismo programa pero
con varias instancias, es decir con distintos procesos. Podemos decir
que un proceso o instancia es una ejecución particular del programa.

## Bloque de control de un proceso.

La memoria estaría así llena de procesos o instancias. Así, el SO es el
encargado de administrarlos de la forma correcta, para que todos sean
ejecutados por el procesador de forma secuencial. Además, el SO tiene la
capacidad de poder **bloquear un proceso**. Para ello, necesita la
siguiente información sobre cada proceso:

- Nombre
- Prioridad (SO algoritmos que la modifican) 
- Estado: en momoria un progrma puede estar, de disco a memoria;: estado nuevo,
  como está en memoria, el SO genera un bloque de proceso, cuando tiene el
relleno de la información esta **preparado** a estar ejecutado, cuando le toque
se ejecutará **estado bloqueado**. 
- Contador de programa: dirección de la siguiente que se va a ejecutar.
- Datos de contexto: registros que modifica. Informacion auditoria, uso de
  recursos, ejemplos de uno que esté sobrecargado, se le da al que gestiona el
sitema.
- Puntero de memoria: direciones entre las que está un programa, dirección base.


## Implementaciín típica de procesos

 - Busca proceso en lista, le da la direccióín recuper información con la que
   carga la información,
 - traza es lo que se pasa, en la CPU

## Llamadas al sistema

El usuario no tiene orden para acceder a los recursos "" leer disco?? se llma
función SO, para ejecutar eso, (so traa en kernel supe susacio..) la forma de
hacerlo se llama **trpa** se cambia de modo usuario a kernel, cuando termina
deja de serlo.  

## Modeo de lo scinco estados.

- nuevo

- preparado: si se le acaba el tiempo pasará a preparado

- preparado 

- ejecutándose

- finalizado: si el programa terminade ejecutarse, el SO actualiza la lista de procesos y libera esa zona de memoria, eso se convierte en basura.

Cuando se carga un programa nuevo:

 - instrucciones.

  - datos: variables sin asignar un valor, estas tiene asignado un valor, basura, el que esta en memoria de otro programa. Hauy compiladorea que te permiten ver en la parte derecha, y puede saber que no le has asignado ningún valor, cuando la vas a utilizar te avisan. (otros no te dan ningún error ni en compilación ni en ejecución). Lo que sí se recomienta es trastear con el compilador. Hay compialdores que en el for la i la ponen, otros no la hacen, calculan el número de vueltas que hace el bucle. Otros, que si haces referencia dentro del buche a la i asocia sí lo tienen en cuennta, y si no no. Te implementea la veces que se repite, esta variable se conoce como void variable **variable vvacía** .


## Transicones entre estados

Diaposiica, en algunos casos aparece de preparado  finalizado, por el mismos no, porque otro proceso lo mate, la inmensa mayoría de so no lo permite. En modo super usuario sí se puded.

## Descripción de procesos:

- punteros de pila: cuando se ejecutan funciones

diferencia entre un apila: el primero que se atiende el último que ha llegado
cola: se atiende el primero que ha llegado

en la sfuncines cuando se va acumulando se forma n
**registro de activación** donde estan los datos, se guarda la dirección en una pila, tiene una dirección que es lo que se conoce como puntero de pila, que soluciona todos estos prolemas.

## Creación de un proceso:

 ## Controll de processos: modode sd eejecución del procesador.

- modo usuario: no accedo a todos los registro de memora, n contador de programa, o registro de instrucción, tampoco otros instrucuciosnes

- modo núcleo, kernel, supervisoor o sistema:

para pasar de uno a otro, se detecta que hay una operación que no se puede hacer en modo usuario.:
 - cuando hay una llama a sistema: leer disco, C pone un código que supone una rutina del so

  - llamo sistema, se lee el dato que quiero, se manda interrucción, en el ciclo de instrucción mira a ver si era la siguiende, cuan es interrucion so compara la prioridad

  - cuando haya una excepción, algo que no debería ocurrir pero ocurre, "overfloat" se levanta un aaletrar etra el so, si lo que pasa no tiene riesgo para el resto de lo sprocesos se deja pasaer (depende del compilador), otra que ocuure se lee de un ficheo, se acaba y se pide que se igue leeye, s en  este caso se aborta el programa.

  - acceder a zona de memoria que no es de tu proceso.


## pasos en la operación de cambio de ususario a kernel:

- el que detecta el cambio de modo es el hardware, cuando el compilado detecta qun ainstruccíon, o interrucón o excepción, la circuitería camia a modo kernel, salva el contador de programa, y la palabra de estado del proceso, hay un bits, le cambia el estado,

- se llama a la rutina que lo gestiona, cuando se sabe cuá, la direccion de esta rutina se mete en el contador de programa. Y y aempieza a ejecuatrse esa rutina.

- dependiendo de la "emergencia", es posble que tenga que salvar el resto de registros de la cpu, en un overfloat como no dice nada no cambia nada, en la palabra de estadlo pone un bits, pro si el compilad r lo tennía previsto,

- cuando termina resustaura, contador de programa con el proceso y la palabra de estado,

esencia programa eecutado de usuari a kernel, lo mismo ocurre cuando aparecen nuevos procesos.
diferencai ; como e cambia de proceso se salca todo do bloque del contros del proceso se coge se cambia, slava- guarda.

## conspto de hebra

proceso: programa + lo aue necesir a, la unidad de procesamieno, lo qu el so le asigna los recurso que necesite,
puede ocurrirr (cada sistm hace los que le sale de las aricese) ejemplo se está navegando, se abren ventana, proceso s distintos,
tennemso instrucucines y datos, el proceso es el mismo, lo que cambia son lso daos , en vez d arir procesos nueco s, ae abren hebras, proceso el mismo, datos de cada ebra distindo, deteo del bloque de conrtol de proceos se parten nuecos registos , direcciones, se ahor amusah memori ad eisntrucciones.

navegado --> proceso asociado a ese programa, dentro de la misma ejecucion (navegador) se abre una hebra. Hebra eecución independiente del mismo proceso.x