#include <iostream>
#include <string>

int main() {
  std::string word1, word2;
  std::cin >> word1 >> word2;
  std::cout << "output laregest word: ";
  if (word1 > word2) {
    std::cout << word1 << std::endl;
  } else {
    std::cout << word2 << std::endl;
  }
  std::cin >> word1 >> word2;
  std::cout << "output largest size word: ";
  if (word1.size() > word2.size()) {
    std::cout << word1 << std::endl;
  } else {
    std::cout << word2 << std::endl;
  }
  return 0;
}