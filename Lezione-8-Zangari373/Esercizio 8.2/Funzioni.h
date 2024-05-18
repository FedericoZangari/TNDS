#ifndef __funzioni_h__
#define __funzioni_h__

#include <math.h>

class FunzioneBase{
public:
  virtual double Eval(double x) const = 0;
};



class Seno: public FunzioneBase{
public:
	Seno() {};
	~Seno(){};	
	double Eval(double x) const {return sin(x);}
};

#endif