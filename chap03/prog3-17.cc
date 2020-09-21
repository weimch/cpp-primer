#include <iostream>
#include <string>
#include <cctype>
#include <vector>

int main() {
  std::vector<std::string> inputLs;
  std::string input;
  while (std::cin >> input) {
    inputLs.push_back(input);
  }
  for (auto &elem : inputLs) {
    for (auto &ch : elem) {
      ch = std::toupper(ch);
    }
  }
  for (const auto &elem : inputLs) {
    std::cout << elem << std::endl;
  }
  return 0;
}