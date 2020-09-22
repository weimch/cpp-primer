#include <iostream>
#include <vector>

int main() {
  std::vector<int> ivec{1,2,3,4,5};
  for (auto &i : ivec) {
    std::cout << ((i & 0x1 == 1) ? i * 2 : i) << " ";
  }
  std::cout << std::endl;
}