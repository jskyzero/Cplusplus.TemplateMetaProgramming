#include <iostream>  // for std::cout
#include "test.hpp"
#include "type-traits.hpp"

struct SomeStruct {
  int SomeMember;
};

void TypeTraits_TEST() {
  assert_equal(TYPE_NAME(int), TYPE_NAME(int));
  assert_equal(
      TYPE_NAME(int),
      TYPE_NAME(GetMemPtrType<decltype(&SomeStruct::SomeMember)>::Result));
  assert_equal(
      TYPE_NAME(SomeStruct),
      TYPE_NAME(GetMemPtrClass<decltype(&SomeStruct::SomeMember)>::Result));
  std::cout << "Pass type-traits Test" << std::endl;
}


int main() {
  TypeTraits_TEST();

  return 0;
}
