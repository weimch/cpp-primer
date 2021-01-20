#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>

int main() {
  std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::list<int> l1, l2, l3;
  std::copy(v.cbegin(), v.cend(), std::back_inserter(l1));
  std::copy(v.cbegin(), v.cend(), std::front_inserter(l2));
  std::copy(v.cbegin(), v.cend(), std::inserter(l3, l3.begin()));
  std::cout << "back_inserter: ";
  for (const auto & e : l1) {
    std::cout << e << " ";
  }
  std::cout << std::endl;
  std::cout << "front_inserter: ";
  for (const auto & e : l2) {
    std::cout << e << " ";
  }
  std::cout << std::endl;
  std::cout << "inserter: ";
  for (const auto & e : l3) {
    std::cout << e << " ";
  }
  std::cout << std::endl;
  return 0;
}
