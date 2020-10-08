#include <iostream>
#include <string>
#include <cctype>

bool hasCapital(const std::string &ss) {
  for (const auto &ch : ss) {
    if (std::isupper(ch)) {
      return true;
    }
  }
  return false;
}

void toLower(std::string &ss) {
  for (auto &ch : ss) {
    ch = std::toupper(ch);
  }
}

int main() {
  std::string ss = "hello World";
  std::cout << hasCapital(ss) << std::endl;
  toLower(ss);
  std::cout << ss << std::endl;
  return 0;
}
