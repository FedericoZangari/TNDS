#include <iostream>
#include <fstream>
#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "funzioni.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TLegend.h"

using namespace std;

int main( int argc , char** argv ) {

  	if ( argc < 2 ) {
  		cout << "Uso del programma : " << argv[0] << " <filename> " << endl;
    	return -1 ;
	}  
  
	TApplication app("app",0,0);
  
	// leggo dati da file

	vector<posizione> v = ReadAll<posizione>(argv[1]);
	
	
	TGraphErrors mygraph;

	for (int k = 0; k < v.size(); k++ ){
		mygraph.SetPoint(k, v[k].getx(), v[k].gety());
		mygraph.SetPointError(k, v[k].getex(), v[k].getey());
	}

	
	TF1 * function = new TF1 ("fit", "[0]*x+[1]",0,1000);
	mygraph.Fit(function);

	double em = function->GetParameter(0);
	double err = function->GetParError(0);

	cout << "e/m = " << em << " +- "<< err << endl;
	cout << "chi2 = " << function->GetChisquare() << endl;
	cout << "probability = " << function->GetProb() << endl;
	
	TCanvas mycanvas ("Plot","Plot");
	mygraph.Draw("AP");
	mygraph.SetTitle("Misura e/m configurazione antiparallela fixed");
	mygraph.GetXaxis()->SetTitle("B_{z}^{2} [T^{2}]");
	mygraph.GetYaxis()->SetTitle("2#DeltaV/R^{2} [V/m^{2}]");
	mygraph.SetMarkerStyle(45);
	mygraph.SetMarkerSize(1);
	mygraph.SetMarkerColor(kCyan);
	function->SetLineColor(kAzure+2);
	
	function->SetLineColor(kAzure+2);
	function->Draw("same");
	TLegend leg (0.15,0.7, 0.3, 0.85) ;
	leg.AddEntry(&mygraph,"data","p");
 	leg.AddEntry(function,"fit","l");
 	leg.Draw("same");

	app.Run();
	return 0;
}
