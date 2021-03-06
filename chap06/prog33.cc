#include <vector>
#include <iostream>
#include <string>

void PrintVector(const std::vector<std::string> &vec, int idx) {
  if (idx == vec.size()) {
    return;
  }
  std::cout << vec[idx] << std::endl;
  PrintVector(vec, idx + 1);
}

int main() {
  std::vector<std::string> vec{"hello", "world", "weimch"};
  PrintVector(vec, 0);
  return 0;
}
