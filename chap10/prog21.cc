#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>

bool isShorter(const std::string &s, std::string::size_type sz) {
  return s.size() >= sz;
}

int main() {
  std::vector<std::string> words{"the", "quick", "red", "fox", "jumps",
    "over", "the", "slow", "red", "turtle"};
  std::string::size_type sz = 4;
  auto f = std::bind(isShorter, std::placeholders::_1, sz);
  std::cout << std::count_if(words.begin(), words.end(), f) << std::endl;
}
