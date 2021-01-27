#include <iostream>
#include <vector>
#include <utility>

int main() {
  std::string ss[] = {"hello", "world", "weimch"};
  int is[] = {1, 2, 3};
  std::vector<std::pair<std::string, int>> vec;
  for (unsigned i = 0; i < 3; ++i) {
    vec.push_back(std::make_pair(ss[i], is[i]));
  }
  for (const auto &e : vec) {
    std::cout << e.first << ":" << e.second << std::endl;
  }
  return 0;
}
