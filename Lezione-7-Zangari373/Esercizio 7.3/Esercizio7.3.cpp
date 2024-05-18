#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <math.h>

#include "FunzioneBase.h"
#include "Funzione.cpp"
#include "Bisezione.h"
     
using namespace std;

int main () {
	
	double eps = 1E-6;
	int cifre = -log10(eps);
	double eps_min = __DBL_EPSILON__;
	if(eps < eps_min){
		cout << "warning: precision required is below the minimum" << endl;
		eps = eps_min;
	}
	
	const Funzione *f = new Funzione();
	Bisezione *bis = new Bisezione();
	bis->SetPrecision(eps);

 
	cout << fixed << setprecision(cifre);
	for(int i = 1; i <= 20; i++){
		cout << "root #" << i << " : \t" << bis->CercaZeri(i*M_PI, i*M_PI + M_PI/2, f) << endl;
	}
	
	
	return 0;

}