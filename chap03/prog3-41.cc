#include <iostream>
#include <vector>

int main() {
  int arr[] = {1, 2, 3, 4};
  std::vector<int> ivec(std::begin(arr), std::end(arr));
  for (const auto &i : ivec) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}