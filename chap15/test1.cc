#include <iostream>

class Base {
 public:
  virtual void print() {
    std::cout << "a" << a << std::endl;
  }
  int a = 1;
};

class Derived : public Base {
 public:
  void print() override {
    std::cout << "a:" << a << " b:" << b << std::endl;
  }
  int b = 2;
};

int main() {
  Derived d1;
  d1.a = 2;
  Derived d2 = d1;
  d1.print();
  d2.print();
}
