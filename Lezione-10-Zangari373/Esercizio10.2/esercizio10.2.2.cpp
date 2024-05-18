#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h"
#include "TGraph.h"

#include <iostream>
#include <fstream>
#include <math.h>

#include "RandomGen.h"
#include "Funzioni.h"
#include "Integral.h"

using namespace std;

int main() {
  TApplication app("app",0,0);

  Seno *sin = new Seno();
  Integral *I = new Integral(0, M_PI, sin, 1);
  vector<int> N{100, 500, 1000, 5000, 10000};
  string filename, histonameAVE, histonameHoM;
  double tmp;
  vector<TH1F> hvectorAVE, hvectorHoM ;
  vector<double> errorsAVE, errorsHoM;

  for(auto i=0; i<N.size(); i++){

    filename = "integral" +to_string(N[i])+ ".dat";
    histonameAVE = "MC-Average integral  N = "+to_string(N[i]);
    histonameHoM = "MC-Hit or Miss integral  N = "+to_string(N[i]);
    ifstream f (filename.c_str());
    
    TH1F ave(histonameAVE.c_str(),histonameAVE.c_str(),100,1.5,2.5);
    ave.SetCanExtend(TH1::kAllAxes);
    TH1F hom(histonameHoM.c_str(),histonameHoM.c_str(),75,1.5,2.5);
    hom.SetCanExtend(TH1::kAllAxes);

    for(int j = 0; j < 10000; j++){
      f >> tmp;
      ave.Fill( tmp );
      f >> tmp;
      hom.Fill( tmp );
    }
    ave.StatOverflows( kTRUE );
    ave.SetTitle(histonameAVE.c_str());
    ave.GetXaxis()->SetTitle("Integral [AU]");
    ave.GetYaxis()->SetTitle("n counts");
    ave.SetFillColor(kTeal-4);
    errorsAVE.push_back( ave.GetStdDev());
    hvectorAVE.push_back(ave);

    hom.StatOverflows( kTRUE );
    hom.SetTitle(histonameHoM.c_str());
    hom.GetXaxis()->SetTitle("Integral [AU]");
    hom.GetYaxis()->SetTitle("n counts");
    hom.SetFillColor(kSpring-4);
    errorsHoM.push_back( hom.GetStdDev());
    hvectorHoM.push_back(hom);
  }

  TCanvas can("can","can");
  can.Divide(2,3);
  for ( auto i = 0 ; i < hvectorAVE.size() ; i++ ) {
    can.cd(i+1);
    hvectorAVE[i].Draw() ;
  }
  TGraph e;
  cout << "Errors table MC-Average" << endl;
	cout << "Nstep \t\t" << "Error" << endl;

	for(auto i=0; i<N.size(); i++){
		cout << setprecision(0) << setw(15) << left << N[i] <<  setprecision(4) << fixed << errorsAVE[i] << endl;
    e.SetPoint(i, N[i], errorsAVE[i]);
	}

  cout << "Errors table MC-Average (single evaluation)" << endl;
	cout << "Nstep \t\t" << "Error" << endl;

	for(auto i=0; i<N.size(); i++){
    double tmp = I->MonteCarlo_AVE(N[i]);
    cout << setprecision(0) << setw(15) << left << N[i] <<  setprecision(4) << fixed << I->Get_eps_Ave() << endl;
	}
  can.cd(hvectorAVE.size()+1);
  e.SetTitle("MC-Average errors");
  e.GetXaxis()->SetTitle("N (number of iterations)");
  e.GetYaxis()->SetTitle("Error");
  e.SetMarkerStyle(43);
	e.SetMarkerSize(0.5);
	e.SetMarkerColor(kGreen+3);
  e.Draw();



  TCanvas can2("can2","can2");
  can2.Divide(2,3);
  for ( auto i = 0 ; i < hvectorHoM.size() ; i++ ) {
    can2.cd(i+1);
    hvectorHoM[i].Draw() ;
  }
  TGraph e2;
  cout << "Errors table MC-Hit or Miss" << endl;
	cout << "Nstep \t\t" << "Error" << endl;

	for(auto i=0; i<N.size(); i++){
		cout << setprecision(0) << setw(15) << left << N[i] <<  setprecision(4) << fixed << errorsHoM[i] << endl;
    e2.SetPoint(i, N[i], errorsHoM[i]);
	}
  can2.cd(hvectorHoM.size()+1);
  e2.SetTitle("MC-Hit or Miss errors");
  e2.GetXaxis()->SetTitle("N (number of iterations)");
  e2.GetYaxis()->SetTitle("Error");
  e2.SetMarkerStyle(45);
	e2.SetMarkerSize(0.5);
	e2.SetMarkerColor(kAzure+3);
  e2.Draw();


  double eps = 0.001;
  int N_ave, N_hom;
  N_ave = pow(errorsAVE[3],2) * N[3]/ pow(eps,2);
  N_hom = pow(errorsHoM[3],2) * N[3]/ pow(eps,2);

  cout << "N of step to get precision of " << eps <<" in MC-Average method: " << N_ave << endl;
  cout << "N of step to get precision of " << eps <<" in MC-Hit or Miss method: " << N_hom << endl;


  app.Run();
  return 0;
}