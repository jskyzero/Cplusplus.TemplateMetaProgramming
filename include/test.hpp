#include <cstring>
#include <cassert>  // for assert()

// TODO
// #include <type_traits> // for is_same()

template<typename Type_A, typename Type_B>
void assert_equal(Type_A left, Type_B right) {
  assert(left == right);
}

template<>
void assert_equal(const char * left, const char * right) {
  assert(strcmp(left, right) == 0);
}
