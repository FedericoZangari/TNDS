#ifndef _Esperimento_Prisma_h_
#define _Esperimento_Prisma_h_

#include "RandomGen.h"

class EsperimentoPrisma {
 public:
   EsperimentoPrisma();
   ~EsperimentoPrisma();

  void Esegui();
  void Analizza();

  double GetTeta0_Mis() {return m_th0_misurato;};
  double GetTeta1_Mis() {return m_th1_misurato;};
  double GetTeta2_Mis() {return m_th2_misurato;};

  double GetDelta1_Mis() {return m_th1_misurato - m_th0_misurato;};
  double GetDelta2_Mis() {return m_th2_misurato - m_th0_misurato;}

  double GetA_Mis() {return m_A_misurato;};
  double GetB_Mis() {return m_B_misurato;};
  double GetN1_Mis() {return m_n1_misurato;};
  double GetN2_Mis() {return m_n2_misurato;};

  double GetA_Inp() {return m_A_input;};
  double GetB_Inp() {return m_B_input;};
  double GetN1_Inp() {return m_n1_input;};
  double GetN2_Inp() {return m_n2_input;};

  double GetTeta0_Inp() {return m_th0_input;};
  double GetTeta1_Inp() {return m_th1_input;};
  double GetTeta2_Inp() {return m_th2_input;};

  

  double GetSigma() {return m_sigmat;};
  
 private:

   RandomGen m_rgen;

   double m_lambda1, m_lambda2, m_alpha, m_sigmat;
   
   double m_A_input, m_A_misurato;
   double m_B_input, m_B_misurato;
   double m_n1_input, m_n1_misurato;
   double m_n2_input, m_n2_misurato;
   double m_th0_input, m_th0_misurato;
   double m_th1_input, m_th1_misurato;
   double m_th2_input, m_th2_misurato;

};
#endif