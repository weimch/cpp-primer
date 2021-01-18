#include <iostream>
#include <forward_list>

int main() {
  std::forward_list<int> fl{1, 2, 3, 4, 5, 6};
  std::forward_list<int>::iterator prev = fl.before_begin(), cur = fl.begin();
  while (cur != fl.end()) {
    if (*cur % 2 == 1) {
      cur = fl.erase_after(prev);
    } else {
      ++prev;
      ++cur;
    }
  }
  for (const auto &e : fl) {
    std::cout << e << " ";
  }
  std::cout << std::endl;
  return 0;
}