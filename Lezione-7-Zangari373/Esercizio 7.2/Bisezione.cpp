#include "Solutore.h"
#include "Bisezione.h"
#include <math.h>
#include <iostream>

using namespace std;

int sign(double x) {return (x==0.?0.:(x>0?1.:-1)); };

Bisezione::Bisezione(){};

double Bisezione::CercaZeri(double a, double b, const FunzioneBase* fun){
	
	f = fun;
	if(a < b){
		m_a = a;
		m_b = b;
	} else{
		m_a = b;
		m_b = a;
	}
	if( sign( f->Eval(m_a) ) * sign( f->Eval(m_b) ) > 0) {
		cout << "invalid initial intervall" << endl;
		exit(-1);
	}
	else if (sign( f->Eval(m_a) ) * sign( f->Eval(m_b) ) == 0){
		if (f->Eval(m_a) == 0) return m_a;
		if (f->Eval(m_b) == 0) return m_b;
	}

	double c;
	int n = 0;
	int n_max = ceil( log2((m_b-m_a)/m_prec) ) + 1;

	while( (m_b -m_a) > m_prec){

		if ( n > n_max){
			cout <<"exit, reached number of max iteration " << n << endl;
			cout << "a: " << m_a << " b: " << m_b << endl;
			break;
		}

		c = ( m_b + m_a ) / 2.;
		
		n++;
		//cout << m_a << "\t" << m_b << "\t" << c << "\t" << m_b-m_a << "\t" << n << endl;

		if ( sign( f->Eval(a) ) * sign( f->Eval(c) ) < 0) m_b = c;
		else if ( sign( f->Eval(b) ) * sign( f->Eval(c) ) < 0) m_a = c;
		else return c;
	}
	
	return c;
  };