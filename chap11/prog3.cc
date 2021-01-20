#include <iostream>
#include <string>
#include <map>

int main() {
  std::map<std::string, int> word_count;
  std::string word;
  while (std::cin >> word) {
    ++word_count[word];
  }
  for (const auto &p : word_count) {
    std::cout << p.first << " " << p.second << std::endl;
  }
  return 0;
}
