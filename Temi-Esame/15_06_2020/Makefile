LIBS:=`root-config --libs`
INCS:=`root-config --cflags`
myLIBS:=RandomGen.o integral.o
myDEPS:=RandomGen.h Integral.h Funzioni.h

compito: compito.cxx  ${myLIBS}
	g++ $^ -o $@ ${INCS} ${LIBS} 


integral.o : Integral.cpp Integral.h ${myDEPS}
	g++ -c $< -o $@

RandomGen.o : RandomGen.cpp RandomGen.h ${myDEPS}
	g++ -c $< -o $@

clean:
	rm compito integral.o