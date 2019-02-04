#include <iostream>     // for std::cout
#include "cpp.tmp.hpp"  // for kLOOP_TIMES

class Base {
 public:
  virtual void method() { int x = 1; }
};

class Derived : public Base {
 public:
  virtual void method() { int x = 2; }
};

int main() {
  for (int i = 0; i < kLOOP_TIMES; i++) {
    Base * base_ptr = new Derived();
    base_ptr->method();
    delete base_ptr;
  }
  return 0;
}
