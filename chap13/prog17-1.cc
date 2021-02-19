#include <iostream>

struct numbered {
  numbered() {
    mysn = id++;
  }
  int mysn;
  static int id;
};

int numbered::id = 0;


void f(numbered s) {
  std::cout << s.mysn << std::endl;
}

int main() {
  numbered a, b = a, c = b;
  f(a); f(b); f(c);
  return 0;
}
