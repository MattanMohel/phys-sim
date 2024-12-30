#ifndef MATRIX_H
#define MATRIX_H

// util class for matrix operations on pointer data 

namespace cds::mat {
  class Matrix {
    Matrix(int h, int w);
    
    void alloc(int h, int w);
    void mul(Matrix &rhs, Matrix* target);
    
    private:
      // matrix scalar data 
      float* m_data;
      
      // dimensions 
      int m_h;
      int m_w;

      // max capacity
      int m_cap = 0;
  };
}

#endif
