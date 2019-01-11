#include <cstdint>
#include <iostream>

int fatorial(int n) { return n == 0 ? 1 : n * fatorial(n - 1); }

int main() {
  for (int i = 10000000; i > 0; i--) {
    fatorial(10);
  }

  return 0;
}