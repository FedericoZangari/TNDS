myDEPS:= Bisezione.h FunzioneBase.h Solutore.h
myLIBS:= funzione.o bisezione.o

esercizio7.3: Esercizio7.3.cpp ${myLIBS}
	g++ $^ -o $@

funzione.o : Funzione.cpp FunzioneBase.h ${myDEPS}
	g++ -c $< -o $@

bisezione.o : Bisezione.cpp Bisezione.h ${myDEPS}
	g++ -c $< -o $@