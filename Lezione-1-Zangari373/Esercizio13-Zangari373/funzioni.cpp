#include "funzioni.h"

double CalcolaMedia( double * data , int size ) {
  double media=0;
  if (size == 0) return media;
  
  for ( int k = 0 ; k < size ; k++ ) media += data[k];
  
  media = media / size;
  
  return media ;
}

double CalcolaVarianza( double * data , int size ){

  double varianza=0;
  if (size == 0) return varianza;

  double media = CalcolaMedia(data, size);

  for ( int k = 0 ; k < size ; k++ ) varianza += (data[k] - media)*(data[k] - media);

  varianza = varianza / size;
  
  return varianza ;
  
}
                                 
double * ReadDataFromFile ( const char* Filename , int size  ) {
  
  double * data = new double[size];
  ifstream f(Filename);

  if(!f){
  	cerr <<"Error: cannot open file " <<endl;
	  exit(1);
  }
  else{  
  	for ( int k = 0 ; k < size ; k++ ){
      	f >> data[k];
      	if(f.eof()){
	     	  cerr << "end of file" << endl;
	     	  exit(2);
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


double CalcolaMediana ( double * vec, int size ) {
  double * vcopy = new double[size];
  for ( int k = 0 ; k < size ; k ++ ) vcopy[k] = vec[k];

  selection_sort( vcopy, size);

  double mediana;

  if(size%2 == 1) mediana = vcopy[size/2];
  else mediana = (vcopy[size/2 -1] + vcopy[size/2 ])/2;

  delete [] vcopy;
  return mediana;
} 

void Print ( const char* Filename, double * data, int size ) {
  ofstream out(Filename);

  for ( int k = 0 ; k < size ; k++ ) out << data[k] << endl; 
  out.close();

}

void Print (double * data, int size){
	for (int k =0 ; k <size ;k++ ) cout << fixed << setprecision(5) << data[k] << endl;

}


double CalcolaMedia_improved( double * data, int size){
  double media=0;
  if (size == 0) return media;
  
  for ( int k = 0 ; k < size ; k++ ){
    media = k * media / (k +1) + data[k] / (k+1);
  } 
  
  return media ;
}

double CalcolaVarianza_improved ( double * data, int size ){
    
  double varianza=0;
  if (size == 0) return varianza;

  double sumx = 0;
  double sumx2 = 0;

  for ( int k = 0 ; k < size ; k++ ){
    sumx += data[k];
    sumx2 += data[k]*data[k];
  }
  varianza = (sumx2 - sumx * sumx / size) / size;
  
  return varianza ;
  
}