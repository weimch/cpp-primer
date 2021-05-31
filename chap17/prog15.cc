#include <iostream>
#include <regex>
#include <string>

int main() {
  std::string pattern("[[:alpha:]]*[^c]ei[[:alpha:]]");
  std::regex r(pattern);
  std::smatch results;
  std::string ts[] = {"receipt", "friend", "theif", "receive"};
  for (auto const &t : ts) {
    if (std::regex_search(t, results, r)) {
      std::cout << t << ": error" << std::endl;
    } else {
      std::cout << t << ": correct" << std::endl;
    }
  }
  return 0;
}
