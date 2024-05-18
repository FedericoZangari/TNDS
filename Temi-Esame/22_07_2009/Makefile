LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

myLIBS:= equazionidifferenziali.o
myDEPS:= VectorOperations.h EquazioniDifferenziali.h

compito: compito.cxx  ${myLIBS}
	g++ $^ -o $@ ${INCS} ${LIBS} 




equazionidifferenziali.o : EquazioniDifferenziali.cpp EquazioniDifferenziali.h ${myDEPS}
	g++ -c $< -o $@

clean:
	rm compito 