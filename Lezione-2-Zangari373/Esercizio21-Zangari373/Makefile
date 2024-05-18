esercizio2: main.o vettore.o funzioni.o
	g++ main.o vettore.o funzioni.o -o esercizio2 -fno-elide-constructors

main.o: main.cpp Vettore.h funzioni.h
	g++ -c main.cpp -o main.o

vettore.o : Vettore.cxx Vettore.h
	g++ -c Vettore.cxx -o vettore.o
	
funzioni.o : funzioni.cxx funzioni.h Vettore.h
	g++ -c funzioni.cxx -o funzioni.o

