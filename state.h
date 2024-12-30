#ifndef STATE_H
#define STATE_H

#define DEFAULT_KD 0.1
#define DEFAULT_KV 0.1

namespace cds {
  class State {
    public:
      State(float kv=DEFAULT_KV, float kd=DEFAULT_KD);
      ~State();

    private:
      // configuration parameters
      float* m_q;
      float* m_q_dot;

      // constraint jacobian
      float* m_j;
      float* m_j_dot;

      // constraint value
      float* m_c;
      float* m_c_dot;

      // applied force 
      float* f_a;

      // constrained force
      float* f_c; 

      // distance and velocity damping values;
      float m_kd, m_kv;
  };
}

#endif
