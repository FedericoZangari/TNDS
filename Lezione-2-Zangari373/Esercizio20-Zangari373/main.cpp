// =====================================================================
// esercizio2.0.cxx : Esempio di codice per imparare a utilizzare la 
//                    classe vettore
// =====================================================================   

#include <iostream>
#include <fstream>
#include <cstdlib>

//#include "funzioni.h"
#include "Vettore.h"

int main ( ) {

  // costruttore senza argomenti ==>> crea un vettore di dimenione nulla 

  Vettore vnull ;
  cout << "Vettore vnull : dimensione = " << vnull.GetN() << endl;
  for ( unsigned int k = 0 ; k < vnull.GetN() ; k++ ) cout << vnull.GetComponent(k) << " " ;
  cout << endl;

  // construttore con intero : costruisco un OGGETTO di tipo vettore di lunghezza 10

  Vettore v(10);
  cout << "Vettore v : = dimensione = " << v.GetN() << endl;
  for ( unsigned int k = 0 ; k < v.GetN() ; k++ ) cout << v.GetComponent(k) << " " ;
  cout << endl;

  // anche come puntatore
  
  Vettore * vp = new Vettore(10);
  cout << "Vettore vp : = dimensione = " << vp->GetN() << endl;
  for ( unsigned int k = 0 ; k < vp->GetN() ; k++ ) cout << vp->GetComponent(k) << " " ;
  cout << endl;    

  // cambio il contenuto di v 

  for ( unsigned int k = 0 ; k < 10 ; k++ ) v.SetComponent(k,k+2);
  
  cout << "Vettore v (dopo le modifiche) : dimensione = " << v.GetN() << endl;
  for ( unsigned int k = 0 ; k < v.GetN() ; k++ ) cout << v.GetComponent(k) << " " ;
  cout << endl;  

  // visualizzo la componente 3 ( n = 2 )
  int comp = 2;
  cout << "Componente " << comp+1 << " = " << v[comp] << endl;
  v[0]=100;

  // copy constructor
  cout << endl;
  Vettore w(v);
  
  //  oppure la sintassi equivalente: Vettore w = v;
  
  cout << "Vettore w : dimensione = " << w.GetN() << endl;
  for ( unsigned int k = 0 ; k < w.GetN() ; k++ ) cout << w.GetComponent(k) << " " ;
  cout << endl;
  
  v.SetComponent(4,99);
  
  cout << "Vettore v : dimensione = " << v.GetN() << endl;
  for ( unsigned int k = 0 ; k < v.GetN() ; k++ ) cout << v.GetComponent(k) << " " ;
  cout << endl;
  
  cout << "Vettore w : dimensione = " << w.GetN() << endl;
  for ( unsigned int k = 0 ; k < w.GetN() ; k++ ) cout << w.GetComponent(k) << " " ;
  cout << endl;
  
  // Operatore di assegnazione : il vettore z e' gia' stato creato

  Vettore z(5) ;
  cout << "Vettore z : dimensione = " << z.GetN() << endl;
  for ( unsigned int k = 0 ; k < z.GetN() ; k++ ) cout << z.GetComponent(k) << " " ;
  cout << endl;
  
  z = w ;

  cout << "Vettore z : dimensione = " << z.GetN() << endl;
  for ( unsigned int k = 0 ; k < z.GetN() ; k++ ) cout << z.GetComponent(k) << " " ;
  cout << endl;
  

  return 0;

}
