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
/*
  PuntoMateriale Sole(0, 0, 0, 0, 1.98844E30);
  Posizione t (147098074E3, 0, 0);
  PuntoMateriale Terra(t, 0, 5.972E24);

  vector<double> x ={t.getX(),0};
  vector<double> y ={t.getY(),0};
  vector<double> z ={t.getZ(),0};

  CampoVettoriale g = Sole.CampoGravitazionale(t);
  RungeKutta rk;
  vector<double> pos ={t.getX(), t.getY(), t.getZ(), 0, 0, 0};*/

  if (argc != 2) {
	    cout << "Usage: ./esercizio9.5 stepsize"<< endl; 
	    return -1;
	}
  
  
  double m = 5.972E24;
  double M = 1.98844E30;
  double perielio = 147098074E3;
  double L = m*30.287E3*perielio;
  RungeKutta rk;
  Gravitazione *g = new Gravitazione{ M, m , L};
  double h = atof(argv[1]);
  
  vector<double> pos{147098074E3, 0, 0, L/m/pow(perielio,2)};
  double t=0;
  double lastt = 2*31536000 ;
  int N =int(lastt/h + 0.5);


  TCanvas mycanvas ("Moto radiale","Plot");
  TGraph r, xy;

  for (int n= 0; n < N; n++) {
    r.SetPoint(n, t , pos[0] );
    xy.SetPoint(n, pos[0]*cos(pos[2]) , pos[0]*sin(pos[2]) );
    pos = rk.Passo(t, pos, h, g);
    t+= h;
  }

  r.Draw("APC");
  string title = "Moto radiale";
	r.SetTitle(title.c_str());
	r.GetXaxis()->SetTitle("t [s]");
	r.GetYaxis()->SetTitle("r [m]");
  r.SetMarkerStyle(43);
	r.SetMarkerSize(0.5);
	r.SetMarkerColor(kGreen+3);
  TF1 * function = new TF1 ("fit", "pol7",0,31536000);
	//r.Fit(function);
  //function->Draw("Csame");
	//double em = function->GetParameter(0);
	
	TLegend* leg = new TLegend(0.2, 0.85, 0.3, 0.90);
  leg->AddEntry(&r,"raggio orbita","p");
  //leg->AddEntry(function,"fit polinomiale","p");
 	leg->Draw("same");

  TCanvas can2("orbita", "orbita");
  xy.Draw("APC");
  string title2 = "Orbita";
	xy.SetTitle(title2.c_str());
	xy.GetXaxis()->SetTitle("x [m]");
	xy.GetYaxis()->SetTitle("y [m]");
  xy.SetMarkerStyle(43);
	xy.SetMarkerSize(0.5);
	xy.SetMarkerColor(kTeal);


  

	app.Run();

	return 0;
}
