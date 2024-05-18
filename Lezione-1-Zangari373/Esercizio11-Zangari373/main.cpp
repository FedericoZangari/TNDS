#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

double CalcolaMedia( double * , int ) ;
double CalcolaVarianza( double * , int );
double CalcolaMediana ( double [] , int ) ;
double * ReadDataFromFile ( const char*  , int ) ;
void Print ( const char* , double * , int ) ;
void scambiaByValue(double , double ) ;
void scambiaByRef(double &, double &) ;
void scambiaByPointer(double *, double *) ;
void selection_sort( double * , int );

int main ( int argc , char** argv) {
  
  if ( argc < 3 ) {
    cout << "Uso del programma : " << argv[0] << " <n_data> <filename> " << endl;
    return -1 ;
  }
  
  int ndata = atoi(argv[1]);
  char * filename = argv[2];
  
  // uso una funzione per leggere gli elementi da un file

  double * data = ReadDataFromFile ( filename, ndata ) ;

  cout << "Dati letti:" << endl;
  for ( int k = 0 ; k < ndata ; k++ ) cout << data[k] << endl;

  // [... aggiungo dei cout per visualizzare il contenuto del vettore ...]

  // uso una funzione per calcolare la media e la varianza

  cout << "Media = " << CalcolaMedia( data , ndata ) << endl;

  cout << "Varianza = " << CalcolaVarianza( data , ndata ) << endl;
  
  // uso una funzione per calcolare la mediana

  cout << "Mediana = " << CalcolaMediana(data, ndata) << endl;
  
  // [ ... aggiungo dei cout per controllare il vettore riordinato ]
  selection_sort( data, ndata);
  for ( int k = 0 ; k < ndata ; k++ ) cout << data[k] << endl;
  // Scrivo i dati riordinati su file

  Print( "output.dat", data, ndata ) ;
  delete [] data;

  return 0;
}

// legge <size> elementi da <Filename> e restituisce un array

double * ReadDataFromFile ( const char* Filename , int size  ) {

  double * data = new double[size];
  ifstream f(Filename);

  if(!f){
    cout <<"Error ...." <<endl; 
    exit(0);
  } else{ 
  for ( int k = 0 ; k < size ; k++ ){
      f >> data[k];
      if(f.eof()){
	      cout << "end of file" << endl;
	      return 0;
      }
    }
  }
  f.close();

  return data;
}

void Print ( const char* Filename, double * data, int size ) {
  ofstream o(Filename);

  for ( int k = 0 ; k < size ; k++ ) o << data[k] << endl; 
  o.close();

}

// calcola la media di <size> elementi dell'array <data>

double CalcolaMedia( double * data , int size ) {
  double media=0;
  for ( int k = 0 ; k < size ; k++ ) media += data[k];
  
  media = media / size;
  
  return media ;
  
}

// calcola la varianza di <size> elementi dell'array <data>

double CalcolaVarianza( double * data , int size ) {
  double varianza=0;
  for ( int k = 0 ; k < size ; k++ ) varianza += (data[k] - CalcolaMedia(data, size))*(data[k] - CalcolaMedia(data, size));

  varianza = varianza / size;
  
  return varianza ;
  
}

// funzioni per scambiare di posto due elementi, utile per il riordinamento

void scambiaByValue(double a, double b) {
  double c=a;
  a=b;
  b=c;

}

void scambiaByRef(double &a, double &b) {
  double c=a;
  a=b;
  b=c;

}

void scambiaByPointer(double *a, double *b) {
  double c=*a;
  *a=*b;
  *b=c;

}

// algoritmo di riordinamento di un array ( selection_sort ) 

void selection_sort( double * vec , int size) {
  for (int i = 0; i < size-1; i++){
	  for (int j = i+1; j < size; j++){
		  if(vec[i] > vec[j]){
			  scambiaByRef(vec[i], vec[j]);
		  }
	  }
  }
                    
}

// Calcolo della mediana di un array <vec> di dimensione <size>. Prima si crea
// una copia dell'array, lo riordina e calcola la mediana

double CalcolaMediana ( double vec[] , int size ) {
  double * vcopy = new double[size];
  for ( int k = 0 ; k < size ; k ++ ) vcopy[k] = vec[k];

  selection_sort( vcopy, size);

  double mediana;

  if(size%2 == 1) mediana = vcopy[size/2];
  else mediana = (vcopy[size/2 -1] + vcopy[size/2 ])/2;
  
  delete [] vcopy;
  return mediana;
} 
