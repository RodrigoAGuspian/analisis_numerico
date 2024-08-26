all: main.o caso.o encontrar.o
	g++ -o main main.o caso.o encontrar.o

main.o: main.cpp caso.h 
	g++ -c -o main.o main.cpp

caso.o: caso.cpp caso.h encontrar.h
	g++ -c -o caso.o caso.cpp

encontrar.o: encontrar.cpp encontrar.h biseccion.h tvi.h expression.h encontrar.h falsa.h newtonRapshon.h secante.h 
	g++ -c -o encontrar.o encontrar.cpp

# Borra los archivos ejecutables y objetos
clean:
	rm -rf *.o main html latex

doc:
	doxygen