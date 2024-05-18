#include <iostream>
#include <fstream>
#include "TApplication.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "funzioni-jacopo.cpp"
#include "TGraph.h"
using namespace std;

int main( int argc , char** argv ){
	TApplication app("MyApp",0,0);
	if ( argc < 2 ) {
    		cout << "Uso del programma : " << argv[0] << " <filename> " << endl;
   		 return -1 ;
	}
	vector<double> Q = Read(argv[1]);
	TCanvas t("q","q");
	TGraph g = qe(Q);
	g.Draw("AP*");
	app.Run();
	return 0;
	

}
