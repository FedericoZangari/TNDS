#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

#include "funzioni.h"

int main( int argc , char** argv ) {

  if ( argc < 4 ) {
    cout << "Uso del programma : " << argv[0] << " <n_data> <input_filename> <output_filename> " << endl;
    return -1 ;
  }  
  
	int ndata = atoi(argv[1]);
	char * filename = argv[2];
	char * outputname = argv[3];

	vector<double> v = Read<double>( filename , ndata );
	//vector<double> v = ReadAll<double>( filename );

	cout << "Dati caricati" << endl;
	Print<double>( v );

	cout << setw(11) << "Media = " << CalcolaMedia<double>( v  ) << endl;
	cout << setw(11) << "Varianza = " << CalcolaVarianza<double>( v  ) << endl;
	cout << setw(11) << "Mediana = " << CalcolaMediana<double>( v ) << endl; 

	cout << "Dati ordinati " << endl;
	sort(v.begin(),v.end());
	Print<double>( v );

	Print<double>( v, outputname ) ;
  
	return 0;
}
