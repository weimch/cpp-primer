#include <iostream>
#include <string>

int main() {
  std::string word, words;
  while (std::cin >> word) {
    words += word + " ";
  }
  std::cout << words << std::endl;
  return 0;
}