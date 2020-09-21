#include <iostream>

int main() {
  int ia[3][4] = {
    {0, 1, 2, 3},
    {4, 5, 6, 7},
    {8, 9, 10, 11}
  };
  // version1
  for (auto &row : ia) {
    for (auto elem : row) {
      std::cout << elem << " ";
    }
    std::cout << std::endl;
  }
  // version2
  for (unsigned i = 0; i < 3; i ++) {
    for (unsigned j = 0; j < 4; j ++) {
      std::cout << ia[i][j] << " ";
    }
    std::cout << std::endl;
  }
  // version3
  for (auto pr=std::begin(ia); pr != std::end(ia); ++pr) {
    for (const int *pe=std::begin(*pr); pe != std::end(*pr); ++pe) {
      std::cout << *pe << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}