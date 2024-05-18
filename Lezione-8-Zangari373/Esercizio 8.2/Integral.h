#ifndef __INTEGRAL_H__
#define __INTEGRAL_H__

#include "Funzioni.h"

class Integral{
public:

   Integral(double a, double b, const FunzioneBase* f);

   double Midpoint(unsigned nstep);
   double Simpson(unsigned nstep);
   double Trapezi_N(unsigned nstep);
   //double Trapezi_io(unsigned nstep);
   //double Trapezi_eps_io(double eps);
   //double Trapezi_eps_new(double eps);
   double Trapezi_eps(double eps);
   int GetN_step_trap() {return (m_b - m_a)/ m_h;};

private:
   double m_a, m_b;
   double m_sum;
   double m_h;
   int m_sign;
   double m_integral;
   const FunzioneBase* f;
};

#endif