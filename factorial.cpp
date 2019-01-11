#include <cstdint>
#include <iostream>
#include "cpp.tmp.hpp"

int fatorial(int n) { return n == 0 ? 1 : n * fatorial(n - 1); }

int main() {
  for (int i = 0; i < kLOOP_TIMES; i++) {
    fatorial(10);
  }

  return 0;
}