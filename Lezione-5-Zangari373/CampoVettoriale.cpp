#include "Posizione.h"
#include "CampoVettoriale.h"
#include <cmath>
#include <iostream>

using namespace std;

CampoVettoriale::CampoVettoriale(){};

CampoVettoriale::CampoVettoriale(const Posizione& p) : Posizione( p) {};

CampoVettoriale::CampoVettoriale(const Posizione& p, double Fx, double Fy, double Fz): Posizione( p){
	m_Fx = Fx;
	m_Fy = Fy;
	m_Fz = Fz;
};
CampoVettoriale::CampoVettoriale(double x, double y, double z, double Fx, double Fy, double Fz) : Posizione( x,  y,  z) {
	m_Fx = Fx;
	m_Fy = Fy;
	m_Fz = Fz;
};

CampoVettoriale::~CampoVettoriale(){};

double CampoVettoriale::Modulo() {
	return sqrt(m_Fx*m_Fx + m_Fy*m_Fy + m_Fz*m_Fz);
};

CampoVettoriale & CampoVettoriale::operator += (const CampoVettoriale &v ){
	return (*this)=(*this) +v;
};

CampoVettoriale CampoVettoriale::operator + (const CampoVettoriale &v ) const{
	CampoVettoriale sum(v);
	sum.m_Fx += GetFx();
	sum.m_Fy += GetFy();
	sum.m_Fz += GetFz();
	return sum;
};