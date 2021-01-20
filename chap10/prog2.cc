#include <string>
#include <list>
#include <iostream>
#include <algorithm>

int main() {
  std::list<std::string> ls{"hello", "weimch", "world", "weimch"};
  std::string fstr = "weimch";
  std::cout << std::count(ls.begin(), ls.end(), fstr) << std::endl;
  return 0;
}
