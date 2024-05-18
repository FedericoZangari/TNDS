#ifndef __funzioni_h__
#define __funzioni_h__

#include <math.h>
#include <vector>
#include <iostream>
#include<fstream>
using namespace std;




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

template <typename T> T Correlazione( const vector<T> & x, const vector<T> & y){

	T correlazione=0;
	T meanx = CalcolaMedia(x);
	T meany = CalcolaMedia(y);
	T sigmax = sqrt(CalcolaVarianza(x));
	T sigmay = sqrt(CalcolaVarianza(y));
	
	if ( x.size() == 0 || y.size() == 0) return correlazione;
	if ( x.size() !=  y.size() ){
		cout << "vectors size's is not equal" << endl;
		exit(-1);
	}

	for ( int k = 0 ; k < x.size(); k++ ) correlazione += x[k] * y[k];
  
	return  (correlazione / T (x.size()) - meanx*meany) / (sigmax* sigmay);
  
}

template <typename T> vector<T> ReadAll( const char* Filename ) {

	vector<T> data;
	ifstream f(Filename);

	if(!f){
  		cerr <<"Error: cannot open file " <<endl;
		exit(0);
	}
  	else{  
		for (;;){
      			T val ;
				f >> val;
      			if(f.eof()){
	     			cout << "End of file reached " << endl;
	     			break;
      			}
				data.push_back( val );
  		}
  	}
	f.close();

	return data;
}

#endif