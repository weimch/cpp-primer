#include <iostream>
#include <string>

int main() {
  std::string word, preWord, repeatWord;
  while (std::cin >> word) {
    if (word == preWord) {
      repeatWord = word;
      break;
    }
    preWord = word;
  }
  if (!repeatWord.empty()) {
    std::cout << "Find repeatly appear word: " << word << std::endl;
  } else {
    std::cout << "No word are repeated" << std::endl;
  }
  return -1;
}
