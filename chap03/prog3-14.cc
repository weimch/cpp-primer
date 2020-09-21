#include <iostream>
#include <vector>

int main() {
  std::vector<int> ivec;
  int input = 0;
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