## TEMA 1. SISTEMAS DE CÓMPUTO

### Índice
- [ Componentes de un sistema de cómputo](#componentes-de-un-sistema-de-cómputo)

  - [Definiciones básicas](#definiciones-básicas) SIN HACER

  - [Elementos básicos](#elementos-basicos)
  
  - [Registros del procesador](#registros-del-procesador)
  
  - [Ejecución de Instrucciones. Tipo de Instrucciones](#ejecución-de-instrucciones) SIN HACER

### Componentes de un sistema de cómputo

#### Definiciones básicas


### Elementos básicos de una computadora 

- **Procesador**

  Controla el funcionamientos del ordenador y realiza funciones de procesamiento de datos. Cuando solo hay uno se le denomina **CPU** `Central Processing Unit`.
  Una de sus funciones es el intercambio de datos, para ello se compone de **registros internos**:
  
  - Registro de dirección de memoria, **RDIM** especifica la dirección de memoria de la siguiente lectura o escritura.

  - Registro de datos de memoria, **RDAM** contiene los datos leídos o que van a ser escritos en memoria.

  - Registro de dirección de E/S **RDI E/S** especifica dispositico de E/S.

  - Registro de datos E/S **RDA E/S** permite intercambio de datos entre disposiivos E/S y procesador.

- **Memoria principal**

  - También llamada memoria real o primaria.

  - Conjunto de posiciones definidas mediante direcciones secuenciales que contiene un patrón de bits interpretable como instrucción o dato.

  - Volátil.

- **Módulo de E/S**
  - Transfiere datos entre dispositivos externos, memoria y procesado.
  - Compuesta de `buffers` zonas de almacenamiento temporal de los datos que se van a enviar.

- **Bus de sistema**

  - Proporciona comunicación entre los procesadores, la memora principal y los módulos de E/S.
  
  ![foto](https://github.com/BlancaCC/images/blob/master/componentes_computador_a_alto_nivel)
  
#### Registros del procesador

Los registros de un computador sirven para dos funciones:

- **Registros visibles para el usuario**

  - Usados por programador en lenguaje máquina o en ensamblador.
  - Minimizar las referencias a la mememoria principal para optimizar el uso de registros.

- **Registros de control y estado**

  - Usados por el procesador para controlar su operación.
  - Usado por rutinas privilegiadas del sistema operativo para controlar la ejecución de programas.

##### Registros visibles para el usuarios

Usados por el programador en lenguaje máquina o ensamblador, cada registro tiene una utilidad distinta:

- **Registros de datos**
 De propósto general con cualquier instrucción de la máquina que realice operaciones con datos aunque hay restriciones.

-**Registros de dirección**
	     Contienen direcciones de memoria principal de datos e instrucciones. Son registros de carácter general.
 Ejemplos:

	- **Regístro de índice** sumar un índice a valor base para obtener dirección efectiva.
	
	- **Puntero de segmento** La memoria se divide en segmentos que son bloques de palabras de dirección variable, este guarda su dirección.

	- **Puntero de pila**

##### Registros de control y estado

Aparte de los registros ya mencionados RDIM, RDAM, RDA E/S y  RDA E/S existen los siguientes para controlar la ejecución de instrucciones:

- **Contador de programa** (PC) Contiene la dirección de la próxima instrucción que se leéra de la memoria.

- **Registro de instrucción** (IR) Contiene la última instrucción leída.

- **Palabra de estado del programa ** PWS registro o conjunto de registros que contienen información del estado del programa y **códigos de condición**.
Los códigos de condición tammbién llamados indicadores son bits asignados por el hardware del procesador teniendo en cuenta el resultado de operaciones (ejemplo: el resultado positivo o negativo de una operación).

#### Ejecución de Instrucciones. Tipo de Instrucciones.

Un programa que va a ejecutarse consta de un conjunto de instrucciones almacenadas en memoria, el procesamiento de un instrucción tiene dos fases, el proceso de lectura de la instrucción('fase de búqueda') en la memoria y el de ejecución de la misma ('fase de ejecución').
     Se denomina **ciclo de instrucciones** a procesamiento requerido para una única instrucción.

#### Búsqueda y ejecución de de una instrucción

1.Principio de ciclo de cada instrucción:

  1. Procesador **lee** la instrucción de la memoria.
  
  2. El **contador de programa** (PC) almacena la dirección de la siguiente instrución que se va leer.

  3. La instrucción leída se carga dentro del registro del procesador: **registro de isntrución** (IR)

  4. El procesador **interpreta la istrucción**  y lleva a cabo la acción requerida.

![foto](https://github.com/BlancaCC/images/blob/master/ciclo_de_instrucci%C3%B3n_b%C3%A1sico)

Estas acciones se dividen en cuatro categorías:

- **Procesador memoria**  Posible transferencia de datos entre memoria y procesador. 

- **Procesador-E/S** Envío de datos entre periféricos y procesador mediante el módulo de E/S.


- **Procesamiento de datos** El procesador puede realizar algunaso operacione aritméticas o lógicas sobre lo datos.

- **Control** Intrucción especifica que se va a alterar la secuencia de ejecución.

![](https://github.com/BlancaCC/images/blob/master/repertorio_elemental_de_instrucciones.png)

