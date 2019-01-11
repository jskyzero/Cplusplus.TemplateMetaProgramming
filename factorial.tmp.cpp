#include <cstdint>
#include <iostream>

template <int N>
struct Factorial {
  enum { value = N * Factorial<N - 1>::value };
};

template <>
struct Factorial<0> {
  enum { value = 1 };
};


int main() {
  for (int i = 10000000; i > 0; i--) {
    // fatorial(10);
    int x = Factorial<10>::value;
  }

  return 0;
}