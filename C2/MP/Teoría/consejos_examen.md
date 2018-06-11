# Preámbulos
Esta es una pequeña guía de cómo afrontar el examen de MP. La he escrito en media mañana, y es posible que haya erratas. Si veis alguna, hacémdelo saber, o actualizad el archivo en [el repositorio de DGIIM Underground](https://github.com/DGIIMUnderground/DGIIM1). Si queréis mejorar el archivo con vuestros ejemplos o consejos, adelante. Encantadísimo que estaría. ¡Espero que os sea útil!
<div style="text-align: right"> -Asmilex </div>

# Constructores por defecto:
En la mayoría de los casos, inicializar los miembros estáticos a 0, -1 o similares. Ejemplo: `int`, `double`, etc.
Punteros: inicializarlos a `0` = `nullptr`. Ejemplo:
```cpp
Class Dissee{
    private:
        int numero;
        int * puntero;      //Recuerda que los arrays pueden ser punteros
    public:
        Dissee(){
            numero  = 0;
            puntero = nullptr;
        }
}
```

# Constructores de copia
Reciben un objeto de la misma clase, y copian sus datos al nuevo. 
¡Cuidado con asignar los punteros a la ligera!
```cpp
Class Dissee{
    private:
        int numero;
        int * puntero;      
    public:
        Dissee(const Dissee otro_objeto ){
            numero  = otro_objeto.numero;
            puntero = new int;
            *puntero = otro_objeto.*puntero;
        }
}
```
Lo que buscamos al igualar punteros es copiar el **contenido** de la dirección del puntero, **no las direcciones** . Por eso, en este caso, `puntero = otro_objeto.puntero` sería incorrecto. Haríamos que nuestro objeto a crear apunte a la zona de memoria de `otro_objeto`

Si nuestros punteros son arrays(que lo van a ser en el exanen) se haría así:
```cpp
Class Dissee{
    private:
        int numero;
        int * puntero;      
    public:
        Dissee(const Dissee & otro_objeto ){
            numero  = otro_objeto.numero;
            puntero = new int [numero];      //supongamos que numero es la dimensión del array
            
            for (int i=0; i<numero; i++)
                puntero[i] = otro_objeto.puntero[i];
        }
}
```
El operador `*` y `[]` para arrays son extremadamente similares. Para nuestro nivel de aprendizaje, idénticos. Ambos acceden al valor que reside en su zona de memoria a la que apunta el puntero

# Operador de asignación
Es exactamente igual al de copia, con un ligero matiz. Como hacen lo mismo, vamos a _copiar_ en una función aparte lo que teníamos en el constructor de copia anterior. Para no repetir código, vamos. Por vagos. Veamos un ejemplo:
```cpp
Class Dissee{
    private:
        int numero;
        int * puntero;      
    public:
        Dissee(const Dissee& otro_objeto ){
            Copiar(otro_objeto);
        }
        //    v         <- Notice me//
        Dissee& operator=(const Dissee& otro_objeto){ 
            Copiar(otro_objeto);
            return *this;
        }

        void Copiar(const Dissee & otro_objeto){
            numero  = otro_objeto.numero;
            puntero = new int [numero];      //supongamos que numero es la dimensión del array
            
            for (int i=0; i<numero; i++)
                puntero[i] = otro_objeto.puntero[i];
        }
}
```
Tenemos que hacer un `return *this`. ¿Por qué? Porque queremos modificar nuestro objeto. En otros operadores, devolveremos otros de la misma clase, pero no cambiamos el nuestro. 

# Destructor
Se encarga de liberar la memoria dinámica. Y ya. Se hacen casi siempre así: 
```cpp
    Class Dissee{
    private:
        int numero;
        int * puntero;      
    public:
        ~Dissee(){
            if (puntero != nullptr)
                delete [] puntero;
        }
}
```

# Otros operadores
Son bastantes similares. Podemos hacerlas como funciones externas o internas a la clase. Si queremos hacerlas externas, tenemos que hacerlas `friend`: 

Supongamos que lo que hace el operador + es sumar ambos arrays. Lo haríamos así: 
```cpp
Class Dissee{
    private:
        int numero;
        int * puntero;      
    public:
        friend Dissee operator+(const Dissee& primero, const Dissee& segundo);
        //Una suma tiene dos partes:         este^       +       ^ este otro
};
//Aquí ya no lleva friend. Ten en cuenta eso
Dissee operator+(const Dissee& primero, const Dissee& segundo){
    //Implementación
}
```
Ya que estamos, vamos a implementarlo:
```cpp
Dissee operator+(const Dissee& primero, const Dissee& segundo){

    //Los pasos serían: hacer un nuevo objeto y copiar ambos objetos poco a poco
    
    Dissee resultado;
    resultado.numero = primero.numero + segundo.numero;

    /*Tenemos que copiarnos los VALORES de los punteros, pero no sus direcciones. Para 
      Ello, tenemos que reservar nueva memoria, y empezar a pasar poco a poco. 
      Siempre es así (para nuestro examen, de momento)*/

    resultado.puntero = new int [resultado.numero];

    int i = 0;

    //Pasamos el primero
    for (i;         i < primero.numero; i++)
        resultado.puntero[i] = primero.puntero[i];

    //Y ahora el otro. Recuerda que tienes que seguir por donde te quedaste
    for (int j = 0; j < segundo.numero; j++){
        resultado.puntero[i] = segundo.puntero[j];
        i++;
    }

    return resultado;
}
```
No olvides que los operadores son funciones. Puestas mu bonicas, pero funciones. Como toda función, tiene un valor de retorno, unos parámetros pasados y un nombre. 

Lo que devuelve va al principio. En la suma de arriba, nos devuelve un objeto de la clase Dissee. El nombre de la función es `operator+` (y se le invoca poniendo solo +. Una suma de toda la vida, vamos), y recibe lo que te haga falta.

Si lo hacemos como método de la clase, recuerda que en la llamada va intrínseco el primer objeto. Por ejemplo, imagina que hubiéramos hecho la suma como método. Entonces, la cabecera sería así: 

```cpp
Dissee operator+(const Dissee& segundo) const{
    //Implementación
}
```
De hecho, implementémoslo. Todo es prácticamente lo mismo. Para matizar dónde está el primer objeto de antes, voy a usar `this`:
```cpp
Class Dissee{
    private:
        int numero;
        int * puntero;      
    public:
        Dissee operator+(const Dissee& segundo) const {

            //Hacemos un nuevo objeto y copiamos ambos objetos
            
            Dissee resultado;
            resultado.numero = this->numero + segundo.numero;

            resultado.puntero = new int [resultado.numero];

            int i = 0;

            //Pasamos nuestro objeto original
            for (i;         i < this->numero; i++)
                resultado.puntero[i] = this->puntero[i];

            //Y ahora el otro. Recuerda que tienes que seguir por donde te quedaste
            for (int j = 0; j < segundo.numero; j++){
                resultado.puntero[i] = segundo.puntero[j];
                i++;
            }
            return resultado;
        }
};
```
`this->` es equivalente a usar cualquier método o valor de la clase, sea privado o no. Vamos, que puedes borrar en todo lo de arriba `this->` y funciona igual

# Entrada y salida a archivos
No sigue una estructura tan marcada como los operadores y los constructores. Pero, a fin de cuentas, se resume en:
1. Crear el flujo de salida o entrada
2. Comprobar que se ha abierto bien el archivo. Si no se ha abierto correcamente, `return false`
3. Leer o escribir los archivos según te lo manden
4. Cerrar el archivo

Vamos a implementar ambas para nuestra cutre-clase. Primero, tenemos que ver cómo está organizado nuestro fichero. Por ejemplo, supongamos que tiene esta forma:
```
4
1 53 63 -1
```
donde el primer número corresponde al miembro privado `numero` y los otros son los que van en el array `* puntero`. En este caso, sería así: 

## Lectura de archivo
```cpp
Class Dissee{
    private:
        int numero;
        int * puntero;      //Recuerda que los arrays pueden ser punteros
    public:
        bool LoadFile(string archivo){

            //Creamos flujo y abrirmos archivo
            ifstream entrada;
            entrada.open(archivo);

            //Comprobamos que se ha abierto bien
            if (!entrada){
                cout <<"El archivo no se ha abierto correctamente";
                return false;
            }
            
            int n; 
            entrada >> n;

            /*Esta parte no es tan mecánica. Se reduce ahora en hacerse un nuevo 
              array del tamaño adecuado, e ir metiendo los valores del fichero.
              Depende en su totalidad de cómo esté organizado el formato del fichero
              En nuestro caso:*/

            this->numero = n;
            this->puntero = new int [n];

            for (int i=0; i<n; i++){
                entrada>>this->puntero[i];
            }

            //Cerramos el fichero y devolvemos true para indicar que ha ido bien
            entrada.close();
            
            return true;
        }
}
```

## Escritura de archivo
Realmente, ambas son funciones similares. Los pasos siguen siendo los mismos:
```cpp
Class Dissee{
    private:
        int numero;
        int * puntero;      //Recuerda que los arrays pueden ser punteros
    public:
        bool SaveFile(string archivo){

            //Creamos flujo y abrirmos archivo
            ofstream salida;
            salida.open(archivo);

            //Comprobamos que se ha abierto bien
            if (!salida){
                cout <<"El archivo no se ha abierto correctamente";
                return false;
            }
            
            //Escribimos en archivo con el formato que nos han indicado
            salida <<this->numero;

            for (int i=0; i<this->numero; i++){
                salida<<this->puntero[i];
            }

            //Cerramos el fichero y devolvemos true para indicar que ha ido bien
            salida.close();
            
            return true;
        }
}
```
# Consejos generales

## Cómo afrontar un examen a papel
Los fundamentos de escritura de código a papel y en ordenador son exactamente los mismos. Sin embargo, tienes que ser más preciso. El tiempo apremia, y si te equivocas, cuesta mucho más borrar las cosas.

**Piensa con calma qué te dan y qué te piden**. Es MUY importante entender esto bien. Gasta el tiempo que necesites, y pregúntale al profesor tantas veces como haga falta. Pero las conclusiones a las que llegues aquí determinan el tiempo y la limpieza con la que harás el examen.

Una vez lo sepas, intenta escribir bien. Un código limpio es un código feliz. Y más si es a papel. Si lo necesitas, usa un folio aparte para hacer guarradas. Después lo pasas a limpio.

Recuerda pensar qué te piden en cada apartado. Muchas veces puedes reusar los anteriores, y se te queda muy limpico el actual
  
## Sobre memoria dinámica
Es bastante posible que tengas que reservar y liberar memoria en varios métodos, sea cual sea el motivo. Aunque pueden llegar a ser funciones muy tontas, a veces viene bien tenerlas en funciones a parte. Suelen tener este formato:
### Reservas de memoria:
```cpp
    void ReservarMemoria(int dimension){
        if (puntero != nullptr)
            LiberarMemoria();
        
        numero  = dimension;
        puntero = new int [dimension];'
    }
```
Hemos supuesto que `numero` guarda la el tamaño del array. Evidentemente, puedes cambiar `int` por lo que sea: pueden ser `float`, `double`, `int *` (para matrices), o incluso objetos de clases.

### Liberación de memoria
No tiene mucha complicación. Eliminas lo que tengas (si es que tienes algo), y actualizas la dimensión

```cpp
    void LiberarMemoria(){
        if (puntero != nullptr)
            delete[] puntero;
        numero = 0;
    }
```
De nuevo, hemos supuesto que `numero` almacena la dimensión del array. 

Podemos reusar estas funciones para diferentes métodos. Incluso constructores. Por ejemplo, el destructor de la clase anterior quedaría así:
```cpp
    Class Dissee{
    private:
        int numero;
        int * puntero;      //Recuerda que los arrays pueden ser punteros
    public:
        ~Dissee(){
            LiberarMemoria();
        };
        
        void LiberarMemoria(){
            if (this->puntero != nullptr)
                delete[] puntero;
            numero = 0;
        }

}
```