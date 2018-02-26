## Sistema de rchivos, introducción a las bases de datos
### Archivos
lso archivos se leen y se escriben toda la información de un registro concreto, desde punto de vista de registros.
Físicamente depende de la tecnología, discos, pendrive, tienen diferentes métodos de almaceamiento, en discos sectores. A la hora de leer se lee un buffer de datos, de esto se encarga el SO.
En uub tiine registros físicos, se leen ellos, por eso es necesario los drives.

Cuando se formatea un disco se TOC: tabla de contenido: nombre del archiovo más dirección de este,
uandl se crea un archivo el sistema opertativo localiza la TOC ve la dirección y toma esta como la dirección de comienzo.

Operaciones archivo: copiar, borrar, crear, leer, cerrar, modificar fecha de creación.

## Clasificación de los archivos según el punto de vista lógica:
### logitud, fisica variable:
- longitud fija: todos los registros, tienen exactamente los mismos campos y de la misma longitud.
- longitud variable: o todos los registros de la misma longitud, se puede saber la longitud de cada uno.
- longitud indefinida: longitud variable a los que no sabemos a priori su longitud ej: a cada nombre se le da la longitud que ocupa, se lee campo ahasque que se acaba, con caracteres de control (enter), *fin de registros* un código en ascii.

Cuando manadamos leer, leemos todo el registro, EOF es el formato de fin de fichero.
Con los de longitud indefinida, se introducen ficheros fin de campo.

## Organización en ficheros.
### Secuencial:
La más sencialla, uno de tras de otro, tanto para escribir como para leer.
#### Secuencial física: materialmente están escritos de esa forma. Se da en dispositivos físicamente secuenciales ej casette.
Se puede añadir información al final del archivo,
Para borrar es muy complicado y difícil.
#### Secuencial lógica o encadana:
Se trabaja como si fuera secuencial, pero de forma física no lo está, ejemplo disco de acceso aleatorio.
Para conseguirlo se encadenan los registros, mediante punteros, en el primer registro, en la toc te TOD, desde el pnto de vista de estructua de datos una lista simplemente enlazada, porque solo avanza hacia delante.

Para la recuperación de la información se lee secuencial.
Para escribir otra entre medias, se escribe y se modifican los ficheros.

### Secuencial indexada.
Como el índice de un libro, cuando se seleccioa el directorio se lee secuencialmente.
Problemas en la insercción en tablas e información prque son secuenciales, es hace al final.
1º localizo

Acces aleatorio, está donde le da la gana, se tiene algún campo que lo idetifique y localice unívocamente. Acceso aletaorio en general, cada registro identificado. Puede haber sinónimos, en este caso, el primero que llega es el que ocupa, entonces se va a la zona de desbordamiento, forma de hacerlo: direccionamiento directo.


Alberto Prieto lo cuenta muy bien esta parte


## Bases de datos
Los sistemas de ficheros se volvían más complejos ocasionando:

- Redundancia directa: repetición campos idénticos
- Redundancia indirecta: datos podrían no aoarecer al obtenerse se otros datos. (Ej código postal, calculable de provincia y barrio). Puede ser *controlada* si se hace a posta, por ejemplo para comprobar que la información es veráz (ej letra DNI).
- Actualización de los datos de manera parcial, creado confusión. Mantenimiento.
- Cada fichero se destina a una utilidad, dependencia asoluta entre información y gestión con programa.
- Lo creado secuencial se mantiene.
- Seguridad: el programa accede al fichero por donde quiera, modo acceso: lectra, escritura.


A finales de 70-80 basados suerge Software intermedio entre usurio y fichero  que evita tales problemas sistema de gestion de ficheros, que da lugar al concepto de base de datos.

Diferencia fundamental: cada dato aparee solo una vez.
Archivo (sobre un tema, entidad):
- registro : campos

. la entidad se caracterizq por diferentes alumnos: ejemplo tema expediente alumno: nombre, notas, doicilio...

El paso de base de datos, en vez de leer archivo a archivo se tiene un especie de saco, en n archivo el dato son los campos.
En la base de datos hay campos:  (son los datos)
A esos campos se les conecta, define una etidad que son los registros.


Definicion estructura e bases
 entidades con campos y relaciones: esquema de la base de datos.
Una vez definido el esquema, aparecen subesquemas,  de datos el programa qe uvisualiza la sesgaddo a los que se le permite a cada usuario, , definido cuando se define la base de datos.
No hay redundacia directa

## Característica de una base
- Accso y utilizaciń múltiple.
- Flexibilidad, no se tiene dependencia absoluta del modo de fichero creado, lectura secuencial, aleatoria.
- seguridad: el administrados establece esquemas, vistas, usuarios al definir base de datos.
- protección contrra fallos: el software, cada x tiempo copia.
- independencia física. El sotfeae de gestion es independiente de la arquitectoura.
- independencia lógica, modificación de la base de daoos, independientemente de los programas. 
- interfaz de alto nivel ddm
- interrogaciń directa sql. 

## estrucutura
Entidad, campos...
En lenguuaje nomral registro para tipo e instancia.
Según el contexto se distiguet tipo genéric o tipo concreto.

## Identificación
En archivos no es necesaria, la identificación en el sistema de gestión.
En una orgaización indexada sí es obligatorio, para lo organización es imprescendible.
en una base de datos sí es necesaria, uno o varios campos.
También son necesarias lar relaciones,

## Relaciones
### relaciones 1 a 1
reliaciones 1 a n
relaciones n a n

## Tippos de bases de datos

### jerárquicas
estructura 1 a n, la entidad como inicio de un árbol.
Problema, en una organizaciin cimpleja la información no tiene porqué ser jerarquica.
al duplicarlos surgen las redundancias

### Bases de dates en red
Se trata como un bloqeu a las bases de datos jerárquicas, el tratamientoes de conjunto conjunto pr el sistema., admiete reaciones n a n.

### Bases de datos relacionales
Con una base de datos en red se admieten todas las relaciones posibles, se ataca directamente el problema para mejprar la optimización.
Lo importante son las entidades y las relaciones, se hace software, independientemente de las relaciones, defina entidades relaciones esuemas subesquemas. Se crean tablas con las vistas, entidades, caracteristicas...


## El software de las bases de dates:
dan te
### DDL lenguaje de definción: lengaje con el que se define la base de datos (gráfico o escrito) 
### DDM lenguaje de manipulacion
axel oracle; para manipulas la base de datos de la que au se ha creado la estructura.
Cuand se ejecuta un progrmaa que utiliza la ninlioteca de
### SQL Lenguaje de interrogación directa.
Lenguae casis estadar para las bases de dato, un usuario sin sotfware de basos se comunica con la base de datos interrogándolo.

## Cómo se dibja una base de datos

### Diagrama entidad relación, (pag 34)