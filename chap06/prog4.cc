#include <iostream>

int fact(int val) {
  int ret = 1;
  while (val > 1) {
    ret *= val--;
  }
  return ret;
}

int main() {
  int val = 0;
  char exitFlag;
  do {
    std::cout << "Input val to fact: ";
    std::flush(std::cout);
    std::cin >> val;
    std::cout << val << "! is " << fact(val) << std::endl;
    std::cout << "Continue? y or n： ";
    std::flush(std::cout);
    std::cin >> exitFlag;
  } while (!std::cin || exitFlag != 'n');
  return 0;
}
