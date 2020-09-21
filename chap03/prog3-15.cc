#include <iostream>
#include <vector>
#include <string>

int main() {
  std::vector<std::string> ivec;
  std::string input;
  while (std::cin >> input) {
    ivec.push_back(input);
  }
  std::cout << "Your input is: ";
  for (const auto &ele : ivec) {
    std::cout << ele << " ";
  }
  std::cout << std::endl;
  return 0;
}