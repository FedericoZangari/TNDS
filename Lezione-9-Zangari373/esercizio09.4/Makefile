myLIBS:=equazionidifferenziali.o
myDEPS:=VectorOperations.h EquazioniDifferenziali.h
RFLAGS:=`root-config --cflags` `root-config --libs`

esercizio9.4: esercizio09.4.cpp ${myLIBS}
	g++ -Wall -o $@ $^ ${RFLAGS} 


equazionidifferenziali.o : EquazioniDifferenziali.cpp EquazioniDifferenziali.h ${myDEPS}
	g++ -Wall -c $< -o $@