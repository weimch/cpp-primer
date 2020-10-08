#include <iostream>

void swap(int &a, int &b) {
  int c = a;
  a = b;
  b = c;
}

int main() {
  int a = 1, b = 2;
  std::cout << "Before swap: a=" << a << " b=" << b << std::endl;
  swap(a, b);
  std::cout << "After swap: a=" << a << " b=" << b << std::endl;
  return 0;
}
