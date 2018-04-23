# CADENAS DE CARACTERES
## Tipos
Es una cadena de caracteres de longitud variable. Distinguimos dos tipos:

- String: Cadenas de caracteres de c++.
- Cstring: Cadenas de caracteres de c.

La principal diferenca es que una cadena de tipo cstring tendrá siempre al final unn terminador (\0).

## Cstring
### Declaración
Tiene tamaño uno más que el número de caracteres (para el teemrinador).
```cpp
#include <cstring>
```
```cpp
char nombre[10] = {’J’,’a’,’v’,’i’,’e’,’r’,’\0’}; //Tiene tamaño 10 pero solo ocupa 7 posiciones de las 10 disponibles.
char nombre[] = {’J’,’a’,’v’,’i’,’e’,’r’,’\0’}; // Asume tamaño 7.
char nombre[10] = "Javier"; //Equivalente a la primera decalración.
char nombre[] = "Javier";//Equivalente a la segunda decalración.
```
**Ojo:** Si introduces la cadena de caracteres como caracteres, deberás indicar explícitamente el terminador, si la declaras como una secuencia (entre comillas) el terminador se colocará automáticamente.

### Introducción y escritura de cadenas
Al contrario que con los arrays, no hace falta usar un bucle para introducir o mostrar elemento a elemento.
```cpp
char nombre[80];
cout << "Introduce tu nombre: ";
cin >> nombre;
cout << "El nombre introducido es: " << nombre;
```
Si se desea introducir una cadena con espacios, se deberá usar _getline_ en lugar de _cin_ como se muestra:
```cpp
cin.getline(<cadena>, <tamaño>);
```

### Funciones
- char * strcpy(char cadena1[], const char cadena2[])
Copia cadena2 en cadena1. Es el operador de asignación de cadenas.
- int strlen(const char s[])
Devuelve la longitud de la cadena s.
- char * strcat(char s1[], const char s2[])
Concatena la cadena s2 al final de s1 y el resultado se almacena en s1.
- int strcmp(const char s1[], const char s2[])
Compara las cadenas s1 y s2. Si la cadena s1 es menor (lexicográficamente) que s2 devuelve un valor menor que cero, si son iguales devuelve 0 y en otro caso devuelve un valor mayor que cero.
- const char * strstr(const char s1[], const char s2[])
char * strstr(char s1[], const char s2[])
Devuelve un puntero a la primera ocurrencia de s2 en s1, o un puntero nulo si s2 no es parte de s1.
```cpp
#include<iostream>
#include<cstring>
using namespace std;
int main(){
	const int DIM=100;
	char c1[DIM]="Hola", c2[DIM];
	strcpy(c2, "mundo");
	strcat(c1, " ");
	strcat(c1, c2);
	cout <<"Longitudes:"<<strlen(c1)<<" "<<strlen(c2);
	cout << "\nc1: " << c1 << " c2: " << c2;
	if (strcmp(c1,"adiós mundo cruel") < 0)
		cout << "\nCuidado con las mayúsculas\n";
	if (strcmp(c2, "mucho") > 0)
		cout << "\n\"mundo\" es mayor que \"mucho\"\n";
	}
```
```cpp
#include <iostream>
#include <cstring>
using namespace std;
void lee_linea(char c[], int tamano);
void deja_solo_primera_palabra(char c[]);
int main() {
	const int DIM=100;
	char cadena[DIM];
	cout << "Introduce una cadena: ";
	lee_linea(cadena, DIM);
	deja_solo_primera_palabra(cadena);
	cout << "Resultado = " << cadena << endl;
}
void deja_solo_primera_palabra(char c[]) {
	int i=0;
	// No hay espacios en blanco al inicio
	while (c[i] != ’ ’ && c[i] != ’\t’ && i < strlen(c))
	i++;
	if (i < strlen(c))
	c[i] = ’\0’;
}
```
```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int DIM=100;
void lee_linea(char c[], int tamano);
void recorta(const char c1[], int ini, int lon, char c2[]);
int main() {
	char cadena1[DIM], cadena2[DIM];
	int i, l;
	cout << "Introduce una cadena: ";
	lee_linea(cadena1, DIM);
	cout <<"Introduce el inicio y la longitud (enteros): ";
	cin >> i >> l;
	recorta(cadena1,i,l,cadena2);
	cout << "Resultado = >" << cadena2 << endl;
}
void recorta(const char c1[], int ini, int lon, char c2[]){
	int i=0;
	while (i+ini < strlen(c1) && i<lon){ //para que ini o lon no sean muy grandes
	// para contar hasta lon
		c2[i] = c1[i+ini];
		i++;
	}
	c2[i] = ’\0’;
}
```

### Conversión
- Cstring a string
```cpp
char cadena1[]="Hola";
string cadena2;
char cadena3[10];
cadena2=cadena1; // cstring-->string
```
- String a cstring
```cpp
char cadena1[]="Hola";
string cadena2;
char cadena3[10];
strcpy (cadena3, cadena2.c_str()); // string-->cstring
```