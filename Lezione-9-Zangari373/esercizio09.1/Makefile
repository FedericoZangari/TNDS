myLIBS:=equazionidifferenziali.o
myDEPS:=VectorOperations.h EquazioniDifferenziali.h
RFLAGS:=`root-config --cflags` `root-config --libs`

esercizio9.1: esercizio09.1.cpp ${myLIBS}
	g++ $^ -o $@ ${RFLAGS} 

equazionidifferenziali.o : EquazioniDifferenziali.cpp EquazioniDifferenziali.h ${myDEPS}
	g++ -c $< -o $@