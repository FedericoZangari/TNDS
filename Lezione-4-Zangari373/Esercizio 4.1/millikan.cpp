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

class Dati{
    public:
        Dati();
        Dati(double q, double err){
            m_q = q;
            m_err = err;
        };

        double GetQ(){ return m_q;};
        
        double GetErr(){ return m_err;};

    private:
        double m_q;
        double m_err;
};

vector<Dati> ReadData( const char* Filename) {
  
  ifstream f(Filename);

  vector<Dati> v;
  double val;
  double er;

  if ( !f ) {
    cout << "Cannot open file " << Filename << endl;
    exit(11);
  };

  
  for(;;){
	  	if(f.eof()==1) break;
        f >> val >> er;
        Dati dat(val, er);
        v.push_back(dat);
        
  }
  
  f.close();
  return v;
}

double sum(double q, vector<Dati> Q){

	double s = 0;
	for(int i = 0; i < Q.size(); i++){
		s += pow(q - Q[i].GetQ()/(floor(Q[i].GetQ() / q + 0.5)) , 2);
	}

	return s;
}

double derivate ( vector<Dati> Q) {
  double sum = 0;
  for ( int k = 0 ; k < Q.size() ; k++ ) sum+= (  Q[k].GetQ()/ floor(Q[k].GetQ()/qbest +0.5) );  
    
  return sum/Q.size() ;
}

double error (vector<Dati> Q){
    double err = 0;
    for ( int k = 0 ; k < Q.size() ; k++ ) err+= pow(  Q[k].GetErr()/ floor(Q[k].GetQ()/qbest +0.5) , 2 );  

    err = sqrt(err) / Q.size();
    return err;
}

int main( int argc , char** argv ) {

  	if ( argc < 2 ) {
  		cout << "Uso del programma : " << argv[0] << " <filename> " << endl;
    	return -1 ;
	}  
  
	TApplication app("app",0,0);
  
	// leggo dati da file

	vector<Dati> data = ReadData(argv[1]);
	//sort(data.begin(), data.end());
	//for(auto it = data.begin() ; it != data.end() ; it++)	cout << *it << endl;
	cout << data.size() << endl;

    TCanvas can1 ("Plot","Plot");
	
	TH1F histo("Charges", "Charges", 100, 0, 20E-19);
    for (int i = 0; i < data.size(); i++) histo.Fill(data[i].GetQ());
    histo.Draw();
	histo.GetXaxis()->SetTitle("Charges [C]");

	TCanvas can2 ("Cariche_Millikan","Cariche_Millikan");
	TGraph g;

	double qi = 1.5000E-19; 
	double passo = 0.5E-22;

	for(int j = 0; j < 700 ; j++){
		
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
    double siserr = error(data);

	cout << setprecision(1) << "errore statistico: "<< uncer << endl;
    cout << "errore sistematico: " << siserr << endl;
	cout << setprecision(5) << mycharge << " +- " << setprecision(3) <<sqrt(siserr*siserr + uncer*uncer) << endl;

	app.Run();
	return 0;
}
