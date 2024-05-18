LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

myLIBS:=RandomGen.o integral.o equazionidifferenziali.o
myDEPS:=RandomGen.h Integral.h Funzioni.h VectorOperations.h EquazioniDifferenziali.h


orale: orale.cpp  ${myLIBS}
	g++ $^ -o $@ ${INCS} ${LIBS} 
	
compito: compito.cxx  ${myLIBS}
	g++ $^ -o $@ ${INCS} ${LIBS} 




integral.o : Integral.cxx Integral.h ${myDEPS}
	g++ -c $< -o $@

RandomGen.o : RandomGen.cxx RandomGen.h ${myDEPS}
	g++ -c $< -o $@

equazionidifferenziali.o : EquazioniDifferenziali.cpp EquazioniDifferenziali.h ${myDEPS}
	g++ -c $< -o $@

clean:
	rm compito integral.o