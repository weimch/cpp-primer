#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>

int main() {
  std::vector<int> v{1, 1, 2, 2, 3, 4, 4, 6};
  std::list<int> l;
  std::unique_copy(v.begin(), v.end(), std::back_inserter(l));
  for (const auto & e : l) {
    std::cout << e << " ";
  }
  std::cout << std::endl;
  return 0;
}
