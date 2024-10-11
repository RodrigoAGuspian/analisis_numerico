all: main.o caso.o gauss.o
	g++ -o main main.o caso.o gauss.o

main.o: main.cpp caso.h 
	g++ -c -o main.o main.cpp

caso.o: caso.cpp caso.h regresion.h regresion_cuadratica.h
	g++ -c -o caso.o caso.cpp

gauss.o: gauss.cpp gauss.h 
	g++ -c -o gauss.o gauss.cpp
# Borra los archivos ejecutables y objetos
clean:
	rm -rf *.o main html latex

doc:
	doxygen