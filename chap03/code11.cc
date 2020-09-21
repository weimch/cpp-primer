#include <iostream>

int main() {
  int array[5] = {1, 2, -4, 3, 2};
  int *pbeg = std::begin(array);
  int *pend = std::end(array);
  std::cout << "Array size is: " << pend - pbeg << std::endl;
  while (pbeg != pend && *pbeg >= 0) {
    ++pbeg;
  }
  std::cout << *pbeg << std::endl;
  return 0;
}