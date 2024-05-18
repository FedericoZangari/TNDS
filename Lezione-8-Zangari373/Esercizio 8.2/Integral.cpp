#include "Integral.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

Integral::Integral(double a, double b, const FunzioneBase* fun)
{
   f = fun;
   m_a = a;
   m_b = b;
   if ( a> b) m_sign = -1;
   else m_sign = 1;   
}

double Integral::Midpoint(unsigned int nstep){
	m_h = (m_b - m_a)/nstep;
	m_sum = 0.;

	for (unsigned int i=0; i < nstep; i++){
		m_sum += f->Eval(m_a + (i+0.5) * m_h) * m_h;
	}	

	m_integral = m_sign*m_sum;

	return m_integral;
}

double Integral::Simpson(unsigned int nstep){
	m_h = (m_b - m_a)/nstep;
	m_sum = 0.;
	
	for (unsigned int i=1; i < nstep; i++){
		if( i % 2 == 1) m_sum += 4./3 * f->Eval(m_a + i * m_h ) * m_h;
		else m_sum += 2./3 * f->Eval(m_a + i * m_h ) * m_h;

	}	
	m_sum += m_h /3 * (f->Eval(m_a) + f->Eval(m_b));

	m_integral = m_sign*m_sum;

	return m_integral;
}

double Integral::Trapezi_N(unsigned int nstep){
	m_h = (m_b - m_a)/nstep;
	m_sum = 0.;

	for (unsigned int i=1; i < nstep; i++){
		m_sum += f->Eval(m_a + i * m_h) * m_h;
	}	

	m_sum += m_h /2. * (f->Eval(m_a) + f->Eval(m_b));

	m_integral = m_sign*m_sum;

	return m_integral;
}
/*
double Integral::Trapezi_io(unsigned int nstep){

	m_sum = (m_b - m_a) /2. * (f->Eval(m_a) + f->Eval(m_b));
	vector<double> I = {m_sum};
	
	for (unsigned int k = 1; k <= log(nstep)/log(2) +1; k++){
		I.push_back( I[k-1] *0.5 );

		for (int j = 0; j <= pow(2, k-1)-1 ; j++){
			I[k] += ( f->Eval(m_a + (m_b-m_a) * (2*j + 1) / pow(2,k) ) ) * (m_b - m_a) / pow(2,k);
		}
	}	

	m_integral = m_sign*I[log(nstep)/log(2)];

	return m_integral;
}

double Integral::Trapezi_eps_io(double eps){

	m_sum = (m_b - m_a) /2. * (f->Eval(m_a) + f->Eval(m_b));
	vector<double> I = {m_sum};
	
	int k = 1;
	for (;;){
		I.push_back( I[k-1] *0.5 );

		for (int j = 0; j <= pow(2, k-1)-1 ; j++){
			I[k] += ( f->Eval(m_a + (m_b-m_a) * (2*j + 1) / pow(2,k) ) ) * (m_b - m_a) / pow(2,k);
		}
		//cout << k << "\t" << I[k] << "\t" << 4./3. * abs( I[k]-I[k-1]) << endl;
		
		if( 4./3. * abs( I[k]-I[k-1]) < eps){
			m_integral = m_sign*I[k];
			//cout << "N =" << setprecision(0) << pow(2,k) << endl;
			return m_integral;
		}

		if(k >= 25){
			m_integral = m_sign*I[k];
			cout << "max # of iteration reached" << endl;
			return m_integral;
		}
		k++;
	}	
}*/

double Integral::Trapezi_eps(double eps){


	double sum = 1. /2. * (f->Eval(m_b) + f->Eval(m_a)) ;
	vector<double> I{sum*(m_b - m_a)};
	int i = 1;
	double h;
	
	for(;;){
		h = (m_b - m_a)/pow(2,i);

		for (int k =1; k < pow(2,i); k+=2 ){
			sum += f->Eval(m_a + h*k );
		}
		I.push_back( sum *(m_b - m_a)/pow(2,i) );
		
		if( 4./3. * abs( I[i]-I[i-1]) < eps){
			m_integral = m_sign*I[i];
			//cout << "N =" <<  pow(2,i) << endl;
			m_h = h;
			return m_integral;
		}
		
		
		i++;
	}
	
}
/*
double Integral::Trapezi_eps_new(double eps){
	Integral* integrator = new Integral(m_a,m_b,f);
	
	double I = integrator->Trapezi_N(100);
	double I2 = integrator->Trapezi_N(100*2);
	double h = (m_b - m_a) / 100.;

	double H = sqrt((eps*3*h*h) / (4* (I - I2)));

	int N = (m_b - m_a) / H;

	return integrator->Trapezi_N(N);
}*/