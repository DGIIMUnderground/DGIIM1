BIN=./bin
OBJ=./obj
SRC=./src
INC=./include
LIB=./lib
ZIP=./zip
DOC=./doc

OPT=-Wall -g
PRJ=practica2

$(BIN)/intervalo: $(OBJ)/main.o $(OBJ)/intervalo.o 
	g++ -o $(BIN)/intervalo $(OPT) $(OBJ)/main.o $(OBJ)/intervalo.o

$(OBJ)/main.o: $(SRC)/main.cpp $(INC)/intervalo.h  
	g++ -c $(OPT) $(SRC)/main.cpp -o $(OBJ)/main.o -I$(INC)
	
$(OBJ)/intervalo.o: $(SRC)/intervalo.cpp $(INC)/intervalo.h
	g++ -c $(OPT) $(SRC)/intervalo.cpp -o $(OBJ)/intervalo.o -I$(INC)

clean:
	rm -rf $(BIN)/* $(OBJ)/* $(DOC)/html $(DOC)/latex $(ZIP)/* $(LIB)/*

doxy: 
	doxygen $(DOC)/intervalo.doxy
	firefox $(DOC)/html/index.html

zip: clean
	zip -r $(ZIP)/practica2.zip *


