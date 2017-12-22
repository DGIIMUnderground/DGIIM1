01/12/2017

POO / PDO (Programación Dirigida a Objetos)

Paradigma de programación que abstrae el concepto
de dato y función para definir el concepto de Clase.

Esta es la base de la definición de tipos de datos abstractos,
pues podemos crear nuevos objetos que se comporten como datos
primitivos.

- Especificación: definir el comportamiento (capa superficial)

- Representación: forma concreta en que se representan
los datos para poder manejarlos.

- Implementación: forma en que se expresan las operaciones


Visión externa: Especificación
Visión interna: Representación e implementación


Ejercicio n1: Pensar en especificación de Fecha.
Ejercicio n2: Pensar en especificación de Complejo.

Una de las ventajas de la representación en clases es la encapsulación
y el reparto de responsabilidades. Tanto la representación como la
implementación importan al programador pero no al usuario de esa
clase. Cuando un programador utiliza esa clase, lo único que deber de tener
en cuenta es la especificación (Público para todos).

¿Se puede representar una fecha con un único entero? Sí, TIMESTAMP
Cambiar la especificación es feo. Lo importante es cambiar la implementación.
Puesto que cambiar la implementación no afecta a los programas que utilicen
esa API.


Objeto: instancia de una clase. Entidad provista de atributos (datos)
y de funcionalidad (métodos).
Métodos: algoritmo asociado a una clase de objetos cuya ejecución se
activa tras la recepción de un mensaje.


```c++
class racional {
    int numerador;
    int denominador;
    racional suma{const racional &) const;
};
```

```c++
racional r(1,2); // Constructor primitivo
racional r; // Constructor por defecto
            // Es como si fuera racional r();
```

Si no especificamos en una clase private o public para sus miembros,
todo será privado.
En el caso de protected, es accesible a clases derivadas (por herencia).

En C++, tenemos el parámetros this como semejante al self, de python.


15/12/17

Importante de cara al examen:

    - Escribir especificación de las funciones en el examen. 
    - Referencias constantes
    - Sobrecarga de operadores (+)
    - Producto de 2 matrices
        - 3 bucles anidados
    

Detalle importante:

Cuando declaramos objetos constantes, ejemplo

```c++
const Fecha f,g
if (f < g)
    cout << "f es menor que g"
```
Esto da error si la sobrecarga del operador `<` está definida
sin especificar `const` al final del método.

Podemos copiar un objeto

```c++
Fecha::MetodoChachiPiruli() const {
    Fecha f(*this);
}
```

Curiosidad, si queremos sobrecargar el `operador++`,
no podemos implementar el método constante.

Para diferenciar la sobrecarga de los operadores
incremento postfijo y el prefijo 

```c++
operator++(int) // Postfijo
operator++() // Prefijo
```

Las variables de clase en C++ las declaramos mediante
`static`

`static const std::vector<int> dias_mes;`

Cuando los métodos son cortos, es preferible implentarlos
directamente en el archivo cabecera anteponiendo la
palabra inline.

Incluso se puede implementar dentro de la cabecera
.h. Pero mezclamos especificación con implementación
lo cual puede ser visto un poco feo.


21/12/2017

Información tiquismiquis:
    - La especificación incluye la cabecera de la
función (valor de retorno), nombre de la función
y argumentos.

    - Los observadores son const, no modifican
el objeto.


Especificación de la clase Polinomio
```c++

/**
    @brief: TDA para representar polinomios
    Vienen dados por a0x^1 + a1 x² + ... + an x^n
    OPeraciones definidas x, - *, / extraer raíces, evaluar
*/
class Polinomio {
    public:

        /**
        @brief: Constructor por defecto
        El objeto es creado como el polinomio 0.
        */
        Polinomio();

        /**
        @brief: Constructor primitivo.
        @param coef:
            Restricciones para el programador:
                 - v.size() == (grado + 1)
                 - v[v.size()] != 0 
        @param grado: 
            0 excluido pues para eso está el constructor por defecto
            Construimos el polinomio de grado "grado" con la forma
            coef[0] + coef[1]x^1 + .... + coef[grado]x^grado
        */
        Polinomio(vector<double>& coef, int grado) const;

        /**
        @brief: Constructor por copia
        
        */
        Polinomio(const Polinomio& polin);

        /**
        @brief: Evalua el polinomio en un punto dado
        @param x: punto en el que se evalúa el polinomio
        @return : Devuelve el valor que se obtiene
        al evaluar el punto en el polinomio
        */
        double Evaluar(double x) const;

        /**
        @brief: Devuelve la suma de dos polnomios
        @param polin: polinomio que se quiere sumar
        @return: suma de los polinomios
        */
        double operator()(double x) const;
        Polinomio suma(const Polinomio& polin) const;

        /**
        @brief: Extrar grado de un polinomio
        @return: en
        */
        int grado() const;

    private:
        vector<double> coef;
        unsigned int grado;
};

Polinomio Polinomio::operator+(const Polinomio& p) const {
    Polinomio r((grado > p) ?: *this : p);

    // p.grado (?) es privado!
    if (grado > p.grado) {
        for (int i=0; i <= p.grado; i++)
            r.coef[i] += p.coef[i];
    } else {
        for (int i=0; i <= grado; i++)
            n.coef[i] += p.coef[i];
    }
    return r;
}

double Polinomio::operator()(const double& x) const {

    // Cuidado:
    // pow es muy costosa, por lo que mereceria la pena
    // quizas tratar los casos i=0, i=1, etc...

    // Pero lo mejor es sin duda el Algoritmo de Horner
    // Sucesivas multiplicaciones


    double suma = 0;
    for (int i=0; i < coef.size(); i++)
        suma += coef[i] * pow(x, i);
    return suma;
}
```

Invariante de la representación:
    - Condición que tiene que cumplir la implementación
para mantener coherente el tipo de dato de Polinomio.
    - Ejemplo:
Cada vez que aparezca un objeto polinomio y sea
manipulado, debe respetar esta condición:

        - v.size() == (grado + 1)
        - v[v.size()] != 0 

Ahora bien, esto es distinto del caso de la restricción
en el constructor, pues es el usuario el que tiene
la responsabilidad.

Función de abstracción

{
coef 
grado 
} -> p(x) = coef[0] + .... 

Indica explícitamente como se construye
el polinomio. Debe estar indicada en la implementación
pues es una operación externa.

Datos sobre funciones recursivas:

    x^n = (x^(n/2))^2

