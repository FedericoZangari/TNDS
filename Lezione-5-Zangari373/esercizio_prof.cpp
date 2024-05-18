
#include "PuntoMateriale.h"
#include "CampoVettoriale.h"

#include "TH1F.h"
#include "TApplication.h"
#include "TGraph.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TArrow.h"
#include "TEllipse.h"
#include "TText.h"
#include "TPaveText.h"

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

int main(int argc, char** argv) {

  TApplication myApp("app",0,0);
  TGraph field;

  if ( argc!=2) {
    cerr << "Usage: " << argv[0] << "<index>" << endl;
    cout << "   index = 1 proton-proton" << endl;
    cout << "   index = 2 proton-electron" << endl;
    cout << "   index = 3 electron-electron" << endl;
    exit(-1);
  }

  int index = atoi( argv[1] ) ;

  const double e =1.60217653E-19 ;
  const double me=9.1093826E-31;
  const double mp=1.67262171E-27;
  const double d =1.E-10;

  double charge1 = 1.;
  double charge2 = 1.;
  string tcharge1 = "+";
  string tcharge2 = "+";
  string nomefile = "protone-protone.png";

  if ( index == 2 ) { charge1 = -1. ; tcharge1 = "-" ; nomefile = "elettrone-protone.png" ;} ;
  if ( index == 3 ) { charge1 = -1. ; charge2 = -1.; tcharge1="-" ; tcharge2 = "-"; nomefile = "elettrone-elettrone.png"; } ;

  
  PuntoMateriale carica1(0.,0., d/2., charge1*e, me );
  PuntoMateriale carica2(0.,0.,-d/2., charge2*e, mp);
  
  Posizione P(0,0,0);

  double maxind = 10;

  TCanvas * canplot = new TCanvas("plot","plot",800,800) ;  
  canplot->cd();
  canplot->DrawFrame (-maxind*d,-maxind*d,maxind*d,maxind*d, "Campo due cariche puntiformi;y[m];z[m]");
  
  for ( int k = -int(maxind) ; k <= int(maxind) ; k=k+1 ) {   
    for ( int j = -int(maxind) ; j <= int(maxind) ; j=j+1 ) {
      if ( sqrt( k*k + j*j  ) < 4  ) continue ;      
      double pz = k*d ;
      double py = j*d ;
      P.setZ( pz ) ;
      P.setY( py ) ; 
      CampoVettoriale Ed = carica1.CampoElettrico(P) + carica2.CampoElettrico(P) ;  
      double scale = 10E-21;    
      TArrow *field = new TArrow( py , pz  , py + Ed.GetFy()*scale, pz + Ed.GetFz()*scale, 0.01 ,">") ;
      field->Draw(">same");
    }
  }
  
  TEllipse * echarge1 = new TEllipse(0,d/2, d/4 ) ;
  TEllipse * echarge2 = new TEllipse(0,-d/2, d/4 ) ;
  TText *lab1 = new TText( 0  , d/2, tcharge1.c_str()) ;
  lab1->SetTextAlign(22);
  lab1->SetTextSize(0.03);
  TText *lab2 = new TText( 0  , -d/2, tcharge2.c_str()) ;
  lab2->SetTextAlign(22);
  lab2->SetTextSize(0.03);

  echarge1->SetFillColor(42);
  echarge2->SetFillColor(42);
  echarge1->Draw("same");
  echarge2->Draw("same");
  lab1->Draw("same");
  lab2->Draw("same");

  canplot->SaveAs(nomefile.c_str());

  myApp.Run();

  return 0;

}


