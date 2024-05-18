myLIBS:=RandomGen.o integral.o
myDEPS:=RandomGen.h Integral.h Funzioni.h
RFLAGS:=`root-config --cflags` `root-config --libs`

esercizio10.2: esercizio10.2.cpp ${myLIBS}
	g++ $^ -o $@ ${RFLAGS} 

esercizio10.2.2: esercizio10.2.2.cpp ${myLIBS}
	g++ $^ -o $@ ${RFLAGS} 

RandomGen.o : RandomGen.cpp RandomGen.h ${myDEPS}
	g++ -c $< -o $@

integral.o : Integral.cpp Integral.h ${myDEPS}
	g++ -c $< -o $@