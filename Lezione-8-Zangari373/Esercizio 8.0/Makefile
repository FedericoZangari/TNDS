LIBS:=`root-config --libs`
INCS:=`root-config --cflags`
myDEPS:= Integral.h Funzioni.h
myLIBS:= integral.o 

esercizio8.0: Esercizio8.0.cpp  ${myLIBS}
	g++ $^ -o $@ ${INCS} ${LIBS} 


integral.o : Integral.cpp Integral.h ${myDEPS}
	g++ -c $< -o $@

clean:
	rm esercizio8.0 integral.o