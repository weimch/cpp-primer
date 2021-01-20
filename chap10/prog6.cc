#include <iostream>
#include <algorithm>

int main() {
  int a[] = {1, 2, 3, 4, 5};
  std::fill_n(std::begin(a), sizeof(a)/sizeof(*a), 0);
  for (int t : a) {
    std::cout << t << std::endl;
  }
}
