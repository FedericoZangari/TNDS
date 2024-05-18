#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

#include "funzioni.h"

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

  double * data = ReadDataFromFile ( filename, ndata ) ;

  // Visualizzo dati caricati 

  cout << "Dati caricati:" << endl;
  Print(data, ndata);

  // Calcolo la media e la varianza

  //cout << "Media = " << "\t" << CalcolaMedia( data , ndata ) << endl;
  cout << setw(10) << "Media =" << "\t" << CalcolaMedia_improved( data , ndata ) << endl;
  //cout << "Varianza = " << "\t" << CalcolaVarianza( data , ndata ) << endl;
  cout << setw(10) << "Varianza =" << "\t" << CalcolaVarianza_improved( data , ndata ) << endl;

  // Calcola la mediana
  
  cout << setw(10) << "Mediana =" << "\t" << CalcolaMediana( data , ndata ) << endl;
  
  // Visualizzo dati ordinati

  cout << "Dati ordinati:" << endl;
  selection_sort( data, ndata);
  Print(data, ndata);

  // Stampo dati ordinati su file
  Print( outputname, data, ndata ) ;

  delete[] data;
  return 0;
}