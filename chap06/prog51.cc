#include <iostream>

void f(int) {
  std::cout << "f(int)" << std::endl;
}

void f(int, int) {
  std::cout << "f(int,int)" << std::endl;
}

void f(double, double = 3.14) {
  std::cout << "f(double,double=3.14)" << std::endl;
}

int main() {
  // std::cout << "(a)";
  // f(2.56, 42);
  std::cout << "(b)";
  f(42);
  std::cout << "(c)";
  f(42, 0);
  std::cout << "(d)";
  f(2.56, 3.14);
}
