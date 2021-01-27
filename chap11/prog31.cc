#include <map>
#include <iostream>

int main() {
  std::multimap<std::string, std::string> m =
    {{"a1", "b1"}, {"a1", "b2"}, {"a2", "b3"}};
  auto fi = m.find("a1");
  m.erase(fi);
  for (const auto &e : m) {
    std::cout << e.first << ":" << e.second << std::endl;
  }
}
