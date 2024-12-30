#include "state.h"

namespace cds {
  State::State(float kv, float kd) : m_kd(kd), m_kv(kv) {};
  State::~State() { /* free data */ }
}
