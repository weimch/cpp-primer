#include <iostream>
#include <string>

int main() {
  std::string s("Hello World!!!");
  for (auto &c : s) {
    c = std::toupper(c);
  }
  std::cout << s << std::endl;
  return 0;
}