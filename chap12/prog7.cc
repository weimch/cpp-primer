#include <iostream>
#include <vector>
#include <memory>

std::shared_ptr<std::vector<int>> getVecPtr() {
  return std::make_shared<std::vector<int>>(std::vector<int>{1, 2, 3, 4});
}

int main() {
  auto vptr = getVecPtr();
  for (const auto &e : *vptr) {
    std::cout << e << std::endl;
  }
}
