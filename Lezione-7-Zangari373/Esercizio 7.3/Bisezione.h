#ifndef __bisezione_h__
#define __bisezione_h__

#include "Solutore.h"
#include "FunzioneBase.h"


class Bisezione: public Solutore{
public:
  Bisezione();
  ~Bisezione();

  double CercaZeri(double a, double b, const FunzioneBase* fun);
};
#endif