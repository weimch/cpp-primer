#include <iostream>

int main() {
  double i = 42.0;
  double &r1 = i;
  const int &r2 = i;
  r1 = 0.0;
  std::cout << r1 << " " << r2 << std::endl;
}
