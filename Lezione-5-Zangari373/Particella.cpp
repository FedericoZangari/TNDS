#include "Particella.h"
#include <iostream>

using namespace std;
	
Particella::Particella(){};

Particella::Particella(double m, double c){
	m_massa = m;
	m_carica = c;
};
Particella::~Particella(){};

void Particella::Print() const{
	cout << "Particella: m = " << m_massa << " q = " << m_carica << endl;
}