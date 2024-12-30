#include "constraint.h" 

namespace cds {
  void Constraint::set_id(int id) {
    m_id = id;
  }

  int Constraint::output_count() { return m_out; }
  int Constraint::input_count() { return m_in; }

  int Constraint::id() { return m_id; }
}
