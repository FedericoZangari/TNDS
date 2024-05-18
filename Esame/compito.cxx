#include <iostream>
#include <cmath>
#include <iomanip>
#include <math.h>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TLegend.h"

#include "Funzioni.h"
#include "Integral.h"
#include "EquazioniDifferenziali.h"

using namespace std;

void print_and_clear_buffer(stringstream &ss)
{
    cout << ss.str();
    ofstream outfile("soluzione.txt", ios::out);
    outfile << ss.str();
    ss.clear();
}

int main(int argc, const char ** argv){
	
	TApplication app("app",0,0);

	if (argc != 2) {
	    cout << "Usage: "<< argv[0] << " nstep"<< endl;
	    return -1;
	}
    stringstream sout;

	double a = 0.;
	double b = sqrt(M_E);
    double I = 3*pow(M_E,2)/16;
    
	int nstep = atoi(argv[1]);

	Fun* f = new Fun();
	Integral* integrator = new Integral(a,b,f,1);

	sout << fixed << setprecision(12) << "Valore dell'integrale con metodo Midpoint: " << integrator->Midpoint(nstep) <<endl << endl;
	
	sout << "Errors table Midpoint" << endl;
	sout << "Nstep \t\t" << "Error" << endl;

	for(int i = 1; i<= 10; i++){
		sout << setprecision(0) << setw(15) << left << pow(2,i) <<  setprecision(12) << abs(I - integrator->Midpoint(pow(2,i)) ) << endl;
	}

	double k1, k2;
	k2= log( abs((I -  integrator->Midpoint(10))) / abs(I - integrator->Midpoint(1000)) ) / log(  ((b - a) / 10) / ((b - a) / 1000 ) );
    k1 = abs(I - integrator->Midpoint(1000)) / pow( ((b - a) / 1000 ) , k2 );
	sout << setprecision(3) <<"Ordine di convergenza del metodo Midpoint: " << endl;
    sout << "k1:\t" << k1 << endl << "k2:\t" << k2 << endl;


    sout << endl << fixed << setprecision(12) << "Valore dell'integrale con metodo Midright: " << integrator->Midright(nstep) <<endl << endl;
	
	sout << "Errors table Midright" << endl;
	sout << "Nstep \t\t" << "Error" << endl;

	for(int i = 1; i<= 10; i++){
		sout << setprecision(0) << setw(15) << left << pow(2,i) <<  setprecision(12) << abs(I - integrator->Midright(pow(2,i)) ) << endl;
	}

	double k11, k22;
	k22= log( abs((I -  integrator->Midright(10))) / abs(I - integrator->Midright(1000)) ) / log(  ((b - a) / 10) / ((b - a) / 1000 ) );
    k11 = abs(I - integrator->Midright(1000)) / pow( ((b - a) / 1000 ) , k22 );
	sout << setprecision(3) <<"Ordine di convergenza del metodo Midright: " << endl;
    sout << "k1:\t" << k11 << endl << "k2:\t" << k22 << endl;

    vector<double> I_ave;

    for(int i = 0; i < 1000; i++){
        I_ave.push_back(integrator->MonteCarlo_AVE(16));
    }
    double eps_ave16 = sqrt(CalcolaVarianza<double>(I_ave));
    sout << "Errore metodo della media: " << eps_ave16 << endl;


    double eps_mid16;
    eps_mid16 = k1 * pow( ((b-a)/16) , k2 );
    int N_ave;
    N_ave = pow(eps_ave16,2) * 16/ pow(eps_mid16,2);

    sout << "Punti necessari per ottenere con il metodo della media la stessa precisione che si ottiene con il metodo midpoint a 16 punti: " << endl;
    sout << N_ave << endl;
/*
    b = 2;
    I = M_PI/2;
    Fun2* f2 = new Fun2();
	Integral* integ = new Integral(a,b,f2,1);

    cout << fixed << setprecision(12) << "Valore del secondo integrale con metodo Midpoint: " << integ->Midpoint(nstep) <<endl << endl;
    k2= log( abs((I -  integ->Midpoint(100))) / abs(I - integrator->Midpoint(1000)) ) / log(  ((b - a) / 100) / ((b - a) / 1000 ) );
    cout << setprecision(3) <<"Ordine di convergenza del metodo Midpoint: " << endl;
    cout << "k2:\t" << k2 << endl;


	
	TCanvas mycanvas ("Simpson-Midpoint error","Plot");

	TGraph g,m;

	for(int j = 1; j < 20 ; j++ ){
		g.SetPoint(j-1, (b -a) / pow(2,j) , abs(2-integrator->Simpson(pow(2,j)) ));
		m.SetPoint(j-1, (b -a) / pow(2,j) , abs(2-integrator->Midpoint(pow(2,j)) ));
	}

	g.Draw("ALP");
	g.SetTitle("Simpson-Midpoint error");
	g.GetXaxis()->SetTitle("Step size h");
	g.GetYaxis()->SetTitle("error");
	g.SetMarkerStyle(45);
	g.SetMarkerSize(1);
	g.SetMarkerColor(kOrange);
	gPad->SetLogx();
	gPad->SetLogy();

	m.Draw("samePL");
	m.SetMarkerStyle(45);
	m.SetMarkerSize(1);
	m.SetMarkerColor(kAzure);
	
	
	TLegend* leg = new TLegend(0.2, 0.80, 0.3, 0.85);
	leg->AddEntry(&g,"Simpson error","p");
	leg->AddEntry(&m,"Midpoint error","p");
 	leg->Draw("same");

	*/
	print_and_clear_buffer(sout);
	app.Run();
	return 0;
}
