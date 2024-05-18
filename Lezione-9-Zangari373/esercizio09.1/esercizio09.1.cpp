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
  

  if (argc != 2) {
	    cout << "Usage: ./esercizio9.1 stepsize"<< endl;
	    return -1;
	}
  TApplication app("app",0,0);

  //test_euler();

  Eulero eulero;
  OscillatoreArmonico oa{1.0};
  const double lastt{70.0};
  const double h = atof(argv[1]);
  vector<double> pos{0.0, 1.0};


  TCanvas mycanvas ("Euler","Plot");

	TGraph g;
  //TGraph e;

  for (double t{}; t <= lastt; t += h) {
    g.SetPoint(t/h, t , pos[0]);
    pos = eulero.Passo(t, pos, h, &oa);
    
    //e.SetPoint(t/h, t , abs(pos[0] - sin(t)) );
    //cout << t << endl;
  }
  //cout << setprecision(12) << "x(70): " << pos[0] << endl;
  //cout << "v(70): " << pos[1] << endl;

  TF1 *s = new TF1("sinx", "sin(x)", 0, 70);
  g.Draw("AP");
  //e.Draw("same");
  s->Draw("same");
	g.SetTitle("Euler");
	g.GetXaxis()->SetTitle("t [s]");
	g.GetYaxis()->SetTitle("x [m]");
	g.SetMarkerStyle(45);
	g.SetMarkerSize(0.5);
	g.SetMarkerColor(kOrange);
  s->SetLineColor(kRed);
	
	TLegend* leg = new TLegend(0.2, 0.80, 0.3, 0.90);
	leg->AddEntry(&g,"position","p");
  leg->AddEntry(s,"sin t","l");
  //leg->AddEntry(&e,"error","p");
 	leg->Draw("same");

	app.Run();
	
	return 0;
}
