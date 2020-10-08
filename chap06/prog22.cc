#include <iostream>

void exchangePtr(const int *&a, const int *&b) {
  const int *t = b;
  b = a;
  a = t;
}

int main() {
  int a = 10, b = 20;
  const int *pa = &a, *pb = &b;
  exchangePtr(pa, pb);
  std::cout << *pa << " " << *pb << std::endl;
  return 0;
}
