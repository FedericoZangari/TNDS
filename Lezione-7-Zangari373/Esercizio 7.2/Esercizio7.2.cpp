#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <math.h>

#include "FunzioneBase.h"
#include "Parabola.cpp"
#include "Bisezione.h"

using namespace std;

int main (int argc, char** argv) {
	if ( argc != 4 ) {
  		cout << "Uso del programma : " << argv[0] << " <xmin> <xmax> <precision> " << endl;
    	return -1 ;
	}
	double a = atof(argv[1]);
	double b = atof(argv[2]);
	double eps = atof(argv[3]);
	int cifre = -log10(eps);

	double eps_min = __DBL_EPSILON__;
	if(eps < eps_min){
		cout << "warning: precision required is below the minimum" << endl;
		eps = eps_min;
	}

	const Parabola *p = new Parabola(3,5,-2);
	
	Bisezione *bis = new Bisezione();
	bis->SetPrecision(eps);

	cout << fixed;
	cout << setprecision(cifre) << "Root found in that interval: " << bis->CercaZeri(a, b, p) << endl;
	return 0;
}