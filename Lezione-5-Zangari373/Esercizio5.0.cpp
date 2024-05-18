#include <iostream>
#include <cstdlib>
#include <iomanip>

#include "Posizione.h"

using namespace std;

int main ( int argc , char** argv) {

	if ( argc < 4 ) {
    	cout << "Uso del programma : " << argv[0] << " <x> <y> <z>" << endl;
    	return -1 ;
	}

	double x = atof(argv[1]);
	double y = atof(argv[2]);
	double z = atof(argv[3]);

	Posizione p(x, y, z);
	Posizione q(x+1, y+1, z+1);

	cout << "Coordinate cartesiane: " << p.getX() << ", " <<  p.getY() << ", " <<  p.getZ() << endl; 
	cout << "Coordinate sferiche: " << p.getR() << ", " <<  p.getTheta() << ", " <<  p.getPhi() << endl; 
	cout << "Coordinate cilindriche: " << p.getRho() << ", " <<  p.getPhi() << ", " <<  p.getZ() << endl; 
	cout << p.Distanza(q) << endl;
	
	return 0;
}