#include <iostream>
#include <vector>

int Add(int a, int b) {
  return a + b;
}

int Minus(int a, int b) {
  return a - b;
}

int Multiply(int a, int b) {
  return a * b;
}

int Divide(int a, int b) {
  return a / b;
}

int main() {
  std::vector<int(*)(int, int)> funcLs{Add, Minus, Multiply, Divide};
  for (decltype(Add) *fp : funcLs) {
    std::cout << fp(4, 2) << std::endl;
  }
  return 0;
}
