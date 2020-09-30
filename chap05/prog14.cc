#include <iostream>
#include <string>

int main() {
  std::string preWord, curWord, maxWord;
  int maxCount = 0, wordCount = 1;
  while (std::cin >> curWord) {
    if (preWord == curWord) {
      ++wordCount;
    } else {
      if (maxCount < wordCount) {
        maxCount = wordCount;
        maxWord = preWord;
      }
      preWord = curWord;
      wordCount = 1;
    }
  }
  std::cout << "Max Word: " << maxWord << " Max Count: "
            << maxCount << std::endl;
  return 0;
}
