#include <iostream>
#include <cstdlib>
#include <iomanip>

#include "Particella.h"
#include "Elettrone.h"

using namespace std;

int main () {

	Particella *a = new Particella(1., 1.60E-19);
	Elettrone *e =new Elettrone();
	Particella *b = new Elettrone();
	 
	a->Print();	
	e->Print(); 
	b->Print();

	//Elettrone *f = new Particella;  non si può
	

	return 0;
}