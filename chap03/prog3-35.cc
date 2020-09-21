#include <iostream>

int main() {
  int arr[] = {1, 2, 3, 4};
  int *pa = arr;
  while (pa != std::end(arr)) {
    *pa = 0;
    ++pa;
  }
  for (auto i : arr) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}