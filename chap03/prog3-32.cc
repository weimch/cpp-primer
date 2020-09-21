#include <iostream>
#include <vector>

int main() {
  // 数组定义及其赋值
  int ix[10];
  for (unsigned i = 0; i < 10; i ++) {
    ix[i] = i;
  }
  int cix[10];
  for (unsigned i = 0; i < 10; i ++) {
    cix[i] = ix[i];
  }
  for (auto i : cix) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  // vector定义及其赋值
  std::vector<int> ivec;
  for (unsigned i = 0; i < 10; ++i) {
    ivec.push_back(i);
  }
  std::vector<int> civec = ivec;
  for (auto i : civec) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}