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

  
  double omega0 = 10.0;
  double omega = 5.0;       
  double a = 1/30.;
  RungeKutta rk;
  OscillatoreArmonicoForzato *oaf = new OscillatoreArmonicoForzato{omega0, omega, a};
  double h = 1.E-2;         
  vector<double> pos{0.0, 0.0};
  double t=0;
  double lastt = 1. / a;    
  int N =int(lastt/h + 0.5);

  TCanvas canvas1 ("OAF","Plot");
  TGraph r;

  for (int n= 0; n < N; n++) {
    r.SetPoint(n, t , pos[0] );
    pos = rk.Passo(t, pos, h, oaf);
    t+= h;
  }

  r.Draw("APC");
  string title = "Oscillatore armonico forzato #omega = "+ to_string(static_cast<int>(omega)) +"rad/s (x_{0},v_{0})=(0,0)";
	r.SetTitle(title.c_str());
	r.GetXaxis()->SetTitle("t [s]");
	r.GetYaxis()->SetTitle("x [m]");
  r.SetMarkerStyle(43);
	r.SetMarkerSize(0.5);
	r.SetMarkerColor(kGreen+3);
	
	TLegend* leg = new TLegend(0.2, 0.85, 0.3, 0.90);
  leg->AddEntry(&r,"oscillatore forzato","p");
 	leg->Draw("same");

 

  TCanvas canvas2 ("Curva di risonanza","Plot2");

  TGraph g;
  omega = 0.9*omega0;
  
    
  for (int j = 0; j< 40; j++){
    omega += 0.05;
    pos = {0.0, 0.0};
    t = 0;  
    oaf->SetOmega(omega);

    for(;;){
      pos = rk.Passo(t, pos, h, oaf);
      t+= h;

      if(t > 10. / a  &&  pos[1] > 0){

        while ( pos[1] > 0) {
          pos = rk.Passo(t, pos, h, oaf);
          t += h;
        }

        g.SetPoint(j, omega, pos[0]);
        break;
      }

    }
    
  }

  g.Draw("APC");  
  g.SetTitle("Curva di risonanza");
	g.GetXaxis()->SetTitle("#omega [rad/s]");
	g.GetYaxis()->SetTitle("Ampiezza A [m]");
	g.SetMarkerStyle(45);
	g.SetMarkerSize(1.5);
	g.SetMarkerColor(kOrange);
  	
	TLegend* leg2 = new TLegend(0.2, 0.85, 0.3, 0.90);
	leg2->AddEntry(&g,"Ampiezza","pl");
 	leg2->Draw("same");

	app.Run();

	return 0;
}
