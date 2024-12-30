#include "rigidbody.h"

namespace cds {
  Rigidbody::Rigidbody(float x, float y, float x_dot, float y_dot, float mass) 
    : m_x(x), m_y(y), m_x_dot(x_dot), m_y_dot(y_dot), m_mass(mass) 
  {}
  
  void Rigidbody::set_id(int id) {
    m_id = id;
  }

  int Rigidbody::id() { return m_id; }
}
