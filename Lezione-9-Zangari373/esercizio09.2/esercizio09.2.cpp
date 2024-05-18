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
	    cout << "Usage: ./esercizio9.2 stepsize"<< endl;
	    return -1;
	}
  

  test_runge_kutta();
  //test_euler();

  Eulero eulero;
  RungeKutta rk;
  OscillatoreArmonico *oa = new OscillatoreArmonico{1.0};
  const double lastt{70.0};
  double h = atof(argv[1]);
  vector<double> pos{0.0, 1.0};
  vector<double> posR{0.0, 1.0};
  double t=0;
  int N =int(lastt/h + 0.5);

  TCanvas mycanvas ("Euler-RK","Plot");

	TGraph g;
  TGraph r;

  for (int n= 0; n < N; n++) {
    g.SetPoint(n, t , pos[0]);
    r.SetPoint(n, t , posR[0] );
    pos = eulero.Passo(t, pos, h, oa);
    posR = rk.Passo(t, posR, h, oa);
    t+= h;
  }
  //cout << setprecision(12) << posR[0] << endl;
  //cout << abs(posR[0]- sin(70)) << endl << endl;

  TF1 *s = new TF1("s", "sin(x)", 0, 70);
  g.Draw("AP");
  r.Draw("P");
  s->Draw("Csame");
  string title = "OA Euler_Runge-Kutta h = " + to_string(h);
	g.SetTitle(title.c_str());
	g.GetXaxis()->SetTitle("t [s]");
	g.GetYaxis()->SetTitle("x [m]");
	g.SetMarkerStyle(45);
	g.SetMarkerSize(0.5);
	g.SetMarkerColor(kOrange);
  r.SetMarkerStyle(43);
	r.SetMarkerSize(0.5);
	r.SetMarkerColor(kGreen+3);
  s->SetLineColor(kRed);
	
	TLegend* leg = new TLegend(0.2, 0.80, 0.3, 0.90);
	leg->AddEntry(&g,"Euler","p");
  leg->AddEntry(s,"sin t","l");
  leg->AddEntry(&r,"Runge-Kutta","p");
 	leg->Draw("same");

 
  TCanvas canvas2 ("Euler errors","Plot2");

  TGraph e_er;
  TGraph rk_er;
    
  for (double j = 0; j< 10; j++){
    pos = {0.0, 1.0};
    posR = {0.0, 1.0};
    h = 0.1 * pow(0.5, j);
    N =int(lastt/h + 0.5);
    t = 0;
    
    for (int n= 0; n < N; n++) {
      pos = eulero.Passo(t, pos, h, oa);
      posR = rk.Passo(t, posR, h, oa);
      t += h;
    }
    e_er.SetPoint(j, h , abs(pos[0] - sin(t)) );
    rk_er.SetPoint(j, h , abs(posR[0] - sin(t) ) );
  }

  e_er.Draw("APL");  
  e_er.SetTitle("Euler errors");
	e_er.GetXaxis()->SetTitle("Passo h [s]");
	e_er.GetYaxis()->SetTitle("Errore a t=70s  [m]");
	e_er.SetMarkerStyle(45);
	e_er.SetMarkerSize(1.5);
	e_er.SetMarkerColor(kOrange);
  
  gPad->SetLogx();
  gPad->SetLogy();
  	
	TLegend* leg2 = new TLegend(0.2, 0.80, 0.3, 0.90);
	leg2->AddEntry(&e_er,"Euler error","p");
 	leg2->Draw("same");


  TCanvas canvas3 ("RK errors","Plot2");
  rk_er.Draw("APL");
  rk_er.SetTitle("Runge-Kutta errors");
	rk_er.GetXaxis()->SetTitle("Passo h [s]");
	rk_er.GetYaxis()->SetTitle("Errore a t=70s  [m]");
  rk_er.SetMarkerStyle(43);
	rk_er.SetMarkerSize(1.5);
	rk_er.SetMarkerColor(kGreen+3);

  gPad->SetLogx();
  gPad->SetLogy();

  TLegend* leg3 = new TLegend(0.2, 0.80, 0.3, 0.90);
  leg3->AddEntry(&rk_er,"Runge-Kutta error","p");
 	leg3->Draw("same");
	app.Run();

	return 0;
}
