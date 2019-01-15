# Makefiles

## Índice

0. Introducción
	- Contenido de un makefile
1. Reglas
	- Sintaxis de una regla
	- Reglas especiales
	- Reglas implícitas
2. Variables
	- Aspectos básicos sobre variables
	- Características de las referencias a variables
	- Variables específicas
	- Variables especiales
3. Directivas y funciones
	- Directivas
	- Funciones
4. Otras utilidades de interés
5. Makefile de ejemplo final
6. Bibliografía y datos del autor

## 0. Introducción

Un archivo del tipo *makefile* es un archivo que hace uso de la utilidad `make`. Esta utilidad determina que partes de un programa deben de compilarse, y les manda comandos para hacerlo. En esencia, un *makefile* sirve para autocompilar un proyecto en lugar de hacerlo manualmente.

Para poder hacer uso de `make`, en primer lugar debe crearse un archivo del tipo *makefile*. Para ello basta con crear uno con nombre "makefile" o "Makefile". Ambos nombres son completamente válidos (el manual de la GNU recomienda usar el segundo, puesto que suele aparecer cerca del inicio en los listados de directorios, junto otros arhcivos importantes como README).

Es posible también nombrar un archivo *makefile* con otro nombre, pero debemos especificarselo a make después con uno de los siguientes formatos:

```bash
make -f ARCHIVO
make --file=ARCHIVO
make --makefile=ARCHIVO
```

En estos apuntes se usarán ejemplos de programas en lenguaje C++. Los makefiles sirven para muchos más lenguajes de programación, además del presentado en estos apuntes. Para información más a fondo sobre makefiles que no aparezca en estos apuntes de puede consultar el manual de la GNU de la orden ``make``, cuyo enlace se encuentra al final del documento.

### 0.1. Contenido de un makefile

Los makefiles están compuestos por 4 tipos de cosas:

1. **Reglas**. Es en definitiva lo que queremos que haga la orden ``make``.
   1. Relgas explícitas. Reglas descritas por el autor del makefile.
   2. Reglas implícitas. Reglas automáticas de ``make``.
2. **Definiciones de variables**. Las variables son alias puestos por el autor del makefile para hacer el archivo más legible y fácil de modificar o ampliar.
3. **Directivas y funciones**. Son expresiones o palabras que se usan para diversas funciones que ayudan a simplificar un makefile.
4. **Comentarios**. Se tratan de anotacionesPara escribir un comentario, simplemente se debe escribir el caracter '``#``' antes del comentario.

## 1. Reglas

Pongamos un ejemplo de una regla. Imaginemos que tenemos un programa en lenguaje C++ que consta de un archivo ``goblin.cpp``, que tiene en su interior una inclusión de la cabecera ``goblin.h``. Para obtener el objeto de forma manual escribiríamos en la terminal la siguiente orden:

```bash
g++ -c -g goblin.cpp
```

Esto se traduciría como la siguiente regla en un makefile:

```makefile
goblin.o: goblin.cpp goblin.h
	g++ -c -g goblin.cpp
```

Esta regla nos dice dos cosas:

1. Cuándo se ejecutará. Solamente tendrá efecto si el ``goblin.o`` no existe o si los archivos ``goblin.cpp`` o ``evil.h`` han sido modificados desde la última vez que se ejecutó. Por tanto, si usamos la orden ``make`` dos veces de forma consecutiva, esta regla no hará nada.
2. Cómo se obtiene ``goblin.o``. La regla dice exactamente como se construye el archivo objeto a partir de las fuentes.

### 1.1. Sintaxis de una regla

#### Sintaxis general

Una regla está compuesta por tres cosas: objetivos (normalmente uno), pre-requisitos o dependencias y recetas. Un objetivo es el archivo u orden que se quiere realizar. Los pre-requisitos son los archivos o reglas de las que depende el objetivo, mientras que las recetas son las acciones que se siguen para obtener el objetivo. Una regla suele verse así:

```Makefile
objetivos: pre-requisitos
	receta
	...
```

O alternativamente de esta manera:

```makefile
objetivos: pre-requisitos; receta
	receta
	...
```

Es **muy importante** seguir al pie de la letra esta sintaxis, puesto que ``make`` no identificará una línea como una receta si no comienza por un tab (literalmente un tab, no es válido una sucesión de espacios), así como no sabrá interpretar la regla si el objetivo no está separado de los pre-requisitos por el caracter ':'. Además, esta sintaxis tiene las siguientes consecuencias:

- Una línea en blanco que comienza por una tab no es una línea en blanco, sino una receta vacía.
- Un comentario en una receta no es un comentario de *makefile*, sino que será pasado al shell literalmente, por lo que depende del shell si es tratado como comentario o no.
- La definición de una variable dentro del "contexto de una receta" (dentro de una regla e indentado con un tab), será tratado como parte de una receta, no como una variable del makefile, y pasado al shell.
- Una expresión condicional dentro del "contexto de una receta" será considerado parte de una receta y pasado al shell. 

#### Sintaxis específica

Volvamos al ejemplo del principio. En la práctica, los programa son más grandes y no suelen tener todos los archivos en un solo directorio. Imaginemos ahora que tenemos el siguiente árbol de directorios:

```
.
├── doc
│   └── adventure.doxy
├── include
│   ├── goblin.h
│   └── underground.h
├── Makefile
├── obj
└── src
    ├── dungeon.cpp
    ├── goblin.cpp
    └── main.cpp
```

Imaginemos que en el archivo Makefile se encuentra la regla descrita anteriormente para construir ``goblin.o``. Si hacemos la orden ``make`` saltará el siguiente error:

```bash
make: *** No rule to make target 'goblin.h', needed by 'goblin.o'.  Stop.
```

¿Cuál es la razón de este error? ¿No era ``goblin.h`` una dependencia y no un objetivo? Esto ocurre porque ``make`` busca archivos solamente en el directorio de trabajo actual. Al no encontrar la cabecera, interpreta que se trata del objetivo de una regla. ¿Cómo arreglar esto? Primeramente, debemos escribir la ruta completa del archivo de cabecera. Después, debemos especificar donde se encuentra ese archivo en la receta. Existen varias maneras de hacer esto: a través de la directiva ``vpath``, la variable ``VPATH`` y el uso de la opción ``-I`` o ``--include-dir`` en la regla. Las dos primeras opciones serán explicadas más adelante.

Esta opción de compilación busca posibles dependencias en  ``[directorio]``. En caso de no especificar ningún directorio, ``make`` busca en los siguientes directorios (si existen) en este orden: ``/usr/local/include``, ``usr/gnu/include``, ``/usr/local/include`` y ``/usr/include``. Otra opción interesante del compilador es ``-o <nombre>``. Esta opción permite modificar el nombre de la salida de la compilación, cambiándolo por ``nombre``. Además, suele ser interesante usar los siguientes flags: ``-Wall`` y ``-g``. El primero hace que el compilador nos muestre todos los warnings, mientras que el segundo especifica al compilador que el archivo resultante pueda ser debuggeado.

En resumen, un archivo *makefile* válido para el programa del ejemplo sería el siguiente:

```makefile
all: adventure;

adventure: obj/dungeon.o obj/goblin.o obj/main.o
  g++ -Wall -g -o adventure obj/dungeon.o obj/goblin.o obj/main.o

obj/main.o: src/main.cpp include/dungeon.h
  g++ -Wall -g -I./include -c src/main.cpp -o obj/main.o

obj/dungeon.o: src/dungeon.cpp include/dungeon.h
  g++ -Wall -g -I./include -c src/dungeon.cpp -o obj/dungeon.o
  
obj/goblin.o: src/goblin.cpp include/goblin.h
  g++ -Wall -g -I./include -c src/goblin.cpp -o obj/goblin.o
```

Sin embargo, es evidente que esta forma de realizar un makefile no es muy práctica, puesto que si se realiza un cambio en el nombre de una carpeta o de un archivo debe buscarse manualmente todas sus instancias en las reglas y escribir el nuevo nombre. Es por ello que se suelen usar variables para nombrar la mayoría de elementos de un makefile.

### 1.2. Reglas especiales

No todas las reglas tienen como objetivos archivos, o sus recetas son simplemente compilar, o tienen pre-requisitos. Como puede observarse, en el ejemplo anterior existe una regla llamada ``all``, que no es un archivo y no tiene recetas. A continuación se explican qué son y cómo se usan este tipo de reglas.

#### Reglas cuyo objetivo no es un archivo

En muchas ocasiones es interesante no tener que realizar acciones manualmente, como eliminar archivos objeto, actualizar los archivos de la documentación, etc. Usando la orden ``make [orden]`` podemos crear reglas en el makefile con ``orden`` como objetivo de una regla, ya que los archivos *makefile* soportan órdenes del shell. He aquí una lista de las más se usan (al menos en la corta experiencia del autor):

- **``all ``**: Esta regla es muy importante, de hecho es casi obligada si se quiere estructurar el makefile de forma flexible. Cuando usamos la orden ``make``, se ejecuta la primera regla que aparezca en el makefile primero. Esto ocurre siempre a no ser que se escriba una regla cuyo objetivo sea ``all``, en cuyo caso se ejecuta esa primero. Suele ser interesante que sus pre-requisitos sean el archivo ejecutable del programa. Ejecutar ``make all`` es equivalente a ``make``.
- **``clean [name]``**: Esta regla sirve para borrar los archivos ``name`` del proyecto. Normalmente estos archivos suelen ser los objeto, el ejecutable y los archivos de documentación. Es importante no equivocarse, puesto que el borrado con órdenes de shell es irreversible. No suele tener pre-requisitos.
- **``doxy``**: Sirve para crear la documentación del programa (en doxygen en este caso). El objetivo de la regla dependerá del programa de documentación de proyectos que se use en cada caso. No suele tener pre-requisitos.
- **``zip`` o ``tar``**: Estas reglas se utilizan para comprimir el proyecto para su posterior distribución. De tener pre-requisitos, suele ser ``clean``, para eliminar los archivos innecesarios para la distribución del programa.
- **``help``**: Sirve para mostrar un mensaje de ayuda sobre los posibles usos del makefile. Suele tratarse de una sucesión de órdenes shell ``echo``.
- **``author``**: Análoga a ``help``, salvo que esta muestra información sobre el autor del makefile.
- **Reglas sin receta**: Explicadas a continuación.

#### Reglas sin receta

Las reglas sin receta consisten en reglas que no hacen nada ellas mismas. La sintaxis preferente para este tipo de reglas es la que usa punto y coma, puesto que queda más claro que dejar una línea en blanco con un tab. Estas reglas se utilizan para evitar las reglas ímplicitas o para evitar errores para objetivos que se crean como efecto secundario de otras recetas: si el objetivo no existe este tipo de reglas aseguran que ``make`` no de errores al no saber cómo construir el objetivo, y asumirá que está desactualizado.

#### Reglas con múltiples objetivos

Escribir una regla con más de un objetivo es equivalente a escribir múltiples reglas idénticas en las que varía el objetivo. Este tipo de reglas son útiles en dos casos:

- Solamente se quieren pre-requisitos. En este caso a cada uno de los objetivos se le añaden los pre-requisitos de la regla. Por ejemplo:

  ```makefile
  obj/main.o obj/dungeon.o: include/dungeon.h
  ```


- Recetas similares para todos los objetivos: Las recetas no deben de ser completamente idénticas, puesto que el uso de la variable automática ``$@`` puede ser usada para sustituir un objetivo concreto. Este uso será ejemplificado más adelante junto con el uso de las variables.

Cuando existan más de una regla con el mismo objetivo, es importante recordar que no debemos escribir más de una receta para construir ese objetivo, independientemente del número de reglas en las que aparezca. No tener en cuenta esto puede provocar errores, puesto que ``make`` sobreescribe todas las distintas recetas por una de ellas.

#### Reglas con pre-requisitos sólo orden

En una regla existen dos tipos de pre-requistos: Los normales y los de sólo orden. Estos pre-requisitos se usan cuando tiene una situación en la que desea imponer un orden específico en las reglas a invocar sin forzar la actualización del objetivo si se ejecuta una de esas reglas. En caso de existir pre-requisitos de ambos tipos, tienen preferencia los de sólo orden. Es por ello que se pueden utilizar también, por ejemplo, para crear un directorio necesario para el objetivo antes de que se ejecuten las recetas. Esta es su sintaxis:

```makefile
objetivos: pre-requisitos | pre-requisitos solo-orden
```

### 1.3 Reglas implícitas

Estas reglas son las que ``make`` puede generar automáticamente si encuentra una regla sin recetas. Dependiendo del lenguaje de programación, puede realizar unas u otras. En el caso de C++, una regla cuyo objetivo sea un ``filename.o`` puede crearlo automáticamente a partir de un ``filename.cpp`` con una receta de la forma:

```makefile
$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c
```

Para resumir y ejemplificar todas estas reglas, se puede ampliar el makefile de ejemplo, quedando de esta forma:

```makefile
all: adventure help author;

rebuild: clean-hard adventure;

obj/main.o obj/dungeon.o: include/dungeon.h

adventure: obj/dungeon.o obj/goblin.o obj/main.o
	g++ -Wall -g -o adventure obj/dungeon.o obj/goblin.o obj/main.o

obj/main.o: src/main.cpp
	g++ -Wall -g -I./include -c src/main.cpp -o obj/main.o

obj/dungeon.o: src/dungeon.cpp
	g++ -Wall -g -I./include -c src/dungeon.cpp -o obj/dungeon.o
	
obj/goblin.o: src/goblin.cpp include/goblin.h
	g++ -Wall -g -I./include -c src/goblin.cpp -o obj/goblin.o
	
clean-hard: clean-exec clean-obj clean-doxygen;

clean-exec:
	rm -f adventure

clean-obj:
	rm -f obj/*.o

clean-doxygen:
	rm -rf doc/html doc/latex
	
doxy: clean-doxygen
	doxygen doc/adventure.doxy
	firefox doc/html/index.html
	
zip: clean-hard | zipdir
	-rm -rf zip/*
	zip -r zip/adventure.zip *

zipdir:
	mkdir -p zip/
	
help:
	@echo "Posibles opciones:"
	@echo "		rebuild			Reconstruye el proyecto desde cero"
	@echo "		clean-hard		Borra todos los archivos creados por el makefile"
	@echo "		clean-exec		Borra el ejecutable"
	@echo "		clean-obj		Borra los archivos objeto"
	@echo "		clean-doxyen	Borra los archivos de documentación"
	@echo "		doxy			Genera la documentación del proyecto"
	@echo "		zip				Genera un zip con el proyecto"

author:
	@echo "Este proyecto ha sido creado por Manuel Gachs Ballegeer"
	@echo "https://github.com/Manuelbelgicano"
```

## 2. Variables

Como se ha mencionado anteriormente, esta forma de hacer archivos *makefile* no es muy recomendable, puesto que cambiar un archivo tiene consecuencia ir buscando por todo el archivo las ocurrencias y cambiarlas, además de hacer el makefile menos legible. Es por ello que se usan variables, que nos ayudan a simplificar el makefile y hacerlo más flexible. Las variables pueden ser desde listas de nombres de archivos, opciones de compilación, directorios, trozos de texto, ... 

### 2.1. Aspectos básicos sobre variables

Un ejemplo de uso de variables en una regla sería el siguiente:

```makefile
OBJECT = obj/goblin.o
SOURCE = src/golin.cpp
HEADER = include/goblin.h

$(OBJECT): $(SOURCE) $(HEADER)
  g++ -Wall -g -I./include -c $(SOURCE) -o $(OBJECT)
```

Como se puede observar, la declaración de una variable va precedida por un signo'=' (aunque veremos más adelante que puede hacerse de otras formas), y que para usar la variable debemos ponerla entre paréntesis predecida por '``$``' (para escribir un dólar en el shell es necesario escribir '``$$``'; y para escribir literlamente el símbolo, es necario la escritura de 4 símbolos consecutivos). La orden ``make`` expande las variables por su respectivo valor al ejecutar el makefile. Muy importante es saber que ``make`` distingue mayúsculas de minúsculas; por lo que ``OBJECT``, ``Object`` y ``object`` son variables distintas.

#### Formas de definir variables

Existen dos formas en las que una variable de un makefile puede obtener un valor, y se distiguen en la manera en la que están definidas y qué hacen cuando son expandidas.

Las variables de la primera forma se denominan **variables de expansión recursiva**, y se definen usando el símbolo ``=`` o por la directiva ``define``. Cuando son expandidas, si contienen referencias a otras variables, éstas son también expandidas, de ahí el nombre. Pongamos el siguiente ejemplo:

```makefile
que = $(es)
es = $(eso)
eso = es queso

all:; echo $(que)
```

Al ejecutar la orden ``make`` sobre este makefile, expande ``$(que)`` a "``$(es)``", que es expandida a "``$(eso)``", que finalmente es expandida a ``es queso``.

Esta forma de definir variables es la que tiene soporte en más versiones de ``make``. Sin embargo, esta forma de definición tiene sus desventajas:

- Imposibilidad de añadir algo al final de una variable. Por ejemplo queremos añadir a las flags de compilación una opción más en un punto del makefile:

  ```makefile
  FLAGS = -Wall
  ...
  FLAGS = $(FLAGS) -g
  ```

  Esto no puede realizarse usando variables de extensión recursiva, puesto que entraría en un bucle infinito a la hora de expandir la variable.

- Cada vez que se use una variable que haga referencia a una función, se llamará a dicha función. Esto hace que ``make`` sea más lento, además de no saber de forma exacta cuándo o cuántas veces va a ejecutarse esa función.

Es por ello que existe otra manera de definir variables, siendo su nombre **variables de expansión simple**, y definidas por ``:=`` o ``::=`` (preferiblemente el primero, puesto que ``::=`` no está implementado en todas las versiones de ``make``). La diferencia que tiene este tipo de variables con las anteriores es que transforma las referencias a otras variables por el contenido que tenían en el momento en el que la variable es definida. Por tanto,

```makefile
x := hasta
y := $(x) luego
x := maricarmen
```

es equivalente a escribir

```makefile
y := hasta luego
x := maricarmen
```

Este tipo de variables generalmente ayudan a hacer los makefiles más complejos predecibles, además de dejar redefinir una variable usando su propio valor.

Existe además un últimpo operador para definir variables, ``?=``, llamado operador condicional de asignación, puesto que solo realiza la asignación si la variable no ha sido definida anteriormente.

#### Agregar texto a una variable

Muchas veces puede ser útil añadir más texto a una variable que ya ha sido definida. Para ello se usa el operador ``+=``. Por ejemplo:

```makefile
OBJ = goblin.o dungeon.o
OBJ += main.o
```

Esto añade a la variable ``OBJ`` el texto "``main.o``", quedando su valor final la cadena de caracteres de los tres archivos objeto. Para variables de expansión simple, usar ``+=`` es similar a lo siguiente:

```makefile
OBJ = goblin.o dungeon.o
OBJ := $(OBJ) main.o
```

aunque tiene diferencias que pueden llegar a ser importantes cuando se usan valores más complejos. Sin embargo, si la variable ``OBJ`` ha sido previamente definida como una variable de extensión simple (``OBJ`` se ha definido como ``OBJ := goblin.o dungeon.o``), sí que es completamente equivalente.

### 2.2. Características de las referencias a variables

Aunque referenciar una variable sea tan simple como rodearla de paréntesis y escribir un dólar, pueden hacerse muchas más cosas con las referencias a variables.

#### Referencias como ayuda para formato

Imaginemos que cambiamos de forma regular la carpeta donde se encuentran los archivos de cabecera, pero no cambiamos los nombres de los archivos en sí. Usar variables que contengan fracciones de la ruta de un archivo pueden ayudarnos a paliar estos problemas. Un ejemplo de este uso podría ser el siguiente:

```makefile
INC := ./include
HEADERS := $(INC)/goblin.h $(INC)/dungeon.h
```

También puede ayudar si queremos que el primer caracter de una variable sea un espacio en blanco. Para ello debemos de "trollear" a ``make``, ya que ignora los caracteres en blanco antes de la definición de variables. Para ello realizamos este truco:

```makefile
NULL :=
space := $(NULL) # fin de la línea
```

El valor de ``space`` es precisamente un espacio solo. El comentario "``# fin de la línea``" es muy importante, puesto que ``make``  solo procesará los caracteres en blanco tras la definición de una variable si contiene un comentario, y solamente procesará la cantidad que se encuentre entre el fin de la declaración de una variable y el caracter '``#``'. Si no se quiere añadir caracteres en blanco, es de vital necesidad acordarse de no escribir un comentario en la misma línea, puesto que podemos provocar este tipo de problemas:

```makefile
INC := ./include    # directorio de los archivos de cabecera
HEADERS := $(INC)/goblin.h $(INC)/dungeon.h
```

En este caso, ``HEADERS`` se expandiría a "``./include    /goblin.h ./include    /dungeon.h``", provocando un error en la orden ``make``.

Las referencias a variables pueden también ser usadas en la definición del nombre de las variables, esto es:

```makefile
PROJECT = adventure
$(PROJECT)_sourcedir := ./src
```

Este ejemplo define las variables "``PROJECT``" y "``adventure_sources``".

#### Referencias de sustitución

Las referencias de sustitución sustituyen el valor de una variable con las alteraciones que se especifiquen. Tiene la forma "``$(var:a=b)``" (o "``${var:a=b}``"), y sustituyen cada 'a' al final de una palabra por una 'b'. Cuando decimos "al final de una palabra", nos referimos a que 'a' debe aparecer al final de un valor o seguido por un caracter en blanco. Otras instancias de 'a' en la variable no son alteradas. Por ejemplo: 

```makefile
SOURCES := goblin.cpp dungeon.cpp main.cpp
OBJECTS := $(SOURCES:.cpp=.o)
```

donde el valor de ``OBJECTS`` es "``goblin.o dungeon.o main.o``".

Otra forma de escribir este tipo de referencias para buscar un patrón es que 'a' contenga un caracter '%'. De esta forma, la sustitución usa la funcion ``patsubst`` para realizar la sustitución (en la práctica no hay mucha diferencia entre ambas formas de definir las referencias de sustitución).

Este tipo de referencias, junto con las variables automáticas, son muy útiles para automatizar reglas, puesto que nos permiten escribir una única regla para construcciones parecidas. Un ejemplo donde se usa este tipo de sustituciones se utiliza más adelante.

#### Referencias a variables anidadas

Este tipo de referencias solamente usa para programar makefiles complejos y sofisticados, por lo que normalmente no es necesario considerar su uso, salvo para saber que una variable con '``$``' en su nombre puede provocar fallos inesperados. Las variables a veces pueden contener referencias a otras en su nombre. Por ejemplo:

```makefile
hasta = luego
luego = maricarmen
texto = $($(hasta))
```

define ``texto`` como la referencia a la referencia de ``hasta``. La expansión sería por tanto la siguiente: Primero "``$($(hasta))``" se expandiría a "``$(luego)``", que a su vez se expandiría a "``maricarmen``". La variable ``texto`` tendría por tanto el valor "``maricarmen``".

El anidamiento no es limitado a dos niveles, puede realizarse un anidamiento de n niveles. Un ejemplo de 4 niveles sería el siguiente:

```makefile
esto = es
es = coser
coser = y
y = cantar
texto = $($($($(esto))))
```

aquí, "``$($($($(esto))))``" se expande a "``$($($(es)))``", que a su vez se expande a "``$($(coser))``", que es expandido a "``$(y)``", que es finalmente expandido a "``cantar``". En este caso, la variable ``texto`` contiene el valor "``cantar``".

Las variables anidadas pueden tener también llamadas a funciones o referencias de sustitución, como por ejemplo:

```makefile
traidor = var1
var2 := Hola
dos = $(subst 1,2,$(traidor))
uno = dos
saludo := $($($(uno)))
```

donde al final la variable ``saludo`` contiene el valor "``Hola``". El proceso de expansión de la variable es el siguiente: "``$($($(uno)))``"  se expande a "``$($(dos))``", que se transforma en "``$($(subst 1,2,$(traidor)))``" (la función ``subst`` aparece más adelante explicada), que cambia "``var1``" por "``var2``"; y finalmente "``$(var2)``" se expande a "``Hola``".

Además, puede realizarse una anidación en la cual exista más de una referncia en un cierto nivel. Esto puede servir para declaraciones de variables condicionales, donde las referencias en el mismo nivel forman el nombre de otra variable. Para conocer más usos y limitaciones de las referencias anidadas es recomendable leer el punto 6.3.2 del manual de la GNU.

### 2.3. Variables específicas

Las variables en ``make`` suelen ser globales; esto es, tienen el mismo valor independientemente del lugar en el que sean evaluadas. En ocasiones, sin embargo, nos interesa que una variable tenga valores distintos dependiendo de la regla en la que se evalúe.

#### Variables específicas a un objetivo

En ocasiones nos interesa que una variable tenga un valor específico para construir un cierto objetivo. Esto se puede hacer de la siguiente manera:

```makefile
objetivos: asignacion-variable
```

Para la asignación de valores de la variable puede usarse cualquiera de los operadores descritos (``=``, ``+=``, ``:=``, ...). Además, si el objetivo de esa regla tiene pre-requisitos, la variable específica tiene efecto también sobre las reglas que lo construyen e incluso ocurre lo mismo con sus pre-requisitos (salvo que los pre-requisitos tengan sus propios valores de esa variable específicos). Un ejemplo de uso de este tipo de variables sería el siguiente:

```makefile
ejecutable: CPPFLAGS = -g
ejecutable: main.o verdugo.o reo.o
```

en el que la variable ``CPPFLAGS`` tiene el valor "``-g``" para la regla ``exec``, pero también para las reglas cuyos objetivos sean ``main.o``, ``verdugo.o`` o ``reo.o``.

#### Variables específicas a un patrón

En otras ocasiones nos interesa que una variable tenga un valor distinto para cierto tipo de objetivos. La sintaxis de esta utilidad es la siguiente:

```makefile
patron: asignacion-variable
```

donde el patrón se escribe como una parte común precedida o sucedida de un caracter '%'. En caso de que un cierto objetivo tenga más de una variable específica por un patrón, usará la que tenga el patrón más específico. En caso de igualdad, usará el que haya sido definido primero. Un ejemplo del uso de estas variables puede ser:

```makefile
%.o: CPPFLAGS := -g
cartera/%.o: CPPFLAGS := -Wall -g

all: bolsillo/llaves.o bolsillo/cartera/dinero.o
```

donde ``llaves.o`` se constuye con el primer valor de ``CPPFLAGS``, mientras que ``dinero.o`` se construye con el segundo, puesto que es más específico.

Las variables específicas a un patrón se buscan después de cualquier variable específica a un objetivo definida explícitamente para ese objetivo, y antes de las variables específicas a un objetivo definidas para el objetivo padre.

### 2.4 Variables especiales

#### Variables automáticas

Las variables automáticas son variables que tienen valores específicos dentro de cada regla. Fuera de las reglas, estas variables no contienen ningún valor. He aquí una lista de las más básicas:

| Nombre |               Descripción                |
| :----: | :--------------------------------------: |
| ``$@`` | El nombre del objetivo de la regla. En caso de que existan más de un objetivo, se refiere al objetivo específico que ha invocado la receta. |
| ``$<`` | El nombre del primer pre-requisito. Si la regla es implícita, será el primer pre-requisito añadido por la relga ímplicita. |
| ``$?`` | Los nombres de todos los pre-requisitos más nuevos que el objetivo, separados por espacios en blanco. |
| ``$^`` | Los nombres de todos los pre-requisitos, separados por espacios en blanco. Esta lista no contiene los pre-requisitos de sólo orden. |
| ``$\|`` | Los nombres de todos los pre-requisitos de sólo orden, separados por espacios. |

#### Variables reservadas

Existen nombres de variables que tienen propiedades especiales. Al ser definidas en un makefile, realizan algún tipo de acción/efecto. Algunas de ellas son:

|        Nombre         |               Descripción                |
| :-------------------: | :--------------------------------------: |
| **``.RECIPEPREFIX``** | Intercambia el caracter para un receta de tab al caracter asignado a la variable. |
|  **``.VARIABLES``**   | Devuelve una lista con el nombre de todas las variables definidas hasta el momento, excluyendo las específicas definidas uúnicamente en ese contexto. |
|     **``VPATH``**     | La orden ``make`` busca en los directorios especificados a la variable además del directorio de trabajo en el que se ejecuta. Busca además en el orden en el que son especificados los directorios. |
|   **``MAKEFILE``**    | La orden ``make`` lee los makefiles especificados en la variable antes que el actual. |
| **``MAKEFILE_LIST``** | Contiene el nombre del último archivo *makefile* abierto por la orden ``make`` |
|    **``.PHONY``**     | Esta variable se usa como objetivo de una regla sin recetas. Los pre-requisitos especificados en esa regla se ejecutan siempre que se realice una orden que puede construirlos o que ejecuta estas reglas, sin importar que no se haya habido ninguna actualización desde la última vez que ``make`` fue ejecutado. |
|     **``FORCE``**     | Es equivalente a ``.PHONY``, salvo que se pone como pre-requisito y es el objetivo de una regla vacía. |

Para ver más variables reservadas mirar en los puntos 6.14 y 4.9 del manual. El makefile de ejemplo completo anterior puede ser mejorado utilizando variables, quedando de la siguiente manera:

```makefile
# Compiler
CXX = g++
CXXFLAGS = -g

# Special variables
VPATH = src/:obj/:include/

# File variables
PROJECT = $(BIN)adventure
MAINSRC := main.cpp
SOURCES := goblin.cpp dungeon.cpp
OBJECTS := $(SOURCES:.cpp=.o)
HEADERS := $(SOURCES:.cpp=.h)
MAINOBJ := $(MAINSRC:.cpp=.o)

# Directory variables
OBJ := obj/
ZIP := zip/
BIN := bin/

# Other variables
DOCUMENTATION = doxygen
BROWSER = firefox
COMPRESS = zip

# Pattern-specific variables
%.o: CXXFLAGS += -Wall -I./include -c

# Recipeless rules
all: $(PROJECT) help author;
.PHONY: $(PROJECT) clean-hard $(DOCUMENTATION)
clean-hard: clean-exec clean-obj clean-doxygen;
$(PROJECT): | $(BIN)
$(COMPRESS): | $(ZIP)
$(MAINOBJ): dungeon.h | $(OBJ)
$(OBJECTS): | $(OBJ)

# File rules
$(PROJECT): $(OBJECTS) $(MAINOBJ)
	$(CXX) $(CXXFLAGS) -o $@ $?
	-mv $? $(OBJ)

$(OBJECTS): %.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -o $@ $<

$(MAINOBJ): $(MAINSRC)
	$(CXX) $(CXXFLAGS) -o $@ $<

# Directory rules
$(OBJ):
	mkdir -p $(OBJ)

$(BIN):
	mkdir -p $(BIN)

$(ZIP):
	mkdir -p $(ZIP)

# Other rules
clean-exec:
	rm -f $(PROJECT)

clean-obj:
	rm -f $(OBJ)*.o

clean-doxygen:
	rm -rf doc/html doc/latex
	
$(DOCUMENTATION):
	$(DOCUMENTATION) doc/adventure.doxy
	$(BROWSER) doc/html/index.html
	
$(COMPRESS): clean-hard
	-rm -rf $(ZIP)*
	$(COMPRESS) -r $(ZIP)/adventure.zip *
	
help:
	@echo "Posibles opciones:"
	@echo "		clean-hard		Borra todos los archivos creados por el makefile"
	@echo "		clean-exec		Borra el ejecutable"
	@echo "		clean-obj		Borra los archivos objeto"
	@echo "		clean-doxyen	Borra los archivos de documentación"
	@echo "		doxygen			Genera la documentación del proyecto"
	@echo "		zip				Genera un zip con el proyecto"

author:
	@echo "Este proyecto ha sido creado por Manuel Gachs Ballegeer"
	@echo "https://github.com/Manuelbelgicano"
```

Como se puede observar, este makefile es mucho más sofisticado, y aunque pueda parecer más confuso en principio, es mucho más claro que sin las variables. Además, contiene un ejemplo de regla automática, la que construye los archivos objeto.

## 3. Directivas y funciones

Para makefiles extensos, complicados o sofisticados, el uso de las directivas y funciones es esencial. Las directivas son llamadas a funciones de ``make`` que realizan diferentes tareas: desde incluir otros makefiles hasta manejar el orden de las asignaciones de las variables. Las funciones tienen labores parecidas, pero en el contexto de las variables.

### 3.1. Directivas

Para obtener una lista de todas mirar el manual de la GNU. Algunas de las directivas más simples son las siguientes:

#### Directiva ``define``

- **Uso**: La directiva ``define`` sirve para encapsular un cierto número de comandos en una variable. Suele ser útil cuando esa secuencia es utilizada en diversas reglas.

- **Sintaxis**:

  ```makefile
  define variable =
  comando-1
  comando-2
  ...
  endef
  ```

  Es importante saber que esta directiva no realiza expansiones de la secuencia encapsulada, sino que se transforman en parte del valor de la variable. Estas referencias sí que son expandidas cuando la variable creada es referenciada en una regla.

- **Ejemplo**:

  ```makefile
  define compile =
  @echo "Compilando el archivo $@"
  $(CXX) $(CXXFLAGS) -o $@ $<
  endef
  ```

#### Directiva ``override``

- **Uso**: La directiva ``override`` se usa sobre la asignación de una variable. Al realizar esto, el resto de asignaciones de valores a esa variable en el makefile son ignorados. Esto es equivalente a realizar una llamada a la orden ``make`` y esciribr la declaración de una variable en la línea de comandos.

- **Sintaxis**:

  ```makefile
  override variable = valor
  override variable := valor
  override define variable =
  valor
  endef
  ```

  Como podemos observar, existen diversas maneras de usar ``override``. Las dos primeras son la forma de asignar un valor a la variable. También podemos usar la directiva con ``define`` de forma conjunta. Para poder modificar el valor de una variable con la directiva ``override``, debemos usar la directiva.

- **Ejemplo:**

  ```makefile
  Hasta = la vista baby 
  override Hasta = luego
  override Hasta += maricarmen
  ```

  En este caso la variable ``Hasta`` contiene el valor "``luego maricarmen``", ignorando la primera declaración de la variable, puesto que la siguiente es con la directiva ``override``.

#### Directiva ``undefine``

- **Uso**: La utilidad de esta directiva recae en que con ella podemos no simplemente borrar el contenido de una variable, sino eliminar la variable en sí.

- **Sintaxis**:

  ```makefile
  undefine variable
  ```

  Con undefine podemos también borrar variables especificadas por la línea de comandos usando la directiva ``override``.

- **Ejemplo**: 

  ```makefile
  amigos = muchos
  undefine amigos
  ```

  Si intentamos usar la variable ``amigos`` posteriormente, saltará error puesto que no existe.

#### Directiva ``vpath``

- **Uso:** La directiva ``vpath`` es una alternativa a la variable ``VPATH`` que otorga más flexibilidad.

- **Sintaxis**:

  ```makefile
  vpath patrón directorio1:directorio2:...
  vpath patrón
  vpath
  ```

  La primera declaración especifica dónde buscar los archivos del tipo ``patrón`` de forma secuencial: primero en el directorio ``directorio1``, si no lo encuentra en el directorio ``directorio2``, etc. La segunda declaración borra todas las directivas ``vpath`` anteriores relativas a ese patrón, mientras que la última borra todas las anteriores directivas ``vpath``.

- **Ejemplo:**

  ```makefile
  vpath %.cpp src/
  vpath %.h include/
  ```

  Aquí se especifica a ``make`` que, de no encontrar los pre-requisitos que cumplan el patrón ``%.cpp`` en el directorio donde se está ejecutando, los busque en el subdirectorio ``src/``. Análogamente, busca los archivos de cabecera en ``include/``.

### 3.2. Funciones

Algunas de las funciones que se han usado en estos apuntes o que son bastante útiles son:

#### Función ``subst``

```makefile
$(subst fragmento,reemplazo,texto)
```

La función subst sustituye ``fragmento`` de ``texto`` por ``reemplazo``. Un ejemplo de uso de la función puede ser el siguiente:

```makefile
eme = la eme me mola
eMe = $(subst m,M,$(eme)) # eMe = la eMe Me Mola
```

#### Función ``patsubst``

```makefile
$(patsubst patrón,reemplazo,texto)
```

Esta función es equivalente a ``subst`` salvo que esta busca las palabras que cumplan ``patrón``. El patrón se escibe usando '%', y si ``reemplazo`` contiene también ese caracter, entonces se sustituye la parte de la palabra que difiere con el patrón. Esta función es equivalente a la referencia de sustitución. Como ejemplo podemos poner:

```makefile
src = macarrones.cpp tomate.cpp salchichas.cpp
obj = $(patsubst %.cpp,%.o,$(src)) # obj = macarrones.o tomate.o salchichas.o
```

#### Función ``wildcard``

```makefile
$(wildcard patrón)
```

La función ``wildcard`` es el equivalente al caracter '``*``' en bash. Esto es, expande la variable a todas las ocurrencias del patrón. Esto nos puede resultar útil cuando queramos definir una variable que sea un conjunto de archivos. Imaginemos que tenemos ``kase.o`` y ``chiste.o``. Un ejemplo del uso de la función es el siguiente:

```makefile
obj = *.o 				# obj = *.o 
obj := $(wildcard *.o) 	# obj = kase.o chiste.o
```

#### Función ``word``

```makefile
$(word n,texto)
```

Esta función devuelve la n-ésima palabra de ``texto``, donde ``n`` comienza por 1. Como ejemplo podemos poner:

```makefile
saludo = hasta la vista baby
edad-mental := $(word 4,$(saludo)) # edad-mental = baby
```

#### Función ``filter`` y ``filter-out``

```makefile
$(filter patrón ...,texto)
$(filter-out patrón ...,texto)
```

La función ``filter`` devuelve todas las instancias de ``patrón`` en ``texto``. La segunda funcón hace lo opuesto. Se pueden especificar más de un patrón separándolos por espacios en blanco antes de ','. Como ejemplo podemos poner el siguiente:

```makefile
bosque = arbol.h bellota.s ardilla.out jabali.cpp
animales := $(filter %.out %.cpp,$(bosque))   # animales = ardilla.out jabali.cpp
relacion := $(filter-out %.h %.cpp,%(bosque)) # relacion = bellota.s ardilla.out
```

#### Función ``if[-else]``

```makefile
$(if condición,acción-si-se-cumple[,acción-si-no-se-cumple])
```

Esta función devuelve el valor correspondiente a la evaluación de ``condición``. Si es falsa y no hay nada especificado en la parte de ``accion-si-no-se-cumple``, entonces la variable se convierte en una variable vacía.

#### Función ``foreach``

```makefile
$(foreach variable,lista,acción)
```

La función ``foreach`` devuelve una lista con el resultado de aplicar ``acción`` a cada uno de los elementos de ``lista``. Un ejemplo de uso de esta función es el siguiente:

```makefile
dirs := src include
archivos := $(foreach dir,$(dirs),$(wildcard $(dir)/*))
```

donde ``archivos`` es ``$(wildcard src/*) $(wildcard $(include)/*)``.

## 4. Otras utilidades de interés

#### Definición de variables o recetas en más de una línea

En ocasiones, por razones estéticas o de claridad, puede resultarnos útil el definir una variable o una receta en más de una línea. Para ello usamos el caracter '``\``'. Un ejemplo de uso es:

```makefile
hola:
	@echo hola\
caracola				#holacaracola
	@echo hola\
	caracola			# holacaracola
	@echo hola \
	caracola			# hola caracola
	@echo hola\
	 caracola			# hola caracola
```

#### Silenciar recetas

Para silenciar recetas, simplemente debemos usar el caracter '``@``' al inicio de la línea. De esta forma, sólo aparecerá en pantalla el mensaje que devuelva la orden de shell que realiza la receta. Suele utilizarse sobretodo en las recetas con ``echo``.

#### Ignorar errores

Para que ``make`` ignore un error y prosiga la ejecución simplemente es necesario añadir a la línea que queremos que ignore si produce un error con  el símbolo '``-``'. Se debe tener cuidado con el uso de esta utilidad, puesto que pueden producirse errores derivados de otros que han sido ignorados.

#### Uso de colores en el texto

Para poder cambiar el color de salida en la terminal de los mensajes, podemos usar la función ``tput``. Esta función no es exclusiva de ``make``, y su sintaxis es la siguiente:

```makefile
tput argumento [1-7]
```

Los posibles valores de ``argumento`` son los siguientes:

- ``setab``: Cambia el color de fondo del texto con el color especificado.

- ``setaf``: Cambia el color de las letras con el color especificado.

- Formatos de texto:

  |  Nombre  |            Descripción            |
  | :------: | :-------------------------------: |
  | ``bold`` |           Modo negrita            |
  | ``dim``  | Disminuye el grosor de las letras |
  | ``smul`` |    Entra en el modo subrayado     |
  | ``rmul`` |      Sale del modo subrayado      |
  | ``rev``  | Entra en el modo de vídeo inverso |
  | ``smso`` |     Entra en el modo negrita      |
  | ``rmso`` |       Sale del modo negrita       |

- ``sgr0``: Elimina todas las modificaciones del texto.

- ``bel``: Suena una campana.

Los códigos de colores son los siguientes:

| Número |  Color   | R G B |
| :----: | :------: | :---: |
|   0    |  negro   | 0 0 0 |
|   1    |   rojo   | 1 0 0 |
|   2    |  verde   | 0 1 0 |
|   3    | amarillo | 1 1 0 |
|   4    |   azul   | 0 0 1 |
|   5    | magenta  | 1 0 1 |
|   6    |   cyan   | 0 1 1 |
|   7    |  blanco  | 1 1 1 |

## 5. Makefile de ejemplo final

El makefile de ejemplo anterior con las variables puede mejorarse con los conocimientos sobre directivas y funciones, llegando al siguiente makefile (se debe señalar que no existe una manera única de escribir un makefile, el que se presenta es una de las posibles soluciones sofisticadas):

```makefile
# Directives
vpath %.h include/
vpath %.cpp src/
vpath %.o $(OBJ)

# Compiler
CXX = g++
CXXFLAGS = -g

# File variables
PROJECT := adventure
EXEC = $(BIN)$(PROJECT)
MAINSRC := main.cpp
SOURCES := goblin.cpp dungeon.cpp
OBJECTS := $(SOURCES:.cpp=.o)
HEADERS := $(SOURCES:.cpp=.h)
MAINOBJ := $(MAINSRC:.cpp=.o)

# Directory variables
OBJ := obj/
ZIP := zip/
BIN := bin/

# Other variables
DOCUMENTATION = doxygen
BROWSER = firefox
COMPRESS = zip
BOLD = `tput bold`
GREEN = `tput setaf 2`
RESET = `tput sgr0`

# Define variables
define compile =
@echo "Compilando $@ ..."
@$(CXX) $(CXXFLAGS) -o $@ $<
@echo "${GREEN}HECHO${RESET}"
endef
define makedir =
@echo "Creando carpeta $@ ..."
@mkdir -p $@
@echo "${GREEN}HECHO${RESET}"
endef
define makeexec =
@echo "Generando el ejecutable $(PROJECT) ..."
@$(CXX) $(CXXFLAGS) -o $@ $^
@-mv $? $(OBJ)
@echo "${GREEN}HECHO${RESET}"
endef

# Pattern-specific variables
%.o: CXXFLAGS += -Wall -I./include -c

# Recipeless rules
all: $(EXEC) help author;
.PHONY: $(EXEC) clean-hard $(DOCUMENTATION)
clean-hard: clean-exec clean-obj clean-doxygen;
$(PROJECT): | $(BIN)
$(COMPRESS): | $(ZIP)
$(MAINOBJ): dungeon.h | $(OBJ)
$(OBJECTS): | $(OBJ)

# File rules
$(EXEC): $(OBJECTS) $(MAINOBJ)
	$(makeexec)

$(OBJECTS): %.o: %.cpp %.h
	$(compile)

$(MAINOBJ): $(MAINSRC)
	$(compile)

# Directory rules
$(OBJ):
	$(makedir)

$(BIN):
	$(makedir)

$(ZIP):
	$(makedir)

# Other rules
clean-exec:
	@rm -f $(PROJECT)
	@echo "El archivo $(PROJECT) ha sido borrado"

clean-obj:
	@rm -rf $(OBJ)
	@echo "La carpeta $(OBJ) ha sido borrada con todos sus archivos"

clean-doxygen:
	@rm -rf doc/html doc/latex
	@echo "La documentación ha sido borrada"
	
$(DOCUMENTATION):
	@echo "Creando documentación..."
	@$(DOCUMENTATION) doc/$(PROJECT).doxy
	@echo "${GREEN}HECHO${RESET}"
	@$(BROWSER) doc/html/index.html
	
$(COMPRESS): clean-hard
	@echo "Creando el archivo comprimido $(PROJECT).zip ..."
	@rm -rf $(ZIP)*
	@$(COMPRESS) -r $(ZIP)/$(PROJECT).zip *
	@echo "${GREEN}HECHO${RESET}"
	
help:
	@echo "Posibles opciones:"
	@echo "		${BOLD}clean-hard${RESET}	\
	Borra todos los archivos creados por el makefile"
	@echo "		${BOLD}clean-exec${RESET}	\
	Borra el ejecutable"
	@echo "		${BOLD}clean-obj${RESET}	\
	Borra los archivos objeto"
	@echo "		${BOLD}clean-doxyen${RESET}	\
	Borra los archivos de documentación"
	@echo "		${BOLD}doxygen${RESET}		\
	Genera la documentación del proyecto"
	@echo "		${BOLD}zip${RESET}		\
	Genera un zip con el proyecto"

author:
	@echo "Este proyecto ha sido creado por Manuel Gachs Ballegeer"
	@echo "https://github.com/Manuelbelgicano"
```

## 6. Bigliografía y datos del autor

Estos apuntes están basados en el manual de la [GNU de make](https://www.gnu.org/software/make/manual/make.html). La función ``tput`` ha sido sacada de [esta pregunta en stackoverflow](https://stackoverflow.com/questions/5947742/how-to-change-the-output-color-of-echo-in-linux#l). Finalmente, los makefiles de ejemplo, junto a sus archivos necesarios están alojados [aquí](https://github.com/Manuelbelgicano/adventure).

Estos apuntes han sido realizados por Manuel Gachs Ballegeer, estudiante del Doble Grado de Ingeniería Informática y Matemáticas en la Universidad de Granada.

- Perfil de Github: https://github.com/Manuelbelgicano
- Correo electrónico: manuelgbal1@gmail.com
