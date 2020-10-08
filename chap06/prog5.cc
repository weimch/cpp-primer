#include <iostream>

void mabs(int val) {
  std::cout << val << " abs is: " << std::abs(val) << std::endl;
}

int main() {
  mabs(-1);
  return 0;
}
