#include <iostream>
#include <cstdlib>
#include <iomanip>

#include "CampoVettoriale.h"


using namespace std;

int main () {
	Posizione P(1, 1, 1);
	CampoVettoriale *a = new CampoVettoriale();
	CampoVettoriale *b = new CampoVettoriale(P);
	CampoVettoriale *c = new CampoVettoriale(P, 1, 2, 3);
	CampoVettoriale *d = new CampoVettoriale(5, 5, 5, 1, 2, 3);

	//cout << b->GetFx() << " " << b->GetFy() << " " << b->GetFz() << endl;

	return 0;
}