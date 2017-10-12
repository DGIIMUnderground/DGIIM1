# TEMA 2 Introducción a los sistemas operativos

## Índice
- [Componentes de un Sistema Operatico (SO) multiprogramdo](## Componentes de un Sistema Operativo multiprogramado)

## Componentes de un Sistema Operativo multiprogramado

### Sistemas multiprogramados y de tiempo compartido
Como el mejor sitio por donde empezar es el principio, comencemos con una breve evolución de las computadoras, hasta un sistema multiprogramado:

1. **Raimundo Lulio** en el siglo XII escribió *Ars Magna*en el que se dedicó a diseñar y construir una máquina lógica de naturaleza mecánica, donde las teorías, los sujetos y los predicados teológicos estaban organizados en figuras geométricas de las consideradas "perfectas" .

2. **Leibnitz ** 1650, construye la primera máquina que multiplica, cuando descubre *Ars magna* empieza a trabajar en la primera de algoritmo.

3. **Babbage** a principio del siglo XIX construye la primera máquina que procesa información.

4. A mediados del mismo siglo las matemáticas se empiezan a formalizar y estructurarse, considerándose un fin por sí mismas, surgiendo los axiomas de Peano, lógica... Todo gracias a personas y asociaciones como: **David Hilbert** y en 1950 **Burbaki**. Gracias a este movimiento **Turing** crea las "máquinas de Turing" y posteriormente la "la máquina universal de Tuuring" que podría considerarse uno de los precursores del ordenador.

5. A este ritmo los ordenadores iban surjiendo de manera natural **A. Church ** saca la máquina de cálculo **Post** y comienzan a aparecer los nuevos paradisgmas: operaionales, funcionales y lógicos.

6. Surge el primer ordenador, **Colosus** para generar tablas de tiro, más tarde los ingleses lo utilizaron para manejar la información de los radares, aunque no se sabe si el primero fue alemán por los archivos encotrados tras su muerte a **Kamrao Zure** ingeniero para el ejército alemán durante la primera guerra mundial.

Aquí se acaba la historia con personajes y comienza la evolución de la arquitectura de los computadores:

1. **Monoprograma** La más arcaica, requiere de mucho tiempo, ya que un humano introduce programa a programa.

2. **Lotes** En vez de introducir un programa se introducen varios en un cinta, "lote" esto reduce algo el tiempo. Para poder controlar los lotes hace falta otro progra, aparece el ** sistema operativo **, denominado *monitor* por el inglén ** Christopher S. Strachey ** pionero también de los lenguajes de programación con *CPL*. El problema de esto era el tiempo que empleaba el ordenador en los periféricos.

3. Para evitar esto surge las **interrucciones** de la mano de un avanace de sofware y hardware, en el cual varios programas se desarrolla a la vez EN SITIOS DIFERENTES .

4. Lo cual daría lugar a la ** multiprogramación** para evitar solapamientos por el interior procedimiento, esto se conoce como **S.pool**, por ejemplo si varios programas requieren del uso de una impresora, el programa que se está ejecutando escribe en un fichero lo que quiere imprimir y después lo vuelca a esta una vez que ha terminado.

5. Teniendo en cuenta que los lotes son cerrados surje las **colas** sistemas de lotes abiertos, donde el SO controla los programas que esperan y los que se ejecutan, y cuándo termina estos da pasos a los siguiente en orden de prioridad. Por tanto si un programa no utilizaba periféricos  u otros recursos se podía quedar eternamente allí, así surjen el **el tiempo compartido**, los programas tienen un tiempo limitado en la CPU.

6. **Multiusuarios** misma idea anterior pero con usuarios, vg: servidores.

7. **Multiprocesadores** más de varias CPU en un mismo ordenador, pueden trabajar en distintas tareas o en **paralelo**, el mismo programa se divide en varios procesadores que trabajan simultaneamente.

8. Finalmente distintos ordenadores, con distintos sistemas operativos que trabajan simultáneamente, todos cordiandos por un **macro sistema operativo**.