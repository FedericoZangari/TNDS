#include "Esperimento.h"
#include <cmath>

Esperimento::Esperimento() :
  m_ma(150), m_sigma_ma(2),
  m_m(25), m_sigma_m(2),
  m_ca(1),
  m_Ta(16.1), m_sigma_Ta(0.2),
  m_mc(27.737),
  m_Tc(90.6), m_sigma_Tc(0.4),
  m_Te(17.2), m_sigma_Te(0.2)
{}

void Esperimento::Esegui(){
  m_ma_mis = m_rgen.Gauss(m_ma, m_sigma_ma);
  m_m_mis = m_rgen.Gauss(m_mc, m_sigma_m);
  m_Ta_mis = m_rgen.Gauss(m_Ta, m_sigma_Ta);
  m_Tc_mis = m_rgen.Gauss(m_Tc, m_sigma_Tc);
  m_Te_mis = m_rgen.Gauss(m_Te, m_sigma_Te);

  m_c_mis = ( (m_ma_mis + m_m_mis) * m_ca * (m_Te_mis - m_Ta_mis) ) / ( m_mc * (m_Tc_mis - m_Te_mis) );
}

