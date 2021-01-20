#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

bool hasFiveChars(const std::string &word) {
  return word.size() >= 5;
}

int main() {
  std::vector<std::string> words{"the", "quick", "red", "fox", "jumps",
    "over", "the", "slow", "red", "turtle"};
  auto ep = std::partition(words.begin(), words.end(), hasFiveChars);
  if (ep != words.end()) {
    std::cout << "words with size >=5 are: ";
    for (auto it = words.begin(); it != ep; ++it) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
  } else {
    std::cout << "words has no word with size >= 5" << std::endl;
  }
}
