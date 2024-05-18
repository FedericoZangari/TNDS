#ifndef __funzione_h__
#define __funzione_h__

#include "FunzioneBase.h"
#include <math.h>

class Funzione: public FunzioneBase{
public:
	Funzione() {};
	~Funzione(){};	
	double Eval(double x) const {return sin(x) - x * cos(x);}
};
#endif     