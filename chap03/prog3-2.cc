#include <iostream>
#include <string>

int main() {
  std::string line;
  // 一次读入一整行
  while (std::getline(std::cin, line)) {
    if (!line.empty()) {
      std::cout << line << std::endl;
    }
  }
  // 一次读入一个词
  // std::string word;
  // while (std::cin >> word) {
  //   if (!word.empty()) {
  //     std::cout << word << std::endl;
  //   }
  // }
  return 0;
}