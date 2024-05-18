#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

#include "funzioni.h"
#include "Vettore.h"

using namespace std;

int main ( int argc , char** argv) {

	if ( argc < 4 ) {
    	cout << "Uso del programma : " << argv[0] << " <n_data> <input_filename> <output_filename>" << endl;
    	return -1 ;
	}

	int ndata = atoi(argv[1]);
	char * filename = argv[2];
	char * outputname = argv[3];

	// carico i dati da file

	Vettore data = Read ( filename, ndata ) ;		

	// Visualizzo dati caricati 

	cout << "Dati caricati" << endl;
	Print(data);
  
	// Calcolo la media e la varianza e la mediana

	cout << setw(10) <<  "Media =" << "\t" << CalcolaMedia( data ) << endl;
	cout << setw(10) <<  "Varianza =" << "\t" << CalcolaVarianza( data ) << endl;
	cout << setw(10) <<  "Mediana =" << "\t" << CalcolaMediana( data ) << endl;
  
	// Visualizzo dati ordinati

	cout << "Dati ordinati " << endl;
	selection_sort( data );
	Print( data );

	// Stampo dati ordinati su file

	Print( data, outputname ) ;
	
	return 0;
}