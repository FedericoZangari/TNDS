#include <iostream>
#include <math.h>
#include <iomanip>

#include "Posizione.h"
#include "CampoVettoriale.h"
#include "PuntoMateriale.h"

#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TLegend.h"
#include "TArrow.h"

#include "TEllipse.h"
#include "TText.h"
#include "TPaveText.h"

double const me = 9.10938370E-31;
double const qe = 1.60217663E-19;
double const mp = 1.67262192E-27;


using namespace std;

int main(int argc, char** argv){
	TApplication app("app",0,0);

	if ( argc != 4 ) {
  		cout << "Uso del programma : " << argv[0] << " <x> <y> <z> " << endl;
    	return -1 ;
	}  

	double const d = 1E-10;
	double x = atof(argv[1]);
	double y = atof(argv[2]);
	double z = atof(argv[3]);

	Posizione r (x, y, z);
	PuntoMateriale elettrone (0, 0,  d/2, -qe, me);
	PuntoMateriale protone (0, 0,  -d/2, qe, mp);

	CampoVettoriale E = elettrone.CampoElettrico(r) + protone.CampoElettrico(r);

	cout << "E = (" << E.GetFx() << ", " << E.GetFy() << ", " << E.GetFz() << " )" << endl; 

	TCanvas c ("dipolo", "dipolo");
	TGraph g;
	int count = 0;
	double a;
	double r1, r2, e1, e2; 
	

	for (double p = 100*d; p < 1000*d; p += d){
		Posizione P(0,p, 0);
		CampoVettoriale e =elettrone.CampoElettrico(P) + protone.CampoElettrico(P);
		g.SetPoint(count, p, e.Modulo());

		if(count == 0) {r1 = p; e1 = e.Modulo(); }
		if(count == 900) {r2 = p; e2 = e.Modulo();}
		count++;
	}

	g.Draw("AP");
	g.SetMarkerColor(kBlue);
	g.SetTitle("Electric Field");
	g.GetXaxis()->SetTitle("Distance [m]") ;
	g.GetYaxis()->SetTitle("E [N/C]") ;

	TLegend* leg = new TLegend(0.2, 0.85, 0.3, 0.90);
  	leg->AddEntry(&g,"Electric Field","p");
 	leg->Draw("same");

	a= log(e1 / e2) / log( r1 / r2);
	cout << "Andamento del modulo del campo: " << setprecision(3) << a << endl;


	TCanvas * canplot = new TCanvas("plot","plot",800,800) ;  
  	canplot->cd();
	canplot->DrawFrame (-10*d,-10*d,10*d,10*d, "Dipolo;x[m];y[m]");
	Posizione P(0,0,0);
  
  	for ( int k = -10; k <= 10; k=k+1 ) {   
    	for ( int j = -10; j <= 10; j=j+1 ) {
      		if ( sqrt( k*k + j*j  ) < 4  ) continue ;      
      		double pz = k*d ;
      		double py = j*d ;
      		P.setZ( pz ) ;
      		P.setY( py ) ; 
      		CampoVettoriale Ed = elettrone.CampoElettrico(P) + protone.CampoElettrico(P) ;  
      		double scale = 10E-21;    
      		TArrow *field = new TArrow( py , pz  , py + Ed.GetFy()*scale, pz + Ed.GetFz()*scale, 0.01 ,">") ;
      		field->Draw(">same");
    	}
  	}
	TEllipse * echarge1 = new TEllipse(0,d/2, d/3 ) ;
  	TEllipse * echarge2 = new TEllipse(0,-d/2, d/3 ) ;
  	TText *lab1 = new TText( 0  , d/2, "-") ;
  	lab1->SetTextAlign(22);
  	lab1->SetTextSize(0.03);
  	TText *lab2 = new TText( 0  , -d/2, "+") ;
  	lab2->SetTextAlign(22);
  	lab2->SetTextSize(0.03);

  	echarge1->SetFillColor(kCyan);
  	echarge2->SetFillColor(kRed);
  	echarge1->Draw("same");
  	echarge2->Draw("same");
  	lab1->Draw("same");
	lab2->Draw("same");

	app.Run();
	return 0;
}