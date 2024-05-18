#ifndef __funzioni__
#define __funzioni__

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <math.h>
#include "Vettore.h"

using namespace std;

template <typename T> Vettore<T> Read( const char* Filename, int size){

	Vettore<T> data(size);
	ifstream f(Filename);

	if(!f){
  		cerr <<"Error: cannot open file " <<endl;
		exit(0);
	}
  	else{  
  		for ( int k = 0 ; k < size ; k++ ){
      			f >> data[k];
      			if(f.eof()){
	     			cerr << "End of file reached exiting" << endl;
	     			exit(0);
      			}
  		}
  	}
	f.close();

	return data;
}

template <typename T> T CalcolaMedia( const Vettore<T> & v ) {

	T accumulo = 0;

	if ( v.GetN() == 0 ) return accumulo;

	for ( int k = 0 ; k < v.GetN() ; k++ ) { 
		accumulo += v.GetComponent(k) ;
	}
  
	return accumulo / T ( v.GetN() ) ;
  
}

template <typename T> T CalcolaVarianza( const Vettore<T> & v){

	T varianza=0;
	T media = CalcolaMedia(v);

	if ( v.GetN() == 0 ) return varianza;
	for ( int k = 0 ; k < v.GetN(); k++ ) varianza += pow(v.GetComponent(k) -  media, 2);
  
	return  varianza / T ( v.GetN() );
  
}

template <typename T> void selection_sort( Vettore<T> & v){

	for (int i = 0; i < v.GetN()-1; i++){
		for (int j = i+1; j < v.GetN(); j++){
			if(v[i] > v[j]){
				v.Scambia(i, j);
			}
		}
	}
    
}

template <typename T> T CalcolaMediana( Vettore<T> v){
	
	selection_sort(v);

	T mediana;

	if(v.GetN() % 2 == 1) mediana = v[v.GetN() / 2];
	else mediana = (v[v.GetN() / 2 -1] + v[v.GetN() / 2 ]) / 2;

	return mediana;
}

template <typename T> void Print ( const Vettore<T> & v){

	for (int k =0 ; k < v.GetN() ;k++ ) cout << fixed << setprecision(5) << v.GetComponent(k) << endl;

}

template <typename T> void Print( const Vettore<T> & v, const char* Filename){

	ofstream out(Filename);
	if( !out){
		cerr << "Error: cannot open file " << Filename << endl;
		exit(0);
	}
	for ( int k = 0 ; k < v.GetN() ; k++ ) out << v.GetComponent(k) << endl; 
	out.close();

}

#endif