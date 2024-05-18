myDEPS:= Bisezione.h FunzioneBase.h Solutore.h
myLIBS:= parabola.o bisezione.o

esercizio7.2: Esercizio7.2.cpp ${myLIBS}
	g++ $^ -o $@

parabola.o : Parabola.cpp FunzioneBase.h ${myDEPS}
	g++ -c $< -o $@

bisezione.o : Bisezione.cpp Bisezione.h ${myDEPS}
	g++ -c $< -o $@