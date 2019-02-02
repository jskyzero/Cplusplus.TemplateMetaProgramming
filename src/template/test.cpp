#include <iostream>  // for std::cout
#include "property.hpp"
#include "test.hpp"
#include "type-traits.hpp"

template<typename Type_A, typename Type_B>
void assert_equal(Type_A left, Type_B right) {
  assert(left == right);
}

template<>
void assert_equal(const char * left, const char * right) {
  assert(strcmp(left, right) == 0);
}

void TypeTraits_TEST() {
  assert_equal(TYPE_NAME(int), TYPE_NAME(int));
  assert_equal(
      TYPE_NAME(int),
      TYPE_NAME(GetMemTypeFromMemPtr<decltype(&SomeStruct::SomeMember)>::Result));
  assert_equal(
      TYPE_NAME(SomeStruct),
      TYPE_NAME(GetClassTypeFromMemPtr<decltype(&SomeStruct::SomeMember)>::Result));

  std::cout << "Pass type-traits test" << std::endl;
}

void Property_TEST() {
  SomeClass sc;
  auto prop = Property<SomeClass, int>();
  prop.Bind(&SomeClass::SomeMember);
  prop.Set(sc, 10);

  assert_equal(sc.SomeMember, 10);

  std::cout << "Pass property test" << std::endl;
}
