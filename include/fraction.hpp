// TODO: make fraction symbol complete

#include <cassert>
#include <iostream>

template <int x, int y>
struct GCD {
  static const int result = GCD<y, x % y>::result;
};

template <int x>
struct GCD<x, 0> {
  static const int result = x;
};

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
struct Simply {
  static const int gcd = GCD<fraction::x, fraction::y>::result;
  typedef Fraction<fraction::x / gcd, fraction::y / gcd> result;
};

template <typename fraction>
void Print() {
  std::cout << "(" << fraction::x << "/" << fraction::y << ")";
};

void GCD_TEST() {
  assert((GCD<0, 0>::result) == 0);
  assert((GCD<1000, 0>::result) == 1000);
  assert((GCD<0, 1000>::result) == 1000);

  assert((GCD<1000, 1>::result) == 1);
  assert((GCD<1, 1000>::result) == 1);

  assert((GCD<54, 24>::result) == 6);
  assert((GCD<24, 54>::result) == 6);

  // sames no rule about the sign
  assert((GCD<54, -24>::result) == 6);
  assert((GCD<-54, 24>::result) == -6);
  assert((GCD<-24, 54>::result) == 6);
  assert((GCD<24, -54>::result) == -6);
}

void Fraction_Part() {
  typedef Fraction<1, 2> x;
  typedef ScalarMultiplication<2, x>::result result;
  Print<result>();
  GCD_TEST();
}
