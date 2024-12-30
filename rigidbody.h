#ifndef RIGIDBODY_H
#define RIGIDBODY_H

namespace cds {
  struct Rigidbody {
    Rigidbody(float x, float y, float x_dot, float y_dot, float m);
    void set_id(int id);
    int id();

    float m_x;
    float m_x_dot;
    float m_y;
    float m_y_dot;
    float m_mass;

    private:
      int m_id = -1;
  };
}

#endif
