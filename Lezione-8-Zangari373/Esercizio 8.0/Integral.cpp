#include "Integral.h"
#include <algorithm>

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