#include <algorithm>    // for std::min
#include <iostream>     // for std::cout
#include <vector>       // for std::vector
#include "cpp.tmp.hpp"  // for kLOOP_TIMES

std::vector<int>& addVector(std::vector<int>& left,
                            const std::vector<int>& right) {
  size_t lenth = std::min(left.size(), right.size());
  for (size_t i = 0; i < lenth; i++) {
    left[i] += right[i];
  }
  return left;
}

int main() {
  for (int i = 0; i < kLOOP_TIMES; i++) {
    const int* array = kARRAY;
    const int length = sizeof(kARRAY) / sizeof(int);
    std::vector<int> left = std::vector<int>(array, array + length);
    std::vector<int> right = std::vector<int>(array, array + length);
    left = addVector(left, right);
  }
  return 0;
}
