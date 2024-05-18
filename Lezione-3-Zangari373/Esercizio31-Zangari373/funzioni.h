#ifndef __funzioni__
#define __funzioni__

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <math.h>
#include <vector>      // contenitore
#include <algorithm>   // sort di STL 
#include <iterator>
#include <numeric>

using namespace std;

template <typename T> vector<T> Read( const char* Filename, int size){

	vector<T> data;
	ifstream f(Filename);

	if(!f){
  		cerr <<"Error: cannot open file " <<endl;
		exit(0);
	}
  	
	copy_n(istream_iterator<T>(f), size, back_inserter(data));
	f.close();

	return data;
}

template <typename T> vector<T> ReadAll( const char* Filename ) {

	ifstream f(Filename);
	if(!f){
  		cerr <<"Error: cannot open file " <<endl;
		exit(0);
	}
  	
	vector<T> data ((istream_iterator<T>(f)), istream_iterator<T>());
	f.close();

	return data;
}

template <typename T> T CalcolaMedia( const vector<T> & v ) {

	T accumulo = 0;
	
	if ( v.size() == 0 ) return accumulo;

	for( auto x : v) accumulo += x;
  
	return accumulo / T ( v.size() ) ;
}

template <typename T> T CalcolaVarianza( const vector<T> & v){

	T varianza=0;
	T mean = CalcolaMedia(v);
	if ( v.size() == 0 ) return varianza;

	for ( auto x : v ) varianza += pow(x -mean , 2);
  
	return  varianza / T ( v.size() );
  
}

template <typename T> T CalcolaMediana( vector<T> v){
	
	sort(v.begin(), v.end());

	T mediana;

	if(v.size() % 2 == 1) mediana = v[v.size() / 2];
	else mediana = (v[v.size() / 2 -1] + v[v.size() / 2 ])/2;

	return mediana;
}

template <typename T> void Print ( const vector<T> & v){

	for (auto x : v) cout << fixed << setprecision(5) << x << endl;
	//for (auto it = v.begin(); it!= v.end(); it++) cout << fixed << setprecision(5) << *it << endl;

}



template <typename T> void Print( const vector<T> & v, const char* Filename){

	ofstream out(Filename);
	if( !out){
		cerr << "Error: cannot open file " << Filename << endl;
		exit(0);
	}
	for ( auto x : v ) out << x << endl; 
	out.close();

}

#endif