#ifndef __puntomateriale_h__
#define __puntomateriale_h__

#include "Particella.h"
#include "Posizione.h"
#include "CampoVettoriale.h"

class PuntoMateriale: public Posizione, Particella{

public:
	PuntoMateriale();
	PuntoMateriale(const Posizione&);
	PuntoMateriale(const Posizione&, const Particella&);
	PuntoMateriale(double x, double y, double z, double c, double m);

	~PuntoMateriale();

	CampoVettoriale CampoElettrico( const Posizione&) const;
	CampoVettoriale CampoGravitazionale( const Posizione&) const;



};

#endif