#ifndef __funzioni_h__
#define __funzioni_h__

#include <math.h>
#include <vector>
#include <iostream>


using namespace std;

class FunzioneBase{
public:
  virtual double Eval(double x) const = 0;
};



class Fun: public FunzioneBase{
public:
	Fun() {};
	~Fun(){};	
	double Eval(double x) const {return pow(x,3) * log( sqrt(M_E+x*x) );}
};

class Fun2: public FunzioneBase{
public:
	Fun2() {};
	~Fun2(){};	
	double Eval(double x) const {
		if(x >= 2 || x <= -2){
			cout << "x fuori dal dominio" << endl;
			exit(-1);
		}
		else return pow( 4 - x*x,-0.5);
	}
};

template <typename T> T CalcolaMedia( const vector<T> & v ) {

	T accumulo = 0;

	if ( v.size() == 0 ) return accumulo;

	for ( int k = 0 ; k < v.size() ; k++ ) accumulo += v[k] ;
  
	return accumulo / T ( v.size() ) ;
  
}

template <typename T> T CalcolaVarianza( const vector<T> & v){

	T varianza=0;
	T mean = CalcolaMedia(v);
	if ( v.size() == 0 ) return varianza;

	for ( int k = 0 ; k < v.size(); k++ ) varianza += pow(v[k] -mean , 2);
  
	return  varianza / T ( v.size() );
  
}

#endif