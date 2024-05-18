#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

#include "Vettore.h"
#include "funzioni.h"

int main ( int argc, char** argv ) {

	if ( argc < 4 ) {
	    cout << "Uso del programma : " << argv[0] << " <n_data> <input_filename> <output_filename>" << endl;
    	return -1 ;
	}

	int ndata = atoi(argv[1]);
	char * filename = argv[2];
	char * outputname = argv[3];

  // usiamo il contenitore Vettore per immagazzinare double 

	Vettore <double> v = Read<double>( filename , ndata );

	cout << "Dati caricati" << endl;
	Print( v );

	cout << setw(10) <<  "Media =" << "\t" << CalcolaMedia<double>( v  ) << endl;
	cout << setw(10) <<  "Varianza =" << "\t" << CalcolaVarianza<double>( v  ) << endl;
	cout << setw(10) <<  "Mediana =" << "\t" << CalcolaMediana<double>( v ) << endl;

	cout << "Dati ordinati " << endl;
	selection_sort( v );
	Print( v );
	
	Print( v, outputname ) ;

	return 0;

}


