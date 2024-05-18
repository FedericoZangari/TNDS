#ifndef __INTEGRAL_H__
#define __INTEGRAL_H__

#include "Funzioni.h"
#include "RandomGen.h"

class Integral{
public:

   Integral(double a, double b, const FunzioneBase* f);
   Integral(double a, double b, const FunzioneBase* f, unsigned int seed);
   Integral(double a, double b, const Funzione2D* f, unsigned int seed);

   double Midpoint(unsigned nstep);
   double Midright(unsigned nstep);
   double Simpson(unsigned nstep);

   double Trapezi_N(unsigned nstep);   
   double Trapezi_eps(double eps);
   double Trapezi_eps_new(double eps);
   int GetN_step_trap() {return (m_b - m_a)/ m_h;};
   
   double Trapezi_eps2D(double eps, double x);

   double MonteCarlo_HoM(double fmax, int n);
   double MonteCarlo_AVE(int n);

private:
   double m_a, m_b;
   double m_sum;
   double m_h;
   int m_sign;
   double m_integral;
   const FunzioneBase* f;
   const Funzione2D* f2;
   RandomGen * m_rand;
};


class FunInt{
public:
	FunInt(double a, double b, double eps) {
		m_a = a;
		m_b = b;
		m_eps = eps;
		m_f = new Fun2D();
		m_integrator = new Integral(m_a,m_b,m_f,1);
	};
	~FunInt(){};	

	double Eval(double x)  {
		return m_integrator->Trapezi_eps2D(m_eps, x);
	}

private:
	double m_eps;
	double m_a, m_b;
	Fun2D* m_f;
	Integral* m_integrator;
};


#endif