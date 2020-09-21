#include <iostream>
#include <vector>

int main() {
  std::vector<int> ivec;
  int input;
  while (std::cin >> input) {
    ivec.push_back(input);
  }
  // 输出每对相邻整数的和
  for (auto it = ivec.cbegin(); it != ivec.cend(); it += 2) {
    std::cout << *it + *(it+1) << " ";
  }
  std::cout << std::endl;
  // 先输出第一个和最后一个元素的和，再输出第二个和倒数第二个元素的和，以此类推
  for (auto it = ivec.cbegin(), ite = ivec.cend() - 1; it < ite; ++it, --ite) {
    std::cout << *it + *ite << " ";
  }
  std::cout << std::endl;
  return 0;
}