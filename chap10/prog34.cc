#include <iostream>
#include <vector>

int main() {
  std::vector<int> v{1, 2, 3, 4, 5};
  for (auto it = v.crbegin(); it != v.crend(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}
