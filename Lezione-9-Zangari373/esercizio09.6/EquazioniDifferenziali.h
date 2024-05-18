#pragma once

#include "VectorOperations.h"
#include <cmath>
#include <vector>

using namespace std;

const double g = 9.81;

//////////////////////////////////////////////////////////////
// Classe astratta, Restituisce la derivata nel punto (t, x)

class FunzioneVettorialeBase {
public:
  virtual std::vector<double> Eval(double t, const std::vector<double> &x) const = 0;
};



// Classe concreta, usata nei test

class OscillatoreArmonico : public FunzioneVettorialeBase {
public:
  OscillatoreArmonico(double omega0) : m_omega0{omega0} {}
  std::vector<double> Eval(double t, const std::vector<double> &a) const override;

private:
  double m_omega0;
};


class Pendolo : public FunzioneVettorialeBase {
public:
  Pendolo(double l) : m_omega0{ sqrt(g/l) } {}
  std::vector<double> Eval(double t, const std::vector<double> &a) const override;

private:
  double m_omega0;
};

/*
class Gravitazione : public FunzioneVettorialeBase {
public:
  Gravitazione(double M, double m, double L) : m_M{M}, m_m{m}, m_L{L} {}
  std::vector<double> Eval(double t, const std::vector<double> &a) const override;

private:
  double m_M;
  double m_m;
  double m_L;
  
};*/

class Gravitazione : public FunzioneVettorialeBase {
public:
  Gravitazione(double M, double m, double L) : m_M{M}, m_m{m}, m_L{L} {}
  std::vector<double> Eval(double t, const std::vector<double> &a) const override;

private:
  double m_M;
  double m_m;
  double m_L;
  
};

class CampoEM : public FunzioneVettorialeBase {
public:
  CampoEM(double q, double m, double Ex, double Ey, double Ez, double Bx, double By, double Bz) : 
  m_q{q}, m_m{m}, m_Ex{Ex}, m_Ey{Ey}, m_Ez{Ez}, m_Bx{Bx}, m_By{By}, m_Bz{Bz} {
    B[0]={0, 0, 0, 1, 0, 0};
    B[1]={0, 0, 0, 0, 1, 0};
    B[2]={0, 0, 0, 0, 0, 1};
    B[3]={0, 0, 0, 0, m_q*m_Bz/m_m, -m_q*m_By/m_m};
    B[4]={0, 0, 0, -m_q*m_Bz/m_m, 0, m_q*m_Bx/m_m};
    B[5]={0, 0, 0, m_q*m_By/m_m, -m_q*m_Bx/m_m, 0};
    E={0, 0, 0, m_q*m_Ex/m_m, m_q*m_Ey/m_m, -m_q*m_Ez/m_m};
  }
  std::vector<double> Eval(double t, const std::vector<double> &a) const override;

private:
  double m_q;
  double m_m;
  double m_Ex, m_Ey, m_Ez;
  double m_Bx, m_By, m_Bz;
  vector<vector<double>> B;
  vector<double> E;

  
};

class OscillatoreArmonicoForzato : public FunzioneVettorialeBase {
public:
  OscillatoreArmonicoForzato(double omega0, double omega, double a) {
    m_omega0 = omega0; 
    m_omega = omega;
    m_a = a;
  };
  std::vector<double> Eval(double t, const std::vector<double> &a) const override;

private:
  double m_omega0;
  double m_omega;
  double m_a;
};



// Classe astratta per un integratore di equazioni differenziali

class EquazioneDifferenzialeBase {
public:
  virtual std::vector<double> Passo(double t, const std::vector<double> &x, double h, FunzioneVettorialeBase *f) const = 0;
};


// Classe concreta, metodo di Eulero

class Eulero : public EquazioneDifferenzialeBase {
public:
  std::vector<double> Passo(double t, const std::vector<double> &x, double h, FunzioneVettorialeBase *f) const override;
};




// Classe concreta, metodo di Runge-Kutta

class RungeKutta : public EquazioneDifferenzialeBase {
public:
  std::vector<double> Passo(double t, const std::vector<double> &x, double h, FunzioneVettorialeBase *f) const override;
};

void test_euler();
void test_runge_kutta();
