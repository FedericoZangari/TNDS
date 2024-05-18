#include "funzioni.h"

double CalcolaMedia( double * data , int size ) {
  double media=0;
  for ( int k = 0 ; k < size ; k++ ) media+= data[k];
  
  media = media / size;
  
  return media ;
}

double CalcolaVarianza( double * data , int size )
{
  double varianza=0;
  for ( int k = 0 ; k < size ; k++ ) varianza += (data[k] - CalcolaMedia(data, size))*(data[k] - CalcolaMedia(data, size));

  varianza = varianza / size;
  
  return varianza ;
  
}
                                 
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
  if(size%2 == 0) mediana = (vcopy[size/2 -1] + vcopy[size/2 ])/2;
  delete [] vcopy;
  return mediana;
} 

