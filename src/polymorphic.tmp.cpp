#include <iostream>     // for std::cout
#include "cpp.tmp.hpp"  // for kLOOP_TIMES

template <typename Derived>
struct Base {
  void interface() {
    static_cast<Derived *>(this)->implementation();
  }
};

struct Derived : Base<Derived> {
  void implementation() {
    int x = 2;
  }
};

int main() {
  for (int i = 0; i < kLOOP_TIMES; i++) {
    Base<Derived> * base_ptr = new Derived();
    base_ptr->interface();
    delete base_ptr;
  }
  return 0;
}
