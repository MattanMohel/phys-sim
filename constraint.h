#ifndef CONSTRAINT_H
#define CONSTRAINT_H

#include "state.h"

namespace cds {
  class Constraint {
    public:
      Constraint();

      virtual void compute(State* state);

    private:
      // amount of parameter inputs
      int m_inp_len;

      // amount of constraint outputs
      int m_out_len;

      // pointer to start of constraint data block 
      float* m_data_ptr;
  };
}

#endif
