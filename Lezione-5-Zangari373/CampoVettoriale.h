#ifndef __campovettoriale_h__
#define __campovettoriale_h__

#include "Posizione.h"

class CampoVettoriale: public Posizione {

public:

	CampoVettoriale();
	CampoVettoriale(const Posizione&);	
	CampoVettoriale(const Posizione&, double Fx, double Fy, double Fz);
	CampoVettoriale(double x, double y, double z, double Fx, double Fy, double Fz);
	~CampoVettoriale();

	CampoVettoriale & operator += (const CampoVettoriale &);
	CampoVettoriale  operator + (const CampoVettoriale &) const;

	double GetFx() const { return m_Fx; };
	double GetFy() const { return m_Fy; };
	double GetFz() const { return m_Fz; };

	void setFx(double x) {m_Fx = x;} ;
	void setFy(double y) {m_Fy = y;} ;
	void setFz(double z) {m_Fz = z;} ;

	double Modulo();
	
private:
	double m_Fx, m_Fy, m_Fz;
};

#endif
