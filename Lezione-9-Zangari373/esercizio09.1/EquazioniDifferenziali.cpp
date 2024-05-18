#include "EquazioniDifferenziali.h"
#include <cassert>
#include <cmath>
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


vector<double> OscillatoreArmonico::Eval(double t, const std::vector<double> &a) const {
  vector<double> f {a[1], -m_omega0*m_omega0*a[0]};
  return f;
}

vector<double> Eulero::Passo(double t, const std::vector<double> &x, double h, FunzioneVettorialeBase *f) const {
  vector<double> y{x + (h* f->Eval(t,x))};
  return y;
}