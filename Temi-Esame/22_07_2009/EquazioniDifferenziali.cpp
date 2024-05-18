#include "EquazioniDifferenziali.h"
#include <cassert>
#include <math.h>
#include <vector>

using namespace std;



vector<double> OscillatoreArmonico::Eval(double t, const std::vector<double> &a) const {
  vector<double> f {a[1], -m_omega0*m_omega0*a[0]};
  return f;
}

vector<double> Pendolo::Eval(double t, const std::vector<double> &a) const {
  vector<double> f {a[1], -m_omega0*m_omega0 * sin(a[0])};
  return f;
}

vector<double> OscillatoreArmonicoForzato::Eval(double t, const std::vector<double> &x) const {
  vector<double> f {x[1], -m_omega0*m_omega0*x[0] -m_a*x[1] + sin(m_omega * t)};
  return f;
}

vector<double> OscillatoreElettrone::Eval(double t, const std::vector<double> &x) const {
  vector<double> f {x[1],  m_q / m_m * m_E_0 * sin(2*M_PI/m_lambda * x[0] - 2*M_PI * m_f * t)};
  return f;
}



vector<double> Eulero::Passo(double t, const std::vector<double> &x, double h, FunzioneVettorialeBase *f) const {
  vector<double> y{x + (h* f->Eval(t,x))};
  return y;
}

vector<double> RungeKutta::Passo(double t, const std::vector<double> &x, double h, FunzioneVettorialeBase *f) const {
  vector<double> k1{ f->Eval(t,x) };
  vector<double> k2{ f->Eval(t + 0.5*h , x + 0.5*h* k1 )};
  vector<double> k3{ f->Eval(t + 0.5*h , x + 0.5*h* k2 )};
  vector<double> k4{ f->Eval(t + h  ,x + h* k3 )};

  return x + h/6. * (k1 + 2.* k2 + 2.* k3 + k4);
}