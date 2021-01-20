#include <list>
#include <iostream>
#include <iterator>
#include <algorithm>

int main() {
  std::list<int> l{1, 2, 0, 3, 4, 5};
  auto fi = std::find(l.crbegin(), l.crend(), 0);
  std::cout << "find index at: " <<
    std::distance(l.cbegin(), fi.base()) << std::endl;
  return 0;
}
