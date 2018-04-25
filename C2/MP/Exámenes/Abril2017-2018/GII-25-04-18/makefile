#############################################################################
#
# METODOLOGIA DE LA PROGRAMACION
# GRADO EN INGENIERIA INFORMATICA
#
# CURSO 2017-2018
# (C) FRANCISCO JOSE CORTIJO BON
# DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
#
# makefile
#
# Examen Práctico 1
#
#############################################################################


BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include

#................................................
all:  	preambulo \
		bibliotecas\
		$(LIB)/libLista.a \
		fin-bibliotecas \
		ejecutables\
		$(BIN)/examen \
		fin-ejecutables

#................................................
preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo METODOLOGÍA DE LA PROGRAMACIÓN
	@echo Grado en Ingeniería Informática - Grupo A
	@echo Antonio David Villegas Yeguas
	@echo CURSO 2017-2018
	@echo
	@echo Examen Práctico 1
	@echo
	@echo ------------------------------------------------------------
	@echo

#................................................
final: 
	@echo

ejecutables:
	@echo Creando ejecutables...

fin-ejecutables:
	@echo ...Creados ejecutables
	@echo 	

bibliotecas:
	@echo Creando bibliotecas...

fin-bibliotecas:
	@echo ...Creadas bibliotecas
	@echo 	

#................................................
# EJECUTABLES

$(BIN)/examen : $(OBJ)/examen.o \
                $(OBJ)/GeneradorAleatorioEnteros.o \
                $(LIB)/libLista.a
	g++ -o $(BIN)/examen $(OBJ)/examen.o $(OBJ)/GeneradorAleatorioEnteros.o \
           -L$(LIB) -lLista

#................................................
# OBJETOS

$(OBJ)/Lista.o : $(SRC)/Lista.cpp \
                 $(INCLUDE)/GeneradorAleatorioEnteros.h \
                 $(INCLUDE)/Lista.h

	g++ -c -o $(OBJ)/Lista.o $(SRC)/Lista.cpp -I$(INCLUDE) -std=c++11


$(OBJ)/GeneradorAleatorioEnteros.o : $(SRC)/GeneradorAleatorioEnteros.cpp \
                                     $(INCLUDE)/GeneradorAleatorioEnteros.h
	g++ -c -o $(OBJ)/GeneradorAleatorioEnteros.o \
              $(SRC)/GeneradorAleatorioEnteros.cpp \
              -I$(INCLUDE) -std=c++11


$(OBJ)/examen.o : $(SRC)/examen.cpp $(INCLUDE)/Lista.h
	g++ -c -o $(OBJ)/examen.o $(SRC)/examen.cpp -I$(INCLUDE) -std=c++11

#................................................
# BIBLIOTECAS

$(LIB)/libLista.a : $(OBJ)/Lista.o
	ar -rvs $(LIB)/libLista.a $(OBJ)/Lista.o

#................................................
# LIMPEZA

clean: clean-objs clean-objetos-bibliotecas clean-bibliotecas

clean-objs: 
	@echo 
	@echo Borrando objetos...

	-rm $(OBJ)/examen.o

	@echo ...Borrados
	@echo 

clean-objetos-bibliotecas: 
	@echo Borrando modulos objeto usados en bibliotecas...

	-rm $(OBJ)/Lista.o
	-rm $(OBJ)/GeneradorAleatorioEnteros.o

	@echo ...Borrados
	@echo 

clean-bibliotecas: 
	@echo Borrando biblioteca...

	-rm $(LIB)/libLista.a

	@echo ...Borrada
	@echo 

clean-bins : 
	@echo Borrando ejecutables...

	-rm $(BIN)/examen

	@echo ...Borrados
	@echo 	

mr.proper:  clean clean-bins

