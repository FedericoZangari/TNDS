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
	
	TApplication app("app",0,0);

	if (argc != 2) {
	    cout << "Usage: "<< argv[0] << " nstep"<< endl;
	    return -1;
	}
    stringstream sout;

	double E_0 = 1E4;
  	RungeKutta rk;
  	OscillatoreElettrone *oe = new OscillatoreElettrone{-1.6E-19, 9.1E-31, E_0, 0.1, 1E9};
  	const double lastt{1E-7};
  	double h = atof(argv[1]);
	double v_0 = 1E8;
	double v_1 = 1.1E8;
  	vector<double> pos{0.0, v_0};
	vector<double> pos2{0.0, v_1};
	
  	
  	double t=0;
  	int N =int(lastt/h + 0.5);

  	TCanvas mycanvas ("RK","Plot");

	TGraph g;
	TGraph f;
  	

  	for (int n= 0; n < N; n++) {
    	g.SetPoint(n, t , pos[1]);
    	pos = rk.Passo(t, pos, h, oe);

		f.SetPoint(n, t , pos2[1]);
    	pos2 = rk.Passo(t, pos2, h, oe);

    	t+= h;
  	}  	

  	string title = "Moto elettrone, h = " + to_string(h);
	f.SetTitle(title.c_str());
	f.GetXaxis()->SetTitle("t [s]");
	f.GetYaxis()->SetTitle("v [m/s]");
	g.SetMarkerStyle(43);
	g.SetMarkerSize(0.5);
	g.SetMarkerColor(kTeal);
	f.SetMarkerStyle(45);
	f.SetMarkerSize(0.5);
	f.SetMarkerColor(kAzure);
	f.Draw("AP");
	g.Draw("P");
  
	
	TLegend* leg = new TLegend(0.2, 0.80, 0.3, 0.90);
	leg->AddEntry(&g,"v_{0} = 10^8 m/s","p");
	string name = "  v_{0} = "+ to_string(static_cast<int>( v_1)) +"m/s";
  	leg->AddEntry(&f,name.c_str() ,"p");
 	leg->Draw("same");

	

	TCanvas canvas2 ("Euler errors","Plot2");

  
  	TGraph er;
 	h = 1E-11;
    
  	for (double j = 0; j< 10; j++){
   		pos = {0.0, v_1};
    
    	h = 1E-11 + j*1E-11;
    	N =int(lastt/h + 0.5);
    	t = 0;
	
    	for(;;){
    		pos = rk.Passo(t, pos, h, oe);
      		t+= h;

      		if(t > 0.6 * lastt  &&  pos[1] > 0){
				double tmp = 0;

        		while ( pos[1] > tmp) {
					tmp = pos[1];
          			pos = rk.Passo(t, pos, h, oe);
          			t += h;
        		}
				cout << tmp << endl;
        		er.SetPoint(j, h, abs(tmp-1E8 - 0.1E8 ) );
        		break;
      		}

    	}
  	}

  	er.Draw("APL");  
  	er.SetTitle("Errors");
	er.GetXaxis()->SetTitle("Passo h [s]");
	er.GetYaxis()->SetTitle("Errore a t=10^{-7}s  [m/s]");
	er.SetMarkerStyle(45);
	er.SetMarkerSize(1.5);
	er.SetMarkerColor(kOrange);
/*
 
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
 	leg3->Draw("same");*/

	print_and_clear_buffer(sout);
	app.Run();
	
	return 0;
}
