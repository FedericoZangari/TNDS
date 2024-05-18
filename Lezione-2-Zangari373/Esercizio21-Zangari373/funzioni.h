#ifndef __funzioni__
#define __funzioni__

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <math.h>
#include "Vettore.h"

using namespace std;

Vettore Read( const char* , int) ;

double CalcolaMedia( const Vettore & ) ;
double CalcolaVarianza( const Vettore & ) ;
double CalcolaMediana( Vettore ) ;

void Print( const Vettore & , const char* ) ;
void Print( const Vettore & ) ;

void selection_sort( Vettore & );

#endif
