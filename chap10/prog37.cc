#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>

int main() {
  std::vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::list<int> l;
  std::copy(v.crbegin() + 2, v.crbegin() + 7, std::back_inserter(l));
  for (const auto &e : l) {
    std::cout << e << " ";
  }
  std::cout << std::endl;
  return 0;
}
