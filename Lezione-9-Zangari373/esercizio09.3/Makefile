myLIBS:=equazionidifferenziali.o
myDEPS:=VectorOperations.h EquazioniDifferenziali.h
RFLAGS:=`root-config --cflags` `root-config --libs`

esercizio9.3: esercizio09.3.cpp ${myLIBS}
	g++ $^ -o $@ ${RFLAGS} 


equazionidifferenziali.o : EquazioniDifferenziali.cpp EquazioniDifferenziali.h ${myDEPS}
	g++ -c $< -o $@