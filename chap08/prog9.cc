#include <iostream>
#include <sstream>

std::istream& readStream(std::istream& in) {
  char ch;
  while (in >> ch) {
    std::cout << ch;
  }
  in.clear();
  return in;
}

int main() {
  std::istringstream iss("hello world weimch");
  readStream(iss);
  return 0;
}
