#ifndef __solutore_h__
#define __solutore_h__

#include "FunzioneBase.h"

class Solutore{
public:
  virtual double CercaZeri(double a, double b, const FunzioneBase* fun)=0;
  void SetPrecision(double epsilon) {m_prec = epsilon;}
  double GetPrecision() {return m_prec;}

protected:
  double m_a, m_b;
  double m_prec;
  const FunzioneBase* f;
};
#endif