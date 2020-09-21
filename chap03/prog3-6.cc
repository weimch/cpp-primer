#include <iostream>
#include <string>

int main() {
  std::string str = "Hello World";
  for (auto &ch : str) {
    ch = 'X';
  }
  std::cout << str << std::endl;
  return 0;
}