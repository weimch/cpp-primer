#include <iostream>

int main() {
  int a = 1;
  int *pa = nullptr;
  pa = &a;
  *pa = 2;
  std::cout << "*pa=" << *pa << " a=" << a << std::endl;
  return 0;
}