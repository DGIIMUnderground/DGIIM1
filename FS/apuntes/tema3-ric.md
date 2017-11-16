# FS: 15/09/17

Para entender los esquemas de representación de árbol, la flecha indica la
estructura de un símbolo no terminal (analogía palabra y frases o párrafos).

Ahora bien, un símbolo puede tener más de una estructura. En este caso, se
utiliza para separar el símbolo |.

Ejemplo de frase:

          E
  .    O        E
  .    .  (   E       )
  .    .
  E    .          E
E  O E  O  E O (E O  E)

id + id * (id-(id/id))

Esto tiene sentido si id es una expresión y +, -, *, / son operaciones.

Además, si añadimos la prioridad de los paréntesis como regla semántica,
podemos evaluar la expresión, de abajo a arriba y encontrar un significado.

# FS: 16/09/17

Repaso: árboles sintácticos

Una estructura sintáctica que tiene más de un significado es ambigua.  Para
resolver estas ambigüedades, necesitamos priorizar las operaciones.

El if es ambiguo si no existe una condición para concretar cual es el
significado.

if condicion then if condicion then if condicion then...


Recordamos la definición de gramática G=(N,T,P,S) Recuerdo que los literales
numéricos son exactamente lo mismo que otro identificador cualquiera.  A cada
identificador se le asigna una dirección de memoria.  La única diferencia es
que los literales son constantes, no se les puede asignar ningún valor.

Algunos tipos de gramática:
    - G. Libres -> Un algoritmo en sí es una gramática libre.
    - G.S.C (Sensibles al contexto) -> Tratamiento de lenguaje natural
    - G.I.C (Independientes del contexto)
    - G. Regulares

Los lenguajes de programación deben tener G.I.C, de manera que evitamos
ambigüedad.  Las expresiones regulares son de este último tipo.


Los lingüistas ya habían desarrollado el concepto de gramática formal. (Años
20)

Por otro lado, los ingenieros de automatización formalizaron matemáticamente la
idea de autómata. (Años 50)

A finales de los años 50, la comunidad de Lenguajes y Sistemas une las dos
cosas unifica la formalización de gramática, especialmente con el tipo
independiente.  Además, construyen automátas capaces de implementar esos tipos
de gramática.

Dentro de esos tipos de automátas:

    - Gramáticas Regulares - Autómatas finitos
    - Gramáticas Independientes del contexto-  Autómatas con pila. (Stack) ->
      El autómata almacena en la pila para almacenar lo que reconoce.
    - Gramáticas libres - Máquina de Turing

Para cada tipo de gramática, se programa el automáta correspondiente, y así
tener hecho el traductor.


Gramáticas regulares: permiten definir el léxico Gramáticas Ind. Cont: permiten
identificar la sintaxis

Como tipo intermedio entre G.I.C y G.S.C:

- Gramática de 2 niveles: (VVG) -> Gramática que genera un lenguaje
- Gramática con atributos: (C.T. Irons) -> Uso particular: utilidas para
  especificar la semántica de los lenguajes de programación.

    Ga = (Gig, A, E, C)

    A: atributos A cada símbolo se le asocian atributos. Ejemplo el
significado.  E: reglas de evaluación

    C: condiciones sobre los valores de los atributos

Ejemplo: constante entera 14:
    - Dígito: [0-9]  - S. terminales

    - Constante: (Símbolos no terminales)
            Dígito | Cte seguida de un dígito
         v(cte) = v(digito)   v(cte) = v(cte)*10 + v(digito)

        Importa la posición 
        Ejemplo 125 es una constante, cuyo valor
        se forma mediante el valor del dígito 1


        - Es necesario especificar que el valor de la constante
        fuera siempre menor o igual al tamaño límite.


    Estas dos primera reglas forman una gramática regular que
    es independiente del contexto.


    - Producciones (estas reglas y también la regla del atributo valor)
    - Axioma: Constante
    - Atributo valor:
        - Asociar a cada carácter de la tabla ASCII un significado
        - Valor del 0: 0 Donde el primero es el símbolo y el segundo el
          significado.

