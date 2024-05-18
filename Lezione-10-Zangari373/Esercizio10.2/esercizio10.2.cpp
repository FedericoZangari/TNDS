#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h"

#include <iostream>
#include <fstream>

#include "RandomGen.h"
#include "Funzioni.h"
#include "Integral.h"

using namespace std;

int main() {
  
  Seno *sin = new Seno();
  Integral *I = new Integral(0, M_PI, sin, 1);
  vector<int> N{100, 500, 1000, 5000, 10000};
  string filename;
  

  for(auto i=0; i<N.size(); i++){

    filename = "integral" +to_string(N[i])+ ".dat";
    ofstream f (filename.c_str());
    
    for(int j = 0; j < 10000; j++){
      f << I->MonteCarlo_AVE(N[i]) <<"\t";
      f << I->MonteCarlo_HoM(1, N[i]) << endl;
    }
  }

  return 0;
}