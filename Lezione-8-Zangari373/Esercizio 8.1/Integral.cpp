#include "Integral.h"
#include <algorithm>
#include <iostream>

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

