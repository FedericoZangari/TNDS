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

	if ( argc != 2 ) {
  		cout << "Uso del programma : " << argv[0] << " <n of poles>" << endl;
    	return -1 ;
	}  

	double const d = 1E-10;
	int n = atoi(argv[1]);

	Posizione r (1, 0, 0);
	

	CampoVettoriale E(r);

	
	
	double a;
	double r1, r2, e1, e2; 
    cout << "E = (" << E.GetFx() << ", " << E.GetFy() << ", " << E.GetFz() << " )" << endl;
    cout << "E = (" << E.getX() << ", " << E.getY() << ", " << E.getZ() << " )" << endl;
	for (int i = 0; i < n; i++){
		double phi = i*(2.*M_PI/n);
        PuntoMateriale part(d*cos(phi), d*sin(phi), 0, pow(-1.,i)*qe, me);
        cout << "p = (" << part.getX() << ", " << part.getY() << ", " << part.getZ() << " )" << endl;
		E += part.CampoElettrico(r);
	}
    cout << "E = (" << E.GetFx() << ", " << E.GetFy() << ", " << E.GetFz() << " )" << endl;
    e1 = E.Modulo();
    r1 = 1E-8;

    r.setX(1E-6);

    CampoVettoriale E2(r);

    for (int i = 0; i < n; i++){
		double phi = i*(2*M_PI/n);
        PuntoMateriale part(d*cos(phi), d*sin(phi), 0, pow(-1,i)*qe, me);
		E2 += part.CampoElettrico(r);
	}
    cout << "E = (" << E2.GetFx() << ", " << E2.GetFy() << ", " << E2.GetFz() << " )" << endl;
    e2 = E2.Modulo();
    r2 = 1E-6;

	a= log(e1 / e2) / log( r1 / r2);
	cout << "Andamento del modulo del campo: " << setprecision(3) << a << endl;


	TCanvas * canplot = new TCanvas("plot","plot",800,800) ;  
  	//canplot->cd();
	canplot->DrawFrame (-10*d,-10*d,10*d,10*d, "Multipolo;x[m];y[m]");
  
  	for ( int k = -10; k <= 10; k=k+1 ) {   
    	for ( int j = -10; j <= 10; j=j+1 ) {
      		if ( sqrt( k*k + j*j  ) < 4  ) continue ;      
      		double px = k*d ;
      		double py = j*d ;
      		r.setX( px ) ;
     		r.setY( py ) ;
            CampoVettoriale e(r);
            for (int i = 0; i < n; i++){
		        double phi = i*(2*M_PI/n);
                PuntoMateriale p(d*cos(phi)/2, d*sin(phi)/2, 0, pow(-1,i)*qe, me);
		        e += p.CampoElettrico(r);
	        }
      		 
      		double scale = 10E-24;    
      		TArrow *field = new TArrow( px , py  , px + e.GetFx()*scale, py + e.GetFy()*scale, 0.01 ,"|>") ;
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