#include <cstring>
#include <cassert>  // for assert()

// TODO
// #include <type_traits> // for is_same()

struct SomeStruct {
  int SomeMember;
};

class SomeClass {
 public:
  int SomeMember;
  SomeClass() : SomeMember(0) {}
};

template<typename Type_A, typename Type_B>
void assert_equal(Type_A left, Type_B right);

template<>
void assert_equal(const char * left, const char * right);


void TypeTraits_TEST();
void Property_TEST();
