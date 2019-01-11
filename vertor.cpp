#include <iostream> // for std::cout
#include <vector> // for std::vector
#include <algorithm>  // for std::min


std::vector<int> & addVector(std::vector<int> & left, std::vector<int> & right) {
  size_t lenth = std::min(left.size, right.size);
  for (size_t i = 0; i < lenth; i++) {
    left[i] += right[i];
  }
  return left;
}


int main() {

}