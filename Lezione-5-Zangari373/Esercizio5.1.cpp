#include <iostream>
#include <cstdlib>
#include <iomanip>

#include "Particella.h"
#include "Elettrone.h"

using namespace std;

int main () {

	Particella *p = new Particella(1., 1.60E-19);
	Elettrone *e =new Elettrone();

	cout << "Particella: " << p->GetMassa() << " " << p ->GetCarica() << endl;
	p->Print();

	cout << "Elettrone: " << e->GetMassa() << " " << e ->GetCarica() << endl;
	e->Print();

	Particella b(*p);
	Particella d(*e);
	d.Print();
	//Elettrone f(d);
	

	return 0;
}