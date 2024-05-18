#pragma once

#include "VectorOperations.h"
#include <cmath>
#include <vector>

const double g = 9.81;


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
  void SetOmega(double omega) { m_omega = omega;};
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
