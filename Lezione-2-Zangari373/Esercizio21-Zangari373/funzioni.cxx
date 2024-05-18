#include "funzioni.h"
#include <assert.h>


Vettore Read( const char* Filename, int size){

	Vettore data(size);
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

double CalcolaMedia( const Vettore & v ) {

	double accumulo = 0;

	if ( v.GetN() == 0 ) return accumulo;

	for ( int k = 0 ; k < v.GetN() ; k++ ) { 
		accumulo += v.GetComponent(k) ;
	}
  
	return accumulo / double ( v.GetN() ) ;
  
}

double CalcolaVarianza( const Vettore & v){

	double varianza=0;
	double media = CalcolaMedia(v);

	if ( v.GetN() == 0 ) return varianza;
	else	for ( int k = 0 ; k < v.GetN(); k++ ) varianza += pow(v.GetComponent(k) -media , 2);
  
	return  varianza / double ( v.GetN() );
  
}

void selection_sort( Vettore & v){

	for (int i = 0; i < v.GetN()-1; i++){
		for (int j = i+1; j < v.GetN(); j++){
			if(v[i] > v[j]){
				v.Scambia(i, j);
			}
		}
	}
    
}

double CalcolaMediana( Vettore v){
	
	selection_sort(v);

	double mediana;

	if(v.GetN() % 2 == 1) mediana = v[v.GetN() / 2];
	else mediana = (v[v.GetN() / 2 -1] + v[v.GetN() / 2 ])/2;

	return mediana;
}

void Print ( const Vettore & v){

	for (int k =0 ; k < v.GetN() ;k++ ) cout << fixed << setprecision(5) << v.GetComponent(k) << endl;

}

void Print( const Vettore & v, const char* Filename){

	ofstream out(Filename);
	if( !out){
		cerr << "Error: cannot open file " << Filename << endl;
		exit(0);
	}
	for ( int k = 0 ; k < v.GetN() ; k++ ) out << v.GetComponent(k) << endl; 
	out.close();

}