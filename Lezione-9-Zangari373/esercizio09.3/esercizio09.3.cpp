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

#include "EquazioniDifferenziali.h"

using namespace std;

int main(int argc, const char *argv[]) {
  TApplication app("app",0,0);

  if (argc != 2) {
	    cout << "Usage: ./esercizio9.3 stepsize"<< endl; 
	    return -1;
	}
  
  double l = 1.0;
  RungeKutta rk;
  Pendolo *p = new Pendolo{l};
  double h = atof(argv[1]);
  double theta0 = 0.5;
  vector<double> pos{0.0, 0.0};
  double t=0;
  
  //prova pendolo

  double lastt = 10;
  int N =int(lastt/h + 0.5);
  pos = {theta0, 0.0};

  TCanvas mycanvas ("Pendolo","Plot");
  TGraph r;

  for (int n= 0; n < N; n++) {
    r.SetPoint(n, t , pos[0] );
    pos = rk.Passo(t, pos, h, p);
    t+= h;
  }

  r.Draw("APC");
  string title = "Traiettoria pendolo (#theta_{0} = " + to_string(theta0) +" rad, h = " + to_string(h) +" )";
	r.SetTitle(title.c_str());
	r.GetXaxis()->SetTitle("t [s]");
	r.GetYaxis()->SetTitle("#theta [rad]");
  r.SetMarkerStyle(43);
	r.SetMarkerSize(0.5);
	r.SetMarkerColor(kGreen+3);
	
	TLegend* leg = new TLegend(0.2, 0.80, 0.3, 0.90);
  leg->AddEntry(&r,"Pendolo","p");
 	leg->Draw("same");

 

  TCanvas canvas2 ("Periodo oscillazione","Plot2");

  TGraph tau;
  double A = 0;
  double v = 0;
  double T;
    
  for (int j = 0; j< 31; j++){
    A += 0.1;
    pos = {-A, 0.0};
    t = 0;
    
    while (pos[1] >= 0) {
      v = pos[1];
      pos = rk.Passo(t, pos, h, p);
      t += h;
    }
    T= t - pos[1] * h / ( pos[1] - v);
    T = 2 * T;
    tau.SetPoint(j, A, T);
  }

  tau.Draw("APC");  
  tau.SetTitle("Periodo oscillazione");
	tau.GetXaxis()->SetTitle("Ampiezza A [rad]");
	tau.GetYaxis()->SetTitle("Periodo T [s]");
	tau.SetMarkerStyle(45);
	tau.SetMarkerSize(1.5);
	tau.SetMarkerColor(kOrange);
  	
	TLegend* leg2 = new TLegend(0.2, 0.80, 0.3, 0.90);
	leg2->AddEntry(&tau,"Periodo","pl");
 	leg2->Draw("same");

	app.Run();

	return 0;
}
