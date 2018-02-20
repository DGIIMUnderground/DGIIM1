## Generación y depuración de aplicaciones

### Concepto de plataforma
Soporte que nos permite ejecutar programa. Por lo general son máquina y sistema operativo.
La plataformas no permiten una máquina virtual ( máqina virtual java, virtual box), máquina virtual: no es hardware, a partir de software, permite.

Los programas multiplotaforma se cosntruye hasta código intermedio, cuando se instala, se concretan rutinas SO...

Entorno de desarrollo:
Herramienta: editor compilador para programar *entorno de desarrollo integrado.

Marco de trabajo:
Tipo de software que se comporta qeu se comporta de la misma manera o similar. Una empresa crea software para otros, que admiten pequeños detalles.

Documento de especificación requisitos de lo que hace mi programa.
Diseño de lo que que se quiere hacer, apoyo en diagrama.  Difici de compromar que el diseño sea correcto. Como comprobación se le puede dar a otro grupo de persona.

Verificación tras hacer el programa.
Hay dos formas que mi programa es correcto. 
#### Verificación formal:
Un programam, lenguaje escrito en algún lenguaje de programción, si en especificaciópn de la semántica del lenguaje de programcias, es una axiomática.
Especificaco semántis del lenguaje de programcióm
docemtno de explicación de las órdenes, axiomática, un sistema deductivo: aiomas y reglas de inferecia (anntecedente que si se cumple produce consiguiente)

Axiomática: semancia simple se execifican en axioma, las compuesas mediante reglas de inferencia: , a partid de esot dse connstruyen lógicas de Hoare, básicamente es un lenguaje. Se mete sistema inductivo y admite lenfguaje de progrmación y de especificación.

Mi programa se construye una *teoría*: conjunto de fórmulas bien formadas, una lógica bien formada si es correcta sintácticamente.

La verificación formal con el sistema deductivo: parto de axiomas y con reglas de inferencia voy obteniendo mis verdades, con este sistema deductivo probar q eesos requisitos los cumplen en esta lṕgica, teoría. Se hacen demostraciones.

Verific el lengaje satisface las demostrasciones, lo que no demuestro es que cuando se ejecute vaya a funcionar.
Normalmente se prueba que la ejecución, se diseña conjunto de datos, de los cuales sabemos los resultados, para someter a todas las tensiones posibles el programa, si esta batería de datos pruebas funciona.
No se puede afirma que sea correcto, pero no tiene dudas dde que pueda fallar.


## Depuración

Supongamos que el programa no funciona, en programas complejos es más habitual que el fallo se detecte donde no se ha producido le fallo. Lo que es la traza de la ejecución. Cuando se corrige el fallo, tener cuidado con la propagación de la corrección, ya que al corregir algo se desajusta una parte. 