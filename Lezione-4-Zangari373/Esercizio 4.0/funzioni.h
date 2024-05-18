#ifndef __funzioni__
#define __funzioni__

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <math.h>
#include <vector>     
#include <algorithm>  

#include "posizione.h"

#include "TH1F.h"

using namespace std;

template <typename T> vector<T> ReadAll( const char* Filename ) {

	vector<posizione> data;
	ifstream f(Filename);

	if(!f){
  		cerr <<"Error: cannot open file " <<endl;
		exit(0);
	}
  	else{  
		for (;;){
      			posizione val ;
				double a;
				f >> a;
				val.setx(a);
				double b;
				f >> b;
				val.setex(b);
				double c;
				f >> c;
				val.sety(c);
				double d;
				f >> d;
				val.setey(d);
				data.push_back( val );
      			if(f.eof()){
	     			cout << "End of file reached " << endl;
	     			break;
      			}
				
  		}
  	}
	f.close();

	return data;
}

#endif