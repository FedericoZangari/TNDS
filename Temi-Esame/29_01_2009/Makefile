LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

myLIBS:=RandomGen.o integral.o 
myDEPS:=RandomGen.h Integral.h Funzioni.h 

compito: compito.cxx  ${myLIBS}
	g++ $^ -o $@ ${INCS} ${LIBS} 


integral.o : Integral.cxx Integral.h ${myDEPS}
	g++ -c $< -o $@

RandomGen.o : RandomGen.cxx RandomGen.h ${myDEPS}
	g++ -c $< -o $@



clean:
	rm compito integral.o