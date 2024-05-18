#pragma once

#include "VectorOperations.h"
#include <cmath>
#include <vector>

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


class CalorimetroIdeale : public FunzioneVettorialeBase {
public:
  CalorimetroIdeale(double k1, double k2, double t10, double t20) {
    m_k1 = k1;
    m_k2 = k2;
    m_T10 = t10;
    m_T20 = t20;
  };
  std::vector<double> Eval(double t, const std::vector<double> &a) const override;

private:
  double m_k1;
  double m_k2;
  double m_T10;
  double m_T20;
};


class CalorimetroReale : public FunzioneVettorialeBase {
public:
  CalorimetroReale(double k1, double k2, double k3, double t10, double t20) {
    m_k1 = k1;
    m_k2 = k2;
    m_k3 = k3;
    m_T10 = t10;
    m_T20 = t20;
  };
  std::vector<double> Eval(double t, const std::vector<double> &a) const override;

private:
  double m_k1;
  double m_k2;
  double m_k3;
  double m_T10;
  double m_T20;
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
