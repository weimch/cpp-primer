#include <iostream>
#include <string>

int main() {
  std::string s("Hello,World!!!");
  std::string ss;
  for (auto c : s) {
    if (!ispunct(c)) {
      ss += c;
    }
  }
  std::cout << ss << std::endl;
  return 0;
}