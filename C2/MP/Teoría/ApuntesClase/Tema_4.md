<!--
Autor:
    Sergio Quijano Rey
    sergiquijano@gmail.com
Descripción:
    Apuntes tomados en clase del tema 4
-->

# **Tema 4: Ampliación de funciones**

## **4.1: Función main**

### 4.1.1: Parámetros de main

~~~c++
int main(int argc, char * argv[]){

    return 0;
}
~~~

* `argc`: el numero de argumentos que le pasamos al programa. El propio nombre de programa es un parámetro, luego siempre va a ser al menos 1
* `char * argv[]`: es un array de cadenas c, no es un puntero a una cadena c
* `return 0`: valor de retorno del programa, indica el estado y otras señales de ejecución del programa

**Ejemplo muy basico de uso**:

```c++
int main(int narg, char * argv[]){
    if(narg < 3){
        cerr << "Numero de argumentos erroneos" << endl;
        return 1;
    }else{
        for(int i = 1; i < narg; i++){
            cout << argv[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
```

### 4.1.2: Convertir `c_str` a `string`

Esto es útil porque tenemos más funcionalidades en la clase `string`. Esto se hace con una asignación usual.

~~~c++
int main(int narg, char * argv[]){
    string argumentos[narg];

    for(int i = 0; i < narg; i++){
        argumentos[i] = argv[i];
    }
}
~~~


## **4.2: Referencias**

Es una especie de alias a otro dato u objeto. Se usa principalmente en:

* Paso por referencia a funciones o métodos
* Referencias como alias a otras variables, *no muy útil*
* Devolución por referencia desde una función, *extremadamente útil*

### 4.2.1: Referencias como alias a otras variables

Una vez establecida la referencia, esta referencia se usa como la variable en si, no hay que pensar como si fuese un puntero.

```c++
//Obligatorio inicializarlo en la declaración
<tipo> & <identificador_alias> = <variable_referenciada>;

int a = 0;
int & alias = a;
alias = 5;    //Cambio a = 5

int lista[] = {1, 2, 3, 4};
int & ref = lista[2];
ref = 10;
```

### 4.2.2: Devolución por referencia

~~~c++
int& valor(int *v, int i){
    return v[i];
}
~~~

Nótese que no se devuelve una copia del dato, sino una referencia a ese dato que actuará como la variable devuelta. Se podría hacer con punteros, pero no nos permitiría una manipulación directa en modo variable, habría que trabajar con la capa de complejidad que supone el puntero. Lo más importante es lo siguiente, partiendo de la función anterior.

~~~c++
int main(){
    int v[] = {1,2,3,4,5,6,2};
    valor(v, 3) = 12;
}
~~~

Es un error muy común devolver por referencia a variables locales, que van a ser destruidas una vez que se acabe de ejecutar la función. No da error de compilación, pero es muy peligroso

**Ejemplo de funcion erronea:**

~~~c++
int& funcion(){
    int x = 3;
    return x;   //Devuelvo variable local
}


int main(){
    int y = funcion();
}
~~~

### 4.2.3: Devolución por referencia constante

~~~c++
const double& getVal(const int * v, int i){
	return v[i];
}

int main(){
	int v[] = {1,2,3,4};
	v[2] = v[2] * 3;		//Correcto
	getVal(v,2) = v[2] * 3;		//Incorrecto
	int value = getVal(2,3) *3;	//Correcto
}
~~~

## **4.3: Valores por defecto**

* No se puede hacer como en otros lenguajes en los que, cuando hay varios parámetros por defecto, en la llamada podemos elegir que parámetros se le pasa

~~~c++
void funcion(int num1, int num2 = 3){
	std::cout << num1 << "num2" << std::endl;
}

int main(){
	funcion(2);
	funcion(2,2);
}
~~~

## **4.4: sobrecarga de funciones**

* Se tienen que separar en:
	* Número de parámetros
	* Orden de los parámetros
	* Tipos de parámetros
	* Nombre de la función
* Hay que tener cuidado con las conversiones implícitas de tipo que hace C++ de forma automática
* No se pueden distinguir dos funciones solo porque devuelvan un tipo de dato distinto
* Se puede distinguir cuando un parámetros se pasa por referencia o por referencia constante (*ejemplo 1*)
* No se puede distinguir entre paso por valor y paso por valor constante (*esto último es poco útil*)
* Hay que tener mucho cuidado con las ambigüedades
	* Ambigüedad de tipo de dato
	* Ambigüedad de valores por defecto

**Ejemplo 1**:

~~~c++
void fun(int *p){
	cout << *p << endl;
}

void func(const int *p){
	cout << *p << endl;
}

int main(){
	int a = 5;
	const int * p1 = &a;
	int * p2 = &a;

	func(p1);	//Segunda funcion
	func(p2);	//Primera funcion
}
~~~

## **4.5: Funciones `inline`**

* En vez de llamar a la función en el programa, `C++` copia y pega el código donde aparece la llamada a la función
* Es obvio que se ejecutan mucho más rápido
* El problema es que si la función se llama en muchos sitios distintos, y además es grande, el ejecutable aumenta de tamaño considerablemente.

## **4.6: Variables locales de funciones `static`**

* Su valor no se pierde cuando acaba la función
* Es obligatorio asignarles un valor en la declaración
	* Es la única vez donde se inicializa


**Ejemplo de uso**:

~~~c++
void contador(){
	static int cont = 0;
	cont++;
	cout << "Se ha llamado " << cont << " veces" << endl;
}
~~~

## *4.6: Recursividad**

* Hay que definir siempre
	* Caso base
	* Caso general
* Es muy ineficiente el uso de funciones recursivas
	* Se usan sobre todo cuando la solución iterativa es muy compleja (*quicksort*) respecto a la solución recursiva
	*
