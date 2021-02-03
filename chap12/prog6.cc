#include <iostream>
#include <vector>

std::vector<int>* getVecPtr() {
  return new std::vector<int>{1, 2, 3};
}

int main() {
  std::vector<int>* vptr = getVecPtr();
  for (const auto &e : *vptr) {
    std::cout << e << std::endl;
  }
  delete vptr;
}
