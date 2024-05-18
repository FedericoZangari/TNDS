myLIBS:=equazionidifferenziali.o 
myDEPS:=VectorOperations.h EquazioniDifferenziali.h 
RFLAGS:=`root-config --cflags` `root-config --libs`

esercizio9.5: esercizio09.5.cpp ${myLIBS}
	g++ $^ -o $@ ${RFLAGS} 


equazionidifferenziali.o : EquazioniDifferenziali.cpp EquazioniDifferenziali.h ${myDEPS}
	g++ -c $< -o $@


