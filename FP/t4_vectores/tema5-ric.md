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

