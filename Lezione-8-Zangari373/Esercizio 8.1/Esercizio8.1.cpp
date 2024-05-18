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
	    cout << "Usage: "<< argv[0] << " nstep"<< endl;
	    return -1;
	}

	double a = 0.;
	double b = M_PI;

	int nstep = atoi(argv[1]);

	Seno* mysin = new Seno();
	Integral* integrator = new Integral(a,b,mysin);

	cout << fixed << setprecision(12) << "Valore dell'integrale: " << integrator->Simpson(nstep) <<endl << endl;
	
	cout << "Errors table " << endl;
	cout << "Nstep \t\t" << "Error" << endl;

	for(int i = 1; i< 8; i++){
		cout << setprecision(0) << setw(15) << left << pow(10,i) <<  setprecision(12) << abs(2 - integrator->Simpson(pow(10,i)) ) << endl;
	}

	double alfa;
	alfa= log( abs((2 -  integrator->Simpson(10))) / abs(2 - integrator->Simpson(1000)) ) / log(  ((b - a) / 10) / ((b - a) / 1000 ) );
	cout << setprecision(3) <<"Ordine di convergenza del metodo di Simpson: " << alfa << endl;

	
	TCanvas mycanvas ("Simpson-Midpoint error","Plot");

	TGraph g,m;

	for(int j = 1; j < 20 ; j++ ){
		g.SetPoint(j-1, (b -a) / pow(2,j) , abs(2-integrator->Simpson(pow(2,j)) ));
		m.SetPoint(j-1, (b -a) / pow(2,j) , abs(2-integrator->Midpoint(pow(2,j)) ));
	}

	g.Draw("ALP");
	g.SetTitle("Simpson-Midpoint error");
	g.GetXaxis()->SetTitle("Step size h");
	g.GetYaxis()->SetTitle("error");
	g.SetMarkerStyle(45);
	g.SetMarkerSize(1);
	g.SetMarkerColor(kOrange);
	gPad->SetLogx();
	gPad->SetLogy();

	m.Draw("samePL");
	m.SetMarkerStyle(45);
	m.SetMarkerSize(1);
	m.SetMarkerColor(kAzure);
	
	
	TLegend* leg = new TLegend(0.2, 0.80, 0.3, 0.85);
	leg->AddEntry(&g,"Simpson error","p");
	leg->AddEntry(&m,"Midpoint error","p");
 	leg->Draw("same");

	app.Run();
	
	return 0;
}
