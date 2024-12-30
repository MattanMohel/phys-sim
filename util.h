#ifndef UTIL_H
#define UTIL_H

#define MAX_CONSTRAINT_IN  3
#define MAX_CONSTRAINT_OUT 3

namespace cds { 
  struct Output {
    float m_c[MAX_CONSTRAINT_OUT];
    float m_c_dot[MAX_CONSTRAINT_OUT];
    float m_j[MAX_CONSTRAINT_IN*MAX_CONSTRAINT_OUT];
    float m_j_dot[MAX_CONSTRAINT_IN*MAX_CONSTRAINT_OUT];
  };
}


#endif
