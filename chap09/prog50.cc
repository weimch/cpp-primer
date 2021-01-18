#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> vec{"1.1", "2.2", "3.3", "4", "5"};
  int sum = 0;
  double sumd = 0.0;
  for (const auto &e : vec) {
    sum += std::stoi(e);
    sumd += std::stod(e);
  }
  std::cout << "sum of int: " << sum << std::endl;
  std::cout << "sum of double: " << sumd << std::endl;
  return 0;
}
