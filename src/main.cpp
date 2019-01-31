#include "test.hpp"
#include "factorial.hpp"
#include "fraction.hpp"
#include "list.hpp"

int main() {
 
  // template part
  //
  TypeTraits_TEST();
  Property_TEST();

  // template metaprogramming part
  // 
  Factorial_Part();
  Fraction_Part();
  List_Part();

  return 0;
}
