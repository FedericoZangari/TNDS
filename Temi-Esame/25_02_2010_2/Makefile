LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

myLIBS:=RandomGen.o  Esperimento.o
myDEPS:=RandomGen.h  Esperimento.h Funzioni.h

compito: compito.cxx  ${myLIBS}
	g++ $^ -o $@ ${INCS} ${LIBS} 



RandomGen.o : RandomGen.cxx RandomGen.h ${myDEPS}
	g++ -c $< -o $@


Esperimento.o : Esperimento.cpp Esperimento.h ${myDEPS}
	g++ -c $< -o $@

clean:
	rm compito 