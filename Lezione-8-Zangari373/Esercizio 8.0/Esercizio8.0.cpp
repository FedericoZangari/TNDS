#include <iostream>
#include <cmath>
#include <iomanip>
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
	    cout << "Usage: ./main nstep"<< endl;
	    return -1;
	}

	double a = 0.;
	double b = M_PI;

	int nstep = atoi(argv[1]);

	Seno* mysin = new Seno();
	Integral* integrator = new Integral(a,b,mysin);

	cout << fixed << setprecision(12) << "valore dell'integrale: " << integrator->Midpoint(nstep) <<endl << endl;
	
	cout << "Errors table " << endl;
	cout << "nstep \t\t" << "error" << endl;

	for(int i = 10; i< 10000000; i*=10){
		cout << setprecision(0) << i << "\t\t" << setprecision(12) << 2 - integrator->Midpoint(i) << endl;
	}

	double alfa;
	alfa= log((2 -  integrator->Midpoint(10))/(2 - integrator->Midpoint(10000))) / log(  ((b - a) / 10) / ((b - a) / 10000 ) );
	cout << setprecision(3) <<"ordine di convergenza: " << alfa << endl;
	
	TCanvas mycanvas ("Midpoint error","Plot");

	TGraph g;

	for(int j = 10; j < 1000 ; j++ ){
		g.SetPoint(j,(b -a) / (j) , abs(2-integrator->Midpoint(j) ));
	}

	g.Draw("AP");
	g.SetTitle("Midpoint error");
	g.GetXaxis()->SetTitle("h");
	g.GetYaxis()->SetTitle("error");
	g.SetMarkerStyle(45);
	g.SetMarkerSize(1);
	g.SetMarkerColor(kCyan);
	
	TLegend* leg = new TLegend(0.2, 0.80, 0.3, 0.85);
	leg->AddEntry(&g,"error","p");
 	leg->Draw("same");

	app.Run();

	return 0;
}
