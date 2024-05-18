#ifndef __posizione_h__
#define __posizione_h__

class Posizione{
	public:
		Posizione();
		Posizione(double x, double y, double z);

		~Posizione();

		void setX(double x) {m_x = x;};
		void setY(double y) {m_y = y;};
		void setZ(double z) {m_z = z;};

		double getX() const;
		double getY() const;
		double getZ() const;

		double getTheta() const;
		double getPhi() const;
		double getR() const;

		double getRho() const;
		
		double Distanza(const Posizione& ) const;
	
	protected:
		double m_x, m_y, m_z;
};

#endif