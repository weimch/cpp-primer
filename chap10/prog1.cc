#include <algorithm>
#include <vector>
#include <iostream>

int main() {
  std::vector<int> vec{0, 55, 1, 2, 55, 3, 4, 55};
  int val = 55;
  std::cout << "vec has " <<
    std::count(vec.begin(), vec.end(), val) << " of 55" << std::endl;
  return 0;
}
