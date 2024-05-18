myLIBS:=RandomGen.o EsperimentoPrisma.o
myDEPS:=RandomGen.h EsperimentoPrisma.h Funzioni.h
RFLAGS:=`root-config --cflags` `root-config --libs`

esercizio11: main.cpp ${myLIBS}
	g++ $^ -o $@ ${RFLAGS} 




RandomGen.o : RandomGen.cpp RandomGen.h ${myDEPS}
	g++ -c $< -o $@

EsperimentoPrisma.o : EsperimentoPrisma.cpp EsperimentoPrisma.h ${myDEPS}
	g++ -c $< -o $@