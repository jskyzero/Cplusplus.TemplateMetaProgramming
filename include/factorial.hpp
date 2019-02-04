#include <iostream>

template<int N>
struct Factorial {
  static const int result = N * Factorial<N - 1>::result;
};

template<>
struct Factorial<0> {
  static const int result = 1;
};


void Factorial_Part() {
  std::cout << std::endl;
  std::cout << "Factorial(5) = " << Factorial<5>::result << std::endl;
}
