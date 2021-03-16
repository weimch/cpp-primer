#include <iostream>
#include <vector>

template<typename T>
void printVec(const T& vec) {
  for (typename T::size_type i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> vec{1, 2, 3, 4};
  printVec(vec);
  return 0;
}
