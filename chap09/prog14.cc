#include <list>
#include <vector>
#include <iostream>
#include <string>

int main() {
  std::list<const char*> ls{"hello", "word", "weimch"};
  std::vector<std::string> v;
  v.assign(ls.begin(), ls.end());
  for (const auto &e : v) {
    std::cout << e << std::endl;
  }
  return 0;
}
