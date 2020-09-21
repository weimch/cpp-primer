#include <iostream>

int main() {
  int ix[10];
  for (unsigned i = 0; i < 10; i ++) {
    ix[i] = i;
  }
  for (auto i : ix) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}