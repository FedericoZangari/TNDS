myLIBS:=  particella.o elettrone.o 
myDEPS:=  Particella.h Elettrone.h 

esercizio7.0: Esercizio7.0.cpp ${myLIBS}
	g++ $^ -o $@

particella.o : Particella.cpp Particella.h ${myDEPS}
	g++ -c $< -o $@

elettrone.o : Elettrone.cpp Elettrone.h ${myDEPS}
	g++ -c $< -o $@