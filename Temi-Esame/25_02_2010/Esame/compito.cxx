#include <iostream>
#include <cmath>
#include <iomanip>
#include <math.h>
#include <string>
#include <sstream>
#include <fstream>
/*
#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TLegend.h"
*/
#include "Funzioni.h"
#include "Integral.h"
#include "EquazioniDifferenziali.h"

using namespace std;

void print_and_clear_buffer(stringstream &ss)
{
    cout << ss.str();
    ofstream outfile("soluzione.txt", ios::out);
    outfile << ss.str();
    ss.clear();
}

int main(int argc, const char ** argv){
	
	//TApplication app("app",0,0);
	if (argc != 2) {
	    cout << "Usage: ./compito Temperatura iniziale"<< endl;
	    return -1;
	}
	
    stringstream sout;

	
  	RungeKutta rk;
  	CalorimetroIdeale *calI = new CalorimetroIdeale(0.002, 0.01, 289.37, 323.15);
  	const double lastt{600.0};
  	double h = 0.001;
	double tc = atof(argv[1]);
  	vector<double> T{tc};
  	double t=0;
  	int N =int(lastt/h + 0.5);


  	for (int n= 0; n < N; n++) {
    	T = rk.Passo(t, T, h, calI);
    	t+= h;
  	}
	
	sout << "Temperatura dopo t=600s : " << fixed << setprecision(2) << T[0] << "K" << endl;

	CalorimetroReale *calR = new CalorimetroReale(0.002, 0.01, 0.0004, 289.37, 323.15);
	vector<double> TR{tc, 0.0};
	t = 0;
	for (int n= 0; n < N; n++) {
    	TR = rk.Passo(t, TR, h, calR);
    	t+= h;
  	}
	sout << "Temperatura dopo t=600s (calorimetro reale): " << fixed << setprecision(2) << TR[0] << "K" << endl;
/*
    b = 2;
    I = M_PI/2;
    Fun2* f2 = new Fun2();
	Integral* integ = new Integral(a,b,f2,1);

    cout << fixed << setprecision(12) << "Valore del secondo integrale con metodo Midpoint: " << integ->Midpoint(nstep) <<endl << endl;
    k2= log( abs((I -  integ->Midpoint(100))) / abs(I - integrator->Midpoint(1000)) ) / log(  ((b - a) / 100) / ((b - a) / 1000 ) );
    cout << setprecision(3) <<"Ordine di convergenza del metodo Midpoint: " << endl;
    cout << "k2:\t" << k2 << endl;


	
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

	app.Run();*/
	print_and_clear_buffer(sout);
	return 0;
}
