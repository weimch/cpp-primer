#include <iostream>
#include <vector>

template<typename T>
void printVec(const T& vec) {
  auto beg = std::begin(vec), end = std::end(vec);
  for (; beg != end; ++beg) {
    std::cout << *beg << " ";
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> vec{1, 2, 3, 4};
  printVec(vec);
  return 0;
}
