#include <iostream>  // for std::cout
#include "property.hpp"
#include "test.hpp"
#include "type-traits.hpp"

struct SomeStruct {
  int SomeMember;
};

class SomeClass {
 public:
  int SomeMember;
  SomeClass() : SomeMember(0) {}
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

void Property_TEST() {
  SomeClass sc;
  auto prop = Property<SomeClass, int>();
  prop.Bind(&SomeClass::SomeMember);
  prop.Set(sc, 10);

  assert_equal(sc.SomeMember, 10);
}

int main() {
  TypeTraits_TEST();

  return 0;
}
