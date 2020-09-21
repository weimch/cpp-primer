#include <iostream>
#include <vector>

int main() {
  std::vector<int> ivec{1, 2, 3, 4};
  int arr[4];
  for (decltype(ivec.size()) i = 0; i < ivec.size(); ++i) {
    arr[i] = ivec[i];
  }
  for (const auto &i : arr) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}