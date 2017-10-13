## TEMA 1. SISTEMAS DE CÓMPUTO

### Índice
- [ Componentes de un sistema de cómputo](#componentes-de-un-sistema-de-cómputo)

  - [Definiciones básicas](#definiciones-básicas) SIN HACER
  
  - [Registros del procesador](#registros-del-procesador)
  
  - [Ejecución de Instrucciones. Tipo de Instrucciones](#ejecución-de-instrucciones) SIN HACER

### Componentes de un sistema de cómputo

#### Definiciones básicas

#### Registros del procesador

**Elementos básicos**

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
  
  ![foto](https://www.dropbox.com/s/wru6zpxj3y75zj2/IMG_9478.JPG?dl=0)
  
#### Ejecución de Instrucciones. Tipo de Instrucciones.
