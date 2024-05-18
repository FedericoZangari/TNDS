#include "Particella.h"
#include "Elettrone.h"
#include <iostream>

using namespace std;
	

Elettrone::Elettrone() : Particella(9.1093826E-31, -1.60217653E-19){};

Elettrone::~Elettrone(){};

void Elettrone::Print() const{
	cout << "Elettrone: m = " << m_massa << " q = " << m_carica << endl;
}