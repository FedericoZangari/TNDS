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

Integral::Integral(double a, double b, const FunzioneBase* fun, unsigned int seed){
   f = fun;
   m_a = a;
   m_b = b;
   if ( a> b) m_sign = -1;
   else m_sign = 1;   
   m_rand = new RandomGen(seed);
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

double Integral::Midright(unsigned int nstep){
	m_h = (m_b - m_a)/nstep;
	m_sum = 0.;

	for (unsigned int i=0; i < nstep; i++){
		m_sum += f->Eval(m_a + (i+1) * m_h) * m_h;
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
	
	Integral* integrator = new Integral(m_a,m_b,f);
	m_eps = 16. / 15. * fabs( m_integral - integrator->Simpson(nstep*2));

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



double Integral::Trapezi_eps_new(double eps){
	Integral* integrator = new Integral(m_a,m_b,f);
	
	double I = integrator->Trapezi_N(100);
	double I2 = integrator->Trapezi_N(100*2);
	double h = (m_b - m_a) / 100.;

	double H = sqrt((eps*3*h*h) / (4* abs(I - I2)));

	int N = ceil( (m_b - m_a) / H );

	return integrator->Trapezi_N(N);
}




 double Integral::MonteCarlo_AVE(int n){
	m_sum = 0.;
	vector<double> f_i;

	for(int i = 0; i < n; i++){
		f_i.push_back(f->Eval( m_rand->Unif(m_a, m_b)));
		m_sum += f_i[i];
	}
	m_integral = (m_b - m_a) * m_sum / n * m_sign;
	m_eps = sqrt(CalcolaVarianza(f_i)/(n-1)) * (m_b-m_a);

	return  m_integral;
 }

 double Integral::MonteCarlo_HoM(double fmax, int n){
	double x, y;
	int Nhit = 0;

	for(int i = 0; i < n; i++){
		x = m_rand->Unif(m_a, m_b);
		y = m_rand->Unif(0, fmax);
		if(y < f->Eval(x)) Nhit++;
	}
	m_integral = m_sign * (m_b - m_a) * fmax * Nhit / n;
	return m_integral;
 }