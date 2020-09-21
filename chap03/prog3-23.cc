#include <iostream>
#include <vector>

int main() {
  std::vector<int> ivec{1,2,3,4,5,6,7,8,9,10};
  for (auto it = ivec.begin(); it != ivec.end(); ++it) {
    *it = *it * *it;
  }
  for (auto it = ivec.cbegin(); it != ivec.cend(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}