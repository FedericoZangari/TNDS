#include <iostream>
#include <fstream>
#include <cstdlib>

#include "funzioni.h"
using namespace std;
// =====================================================================
// incomincia il programma principale 
// =====================================================================

int main ( int argc , char** argv) {

  if ( argc < 3 ) {
    cout << "Uso del programma : " << argv[0] << " <n_data> <filename> " << endl;
    return -1 ;
  }
  
  int ndata = atoi(argv[1]);
  char * filename = argv[2];

  // carico i dati da file

  double * data = ReadDataFromFile ( filename, ndata ) ;

  // Visualizzo dati caricati 

  cout << "Dati caricati:" << endl;
  for ( int k = 0 ; k < ndata ; k++ ) cout << data[k] << endl;

  // Calcolo la media

  cout << "Media = " << CalcolaMedia( data , ndata ) << endl;
  cout << "Varianza = " << CalcolaVarianza( data , ndata ) << endl;

  // Calcola la mediana
  
  cout << "Mediana = " << CalcolaMediana( data , ndata ) << endl;
  
  // Visualizzo dati ordinati
  selection_sort( data, ndata);
  for (int k =0 ; k <ndata ;k++ ) cout << data[k] << endl;

  delete[] data;
  return 0;

}






