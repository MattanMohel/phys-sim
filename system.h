#ifndef SYSTEM_H
#define SYSTEM_H

#include "rigidbody.h"
#include "constraint.h"
#include "state.h"

#include <vector>
#include <iostream>

namespace cds {
  class System {
    public:
      void push_rb(Rigidbody* rb);
      void push_constraint(Constraint* constraint);
      void process();

      void update(float dt);

    private:
      std::vector<Rigidbody*> m_rbs;
      std::vector<Constraint*> m_constraints;
      Output m_out;
      State m_state;


      int m_constraint_count = 0;
      int m_parameter_count = 0;
  };
}
#endif
