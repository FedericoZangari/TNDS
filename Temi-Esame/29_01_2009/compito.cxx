#include <iostream>
#include <cmath>
#include <iomanip>
#include <math.h>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TLegend.h"

#include "Funzioni.h"
#include "Integral.h"

using namespace std;

void print_and_clear_buffer(stringstream &ss)
{
    cout << ss.str();
    ofstream outfile("soluzione.txt", ios::out);
    outfile << ss.str();
    ss.clear();
}

int main(int argc, const char ** argv){
	
	TApplication app("app",0,0);

	
    stringstream sout;

	double d = 10E-6;
	double a = -d/2.;
	double b = d/2.;
    double eps = 1E-4;
    
	

	FunInt* f = new FunInt(a, b, eps);
	
	TCanvas can("fun int","fun int");
	TGraph g;
	int i = 0;

	for(double x = -0.2; x <= 0.2 ; x+= 0.001 ){
		g.SetPoint( i, x , f->Eval(x));
		i++;
		
	}

	g.Draw("ACP");
	g.SetTitle("Figura di diffrazione");
	g.GetXaxis()->SetTitle("x [m]");
	g.GetYaxis()->SetTitle("A [m]");
	g.SetMarkerStyle(45);
	g.SetMarkerSize(1);
	g.SetMarkerColor(kOrange);
	
	
	

	
	//print_and_clear_buffer(sout);

	app.Run();
	return 0;
}
