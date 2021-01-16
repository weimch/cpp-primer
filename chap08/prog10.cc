#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

int main() {
  std::fstream fin("prog10.input");
  std::string line, word;
  std::vector<std::string> lines;
  while (fin >> line) {
    lines.push_back(line);
  }
  for (const auto &e : lines) {
    std::istringstream iss(e);
    iss >> word;
    std::cout << word << std::endl;
  }
  return 0;
}
