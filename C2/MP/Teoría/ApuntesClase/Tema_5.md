<!--
Autor:
    Sergio Quijano Rey
    sergiquijano@gmail.com
Descripción:
    Apuntes del tema 5 tomados en clase
-->

# **Tema 5: Ampliación de clases**

## 5.1: Algunos conceptos

* Abstracción
* Abstracción funcional: ocultar como están implementadas las funciones, solo se necesita saber que hacen y qué parámetros se necesitan.
    * Inconvenientes de la programación directa sin modularización:
        * Código no reutilizable
        * Conlleva repetición de código
        * Modificación y mantenimiento de código costosa
    * Ventajas del desarrollo modular (abstracción funcional)
        * Se solucionan problemas más sencillo
        * Programa más sencillo de entender
        * Programa más fácil de mantener
        * Más fácil la localización de errores
        * Se permite la reutilización
* Abstracción de dato
    * Inconvenientes de la abstracción modular
        * Difícil de modificar: hay que cambiar completamente la interfaz del módulo, por ejemplo, hay que cambiar los parámetros de las funciones, y por tanto los programas que lo utilizan
    * Ventajas de la abstracción de datos
        * Se oculta la representación de datos mediante `struct` o `class`
        * Un cambio en la representación no supone que se tengan que cambiar los programas que usan el módulo
* Tipo de dato abstracto o `TDA` o `ADT`
    * Se implementan con `struct` o `class`. Nosotros nos vamos a centrar en `class`
    * En `struct`, por defecto, todo es público. En `class` es precisamente lo contrario. Es decir, no se evita que alguien use los datos de un `struct` de forma directa sin usar la interfaz diseñada. No hay **ocultamiento de la representación**
    * Los `struct` se usan normalmente para agrupar datos
* `Class`
    * Parte interna: especialmente la representación de ltipo de dato
    * Interfaz: limita y controla la interacción con la parte interna

## 5.2: Clases con datos dinámicos

### 5.2.1: Ejemplo con polinomios

* Queremos trabajar con cualquier poliniomio de `Rn[x]`
* No sabemos su grado, trabajamos con memoria dinámica para guardar monomios
* Nuestra clase tendrá los siguientes datos:
    * Array de coeficientes
    * Grado del polinomio

### 5.2.2: Constructores

* Se tiene que reservar memoria dinámica
* Tipos de constructores
    * Constructor por defecto creado automáticamente por `c++`
        * No inicializa los datos miembros (datos con contenido basura)
        * Lo que hace, que es muy útil, es llamar a los constructores de los datos de los datos miembro
        * Es aconsejable definir nosotros el constructor por defecto
    * Constructor por defecto implementado por el programador
    * Constructor con parámetros
        * Se le pasa al menos un parámetro

### 5.2.3: Operaciones

* Hay que pensar que operaciones soporta el tipo de dato abstracto
    * Se tiene que implementar un conjunto de operaciones mínimas que definan la funcionalidad básica
    * **Funciolidad adicional**: se añaden métodos que no son imprescindible, pero que son realmente útiles. En el ejemplo de nuestro polinomio, evaluarlo en un punto, derivarlo...
* Se pueden añadir funcionalidades y operaciones como:
    * Método: lo más usual
    * Funciones externas: algunas operaciones solo se pueden realizar de este método. Se suelen añadir en el `.h` de nuestro método
* Se recomienda que:
    * El número de operaciones sea no muy grande
    * No extenderse mucho en la funcionalidad adicional
    * Se utilicen directamente los datos miembros
    * No se recomienda que los métodos de la funcionalidad adicional accedan directamente a los datos miembro, para evitar cambiar código cuando se cambia la representación interna
    * Los métodos `inline` son muy recomendables para los *getters*. Se puede hacer colocando `inline` al principio de la función o implementando el método en el `.h`
* Tipos de operaciones
    * Consultores de los dato miembro
    * Modificadores de los datos miembro
    * Funcionalidades adicionales

### 5.2.4: Metodos `const`

* Se suelen utilizar en los *getters*
* De este modo, se asegura que no se modifiquen los datos miembros
* Los objetos declarados constantes, solo pueden usar métodos constantes

### 5.2.?: Ejemplo completo Polinomio

~~~c++
class Polinomio{
public:
    //CONSTRUCTORES
    Polinomio(){
        coeficientes = NULL;
        grado = 0;
    }

    Polinomio(const double * _coef, int size){
        grado = size;
        coeficientes = new double[size];

        //Copio los coeficientes
        for(int i = 0; i < size; i++){
            coeficientes[i] = _coef[i];
        }
    }

    Polinomio(int grado){
        size = grado;
        coeficientes = new double[size];

        //Lo asigno todo a cero
        for(int i = 0; i < size; i++){
            coeficientes[i] = 0;
        }
    }

    //GETTERS
    int getGrado() const{
        return grado;
    }

    double * getCoeficientes() const{
        return coeficientes;
    }

    double getCoeficiente(int pos){
        return coeficietes[pos];
    }

    //MODIFIERS
    void modifyCoeficientes(const double * _coef, int _size){
        coeficientes = _coef;
        size = _size;
    }

    void modifyCoeficiente(int val, int pos){
        if(val != 0){
            if(pos <= grado){
                coeficientes[pos] = val;
            }else{
                double * aux = new double[pos];

                //Copio los coeficientes
                for(int i = 0; i < grado; i++){
                    aux[i] = coeficientes[i];
                }
                aux[pos-1] = val;

                //Reasigno memoria
                delete[] coeficientes;
                coeficientes = aux;

                //Cambio el tamaño
                grado = pos;
            }
        }
    }

    //FUNCIONALIDADES ADICIONALES
    void show() const{
        for(int i = 0; i < grado; i++){
            cout << coeficientes[i] << "x^" << i;
            if(i != grado - 1){
                cout << " + ";
            }else{
                cout << endl;
            }
        }
    }

private:
    double * coeficientes;
    int grado;
};

int main(){
    Polinomio pol1; //Se llama al constructor por defecto
}
~~~
