#ifndef __particella_h__
#define __particella_h__

class Particella{

public:
	Particella();
	Particella(double m, double c);

	~Particella();

	double GetMassa() const { return m_massa; };
	double GetCarica() const { return m_carica; };
	void Print() const;

protected:
	double m_massa, m_carica;
};

#endif
