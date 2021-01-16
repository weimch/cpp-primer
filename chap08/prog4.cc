#include <string>
#include <vector>
#include <iostream>
#include <fstream>

int main() {
  std::ifstream fin("prog4.input");
  std::string line;
  std::vector<std::string> v;
  while (getline(fin, line)) {
    v.push_back(line);
  }
  for (auto &t : v) {
    std::cout << t << std::endl;
  }
  return 0;
}
