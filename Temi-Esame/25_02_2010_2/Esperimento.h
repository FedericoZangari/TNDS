#ifndef _Esperimento_h_
#define _Esperimento_h_

#include "RandomGen.h"

class Esperimento {
 public:
   Esperimento();
   ~Esperimento();

  void Esegui();
  

  double Get_C_Mis() {return m_c_mis;};
  
 private:

   RandomGen m_rgen;

   double m_ma, m_sigma_ma;
   double m_m, m_sigma_m;
   double m_ca;
   double m_Ta, m_sigma_Ta;
   double m_mc;
   double m_Tc, m_sigma_Tc;
   double m_Te, m_sigma_Te;

   double m_ma_mis;
   double m_Ta_mis;
   double m_m_mis;
   double m_Tc_mis;
   double m_Te_mis;
   double m_c_mis;

};
#endif