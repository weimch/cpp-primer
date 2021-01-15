#include <iostream>

std::istream& readStream(std::istream& in) {
  char ch;
  while (in >> ch) {
    std::cout << ch;
  }
  std::cout << std::endl;
  std::cout << "after read is cin valid? -> " << in.good() << std::endl;
  std::cout << "cin reset" << std::endl;
  in.clear();
  return in;
}

int main() {
  std::istream &in = readStream(std::cin);
  std::cout << "is cin valid? -> " << in.good() << std::endl;
  return 0;
}
