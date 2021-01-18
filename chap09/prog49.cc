#include <iostream>
#include <fstream>
#include <string>

int main() {
  std::ifstream fin("letters.txt");
  std::string ex("dfpg");
  std::string word, result = "";
  while (fin >> word) {
    if (word.find_first_of(ex) == word.npos) {
      result = result.size() < word.size() ? word : result;
    }
  }
  std::cout << "The longest word is: " << result << std::endl;
  return 0;
}

