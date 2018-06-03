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
# Examen Práctico 2
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
		fin-bibliotecas \
		ejecutables\
		$(BIN)/examen2 \
		fin-ejecutables

#................................................
preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo METODOLOGÍA DE LA PROGRAMACIÓN
	@echo Grado en Ingeniería Informática - Grupo A
	@echo CURSO 2017-2018
	@echo
	@echo Examen Práctico 2
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

$(BIN)/examen2 : $(SRC)/examen2.cpp

	g++ -o $(BIN)/examen2 $(SRC)/examen2.cpp -std=c++11

#................................................
# OBJETOS


#................................................
# BIBLIOTECAS


#................................................
# LIMPEZA

clean: clean-objs clean-objetos-bibliotecas clean-bibliotecas

clean-objs: 
	@echo 
	@echo Borrando objetos...

	@echo ...Borrados
	@echo 

clean-objetos-bibliotecas: 
	@echo Borrando modulos objeto usados en bibliotecas...

	@echo ...Borrados
	@echo 

clean-bibliotecas: 
	@echo Borrando bibliotecas...

	@echo ...Borradas
	@echo 

clean-bins : 
	@echo Borrando ejecutables...

	@echo ...Borrados
	@echo 	

mr.proper:  clean clean-bins

 
