#include <iostream>

void print(const int c) {
  std::cout << c << std::endl;
}

void print(const int (&arr)[2]) {
  for (auto & c : arr) {
    std::cout << c << " ";
  }
  std::cout << std::endl;
}

int main() {
  int i = 0, j[2] = {0, 1};
  print(i);
  print(j);
}
