#1. Dado el código fuente realice el fichero makefile para que se compile el programa cuando escribamos la siguientes órdenes indistintamente:
# make
# make all
#Dicha orden debe permitir la depuración del programa ejecutable resultante. Guarde dicho fichero como makefile1.
#Realice además las modificaciones oportunas para que se cree una biblioteca llamada libpi.a que contenga los ficheros objetos resultantes del código de los ficheros pi.cpp, pi.h, rand.cpp y rand.h. Además la última fase de compilación debe realizarse utilizando la librería y no los ficheros objeto. Escriba un comentario con los cambios realizados. Guarde el nuevo fichero como makefile2.
#Adicionalmente, al escribir la orden:
# make clean
#se deberían eliminar todos los ficheros objeto del directorio y la biblioteca creada, así como los ficheros temporales. Escriba un comentario con los cambios realizados. Guarde el nuevo fichero como Makefile.



###Solución###

#Nombre archivo: makefile
#Uso: make
#     make all
#Descripción: mantiene todas las dependencias

# Variables
CC=g++
CPPFLAGS=-Wall

SRCS=main.cpp pi.cpp rand.cpp
OBJS=main.o pi.o rand.o
HDRS=pi.h rand.h

LIB_MODS=pi.cpp rand.cpp
LIB_OBJS=$(LIB_MODS:.cpp=.o)
LIB_HDRS=$(LIB_MODS:.cpp=.h)

LIB_NAME=libpi.a

EXECUTABLE=makefile1.out


all: $(EXECUTABLE) $(LIB_NAME)

$(EXECUTABLE): $(OBJS)
	$(CC) -o $@ $(OBJS)

main.o: main.cpp $(LIB_HDRS)
	$(CC) -c $(CPPFLAGS) $<

pi.o: pi.cpp pi.h
	$(CC) -c $(CPPFLAGS) $<

rand.o: rand.cpp rand.h
	$(CC) -c $(CPPFLAGS) $<

$(LIB_NAME): $(LIB_OBJS)
	-ar -rvs $@ $^

clean:
	rm $(OBJS) $(LIB_NAME) $(EXECUTABLE) 
