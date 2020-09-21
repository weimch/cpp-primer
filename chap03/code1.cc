#include <iostream>

using std::cin;

int main() {
  int i;
  cin >> i; // 正确：cin和std::cin的含义相同
  // cout << i; // 错误：没有对应的using声明，必须使用完整的名字
  std::cout << i;
  return 0;
}