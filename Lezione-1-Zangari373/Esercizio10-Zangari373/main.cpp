#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main ( int argc, char** argv ) {

  if ( argc < 2 ) {
    cout << "Uso del programma : " << argv[0] << " <n_data> <filename> " << endl;
    return -1 ;
  }
  int ndata = atoi(argv[1]);
  double* data = new double[ndata];
  char * filename = argv[2];
  ifstream f(filename);
  ofstream o("output.dat");

  if(!f){
  cout <<"Error" <<endl; 
  return -1; 
  } else{
    for ( int k = 0 ; k < ndata ; k++ ){
      f >> data[k];
      if(f.eof()){
	      cout << "end of file reached" << endl;
	      exit(0);
      }
    }
  }
  f.close();

  cout << "Dati letti: " << endl;
  for ( int k = 0 ; k < ndata ; k++ ) cout << data[k] << endl; 
   
  // [ ... 2) calcolo la media e la varianza degli elementi caricati ... ]
  double media=0;
  double varianza=0;

  for ( int k = 0 ; k < ndata ; k++ ) media += data[k];
  
  media = media / ndata;

  for ( int k = 0 ; k < ndata ; k++ ) varianza += (data[k] - media)*(data[k] - media);

  varianza = varianza / ndata;
  cout << "Media =  " << media << "   Varianza = " << varianza << endl; // 

  //  calcola la mediana : prima creo una copia del vettore di partenza  

  double * vcopy = new double[ndata];
  for ( int k = 0 ; k < ndata ; k ++ ) vcopy[k] = data[k];
  
  // [ ... 3) poi riordino gli elementi del vettore copia dal minore al maggiore ... ]
  for (int i = 0; i < ndata-1; i++){
	  for (int j = i+1; j < ndata; j++){
		  if(vcopy[i] > vcopy[j]){
			  double tmp = vcopy[i];
			  vcopy[i] = vcopy[j];
			  vcopy[j] = tmp;
		  }
	  }
  }
  cout << "Dati ordinati in ordine crescente: " << endl;
  for ( int k = 0 ; k < ndata ; k++ ) cout << vcopy[k] << endl; // dopo averli riordinati visualizzo

  // [ ... 4) poi prendo il valore centrale ( ndata dispari ) o la media tra i due centrali

  double mediana;

  if(ndata%2 == 1) mediana = vcopy[ndata/2];
  else  mediana = (vcopy[ndata/2 -1] + vcopy[ndata/2 ])/2.;

  cout << "Mediana = " << mediana << endl; // stampa la mediana calcolata
                                                                   
  
                                                               
  // [ ... 5) scrivo i dati riordinati su un file ... ]
  for ( int k = 0 ; k < ndata ; k++ ) o << vcopy[k] << endl; 
  o.close();

  delete [] vcopy ;
  delete [] data;
  
  return 0;

}
