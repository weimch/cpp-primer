#include <iostream>

void reset(int &i) {
  i = 0;
}

int main() {
  int i = 10;
  std::cout << "Before reset: i=" << i << std::endl;
  reset(i);
  std::cout << "After reset: i=" << i << std::endl;
}
