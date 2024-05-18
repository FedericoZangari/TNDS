compila: main.o funzioni.o
	g++ main.o funzioni.o -o main

main.o: main.cpp funzioni.h
	g++ -c main.cpp -o main.o
	
funzioni.o : funzioni.cpp funzioni.h
	g++ -c funzioni.cpp -o funzioni.o

esegui: main data.dat
	./main 100 data.dat