all: main.o caso.o encontrar.o comparar.o
	g++ -o main main.o caso.o encontrar.o comparar.o

main.o: main.cpp caso.h 
	g++ -c -o main.o main.cpp

caso.o: caso.cpp caso.h encontrar.h
	g++ -c -o caso.o caso.cpp

encontrar.o: encontrar.cpp encontrar.h comparar.h biseccion.h tvi.h expression.h encontrar.h falsa.h newtonRaphson.h newtonRaphsonG.h secante.h  muller.h
	g++ -c -o encontrar.o encontrar.cpp

comparar.o: comparar.cpp comparar.h encontrar.h
	g++ -c -o comparar.o comparar.cpp


# Borra los archivos ejecutables y objetos
clean:
	rm -rf *.o main html latex

doc:
	doxygen