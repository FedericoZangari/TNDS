#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h"

#include <iostream>
#include <string>

#include "RandomGen.h"

int main() {

  
  TApplication app("app",0,0);

  RandomGen mygen(1);

  int nmax = 10000;

  TCanvas can1("Uniforme","Uniforme");
  can1.cd();
  TH1F unif("Uniforme","Uniforme",100,4,11);

  for (int k=0;k<nmax;k++){
    unif.Fill(mygen.Unif(5,10)); 
  }

  unif.GetXaxis()->SetTitle("x [AU]");
  unif.GetYaxis()->SetTitle("N");
  unif.Draw();



  TCanvas can2("Esponenziale","Esponenziale");
  can2.cd();
  TH1F exp("Esponenziale","Esponenziale",100,0,10);

  for (int k=0;k<nmax;k++){
    exp.Fill(mygen.Exp(1)); 
  }

  exp.GetXaxis()->SetTitle("x [AU]");
  exp.GetYaxis()->SetTitle("N");
  exp.Draw();


  TCanvas can3("Gauss","Gauss");
  can3.cd();
  TH1F gaus("Gauss","Gauss",100,-4,6);

  for (int k=0;k<nmax;k++){
    gaus.Fill(mygen.Gauss(1,1)); 
  }

  gaus.GetXaxis()->SetTitle("x [AU]");
  gaus.GetYaxis()->SetTitle("N");
  gaus.Draw();


  TCanvas can4("GaussAR","GaussAR");
  can4.cd();
  TH1F gausAR("GaussAR","GaussAR",100,-4,6);

  for (int k=0;k<nmax;k++){
    gausAR.Fill(mygen.GaussAR(1,1)); 
  }

  gausAR.GetXaxis()->SetTitle("x [AU]");
  gausAR.GetYaxis()->SetTitle("N");
  gausAR.Draw();
  
  app.Run();
  return 0;
}