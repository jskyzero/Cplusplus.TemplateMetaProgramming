// TODO: make fraction symbol complete

#include <cassert>
#include <iostream>

typedef int TYPE;

template <TYPE x_, TYPE y_>
struct Pair {
  static const TYPE x = x_;
  static const TYPE y = y_;
};

template <TYPE x, TYPE y>
struct GCD {
  static const TYPE result = GCD<y, x % y>::result;
};

template <TYPE x>
struct GCD<x, 0> {
  static const TYPE result = x;
};

template <TYPE x_, TYPE y_>
struct Fraction {
  static const TYPE gcd = GCD<x_, y_>::result;
  typedef Pair<x_ / gcd, y_ / gcd> result;
  static const TYPE x = result::x;
  static const TYPE y = result::y;
};

template <TYPE num, typename fraction>
struct ScalarMultiplication {
  // ugly version
  // static const TYPE x = num * fraction::x;
  // static const TYPE y = fraction::y;
  // a better way
  typedef Fraction<num * fraction::x, fraction::y> result;
};

template <typename fraction1, typename fraction2>
struct FractionMultiplication {
  typedef Fraction<fraction1::x * fraction2::x, fraction1::y * fraction2::y>
      result;
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
  typedef FractionMultiplication<x, result>::result result2;

  Print<result2>();
  GCD_TEST();
}
