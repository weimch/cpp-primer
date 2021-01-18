#include <forward_list>
#include <string>
#include <iostream>

void insertIntoFl(std::forward_list<std::string> &fl,
                  std::string s1, std::string s2) {
  auto cur = fl.begin(), prev = fl.before_begin();
  while (cur != fl.end()) {
    if (*cur == s1) {
      fl.insert_after(cur, s2);
      return;
    }
    ++cur;
    ++prev;
  }
  fl.insert_after(prev, s2);
}

int main() {
  std::forward_list<std::string> fl;
  insertIntoFl(fl, "hello", "world");
  insertIntoFl(fl, "world", "hello");
  for (const auto &e : fl) {
    std::cout << e << " ";
  }
  std::cout << std::endl;
  return 0;
}
