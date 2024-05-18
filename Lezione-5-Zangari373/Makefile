LIBS:=`root-config --libs`
INCS:=`root-config --cflags`
myLIBS:=  posizione.o particella.o elettrone.o campovettoriale.o puntomateriale.o
myDEPS:=  Posizione.h Particella.h Elettrone.h CampoVettoriale.h PuntoMateriale.h

esercizio5.0: Esercizio5.0.cpp ${myLIBS}
	g++ $^ -o $@

esercizio5.1: Esercizio5.1.cpp ${myLIBS}
	g++ $^ -o $@

esercizio5.2: Esercizio5.2.cpp ${myLIBS}
	g++ $^ -o $@

esercizio5.3: Esercizio5.3.cpp ${myLIBS}
	g++ $^ -o $@ ${INCS} ${LIBS} 

esercizio5.4: Esercizio5.4.cpp ${myLIBS}
	g++ $^ -o $@ ${INCS} ${LIBS} 

eserciziop: esercizio_prof.cpp ${myLIBS}
	g++ $^ -o $@ ${INCS} ${LIBS} 

posizione.o : Posizione.cpp Posizione.h ${myDEPS}
	g++ -c $< -o $@

particella.o : Particella.cpp Particella.h ${myDEPS}
	g++ -c $< -o $@

elettrone.o : Elettrone.cpp Elettrone.h ${myDEPS}
	g++ -c $< -o $@

campovettoriale.o : CampoVettoriale.cpp CampoVettoriale.h ${myDEPS}
	g++ -c $< -o $@

puntomateriale.o : PuntoMateriale.cpp PuntoMateriale.h ${myDEPS}
	g++ -c $< -o $@