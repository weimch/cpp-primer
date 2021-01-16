#include <string>
#include <vector>
#include <iostream>
#include <fstream>

int main() {
  std::ifstream fin("prog4.input");
  std::string word;
  std::vector<std::string> v;
  while (fin >> word) {
    v.push_back(word);
  }
  for (auto &t : v) {
    std::cout << t << std::endl;
  }
  return 0;
}
