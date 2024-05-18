#include <iostream>
#include <cmath>
#include <iomanip>
#include <math.h>
#include <string>
#include <sstream>
#include <fstream>

#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TLegend.h"

#include "Funzioni.h"
#include "Integral.h"


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
	stringstream sout;

	double a = 0.; 
	double b = 1;
	double eps = 0.005;
	int cifre = ceil(-log10(eps));
    

	Fun* f = new Fun();
	Integral* integrator = new Integral(a,b,f,1);

	sout << fixed << setprecision( cifre ) << "valore dell'integrale (trapezi): " << integrator->Trapezi_eps_new(eps) <<endl << endl;
	sout << fixed << setprecision( cifre ) << "valore dell'integrale (trapezi): " << integrator->Trapezi_eps_g(eps) <<endl << endl;
	
	/*double I = integrator->Trapezi_N(10000);
	double I2 = integrator->Trapezi_N(10000/2.);
	double h = (b - a) / 10000.;
	double H = sqrt( (eps*3*h*h) / (4* abs(I - I2)) );
	int N = ceil((b - a) / H);*/

	int N = integrator->GetN_step_trap();

	sout << "Numero di punti per ottenere la precisione di 0.005: " << N << endl << endl;

	sout << fixed << setprecision( 6 ) << "valore dell'integrale (Simpson): " << integrator->Simpson(N) <<endl;

	double eps_S = 16. / 15. * fabs( integrator->Simpson(N) - integrator->Simpson(N/2));
	
	sout <<  "Stima errore commeso (Simpson): " << eps_S << endl << endl;

	

	vector<double> I_ave;
	for(int j = 0; j < 10000; j++){
      I_ave.push_back( integrator->MonteCarlo_AVE(N) );
    }
	double eps_AVE_N = sqrt( CalcolaVarianza(I_ave) );
	sout << fixed << setprecision( 6 ) << "valore dell'integrale (media): " << CalcolaMedia(I_ave) <<endl ;
	sout <<  "Stima errore commeso (media): " << eps_AVE_N << endl;

	int N_ave;
    N_ave = pow(eps_AVE_N,2) * N/ pow(0.005,2);
	sout << "Numero di punti per ottenere la precisione di 0.005 con il metodo della media: " << N_ave << endl << endl;
	

	vector<double> errors;
	sout << "Errors table MC-Average" << endl;
	sout << "Nstep \t" << "Error" << endl;
	TCanvas can("can","can");
  
  	TGraph e;

	for(int i=0; i<10; i++){

		vector<double> Integ{0.0};

    	for(int j = 0; j < 1000; j++){
      		Integ.push_back( integrator->MonteCarlo_AVE(N_ave) );
      	}

		errors.push_back( sqrt( CalcolaVarianza(Integ) ) );
		sout << setprecision(0) << setw(12) << left << N_ave <<  setprecision(4) << fixed << errors[i] << endl;
		e.SetPoint(i, N_ave, errors[i]);
		N_ave -= 500;
  	}

  	e.SetTitle("MC-Average errors");
  	e.GetXaxis()->SetTitle("N (number of iterations)");
  	e.GetYaxis()->SetTitle("Error");
  	e.SetMarkerStyle(43);
	e.SetMarkerSize(0.5);
	e.SetMarkerColor(kGreen+3);
  	e.Draw();


	vector<double> I_ave_exp;
	for(int j = 0; j < 10000; j++){
      I_ave_exp.push_back( integrator->MonteCarlo_AVE_exp(N) );
    }
	double eps_AVE_exp = sqrt( CalcolaVarianza(I_ave_exp) );
	sout << fixed << setprecision( 6 ) << "valore dell'integrale (sampling): " << CalcolaMedia(I_ave_exp) <<endl ;
	sout <<  "Stima errore commeso (media): " << eps_AVE_exp << endl;


	vector<double> errors2;
	sout << "Errors table MC-sampling" << endl;
	sout << "Nstep \t\t" << "Error" << endl;
	TCanvas can2("can","can");
  
  	TGraph e2;
	N_ave = 5829;

	for(int i=0; i<10; i++){

		vector<double> Integ{0.0};

    	for(int j = 0; j < 1000; j++){
      		Integ.push_back( integrator->MonteCarlo_AVE_exp(N_ave) );
      	}

		errors2.push_back( sqrt( CalcolaVarianza(Integ) ) );
		sout << setprecision(0) << setw(15) << left << N_ave <<  setprecision(4) << fixed << errors2[i] << endl;
		e2.SetPoint(i, N_ave, errors2[i]);
		N_ave -= 500;
  	}

  	e2.SetTitle("MC-sampling errors");
  	e2.GetXaxis()->SetTitle("N (number of iterations)");
  	e2.GetYaxis()->SetTitle("Error");
  	e2.SetMarkerStyle(43);
	e2.SetMarkerSize(0.5);
	e2.SetMarkerColor(kGreen+3);
  	e2.Draw();


	
	print_and_clear_buffer(sout);
	app.Run();
	return 0;
}
