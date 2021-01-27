#include <map>
#include <iostream>

int main() {
  std::multimap<std::string, std::string> m =
    {{"a2", "b3"}, {"a1", "b2"}, {"a1", "b1"}};
  for (const auto &e : m) {
    std::cout << e.first << ":" << e.second << std::endl;
  }
}
