#ifndef MATRIX_H
#define MATRIX_H

#include <string>

// util class for matrix operations on pointer data 

namespace cds::mat {
  class Matrix {
    public:
      Matrix(int h, int w);

      void mul(Matrix &rhs, Matrix* target);
      void add(Matrix &rhs, Matrix* target);
      void sub(Matrix &rhs, Matrix* target);
      
      float get(int x, int y);
      void set(int x, int y, float val);
      std::string to_string();

    private: 
      void alloc(int h, int w);
      
      // matrix scalar data 
      float* m_data = nullptr;
      
      // dimensions 
      int m_h;
      int m_w;

      // max capacity
      int m_cap = 0;
  };
}

#endif
