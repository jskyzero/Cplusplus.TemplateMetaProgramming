// TODO: make fraction symbol complete

#include <iostream>

template <int x_, int y_>
struct Fraction {
  static const int x = x_;
  static const int y = y_;
};

template <int num, typename fraction>
struct ScalarMultiplication {
  // ugly version
  // static const int x = num * fraction::x;
  // static const int y = fraction::y;
  // a better way
  typedef Fraction<num * fraction::x, fraction::y> result;
};

template <typename fraction>
void Print() {
  std::cout << "(" << fraction::x << "/" << fraction::y << ")";
};

void Fraction_Part() {
  typedef Fraction<1, 3> x;
  typedef ScalarMultiplication<2, x>::result result;
  Print<result>();
}
