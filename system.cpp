#include "system.h"

namespace cds {
  void System::push_rb(Rigidbody* rb) {
    rb->set_id(m_rbs.size());
    m_rbs.emplace_back(rb);

    m_parameter_count += 2;
  }

  void System::push_constraint(Constraint* constraint) {
    constraint->set_id(m_constraints.size());
    m_constraints.emplace_back(constraint);
  
    m_constraint_count += constraint->output_count(); 
  }

  void System::process() {
    m_state.init(m_parameter_count, m_constraint_count); 
  }

  void System::update(float dt) {
    for (int i = 0; i < m_rbs.size(); i++) {
      m_state.m_q[2*i + 0] = m_rbs[i]->m_x;
      m_state.m_q[2*i + 1] = m_rbs[i]->m_y;
      m_state.m_q_dot[2*i + 0] = m_rbs[i]->m_x_dot;
      m_state.m_q_dot[2*i + 1] = m_rbs[i]->m_y_dot;
    }

    for (int i = 0; i < m_constraints.size(); i++) {
      m_constraints[i]->compute(m_out, m_state);
    }


  }
}
