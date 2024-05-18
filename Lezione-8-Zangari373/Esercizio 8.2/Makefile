LIBS:=`root-config --libs`
INCS:=`root-config --cflags`
myDEPS:= Integral.h Funzioni.h
myLIBS:= integral.o 

esercizio8.2: Esercizio8.2.cpp  ${myLIBS}
	g++ $^ -o $@ ${INCS} ${LIBS} 


integral.o : Integral.cpp Integral.h ${myDEPS}
	g++ -c $< -o $@

clean:
	rm esercizio8.2 integral.o