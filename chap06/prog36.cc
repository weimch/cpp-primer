#include <iostream>
#include <string>

std::string (&GetStrings(std::string (&ss)[10]))[10] {
  return ss;
}

int main() {
  std::string ss[10] = {"1", "2", "3"};
  std::string (&rss)[10] = GetStrings(ss);
  for (const auto &elem : rss) {
    std::cout << elem << std::endl;
  }
  return 0;
}
