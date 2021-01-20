#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

void printVector(const std::vector<std::string> &words) {
  for (const std::string &e : words) {
    std::cout << e << " ";
  }
  std::cout << std::endl;
}

void elimDups(std::vector<std::string> &words) {
  std::cout << "Before Sort" << std::endl;
  printVector(words);
  std::sort(words.begin(), words.end());
  std::cout << "After Sort" << std::endl;
  printVector(words);
  auto eidx = std::unique(words.begin(), words.end());
  std::cout << "After Unique" << std::endl;
  printVector(words);
  words.erase(eidx, words.end());
  std::cout << "After erase" << std::endl;
  printVector(words);
}

int main() {
  std::vector<std::string> words{"the", "quick", "red", "fox", "jumps",
    "over", "the", "slow", "red", "turtle"};
  elimDups(words);
  return 0;
}
