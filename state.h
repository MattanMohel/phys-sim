#ifndef STATE_H
#define STATE_H

#define DEFAULT_KD 0.1
#define DEFAULT_KV 0.1

namespace cds {
  class State {
    public:
      State(float kv=DEFAULT_KV, float kd=DEFAULT_KD);
      ~State();

      void init(int parameters, int constraints);

      // configuration parameters
      float* m_q     = nullptr;
      float* m_q_dot = nullptr;

      // constraint jacobian
      float* m_j     = nullptr;
      float* m_j_dot = nullptr;

      // constraint value
      float* m_c     = nullptr;
      float* m_c_dot = nullptr;

      // applied force 
      float* m_f = nullptr;

      // distance and velocity damping values;
      float m_kd, m_kv;

    private:
      bool m_init = false;
  };
}

#endif
