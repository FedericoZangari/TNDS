#include <iostream>
#include <cstdlib>
#include <iomanip>

#include "FunzioneBase.h"
#include "Parabola.h"

using namespace std;

int main () {

	Parabola *p = new Parabola(1,1,0);
	cout << p->Vertice() << endl;
	cout << p->Eval(2) << endl;;
	return 0;
}