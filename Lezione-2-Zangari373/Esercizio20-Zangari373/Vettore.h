
#ifndef __Vettore_h__
#define __Vettore_h__

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Vettore {
 public:

	Vettore();
	Vettore(unsigned int N);
	Vettore(const Vettore&); // copy constructor
	Vettore& operator=(const Vettore&);

	~Vettore(){delete [] m_v;};
	
	unsigned int GetN() const{ return m_N; };
	void SetComponent(unsigned int, double);
	double GetComponent(unsigned int) const;

	void Scambia(unsigned int, unsigned int);

	double& operator[] (unsigned int i);

private:
	unsigned int m_N;
	double* m_v;
};

#endif 
