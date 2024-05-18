#include <iostream>
#include <fstream>
#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"

#include "funzioni.h"

int main( int argc , char** argv ) {

  if ( argc < 2 ) {
    cout << "Uso del programma : " << argv[0] << " <filename> " << endl;
    return -1 ;
  }  

  TApplication app("app",0,0);
  
  // leggo dati da file

  vector<double> v = ReadAll<double>(argv[1]);

  // creo e riempio il vettore. L'opzione StatOvergflows permetter di calcolalare
  // le informazioni statistiche anche se il dato sta fuori dal range di definizione
  // dell'istogramma
  
  TH1F histo = FillHisto<double>(v);
  
  // accedo a informazioni statistiche 

  cout << "Media dei valori caricati = " << histo.GetMean() << endl;

  // disegno

  TCanvas mycanvas ("Histo","Histo");
  histo.Draw();
  histo.GetXaxis()->SetTitle("measurement");

  app.Run();
  
}
