#include "Posizione.h"
#include <cmath>
	
Posizione::Posizione(){};

Posizione::Posizione(double x, double y, double z){
	m_x = x;
	m_y = y;
	m_z = z;
};
Posizione::~Posizione(){};

double Posizione::getX() const{
	return m_x;
};

double Posizione::getY() const{
	return m_y;
};

double Posizione::getZ() const{
	return m_z;
};

double Posizione::getTheta() const{
	return acos(m_z/getR());
};

double Posizione::Posizione::getPhi() const{
	return atan2(m_y, m_x);
};

double Posizione::getR() const{
	return sqrt(m_x*m_x + m_y*m_y + m_z*m_z);
};

double Posizione::getRho() const{
	return sqrt(m_x*m_x + m_y*m_y);
};
double Posizione::Distanza(const Posizione& p) const{
	return sqrt(pow(getX()-p.getX(),2) + pow(getY()-p.getY(),2) + pow(getZ()-p.getZ(),2));
};

