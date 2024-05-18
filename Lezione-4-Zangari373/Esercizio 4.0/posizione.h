#include <iostream>

using namespace std;

class posizione{
	public:
		posizione() { m_x = 0; m_y = 0; m_ex = 0; m_ey = 0;}
		posizione(double x, double y, double ex, double ey) { m_x = x; m_y = y; m_ex = ex; m_ey = ey; }

		double getx() {return m_x;};
		double gety() {return m_y;};
		double getex() {return m_ex;};
		double getey() {return m_ey;};

		void setx(double x) {m_x = x;} ;
		void sety(double y) {m_y = y;} ;
		void setex(double ex) {m_ex = ex;} ;
		void setey(double ey) {m_ey = ey;} ;

	private:
		double m_x , m_y , m_ex, m_ey;
};
