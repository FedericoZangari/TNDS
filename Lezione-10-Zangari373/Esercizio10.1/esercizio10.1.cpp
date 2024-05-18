#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h"

#include <iostream>
#include <string>

#include "RandomGen.h"

using namespace std;

int main(int argc, const char ** argv) {

  
  TApplication app("app",0,0);

  if (argc != 2) {
	    cout << "Usage: "<< argv[0] << " nstep"<< endl;
	    return -1;
	}

  RandomGen mygen(1);

  int N = atoi(argv[1]);

  TCanvas can1("Limite centrale","plot");
  can1.Divide(2);
  can1.cd(1);
  TH1F unif("Uniforme","Uniforme",75,-0.5,1.5);
  unif.SetCanExtend(TH1::kAllAxes);
  TH1F sum("somme","somme", 100, 0, 2);
  sum.SetCanExtend(TH1::kAllAxes);
  double x, s = 0;

  for (int k=0;k<N;k++){
    x =mygen.Unif(0,1);
    s += x;
    unif.Fill(x); 
    sum.Fill(s/k); 
  }

  unif.GetXaxis()->SetTitle("x [AU]");
  unif.GetYaxis()->SetTitle("N");
  unif.Draw();



  can1.cd(2);
  

  sum.GetXaxis()->SetTitle("x [AU]");
  sum.GetYaxis()->SetTitle("N");
  sum.Draw();

  cout << "Valor medio delle variabili aleatorie:\t" << unif.GetMean() << endl;
  cout << "Valor medio delle medie:\t\t" << sum.GetMean() << endl;
  cout << "Dev std delle variabili aleatorie:\t" << unif.GetStdDev() << endl;
  cout << "Dev std delle medie:\t\t\t" << sum.GetStdDev() << endl;
  cout << "Dev std delle variabili aleatorie/sqrt(N):"  << unif.GetStdDev()/sqrt(N) << endl;

  
  
  app.Run();
  return 0;
}