#include "state.h"

namespace cds {
  State::State(float kv, float kd) : m_kd(kd), m_kv(kv) {};
  
  State::~State() { 
    if (!m_init) return;
    delete[] m_q;
    delete[] m_q_dot;
    delete[] m_c;
    delete[] m_c_dot;
    delete[] m_j;
    delete[] m_j_dot;
    delete[] m_f;
  }

  void State::init(int parameters, int constraints) {
    m_q = new float(parameters);
    m_q_dot = new float(parameters);

    m_c = new float(constraints);
    m_c_dot = new float(constraints);

    m_j = new float(constraints*parameters);
    m_j_dot = new float(constraints*parameters);

    m_f = new float(parameters);

    m_init = true;
  }
}
