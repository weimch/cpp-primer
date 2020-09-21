#include <iostream>
#include <vector>

int main() {
  std::vector<int> ivec;
  int input;
  while (std::cin >> input) {
    ivec.push_back(input);
  }
  // 输出每对相邻整数的和
  for (decltype(ivec.size()) i = 1; i < ivec.size(); ++i) {
    std::cout << ivec[i] + ivec[i-1] << " ";
  }
  std::cout << std::endl;
  // 先输出第一个和最后一个元素的和，再输出第二个和倒数第二个元素的和，以此类推
  for (decltype(ivec.size()) i = 0; i < ivec.size() / 2; ++i) {
    std::cout << ivec[i] + ivec[ivec.size()-1-i] << " ";
  }
  std::cout << std::endl;
  return 0;
}