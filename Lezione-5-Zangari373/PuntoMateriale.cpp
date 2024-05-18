#include "Posizione.h"
#include "CampoVettoriale.h"
#include "Particella.h"
#include "PuntoMateriale.h"
#include <cmath>
#include <iostream>

double const eps_0 = 8.85418781E-12;
double const qe = 1.60217653E-19 ;
double const G = 6.674E-11 ;

using namespace std;

PuntoMateriale::PuntoMateriale(){};

PuntoMateriale::PuntoMateriale(const Posizione& p) : Posizione( p) {};

PuntoMateriale::PuntoMateriale(const Posizione& p, const Particella& part): Posizione( p), Particella(part){ };

PuntoMateriale::PuntoMateriale(double x, double y, double z, double c, double m) : Posizione( x,  y,  z), Particella(m, c) { };

PuntoMateriale::~PuntoMateriale(){};

CampoVettoriale PuntoMateriale::CampoElettrico(const Posizione & p)const{
	CampoVettoriale e(p);
	e.setFx( 1/(4*M_PI*eps_0) * m_carica *(e.getX() -m_x) / pow(Distanza(p) , 3));
	e.setFy( 1/(4*M_PI*eps_0) * m_carica *(e.getY() -m_y) / pow(Distanza(p) , 3));
	e.setFz( 1/(4*M_PI*eps_0) * m_carica *(e.getZ() -m_z) / pow(Distanza(p) , 3));

	return e;
}

CampoVettoriale PuntoMateriale::CampoGravitazionale(const Posizione & p)const{
	CampoVettoriale g(p);
	g.setFx( -G * m_massa *(g.getX() -m_x) / pow(Distanza(p) , 3));
	g.setFy( -G * m_massa *(g.getY() -m_y) / pow(Distanza(p) , 3));
	g.setFz( -G * m_massa *(g.getZ() -m_z) / pow(Distanza(p) , 3));

	return g;
}