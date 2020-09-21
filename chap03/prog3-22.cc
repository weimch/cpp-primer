#include <vector>
#include <iostream>
#include <string>
#include <cctype>

int main() {
  std::vector<std::string> text{"hello", "", "world"};
  for (auto it = text.begin(); it != text.end() && !it->empty(); ++it) {
    for (auto &ch : *it) {
      ch = std::toupper(ch);
    }
    std::cout << *it << std::endl;
  }
}