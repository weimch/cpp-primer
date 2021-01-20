#include <iostream>
#include <list>
#include <string>

void elimDups(std::list<std::string> &words) {
  words.sort();
  words.unique();
}

int main() {
  std::list<std::string> words{"the", "quick", "red", "fox", "jumps",
    "over", "the", "slow", "red", "turtle"};
  elimDups(words);
  for (const auto &e : words) {
    std::cout << e << " ";
  }
  std::cout << std::endl;
  return 0;
}
