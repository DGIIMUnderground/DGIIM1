#Makefile rápidillo
all:
	g++ -o bin/positividad src/main.cpp src/celdas.cpp -I./include
clean:
	@sudo rm -rf obj/* bin/*  src/*~ data/*~ include/*~ *~
test:
	valgrind --leak-check=full ./bin/positividad
exe:
	./bin/positividad

