#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>

int main() {
  std::ifstream fin("prog29.input");
  std::istream_iterator<std::string> sfin(fin), eof;
  std::vector<std::string> v;
  while (sfin != eof) {
    v.push_back(*sfin++);
  }
  for (const auto &e : v) {
    std::cout << e << std::endl;
  }
  return 0;
}
