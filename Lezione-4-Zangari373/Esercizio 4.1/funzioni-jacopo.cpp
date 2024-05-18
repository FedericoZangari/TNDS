#include <iostream>
#include <fstream> 
#include <vector>
#include "TGraph.h"
#include "TApplication.h"
#include "cmath"
using namespace std;

// =====================================================================

template <typename T> void Print( const vector<T> & v ) {
  for (unsigned int i=0; i<v.size(); i++) cout << v[i] << endl;
};

#include <iostream>
#include <fstream> 
#include <cmath>
#include <vector>      
#include <algorithm>   

using namespace std;


template <typename T> void Print( const vector<T> & v  , const char* filename ) {
 
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<endl;
  	}
}


 vector<double> Read(const char* filename ) {

	
	ifstream i(filename);
	if(!i){
		cout<<"Impossibile aprire il file"<<endl;
		exit(-1);
	}
	vector<double> p;
	for(;;){
		
		double a;
		if(i.eof()){
			cout<<"lettura file completata"<<endl;
			break;
		}
		i>>a;
		p.push_back(a);
		

		
	}
	return p; 
};

template <typename T> vector<T> ReadAll( const char* filename ) {
	ifstream i(filename);
	if(!i){
		cout<<"Impossibile aprire il file"<<endl;
		exit(-1);
	}
	vector<T> p;
	for(;;){
		double a;
		if(i.eof()){
			cout<<"lettura file completata"<<endl;
			break;
		}
		i>>a;
		p.push_back(a);
		
	}
	return p; 
};
template <typename T> double CalcolaMedia( const vector<T> & v) {
	double accumulo = 0; 
 	 for ( int k = 0 ; k < v.size() ; k++ ) { 
    		accumulo += v[k] ;
			
  	}
  
  	return accumulo / double ( v.size()) ;
	
};


template <typename T> double CalcolaMediana( vector<T>  & v ) {

	sort( v.begin(), v.end() ); 
	double mediana;
	if(v.size() %2 == 0){
	mediana = (v[(v.size())/2-1]+v[((v.size())/2)/2]);
  	}else{
	mediana = v[(v.size())/2];
  	}

	return mediana;

};

template <typename T> double CalcolaVarianza( const vector<T> & v) {
	
	double media=CalcolaMedia(v);
  	double scarti=0;
  	for(int i=0;i<v.size();i++){
	  	scarti+=pow((v[i]-media),2);
  	}
   	return scarti/double(v.size()); ;



};
int r(double i){
	if(i-int(i)>0.5){
		return int(i+0.5);

	}else{
		return int(i);
	}
}


int ck(double q, double Q){
	return r(Q/q);
};

double S(vector<double> Q, double q){
	double Sq=0;
	for(int i=0;i<Q.size();i++){
		double k= ck(q,Q[i]);
		Sq+=pow(((Q[i]/k)-q),2);
	}
	return Sq;
}
TGraph qe(vector<double> Q){
	TGraph qe;
	double qi=1.400E-19;
	double min=1000000;
	int nmin=1000;
	for(int k=0;k<60;k++){
		qi+=1.000E-21;
		qe.SetPoint(k,qi,S(Q,qi));
		if(S(Q,qi)<min){
			min = S(Q,qi);
			nmin=k;
		}
	
	}
	cout<<"qe= "<<1.400E-19+1.000E-21*nmin<<endl;
	return qe;
}