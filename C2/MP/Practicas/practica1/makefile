bin/intervalo : obj/intervalo.o obj/main.o
	g++ -o bin/intervalo obj/main.o obj/intervalo.o

obj/intervalo.o : src/intervalo.cpp include/intervalo.h
	g++ -c src/intervalo.cpp -o obj/intervalo.o -Iinclude/

obj/main.o : src/main.cpp include/intervalo.h
	g++ -c src/main.cpp -o obj/main.o -Iinclude/

clean:
	rm -rf doc/html doc/latex obj/* bin/*

doxy:
	doxygen doc/intervalo.doxy
	firefox doc/html/index.html

zip: clean
	zip -r zip/practica2.zip *
