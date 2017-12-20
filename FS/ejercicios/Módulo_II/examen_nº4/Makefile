# Cree un fichero llamado Makefile con las siguientes características:
# 1. Debe tener una regla adicional llamada all que construya todo el programa
# 2. Debe tener una regla clean que limpie el proyecto (borrando ficheros objeto,
# de biblioteca y temporales).
# 3. Debe crear todos los ficheros necesarios para minimizar el tiempo de
# compilación del proyecto garantizando su coherencia.
# 4. Debe crear una biblioteca (librería) que se usará para construir el programa.
# Dicha biblioteca contendrá los ficheros asociados para los ficheros: complex,
# dist, fmat, geom. La biblioteca se llamará bib1.
# 5. Debe crear una biblioteca (librería) que se usará para construir el programa.
# Dicha biblioteca contendrá los ficheros asociados para los ficheros: msg,
# vector, imat y matriz. La biblioteca se llamará bib2.
# La regla a ejecutar por defecto debe ser la regla all. Mantenga la estructura de
# ficheros dada.


#Nombre archivo: Makefile
#Uso: make
#	make all
#Descripción: mantiene todas las dependencias

#Compilador:
CC=g++

#Ejecutable:
EXECUTABLE=nombre_del_ejecutable

#Ficheros de código fuente:
SOURCE_MODULES=ficherOS_codigo_fuente_.cpp

#Archivos objeto:
OBJET_MODULES=$(SOURCE_MODULES:.cpp=.o)

#Nombre de las bibliotecas:
LIB_NAME=bib1 bib2

#Directorio en el que se encuentran las bibliotecas:
LIB_DIR=directorio_en_el_que_se_encuentran_las_librerías

#Directorio en el que se encuentran los includes:
INCLUDE_DIR=directorio_en_el_que_se_encuentran_los_includes

all: $(EXECUTABLE) $(LIB_NAME)
	
$(EXECUTABLE): $(OBJET_MODULES)
	$(CC) -L$(LIB_DIR) -o $@ $^

bib1.a: complex.o dist.o fmat.o geom.o
	ar -rvs $@ $^
	
complex.o: complex.cpp
	$(CC) -I$(INCLUDE_DIR) -c $^

dist.o: dist.cpp
	$(CC) -I$(INCLUDE_DIR) -c $^
	
fmat.o: fmat.cpp
	$(CC) -I$(INCLUDE_DIR) -c $^

geom.o: geom.cpp
	$(CC) -I$(INCLUDE_DIR) -c $^

bib2.a: msg.o vector.o imat.o matriz.o
	ar -rvs $@ S^
	
msg.o: msg.cpp
	$(CC) -I$(INCLUDE_DIR) -c S^
	
vector.o: vector.cpp
	$(CC) -I$(INCLUDE_DIR) -c $^
	
imat.o: imat.cpp
	$(CC) -I$(INCLUDE_DIR) -c $^
	
matriz.o: matriz.cpp
	$(CC) -I$(INCLUDE_DIR) -c $^

clean:
	rm $(OBJET_MODULES) $(LIB_NAME)
