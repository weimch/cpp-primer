#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>

int main() {
  std::map<std::string, int> word_count;
  std::string word;
  while (std::cin >> word) {
    for (char &ch : word) {
      ch = std::tolower(ch);
    }
    auto rch = std::remove_if(word.begin(), word.end(), ispunct);
    word.erase(rch, word.end());
    ++word_count[word];
  }
  for (const auto &p : word_count) {
    std::cout << p.first << " " << p.second << std::endl;
  }
  return 0;
}
