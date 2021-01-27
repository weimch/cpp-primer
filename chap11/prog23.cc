#include <map>
#include <iostream>
#include <string>

int main() {
  std::multimap<std::string, std::string> m;
  std::string ln;
  for (std::string ln; std::cout << "Last name:\n", std::cin >> ln && ln != "@q";)
      for (std::string cn; std::cout << "|-Children's names:\n", std::cin >> cn && cn != "@q";)
          m.insert({ln, cn});
  for (const auto &e : m) {
    std::cout << e.first << ":" << e.second << std::endl;
  }
  return 0;
}
