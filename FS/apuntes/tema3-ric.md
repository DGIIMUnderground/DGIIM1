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


22/11/17









<letra> a | b | c | d | e | ... | z
<digito> 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
<letra digito> <letra>|<digito>

<identificador> -> <letra> | <identificador><letra digito>


Esta gramática genera un lenguaje que sería el que contendría
los identificadores formados por caracteres y digitos, teniendo
en cuenta que


Lexemas: p1a2b3c.


Analogía en español:
     lex      lex    lex
    Pepe     come    un bocadillo

Abstrayendo
    Sujeto + Verbo + Complemento


Esa abstracción es un token.
La estructura sintáctica se representa en términos de token.


¿Qué hace un compilador con esta sentencia?


1. Análisis léxico

```
juan := pepe + 10
```

El compilador lee de izquierda a derecha analizando si la estructura corresponde
con la gramática.

El := actúa como separador. Pero también podrían haber sido los espacios
en blanco.

Además, el compilador genera una tabla de símbolos


Se construye la tabla de símbolos para que en otras fases las utilice.

Lexema | Tipo | Longitud | Dirección | Otros | Valor        |
---    | ---  | ---      | ---       | ---   | ---          |
Juan   | I    | 2        | 0         | ...   | (El que sea) | 
p      | R    | 4        | 2         | ...   | (El que sea) |
C      | I    | 2        | 6         | ...   |              |


En un programa, lo primero que aparece es la parte de declaración
(incluidas en librerías o no).


En el caso de Python, es dinámicamente tipado, lo cual significa que no hay
declaración explícita del tipo de variables. (No indicamos int char, etc.)
Es un lenguaje polimórfico, porque los identificadores son objetos.

2. Análisis sintáctico


juan := pepe + 10

id       id  op id

identificador_variable = expresión



- Funciones:

    - Abstracciones de expresiones
    - Siempre devuelven variables

```c++
string ladrido(string nombre) {
    return "Guau " + nombre;
}

int main() {
    string sonido = ladrido("Ricardo");
    cout << sonido << endl; // Guau Ricardo
}
```

2. Procedimientos:

    - Abstracciones de sentencias
    - Realizan acciones pero no devuelven valor
    - Pueden modificar variables.


```c++
void ladrar(string nombre) {
    cout << "Guau  " << nombre << endl;
}
int main() {
    ladrar()
}
```

Algunos conjuntos de gramáticas:

- LL (left left)

Las gramáticas que elaboran el árbol sintáctico de forma
descendente y de izquierda a derecha. 
(Si la frase es correcta tiene que terminar en el axioma).

- LR (left right)

Las gramáticas que elaboran el árbol de abajo hacia arriba
y de derecha a izquierda.

- LL(n) 
- LR(n)

Donde n es el número de tokens que hay que enviar para que reconozca 
unívocamente la frase que está analizando.

Cualquier gramática con n > 1, se puede trabajar con una gramátic
equivalente n = 1.


Resumen:

Cualquier sentencia de un lenguaje de programación.
Caracter a caracter de izquierda a derecha. Reconoce palabras
y la anota en la tabla de símbolos.
Estos tokens los manda al analizador sintáctico que crea
el árbol, mediante LL o LR, o LL(n) LR(n):


- Análisis léxico (automáta finito)
- Análisis sintáctico (autómata con pilas)
