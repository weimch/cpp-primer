#include <list>
#include <vector>
#include <iostream>

int main() {
  std::list<int> ls{1, 2, 3};
  std::vector<double> vd(ls.begin(), ls.end());
  for (const auto &e : vd) {
    std::cout << e << " ";
  }
  std::cout << std::endl;
  return 0;
}
