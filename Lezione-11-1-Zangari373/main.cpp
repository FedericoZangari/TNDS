#include <iostream>
#include <iomanip>
#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TAxis.h"

#include "EsperimentoPrisma.h"
#include "Funzioni.h"

using namespace std;

int main() {
  TApplication app("app",0,0);
  
  
  EsperimentoPrisma *esp= new EsperimentoPrisma();
  double teta0 = esp->GetTeta0_Inp();
  double teta1 = esp->GetTeta1_Inp();
  double teta2 = esp->GetTeta2_Inp();
  double sigma = esp->GetSigma();
  double A = esp->GetA_Inp();
  double B = esp->GetB_Inp();
  double n1 = esp->GetN1_Inp();
  double n2 = esp->GetN2_Inp();
  double delta1 = teta1 - teta0;
  double delta2 = teta2 - teta0;

  TCanvas can2("Prisma","Prisma");
  can2.Divide(3,1);

  TH1F t0("#theta0","#theta0",150,  teta0-4*sigma, teta0+4*sigma);
  TH1F t1("#theta1","#theta1",150, teta1-4*sigma, teta1+4*sigma);
  TH1F t2("#theta2","#theta2",150, teta2-4*sigma, teta2+4*sigma);

  TH1F a("A","A",150,  -0.005, 0.005);
  TH1F b("B","B",150, -1E-15, 1E-15 );
  TH1F D1("#delta1","#delta1",150, -0.002, 0.002);
  TH1F D2("#delta2","#delta2",150, -0.002, 0.002);
  TH1F N1("n1","n1",150, -0.001, 0.001);
  TH1F N2("n2","n2",150, -0.001, 0.001);

  TH2F delta2D ("#delta","#delta",150, -0.002, 0.002, 150, -0.002, 0.002);
  TH2F n2D ("n","n",150, -0.001, 0.001, 150, -0.001, 0.001);
  TH2F AB2D ("A B","A B", 150,  -0.005, 0.005, 150, -1E-15, 1E-15);

  vector<double> A_mis, B_mis, n1_mis, n2_mis, d1_mis, d2_mis;

  for(int i = 0; i <10000; i++){
    
    esp->Esegui();
    t0.Fill( esp->GetTeta0_Mis() );
    t1.Fill( esp->GetTeta1_Mis() );
    t2.Fill( esp->GetTeta2_Mis() );

    esp->Analizza();

    A_mis.push_back(esp->GetA_Mis());
    B_mis.push_back(esp->GetB_Mis());
    n1_mis.push_back(esp->GetN1_Mis());
    n2_mis.push_back(esp->GetN2_Mis());
    d1_mis.push_back(esp->GetDelta1_Mis());
    d2_mis.push_back(esp->GetDelta2_Mis());

    D1.Fill(d1_mis[i]-delta1);
    D2.Fill(d2_mis[i]-delta2);
    N1.Fill(n1_mis[i]-n1);
    N2.Fill(n2_mis[i]-n2);
    a.Fill(A_mis[i]-A);
    b.Fill(B_mis[i]-B);

    delta2D.Fill(d1_mis[i]-delta1, d2_mis[i]-delta2);
    n2D.Fill(n1_mis[i]-n1, n2_mis[i]-n2);
    AB2D.Fill(A_mis[i]-A, B_mis[i]-B);
    
  }

  vector<TH1F> h{t0, t1, t2};
  string name, axis;
  cout << "Risultati della simulazione:" << endl << endl;

  for ( auto i = 0 ; i < h.size() ; i++ ) {
    can2.cd(i+1);
    name = "Distribuzione #theta_{"+to_string(i)+"} misurato";
    h[i].SetTitle(name.c_str());
    axis = "#theta_{"+to_string(i)+"} [rad]";
    h[i].GetXaxis()->SetTitle(axis.c_str());
    h[i].GetYaxis()->SetTitle("n counts");
    h[i].StatOverflows( kTRUE );
    h[i].SetFillColor(kOrange+i);
    h[i].Draw();
    cout << "Theta" << i <<" = " << h[i].GetMean();
    cout << " +- " << fixed << setprecision(5) << h[i].GetStdDev() << endl;
  }
  
  vector<TH1F> g{ D1, D2, N1, N2, a, b};
  vector<TH2F> h2{delta2D, n2D, AB2D};

  TCanvas *c1 = new TCanvas;
  TCanvas *c2 = new TCanvas;
  TCanvas *c3 = new TCanvas;
  
  vector<TCanvas*> can{ c1, c2, c3};
 
  vector<string> nomehisto{"#delta_{m,1} ", "#delta_{m,2} ", "n_{1} ", "n_{2} ", "A ", "B "};
  vector<string> nomeaxis{" [rad]", " [rad]", "", "", "", " [m^{2}]"};
  
  for(int j = 0; j < 3; j++){
    
    can[j]->Divide(3,1);
    
    for(int i = 0; i < 2; i++){
      can[j]->cd(i+1);
      name = "Distribuzione "+nomehisto[2*j+i];
      g[2*j+i].SetTitle(name.c_str());
      axis = "Errore "+nomehisto[2*j+i] + nomeaxis[2*j+i];
      g[2*j+i].GetXaxis()->SetTitle(axis.c_str());
      g[2*j+i].GetYaxis()->SetTitle("n counts");
      g[2*j+i].StatOverflows( kTRUE );
      g[2*j+i].SetFillColor(kTeal-i-2*j);
      g[2*j+i].Draw();
    }

    can[j]->cd(3);
    name = "Distribuzione residui "+nomehisto[2*j]+nomehisto[2*j+1];
    h2[j].SetTitle(name.c_str());
    axis = "Errore "+nomehisto[2*j] + nomeaxis[2*j];
    h2[j].GetXaxis()->SetTitle(axis.c_str());
    axis = "Errore "+nomehisto[2*j+1] + nomeaxis[2*j+1];
    h2[j].GetYaxis()->SetTitle(axis.c_str());
    h2[j].SetFillColor(kAzure);
    h2[j].Draw();
  }


  cout << endl;
  cout << "Media delta1: " << CalcolaMedia<double>(d1_mis) << "\tsigma: " << sqrt(CalcolaVarianza<double>(d1_mis)) << endl;
  cout << "Media delta2: " << CalcolaMedia<double>(d2_mis) << "\tsigma: " << sqrt(CalcolaVarianza<double>(d2_mis)) << endl;
  cout << "Correlazione: " << setprecision(2) <<Correlazione(d1_mis, d2_mis) << endl << endl;

  cout << "Media n1: " << setprecision(5) << CalcolaMedia<double>(n1_mis) << "\tsigma: " << sqrt(CalcolaVarianza<double>(n1_mis)) << endl;
  cout << "Media n2: " << CalcolaMedia<double>(n2_mis) << "\tsigma: " << sqrt(CalcolaVarianza<double>(n2_mis)) << endl;
  cout << "Correlazione: " << setprecision(2) <<Correlazione(n1_mis, n2_mis) << endl << endl;
  
  cout << "Media A: " << setprecision(5) << CalcolaMedia<double>(A_mis) << "\tsigma: " << sqrt(CalcolaVarianza<double>(A_mis)) << endl;
  cout << "Media B: " << scientific <<  setprecision(3) << CalcolaMedia<double>(B_mis) << "\tsigma: " << setprecision(1) <<sqrt(CalcolaVarianza<double>(B_mis)) << endl;
  cout << "Correlazione: " <<fixed << setprecision(2) << Correlazione(A_mis, B_mis) << endl;

  app.Run();
  return 0;
}