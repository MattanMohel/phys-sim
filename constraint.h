#ifndef CONSTRAINT_H
#define CONSTRAINT_H

#include "state.h"
#include "util.h"

#define MAX_IN  3
#define MAX_OUT 3

namespace cds {
  class Constraint {
    public:
      Constraint(int in, int out);
      virtual void compute(Output& out, const State& state);
      void set_id(int id);
      int id();
      int output_count();
      int input_count();

    private:
      // amount of parameter inputs
      int m_in;

      // amount of constraint outputs
      int m_out;

      int m_id = -1;
  };
}

#endif
