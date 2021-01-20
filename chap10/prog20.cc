#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

int main() {
  std::vector<std::string> words{"the", "quick", "red", "fox", "jumps",
    "over", "the", "slow", "red", "turtle"};
  std::string::size_type sz = 4;
  std::cout << std::count_if(words.begin(), words.end(),
    [sz](const std::string &s) { return s.size() >= sz; })
    << std::endl;
}
