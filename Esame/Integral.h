#ifndef __INTEGRAL_H__
#define __INTEGRAL_H__

#include "Funzioni.h"
#include "RandomGen.h"

class Integral{
public:

   Integral(double a, double b, const FunzioneBase* f);
   Integral(double a, double b, const FunzioneBase* f, unsigned int seed);

   double Midpoint(unsigned nstep);
   double Midright(unsigned nstep);
   double Simpson(unsigned nstep);
   double Get_eps_Simpson() {return m_eps;};

   double Trapezi_N(unsigned nstep);   
   double Trapezi_eps(double eps);
   double Trapezi_eps_new(double eps);
   int GetN_step_trap() {return (m_b - m_a)/ m_h;};

   double MonteCarlo_HoM(double fmax, int n);
   double MonteCarlo_AVE(int n);
   double Get_eps_Ave() {return m_eps;};

private:
   double m_a, m_b;
   double m_sum;
   double m_h;
   double m_eps;
   int m_sign;
   double m_integral;
   const FunzioneBase* f;
   RandomGen * m_rand;
};

#endif