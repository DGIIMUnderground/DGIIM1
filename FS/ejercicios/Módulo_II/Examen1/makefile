#2. Cree un fichero llamado Makefile con las siguientes características:
#	1. Debe tener una regla adicional llamada all que construya todo el programa
#	2. Debe tener una regla clean que limpie el proyecto (borrando ficheros objeto, de biblioteca y temporales).
#	3. Debe tener una regla install que instale el programa en el directorio dado por la variable INSTALL_DIR (ver siguientes puntos).
#	4. Debe tener una regla uninstall que desistale el programa del directorio dado por la variable INSTALL_DIR (ver siguientes puntos).
#	5. Debe declarar una variable de Makefile definida apuntando al directorio temporal del sistema, llamada INSTALL_DIR
#	6. Debe crear todos los ficheros necesarios para minimizar el tiempo de compilación del proyecto garantizando su coherencia.
#	7. Debe crear una biblioteca (librería) que se usará para construir el programa. Dicha biblioteca contendrá los ficheros asociados para los ficheros geom, complex y vector.

#La regla a ejecutar por defecto debe ser la regla all.


###SOLUCIÓN###
#Uso: make
#     make all
#Descripción: mantiene todas las dependencias
#Variables
SRCS=complex.cpp geom.cpp pr.cpp vector.cpp
OBJS=$(SRCS:.cpp=.o)
HDRS=$(SRCS:.cpp=.h)

LIB_MODS=complex.cpp geom.cpp vector.cpp
LIB_OBJS=$(LIB_MODS:.cpp=.o)
LIB_HDRS=$(LIB_MODS:.cpp=.h)

EXECUTABLE=makefile.out

INSTALL_DIR=/tmp

LIB_NAME=libcomp.a
LIB_DIR=./

CPPFLAGS=-Wall
CC=g++


all: $(EXECUTABLE) $(LIB_NAME)

$(EXECUTABLE): $(OBJS)
	$(CC) -o $@ $^

complex.o: complex.cpp complex.h
	$(CC) -c $(CPPFLAGS) $<

geom.o: geom.cpp geom.h
	$(CC) -c $(CPPFLAGS) $<

vector.o: vector.cpp vector.h
	$(CC) -c $(CPPFLAGS) $<

pr.o: pr.cpp $(LIB_HDRS)
	$(CC) -c $(CPPFLAGS) $<	

$(LIB_NAME): $(LIB_OBJS)
	-ar -rvs $@ $^

install: $(EXECUTABLE)
	mv $(EXECUTABLE) $(INSTALL_DIR)

uninstall:
	rm "$(INSTALL_DIR)/$(EXECUTABLE)"

clean:
	rm $(OBJS) $(LIB_NAME) 
