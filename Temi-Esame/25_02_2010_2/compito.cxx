#include <iostream>
#include <cmath>
#include <iomanip>
#include <math.h>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
/*
#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TLegend.h"
*/
#include "Esperimento.h"
#include "Funzioni.h"

using namespace std;

void print_and_clear_buffer(stringstream &ss)
{
    cout << ss.str();
    ofstream outfile("soluzione.txt", ios::out);
    outfile << ss.str();
    ss.clear();
}

int main(int argc, const char ** argv){
	
	//TApplication app("app",0,0);
	Esperimento *esp= new Esperimento();
	
    stringstream sout;

	vector<double> c;

	for(int i = 0; i < 1000; i++){
		esp->Esegui();
		c.push_back(esp->Get_C_Mis());
	}
	sout << "Errore su c: " << sqrt(CalcolaVarianza(c)) << endl;

	print_and_clear_buffer(sout);
	return 0;
}
