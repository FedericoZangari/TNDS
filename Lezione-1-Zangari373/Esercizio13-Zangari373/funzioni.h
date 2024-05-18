#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <iomanip>
using namespace std;

double CalcolaMedia( double * , int ) ;
double CalcolaVarianza( double * , int ) ;

double CalcolaMedia_improved( double * , int ) ;
double CalcolaVarianza_improved ( double * , int ) ;
double CalcolaMediana( double * , int ) ;

double * ReadDataFromFile ( const char*  , int ) ;

void scambiaByValue(double , double ) ;
void scambiaByRef(double &, double &) ;
void scambiaByPointer(double *, double *) ;

void selection_sort( double * , int );

void Print ( const char* , double * , int ) ;
void Print (double * , int);