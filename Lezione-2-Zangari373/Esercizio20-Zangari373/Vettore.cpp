#include "Vettore.h"
#include <iomanip>
#include <cmath>
#include <cstdlib>

#define NDEBUG 

#include <assert.h>

// costruttore senza argomenti

Vettore::Vettore()  {
  cout << "Calling default constructor" << endl;
  m_N = 0;
  m_v = NULL;
}

// costruttore con dimensione

Vettore::Vettore(unsigned int N) {
  cout << "Calling constructor with arguments" << endl;
  m_N = N;
  m_v = new double[N];
  for ( int k = 0 ; k < N ; k++ ) m_v[k] = 0;
  
}

// copy constructor

Vettore::Vettore(const Vettore& V){
	cout << "Calling copy constructor" << endl;
	m_N = V.GetN();
	m_v = new double[m_N];
	for(int i=0; i < m_N; i++) m_v[i] = V.GetComponent(i);
}

Vettore& Vettore::operator=(const Vettore& V){
	m_N = V.GetN();
	if (m_v) delete[] m_v;
	m_v = new double[m_N];
	for (int i = 0; i < m_N; i++) m_v[i]= V.GetComponent(i);
	return *this;
}

void Vettore::SetComponent(unsigned int i, double a) {
  assert( ( m_N > i ) && "Errore : l'indice e' troppo grande");
  if ( i<m_N ) {
    m_v[i]=a;
  } else {
    cerr << "Errore: indice " << i << ", dimensione " << m_N << endl;
    exit (-1);
  }
}

double Vettore::GetComponent(unsigned int i) const{
	assert( ( m_N > i ) && "Errore : l'indice e' troppo grande");
	if ( i<m_N ) {
		return m_v[i];
	} else {
		cerr << "Errore: indice " << i << ", dimensione " << m_N << endl;
   		exit (-1);
	}
}

void Vettore::Scambia(unsigned int i, unsigned int k){
	double tmp = m_v[i];
	m_v[i]=m_v[k];
	m_v[k]= tmp;
}

double& Vettore::operator[] (unsigned int i){
	assert( ( m_N > i ) && "Errore : l'indice e' troppo grande");
	if ( i<m_N ) {
		return m_v[i];
	} else {
		cerr << "Errore: indice " << i << ", dimensione " << m_N << endl;
   		exit (-1);
	}
}