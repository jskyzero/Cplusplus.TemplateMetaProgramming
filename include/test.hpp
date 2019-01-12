#include <cstring>
#include <cassert>  // for assert()

// TODO
// #include <type_traits> // for is_same()

void assert_equal(const char * left, const char * right) {
  assert(strcmp(left, right) == 0);
}
