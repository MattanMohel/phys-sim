#include "matrix.h"
#include "stdlib.h"

namespace cds::mat {
  Matrix::Matrix(int h, int w) : m_h(h), m_w(w), m_cap(h*w) {
    m_data = new float(w*h);
  }

  float Matrix::get(int x, int y) {
    return m_data[x + m_w * y];
  }

  void Matrix::set(int x, int y, float val) {
    m_data[x + m_w * y] = val;
  }

  std::string Matrix::to_string() {
    std::string res = "";
    for (int y = 0; y < m_h; y++) {
      for (int x = 0; x < m_w; x++) {
        res += std::to_string(get(x, y));
        res += " ";
      }
      res += "\n";
    }

    return res;
  }

  void Matrix::alloc(int h, int w) {
    if (h*w >= m_cap) {
      delete m_data;
      m_data = new float(h*w);
      m_cap = h*w;
    } 

    m_h = h;
    m_w = w;
  }

  void Matrix::mul(Matrix &rhs, Matrix* target) {
    // assert width = rhs height

    for (int x = 0; x < rhs.m_w; x++) {
      for (int y = 0; y < m_h; y++) {
        float prod = 0;
        for (int i = 0; i < m_w; i++) {
          prod += get(i, y) * rhs.get(x, i);
        }
        target->set(x, y, prod);
      }
    }
  }

  void Matrix::add(Matrix &rhs, Matrix* target) {
    // assert dimensions 

    for (int i = 0; i < m_w; i++) {
      for (int j = 0; j < m_h; j++) {
        target->set(i, j, get(i, j) + rhs.get(i, j));
      }
    }
  }
 
  void Matrix::sub(Matrix &rhs, Matrix* target) {
    // assert dimensions 

    for (int i = 0; i < m_w; i++) {
      for (int j = 0; j < m_h; j++) {
        target->set(i, j, get(i, j) - rhs.get(i, j));
      }
    }
  }
}
