#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TLegend.h"

using namespace std;

double const qe = 1.60217653E-19 ;
double qbest = 1.60217653E-19;

vector<double> ReadData( const char* Filename) {
  
  ifstream f(Filename);

  vector<double> v;
  double val;
  
  if ( !f ) {
    cout << "Cannot open file " << Filename << endl;
    exit(11);
  };
  
  while ( f >> val ) v.push_back(val);
  
  f.close();
  return v;
}

double sum(double q, vector<double> Q){
	double s = 0;
	for(int i = 0; i < Q.size(); i++){
		s += pow(q - Q[i]/(floor(Q[i] / q + 0.5)) , 2);
	}

	return s;
}

double derivate ( vector<double> Q) {
  double sum = 0;
  for ( int k = 0 ; k < Q.size() ; k++ ) sum+= (  Q[k]/ floor(Q[k]/qbest +0.5) );  
    
  return sum/Q.size() ;
}

int main( int argc , char** argv ) {

  	if ( argc < 2 ) {
  		cout << "Uso del programma : " << argv[0] << " <filename> " << endl;
    	return -1 ;
	}  
  
	TApplication app("app",0,0);
  
	// leggo dati da file

	vector<double> data = ReadData(argv[1]);
	sort(data.begin(), data.end());
	//for(auto it = data.begin() ; it != data.end() ; it++)	cout << *it << endl;
	
/*
    TCanvas can1 ("Plot","Plot");
	
	TH1F histo("cariche", "cariche", 100, 0, 20E-19);
    for (int i = 0; i < data.size(); i++) histo.Fill(data[i]);
    histo.Draw();
	histo.GetXaxis()->SetTitle("Cariche [C]");*/

	TCanvas can2 ("Cariche_Millikan","Cariche_Millikan");
	TGraph g;

	double qi = 1.5000E-19; 
	double passo = 0.5E-22;

	for(int j = 0; j < 500 ; j++){
		
		g.SetPoint(j, qi, sum(qi, data) );
		if(sum(qi, data) <= sum(qbest, data) ) qbest = qi;
		qi += passo;
	}


	/*
	for(double q = 1.5e-19; q < 1.7e-19; q+= 0.0001e-19){
		g.SetPoint(count, q, sum(q, data));
		count++;
	}*/

	g.Draw("AP");
	g.SetMarkerStyle(20);
	g.SetMarkerSize(0.25);
	g.SetMarkerColor(kBlue);
	g.SetTitle("Best charge value");
	g.GetXaxis()->SetTitle("Charge (C)") ;
	g.GetYaxis()->SetTitle("S(q) (C^{2})") ;

	
	//cout << count << endl;
	cout << setprecision(4) << scientific << "minimum of S(q) : " << qbest << endl;

	double mycharge = derivate(data ) ;
	double uncer = sqrt(  sum(mycharge, data) / ( data.size() * (data.size()-1))   ); 
	cout << mycharge << " +- " << setprecision(2) << uncer << endl;
	

	app.Run();
	return 0;
}
