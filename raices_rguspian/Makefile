all: main.o caso.o
	g++ -o main main.o caso.o

main.o: main.cpp caso.h
	g++ -c -o main.o main.cpp

caso.o: caso.cpp caso.h biseccion.h tvi.h expression.h falsa.h newtonRapshon.h secante.h
	g++ -c -o caso.o caso.cpp


# Borra los archivos ejecutables y objetos
clean:
	rm -rf *.o main html latex

doc:
	doxygen