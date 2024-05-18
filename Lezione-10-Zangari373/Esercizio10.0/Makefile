myLIBS:=RandomGen.o
myDEPS:=RandomGen.h
RFLAGS:=`root-config --cflags` `root-config --libs`

esercizio10.0: esercizio10.0.cpp ${myLIBS}
	g++ $^ -o $@ ${RFLAGS} 


RandomGen.o : RandomGen.cpp RandomGen.h ${myDEPS}
	g++ -c $< -o $@