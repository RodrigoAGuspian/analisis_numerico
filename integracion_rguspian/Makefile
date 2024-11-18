all: main.o caso.o 
	g++ -o main main.o caso.o

main.o: main.cpp caso.h 
	g++ -c -o main.o main.cpp

caso.o: caso.cpp caso.h trapecio.h simpson13.h simpson38.h simpson.h romberg.h
	g++ -c -o caso.o caso.cpp



# Borra los archivos ejecutables y objetos
clean:
	rm -rf *.o main html latex

doc:
	doxygen