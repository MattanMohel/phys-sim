#include <SDL2/SDL.h>
#include <iostream>
#include "renderer.h"
#include "test_obj.h"
#include "matrix.h"

int main (int argc, char** args) {
  cds::mat::Matrix m1(2, 2);
  cds::mat::Matrix m2(2, 3);
  cds::mat::Matrix m3(2, 3);

  m1.set(0, 0, 1);
  m1.set(1, 0, 3);
  m1.set(0, 1, 4);
  m1.set(1, 1, 5);

  m2.set(0, 0, 1);
  m2.set(1, 0, 3);
  m2.set(2, 0, 4);
  m2.set(0, 1, 6);
  m2.set(1, 1, 7);
  m2.set(2, 1, 8);

  m1.mul(m2, &m3);

  std::cout << m3.to_string();
  
  cds::rend::Renderer rend(480, 640);
  cds::rend::TestObj* obj = new cds::rend::TestObj();
  rend.push_obj(obj);

  rend.print_errors();

  //rend.entry();

  return 0;
}
