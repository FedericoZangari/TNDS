myLIBS:=RandomGen.o
myDEPS:=RandomGen.h
RFLAGS:=`root-config --cflags` `root-config --libs`

esercizio10.1: esercizio10.1.cpp ${myLIBS}
	g++ $^ -o $@ ${RFLAGS} 


RandomGen.o : RandomGen.cpp RandomGen.h ${myDEPS}
	g++ -c $< -o $@