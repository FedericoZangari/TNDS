#include "EquazioniDifferenziali.h"
#include <cassert>
#include <math.h>
#include <vector>

using namespace std;

bool is_close(double a, double b, double epsilon = 1e-8) {
  return std::fabs(a - b) < epsilon;
}

void test_euler() {
  Eulero eulero;
  OscillatoreArmonico oa{1.0};
  const double lastt{70.0};
  const double h{0.1};
  std::vector<double> pos{0.0, 1.0};

  for (double t{}; t <= lastt; t += h) {
    pos = eulero.Passo(t, pos, h, &oa);
  }

  assert(is_close(pos[0], 19.773746013860173));
  assert(is_close(pos[1], 25.848774751522960));
}

void test_runge_kutta() {
  RungeKutta rk;
  OscillatoreArmonico oa{1.0};
  const double lastt{70.0};
  const double h{0.1};
  std::vector<double> pos{0.0, 1.0};

  for (double t{}; t <= lastt; t += h) {
    pos = rk.Passo(t, pos, h, &oa);
  }

  assert(is_close(pos[0], 0.7738501114078689));
  assert(is_close(pos[1], 0.6333611095194112));
}



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
/*
vector<double>Gravitazione::Eval(double t, const std::vector<double> &x) const {
  double G = 6.67E-11;
  vector<double> f {x[1], -G*m_M/ pow(x[0], 2) + m_L*m_L/pow(x[0], 3)/m_m/m_m };
  return f;
  {x[1],   -G*m_M/ pow(x[0],2) + m_L*m_L/pow(x[0],3)/m_m/m_m,  m_L/m_m/pow(x[0],2),  0 }
}*/

vector<double>Gravitazione::Eval(double t, const std::vector<double> &x) const {
  double G = 6.67E-11;
  vector<double> f {x[1],   -G*m_M/ pow(x[0],2) + x[0]*pow(x[3],2),  x[3],  -2*x[1]*x[3]/x[0] };
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