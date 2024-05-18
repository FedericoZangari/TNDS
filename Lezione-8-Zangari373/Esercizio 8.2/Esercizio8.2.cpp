#include <iostream>
#include <cmath>
#include <iomanip>
#include <math.h>

#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TLegend.h"

#include "Funzioni.h"
#include "Integral.h"

using namespace std;

int main(int argc, const char ** argv){
	
	TApplication app("app",0,0);

	if (argc != 2) {
	    cout << "Usage: "<< argv[0] << " precision"<< endl;
	    return -1;
	}


	double a = 0.;
	double b = M_PI;

	double eps = atof(argv[1]);
	int cifre = ceil(-log10(eps));
	
	double eps_min = __DBL_EPSILON__;
	//cout << eps_min << endl;
	if(eps < eps_min){
		cout << "warning: precision required is below the minimum" << endl;
		eps = eps_min;
	}

	Seno* mysin = new Seno();
	Integral* integrator = new Integral(a,b,mysin);
	
	cout << fixed << setprecision( cifre ) << "valore dell'integrale: " << integrator->Trapezi_eps(eps) <<endl << endl;
	
	//cout << fixed  << "valore dell'integrale: " << integrator->Trapezi_N(integrator->GetN_step_trap()) <<endl << endl;
	
	
	return 0;
}
