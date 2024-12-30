#ifndef TEST_OBJ_H
#define TEST_OBJ_H

#include "object.h"

#define CIRCLE "res/circle.png"

namespace cds::rend {
  class TestObj : public Object {
    public:
      TestObj() : Object(CIRCLE) {
      
    }
  };
}
#endif
