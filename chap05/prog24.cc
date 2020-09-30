#include <iostream>
#include <stdexcept>

int main() {
  int a = 0, b = 0;
  while (std::cin >> a >> b) {
    try {
      if (b == 0) {
        throw std::runtime_error("digit 0 can't be division");
      }
      std::cout << a / b << std::endl;
    } catch (std::runtime_error err) {
      std::cout << err.what() << "\nTry again? Enter y or n" << std::endl;
      char ch;
      std::cin >> ch;
      if (!std::cin || ch == 'n') {
        break;
      }
    }
  }
  return 0;
}
