#ifndef __Vettore_h__
#define __Vettore_h__

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#define NDEBUG 

#include <assert.h>

using namespace std;

template <typename T> class Vettore {
                          
 public:
	Vettore() {
		cout << "Calling default constructor" << endl;
		m_N = 0;
		m_v = NULL;
	};

	Vettore(unsigned int N) {
		cout << "Calling constructor with arguments" << endl;
		m_N = N;
		m_v = new T[N];
		for ( int k = 0 ; k < N ; k++ ) m_v[k] = 0;
	};

	Vettore(const Vettore<T> & V){
		m_N = V.GetN();
		m_v = new T[m_N];
		for(int i=0; i < m_N; i++) m_v[i] = V.GetComponent(i);
	};
	
	Vettore& operator=(const Vettore<T> & V){
		m_N = V.GetN();
		if (m_v) delete[] m_v;
		m_v = new T[m_N];
		for (int i = 0; i < m_N; i++) m_v[i]= V.GetComponent(i);
	
		return *this;
	};

	Vettore( Vettore<T>&& V){
		cout << "Calling move constructor" << endl;
		m_N = V.m_N;
		m_v = V.m_v;
		V.m_N = 0;
		V.m_v = nullptr;
	}

	Vettore& operator=( Vettore<T>&& V){
		cout << "Calling move operator" << endl;
		delete[] m_v;
		m_N = V.m_N;
		m_v = V.m_v;

		V.m_N = 0;
		V.m_v = nullptr;

		return *this;
	}

	~Vettore(){delete [] m_v;};
	
	unsigned int GetN() const{ return m_N; };

	void SetComponent(unsigned int i, T a){
		assert( ( m_N > i ) && "Errore : l'indice e' troppo grande");
		if ( i<m_N ) {
			m_v[i]=a;
		} else {
   		 	cerr << "Errore: indice " << i << ", dimensione " << m_N << endl;
    		exit (-1);
		}
	};

	T GetComponent(unsigned int i) const{
		assert( ( m_N > i ) && "Errore : l'indice e' troppo grande");
		if ( i<m_N ) {
			return m_v[i];
		} else {
			cerr << "Errore: indice " << i << ", dimensione " << m_N << endl;
   			exit (-1);
		}
	};

	void Scambia(unsigned int i, unsigned int k){
		T tmp = m_v[i];
		m_v[i]=m_v[k];
		m_v[k]= tmp;
	};

	T& operator[] (unsigned int i){
		assert( ( m_N > i ) && "Errore : l'indice e' troppo grande");
		if ( i<m_N ) {
			return m_v[i];
		} else {
			cerr << "Errore: indice " << i << ", dimensione " << m_N << endl;
   			exit (-1);
		}
	};

 private:
  
   unsigned int m_N;                        
   T* m_v;     
  
};

#endif // __Vettore_h__



