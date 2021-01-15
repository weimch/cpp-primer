#include <iostream>

int main() {
  int ival;
  std::cin >> ival;
  std::cout << "is fail? ->" << std::cin.fail() << std::endl;
  auto old_state = std::cin.rdstate();
  std::cin.clear();
  std::cin.setstate(old_state);
}
