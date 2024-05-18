#ifndef __elettrone_h__
#define __elettrone_h__

#include "Particella.h"

class Elettrone: public Particella {

public:
  Elettrone();
  ~Elettrone();

  void Print() const; 
};

#endif