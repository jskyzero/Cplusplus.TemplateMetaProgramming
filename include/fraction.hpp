#include <cassert>   // for assert
#include <iostream>  // for std::cout
#include <string>    // for std::string

typedef int TYPE;

template <TYPE x_, TYPE y_>
struct Pair {
  static const TYPE x = x_;
  static const TYPE y = y_;
};

template <TYPE x>
struct Abs {
  static const TYPE result = x > 0 ? x : -x;
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
  static const TYPE gcd = GCD<Abs<x_>::result, Abs<y_>::result>::result;
  //   x_  y_  x  y
  //   +   +   +  +
  //   +   -   -  +
  //   -   +   -  +
  //   -   -   +  +
  static const TYPE sign = y_ < 0 ? -1 : 1;
  static const TYPE x = sign * x_ / gcd;
  static const TYPE y = Abs<y_>::result / gcd;
};

template <typename f1, typename f2>
struct Addition {
  typedef Fraction<f1::x * f2::y + f1::y * f2::x, f1::y * f2::y> result;
};

template <typename f1, typename f2>
struct Subtraction {
  typedef Fraction<f1::x * f2::y - f2::x * f1::y, f1::y * f2::y> result;
};

template <typename f1, typename f2>
struct Multiplication {
  typedef Fraction<f1::x * f2::x, f1::y * f2::y> result;
};

template <TYPE num, typename f>
struct ScalarMultiplication {
  // ugly version
  // static const TYPE x = num * fraction::x;
  // static const TYPE y = fraction::y;
  // a better way
  // typedef Fraction<num * fraction::x, fraction::y> result;
  typedef Fraction<num, 1> f_;
  typedef typename Multiplication<f, f_>::result result;
};

template <typename f1, typename f2>
struct Division {
  typedef Fraction<f2::y, f2::x> f2_;
  // here should add a typename before the Multiplication
  typedef typename Multiplication<f1, f2_>::result result;
};

template <typename fraction>
std::string FractionToString() {
  return "( " + std::to_string(fraction::x) + " / " + std::to_string(fraction::y) +
         " )";
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
  GCD_TEST();

  typedef Fraction<1, -3> x;
  typedef Fraction<-1, 2> y;

  std::cout << std::endl;
  std::cout << "x     = " << FractionToString<x>() << std::endl;
  std::cout << "y     = " << FractionToString<y>() << std::endl;
  std::cout << "x + y = " << FractionToString<Addition<x, y>::result>()
            << std::endl;
  std::cout << "x - y = " << FractionToString<Subtraction<x, y>::result>()
            << std::endl;
  std::cout << "x * y = " << FractionToString<Multiplication<x, y>::result>()
            << std::endl;
  std::cout << "3 * x = "
            << FractionToString<ScalarMultiplication<3, x>::result>()
            << std::endl;
  std::cout << "x / y = "
            << FractionToString<Division<x, y>::result>()
            << std::endl;
}
